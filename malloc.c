#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

static const char zero = 1;
void* __libc_malloc(size_t);
void* __libc_calloc(size_t,size_t);
void* __libc_realloc(void*,size_t);
void __libc_free(void*);

static void* (*real_malloc)(size_t)=NULL;
static void* (*real_calloc)(size_t, size_t)=NULL;
static void* (*real_realloc)(void*, size_t)=NULL;
static void (*real_free)(void*)=NULL;
static int initialized = 0;

static void mtrace_init(void)
{
    if(!initialized){ 
      initialized = 1; // ok
    } else {
      fprintf(stderr, "Error, mtrace_init called recursively.\n");
    }
    real_malloc = __libc_malloc;
    real_calloc = __libc_calloc;
    real_realloc = __libc_realloc;
    real_free = __libc_free;
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

