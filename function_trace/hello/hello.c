#include "hello.h"
#include <stdio.h>


/**
 * @brief 
 */
static void _hello()
{
  printf("local Hello World\n");
  return;
}



/**
 * @brief   
 */
void hello()
{
  printf("Hello World\n");
  _hello();
  return;
}
