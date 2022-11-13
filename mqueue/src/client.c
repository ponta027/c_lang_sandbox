#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <time.h>
#include <errno.h>

#include "mqueue_util.h"
#include "sample_mqueue.h"

int main(int argc, char* argv[])
{
  // timeout setup
  struct timespec timeout;
  timeout.tv_sec += 1;


  int error_ret = 0;

  unsigned int cnt = 0;
  ssize_t ret_size;
  char buf[MQ_BUF_SIZE]="Hello World";
  mqd_t fd_req = open_mqueue( MQ_CLIENT_TO_SERVER_NAME,MQ_BUF_SIZE) ;  
  mqd_t fd_res = open_mqueue( MQ_SERVER_TO_CLIENT_NAME,MQ_BUF_SIZE) ;  

  while(1){
    sprintf( buf ,"%s:%d", "Hello World", cnt);
    printf("SEND:%s to : %s\n", buf , MQ_CLIENT_TO_SERVER_NAME);
    ret_size = mq_send( fd_req , buf ,  MQ_BUF_SIZE , 0 );
    printf("SEND:%s(size:%ld) to : %s\n", buf , ret_size, MQ_CLIENT_TO_SERVER_NAME);

    if(-1 == clock_gettime(CLOCK_REALTIME, &timeout))
    {
      perror("error");
    }
    printf("set timeout\n");
    timeout.tv_sec += 2;
    ret_size = mq_timedreceive(fd_res, buf, MQ_BUF_SIZE , NULL, &timeout);
    //    ret_size = mq_receive( fd_res , buf , MQ_BUF_SIZE,NULL); 
    error_ret = errno;;
    printf("RECV:RET:%ld BUF:%s from %s: err%d\n", ret_size , buf, MQ_SERVER_TO_CLIENT_NAME, error_ret);
    if ( cnt > 100 ) {
      break;
    }
    /*
       if (strcmp(buf,"EOL")==0){
       break;
       }
       */
    cnt ++;

  }
  close_mqueue( fd_req);
  close_mqueue( fd_res);

  fflush(stdout);
  return 0;
}
