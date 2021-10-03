#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../src/stack.h"

bool ass(int cond) {
  if (cond) {
    printf(".");
    return true;
  } else {
    printf("F");
    return false;
  }
}

/**
 * @brief Test for stack_new function
 */
bool test_stack_new() {
  bool result = true;
  printf("stack.h: stack_new => ");

  stack_t *stack = stack_new();
  if (!ass(stack != NULL)) result = false;
  if (!ass(stack != NULL && stack->length == 0)) result = false;
  if (!ass(stack != NULL && stack->top == NULL)) result = false;

  printf("\n");
  return result;
}

/**
 * @brief Test for stack_destroy function
 */
bool test_stack_destroy() {
  bool result = true;
  printf("stack.h: stack_destroy => ");

  stack_t *stack = stack_new();
  if (!ass(stack != NULL)) result = false;
  if (!ass(stack_destroy(stack, false))) result = false;

  printf("\n");
  return result;
}

/**
 * @brief Test for stack_length function
 */
bool test_stack_length() {
  bool result = true;
  printf("stack.h: stack_length => ");

  stack_t *stack = stack_new();
  if (!ass(stack != NULL)) result = false;
  
  int a = 1;
  int b = 2;

  if (!ass(stack_push(stack, (void*)&a))) result = false;
  if (!ass(stack_length(stack) == 1)) result = false;
  if (!ass(stack_push(stack, (void*)&b))) result = false;
  if (!ass(stack_length(stack) == 2)) result = false;

  printf("\n");
  return result;
}

/**
 * @brief Test for stack_push function
 */
bool test_stack_push_pop() {
  bool result = true;
  printf("stack.h: stack_push_pop => ");

  stack_t *stack = stack_new();
  if (!ass(stack != NULL)) result = false;
  
  int a = 1;
  int b = 2;

  if (!ass(stack_push(stack, (void*)&a))) result = false;
  if (!ass(stack_length(stack) == 1)) result = false;
  if (!ass(stack_push(stack, (void*)&b))) result = false;
  if (!ass(stack_length(stack) == 2)) result = false;

  printf("\n");
  return result;
}

/**
 * @brief entrypoint for stack.h tests
 */
bool test_stack() {
  bool result = true;
  if (
    !test_stack_new() ||
    !test_stack_destroy() ||
    !test_stack_length() ||
    !test_stack_push_pop()
  )
    result = false;
  return result;
}