#include <mqueue.h>
#include <fcntl.h>

#include "mqueue_util.h"

#define MQ_OFLAG O_CREAT|O_RDWR
#define MQ_OFLAG_OPEN O_RDWR
#define MQ_MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

mqd_t open_mqueue( const char* mq_name ,unsigned int size)
{
  struct mq_attr mqattr;
  mqattr.mq_flags = 0;
  mqattr.mq_maxmsg = 1;
  mqattr.mq_msgsize = size;
  mqd_t fd = mq_open( mq_name , MQ_OFLAG_OPEN , MQ_MODE , &mqattr);
  return fd;
}

mqd_t create_mqueue( const char* mq_name ,unsigned int size)
{
  struct mq_attr mqattr;
  mqattr.mq_flags = 0;
  mqattr.mq_maxmsg = 1;
  mqattr.mq_msgsize = size;
  mqd_t fd = mq_open( mq_name , MQ_OFLAG , MQ_MODE , &mqattr);
  return fd;
}

int close_mqueue( mqd_t fd ) {
  return mq_close( fd );
}

int delete_mqueue( const char* mq_name){

  return mq_unlink( mq_name );
}
