#include <bicycles/hash.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  for (int i = 0; i < argc; i++)
    printf("djb2(%s)=%lu\n", argv[i], djb2(argv[i]));
  return EXIT_SUCCESS;
}