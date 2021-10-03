#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>

stack_t *stack_new() {
  stack_t *stack = malloc(sizeof(stack_t));
  if (stack == NULL) return NULL;
  stack->length = 0;
  stack->top  = NULL;
  return stack;
}

bool stack_destroy(stack_t *stack, bool needs_free) {
  if (stack == NULL) return false;
  stack_node_t *node;

  while ((node = stack->top)) {
    if (node->data != NULL && needs_free)
      free(node->data);

    stack->top = node->next;
    stack->length--;

    free(node);
  }

  return true;
}

size_t stack_length(stack_t *stack) {
  if (stack == NULL) return 0;
  return stack->length;
}

bool stack_push(stack_t *stack, void* data) {
  if (stack == NULL) return false;
  stack_node_t *node = malloc(sizeof(stack_node_t));
  if (node == NULL) return false;

  node->data = data;
  node->next = stack->top;

  stack->top = node;
  stack->length++;

  return true;
}

void *stack_pop(stack_t *stack) {
  if (stack == NULL) return NULL;
  if (stack->top == NULL) return NULL;

  stack_node_t *node = stack->top;
  stack->top = node->next;
  stack->length--;

  void *data = node->data;
  free(node);
  return data;
}
