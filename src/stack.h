/**
 * @file stack.h
 * @author Ivan Fedorov <inbox@titaniumhocker.ru>
 * @copyright MIT Licence
 * @date 2021
 * @brief File containing implementation of stack abstract data type.
 * 
 * Stack is abstract data type that contains a collections of
 * elements with, at least, two main operations:
 *  - Push: adds an element to the collection.
 *  - Pop: removes recently added element from the collection.
 * 
 * This implementation of stack is based on single
 * linked list abstract data type.
 * 
 * @see https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 */

#ifndef __LIBBICYCLES_STACK_H__
#define __LIBBICYCLES_STACK_H__

#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Stack node struct
 * 
 * Implemented as element of single linked list.
 * 
 */
typedef struct StackNode {
  void *data;               ///< Pointer to stored data.
  struct StackNode *next;   ///< Pointer to next node.
} stack_node_t;

/**
 * @brief Stack struct
 * 
 */
typedef struct Stack {
  stack_node_t *top;        ///< Pointer to node at the top.
  size_t length;            ///< Current number of elements in stack.
} stack_t;

/**
 * @brief Create new stack
 *  
 * @returns Pointer to new stack instance
 *  or NULL if failed to create new stack.
 */
stack_t *stack_new();

/**
 * @brief Destroy stack
 * 
 * @param stack Pointer to a stack.
 * @param needs_free true if need to call free on node data, else false.
 * @returns false if given NULL ponter, overwise true.
 */
bool stack_destroy(stack_t *stack, bool needs_free);

/**
 * @brief Get current number of elements in given stack
 *  
 * @param stack Pointer to a stack.
 * @return Current size of a stack.
 */
size_t stack_length(stack_t *stack);

/**
 * @brief Push new value to a stack
 *  
 * @param stack Pointer to a stack.
 * @param data Void pointer to data.
 * @returns true if push was successfull, overwise false.
 */
bool stack_push(stack_t *stack, void *data);

/**
 * @brief Pop value from a stack
 *  
 * @param stack Pointer to a stack.
 * @returns Pointer to popped data or NULL
 *  if stack is empty and nothing to pop.
 */
void *stack_pop(stack_t *stack);

#endif /* __LIBBICYCLES_STACK_H__ */
