#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "test_hash.h"
#include "test_stack.h"


bool run_tests() {
  bool result = true;

  if (!test_hash()) result = false;
  if (!test_stack()) result = false;

  return result;
}

int main(int argc, char** argv) {
  int result = EXIT_SUCCESS;

  printf("---- Starting tests ----\n");

  if (!run_tests())
    result = EXIT_FAILURE;
  
  if (result == EXIT_SUCCESS)
    printf("---- Tests succeeded ----\n");
  else
    printf("---- Tests failed ----\n");

  return result;
}
