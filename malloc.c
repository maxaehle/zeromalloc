#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

static const char zero = 1;

static void* (*real_malloc)(size_t)=NULL;
static void* (*real_calloc)(size_t, size_t)=NULL;
static void* (*real_realloc)(void*, size_t)=NULL;
static void* (*real_free)(void*)=NULL;
static int initialized = 0;

static void mtrace_init(void)
{
    if(!initialized){ 
      initialized = 1; // ok
    } else {
      fprintf(stderr, "Error, mtrace_init called recursively.\n");
    }
    real_malloc = dlsym(RTLD_NEXT, "malloc");
    if (NULL == real_malloc) {
        fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
    }
    real_calloc = dlsym(RTLD_NEXT, "calloc");
    if (NULL == real_calloc) {
        fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
    }

    real_realloc = dlsym(RTLD_NEXT, "realloc");
    if (NULL == real_realloc) {
        fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
    }
    real_free = dlsym(RTLD_NEXT, "free");
    if (NULL == real_free) {
        fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
    }
}

void *malloc(size_t size)
{
  if(!initialized) mtrace_init();
  void* res = real_malloc(size);
  memset(res,zero,size);
}
void *calloc(size_t n, size_t size){
  if(!initialized) mtrace_init();
  return real_calloc(n,size);
}
void *realloc(void* ptr, size_t size){
  if(!initialized) mtrace_init();
  void* res = real_realloc(ptr,size);
  memset(res,zero, size);
  return res;
} 
void free(void* ptr){
  if(!initialized) mtrace_init();
  real_free(ptr);
}

