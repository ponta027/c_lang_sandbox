#include <dlfcn.h>
#include <stdio.h>


/**
 * @brief 
 *
 * @param 
 */
__attribute__((no_instrument_function)) const char *addr2name(void *address)
{
  Dl_info dli;
  if (dladdr(address, &dli) != 0)
  {
    return dli.dli_sname;
  }
  else
  {
    return NULL;
  }
}


/**
 * @brief 
 *
 * @param 
 * @param call_site
 */
__attribute__((no_instrument_function)) void __cyg_profile_func_enter(void *func_address, void *call_site)
{

  const char *call_func_name = addr2name(func_address);
  const char *caller_func_name = addr2name(call_site);
  printf("[enter]%s->%s\n", caller_func_name, call_func_name);

}

/**
 * @brief 
 *
 * @param 
 * @param call_site
 */
__attribute__((no_instrument_function)) void __cyg_profile_func_exit(void *func_address, void *call_site)
{
  const char *call_func_name = addr2name(func_address);
  const char *caller_func_name = addr2name(call_site);
  printf("[exit]%s->%s\n", call_func_name, caller_func_name);
}

