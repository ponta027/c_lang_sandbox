#ifndef MQUEUE_UTIL_H
#define MQUEUE_UTIL_H

mqd_t open_mqueue( const char* mq_name ,unsigned int size);
mqd_t create_mqueue( const char* mq_name ,unsigned int size);

int delete_mqueue( const char* mq_name);
int close_mqueue( mqd_t fd );
#endif
