#include "hash.h"

unsigned long djb2(char* string) {
  unsigned long hash = BICYCLES_DJB2_MAGIC_HASH;
  int c;

  while ((c = *string++))
    hash = ((hash << 5) + hash) + c;
  
  return hash;
}
