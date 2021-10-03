#ifndef __LIBBICYCLES_TEST_HASH_H__
#define __LIBBICYCLES_TEST_HASH_H__

#include <stdlib.h>
#include <stdbool.h>
#include "../src/hash.h"

/**
 * @brief Test for djb2 hash function
 * 
 * @return true if all tests passed, else false.
 */
bool test_hash_djb2();

/**
 * @brief Entrypoint for tests of hash.h
 * 
 * @returns true if all tests passed, else false.
 */
bool test_hash();

#endif /* __LIBBICYCLES_TEST_HASH_H__ */
