#include <stdlib.h>
#include <stdio.h>

int main(){
  int* a = malloc(sizeof(int)*3);
  printf("%d %d %d\n", a[0], a[1], a[2]);
}
