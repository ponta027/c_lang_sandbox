#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


#include "sample_mqueue.h"
#include "mqueue_util.h"


int main(int argc, char* argv[])
{
  ssize_t ret_size;
  char buf[MQ_BUF_SIZE]="Hello World";
  mqd_t fd_req = create_mqueue( MQ_CLIENT_TO_SERVER_NAME,MQ_BUF_SIZE) ;  
  mqd_t fd_res = create_mqueue( MQ_SERVER_TO_CLIENT_NAME,MQ_BUF_SIZE) ;  


  while(1){

    ret_size = mq_receive( fd_req , buf , MQ_BUF_SIZE,NULL); 
    printf("RECV:%s from %s\n",buf, MQ_CLIENT_TO_SERVER_NAME);

    if (strcmp(buf,"Hello World:2")==0){
      break;
    }
    sleep(1);

    //
    ret_size = mq_send( fd_res , buf ,  MQ_BUF_SIZE , 0 );
    printf("SEND:%s(size:%ld) to : %s\n", buf , ret_size, MQ_SERVER_TO_CLIENT_NAME);
    sleep(1);

  }
  close_mqueue( fd_req);
  close_mqueue( fd_res);


  delete_mqueue( MQ_SERVER_TO_CLIENT_NAME);
  delete_mqueue( MQ_CLIENT_TO_SERVER_NAME);

  fflush(stdout);
  return 0;
}
