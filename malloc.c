#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

void* __libc_malloc(size_t);
void* __libc_calloc(size_t,size_t);
void* __libc_realloc(void*,size_t);
void __libc_free(void*);

static const char zero = 0;

void *malloc(size_t size)
{
  void* res = __libc_malloc(size);
  memset(res,zero,size);
  return res;
}
void *calloc(size_t n, size_t size){
  return __libc_calloc(n,size);
}
void *realloc(void* ptr, size_t size){
  void* res = __libc_realloc(ptr,size);
  // memset(res,zero, size); // causes problems
  return res;
} 
void free(void* ptr){
  __libc_free(ptr);
}

