#ifndef __LIBBICYCLES_TEST_STACK_H__
#define __LIBBICYCLES_TEST_STACK_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../src/stack.h"

/**
 * @brief Test for stack_new function
 */
bool test_stack_new();

/**
 * @brief Test for stack_destroy function
 */
bool test_stack_destroy();

/**
 * @brief Test for stack_length function
 */
bool test_stack_length();

/**
 * @brief Test for stack_push function
 */
bool test_stack_push();

/**
 * @brief Test for stack_pop function
 */
bool test_stack_pop();

/**
 * @brief entrypoint for stack.h tests
 */
bool test_stack();

#endif /* __LIBBICYCLES_TEST_STACK_H__ */
