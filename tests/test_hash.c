#include "test_hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include "../src/hash.h"

bool test_hash_djb2() {
  bool result = true;

  const int djb2_test_cases = 6;
  char* djb2_inputs[] = {
    "lhg9t5r6",
    "some",
    "vj6toue1",
    "test",
    "3cxcg2oq",
    "strings",
  };
  unsigned long djb2_outputs[] = {
    7572625982038314,
    6385698233,
    7573052901628681,
    6385723493,
    7570190988088655,
    229483039272943
  };

  printf("hash.h: djb2 => ");
  for (int i = 0; i < djb2_test_cases; i++) {
    if (djb2(djb2_inputs[i]) == djb2_outputs[i]) {
      printf(".");
    } else {
      printf("F");
      result = false;
    }
  }
  printf("\n");

  return result;
}

extern bool test_hash() {
  bool result = true;
  if (!test_hash_djb2())
    result = false;
  return result;
}