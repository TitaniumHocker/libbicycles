/**
 * @file list.h
 * @author Ivan Fedorov <inbox@titaniumhocker.ru>
 * @copyright MIT Licence
 * @date 2021
 * @brief File containing implementation of list via
 *  doubly linked list abstract data type.
 * 
 * @see https://en.wikipedia.org/wiki/Doubly_linked_list
 */

#ifndef __LIBBICYCLES_LIST_H__
#define __LIBBICYCLES_LIST_H__

#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief List node
 */
typedef struct ListNode {
  void *data;               ///< Pointer to stored data.
  struct ListNode *next;    ///< Pointer to next node.
  struct ListNode *prev;    ///< Pointet to previous node.
} list_node_t;

/**
 * @brief List
 */
typedef struct List {
  list_node_t *head;        ///< Pointer to first element of list.
  list_node_t *tail;        ///< Pointer to last element of list.
  size_t length;            ///< Current length of list.
} list_t;

/**
 * @brief Iterator for list
 */
typedef struct ListIterator {
  list_node_t *current;     ///< Pointer to current node of list.
} list_iter_t;

/**
 * @brief Function pointer for equals operations
 */
typedef bool (*equals_t)(void*, void*);

/**
 * @brief Function pointer for comparing operations
 */
typedef int (*comparator_t)(void*, void*);

/**
 * @brief Create list
 * 
 * @returns Pointer to created list
 *  or NULL if failed to create.
 */
extern list_t *list_new();

/**
 * @brief Destroy list
 * 
 * @param list Pointer to list.
 * @param needs_free true if need to call free on node data, else false.
 * @returns false if given NULL pointer, overwise true.
 */
extern bool list_destroy(list_t *list, bool needs_free);

/**
 * @brief Get current length of list
 * 
 * @param list Pointer to list.
 * @returns Number of elements in given list.
 */
extern size_t list_length(list_t *list);

/**
 * @brief Add new element at head of the list
 * 
 * @param list Pointer to list.
 * @param data Pointer to data to add.
 * @returns true if success, else false.
 */
extern bool list_push(list_t *list, void *data);

/**
 * @brief Remove element from head of the list
 * 
 * @param list Pointer to list.
 * @returns Pointer to data from removed node,
 *  if list is empty - NULL.
 */
extern void *list_pop(list_t *list);

/**
 * @brief Add new element at tail of the list
 * 
 * @param list Pointer to list.
 * @param data Pointer to data to add.
 * @returns true if success, else false.
 */
extern bool list_append(list_t *list, void *data);

/**
 * @brief Remove element from tail of the list
 * 
 * @param list Pointer to list.
 * @returns Pointer to data from removed node,
 *  if list is empty - NULL.
 */
extern void *list_shift(list_t *list);

/**
 * @brief Add elements from another list to tail of the list
 * 
 * @param list Pointer to list to extend.
 * @param source Pointer to source list.
 * @return true on success, else false.
 */
extern bool list_extend(list_t *list, list_t *source);

/**
 * @brief Check if data pointer exists in list
 * 
 * Iterates through all elements of list for searching an element
 * with givent ponter as data.
 *
 * @warning This operation will perform linear search.
 * 
 * @param list Pointer to list.
 * @param data Pointer to checking data.
 * @returns true if this pointer exists in list, overwise false.
 */
extern bool list_pcontains(list_t *list, void *data);

/**
 * @brief Check if data exists in list
 * 
 * Iterates through all elements of list for searching an
 * element with which compairing function eq returns true.
 * 
 * @warning This operation will perform linear search.
 * 
 * @param list Pointer to list.
 * @param data Pointer to checking data.
 * @param eq Pointer to function that will be used for equals check.
 * @returns true if this data exists in list, overwise false.
 */
extern bool list_contains(list_t *list, void *data, equals_t eq);

/**
 * @brief Remove element from list by pointer
 * 
 * @param list Pointer to a list.
 * @param data Pointer to value.
 * @param needs_free true if need to call free on node data, else false.
 * @returns true on success, else false.
 */
extern bool list_premove(list_t *list, void *data, bool needs_free);

/**
 * @brief Remove element from list by value
 * 
 * @param list Pointer to a list.
 * @param data Pointer to value.
 * @param eq Pointer to function that will be used for equals check.
 * @param needs_free true if need to call free on node data, else false.
 * @returns true on success, else false
 */
extern bool list_remove(list_t *list, void *data, equals_t eq, bool needs_free);

/**
 * @brief Remove all elements from the list by pointer
 * 
 * @param list Pointer to the list.
 * @param data Pointer to value.
 * @param needs_free true if need to call free on node data, else false.
 * @returns true on success, else false.
 */
extern bool list_premove_all(list_t *list, void *data, bool needs_free);

/**
 * @brief Remove all elements from the list by value
 * 
 * @param list Pointer to the list.
 * @param data Pointet to data.
 * @param eq Pointer to function that will be used for equals check.
 * @param needs_free true if need to call free on node data, else false.
 * @returns true on success, else false
 */
extern bool list_remove_all(list_t *list, void *data, equals_t eq, bool needs_free);

/**
 * @brief Create list iterator
 * 
 * @param list Pointer to list.
 * @returns Iterator pointer or NULL if failed to create.
 */
extern list_iter_t *list_iter_new(list_t *list);

/**
 * @brief Perform iteration in iterator
 * 
 * @param iter Pointer to iterator.
 * @returns Pointer to data from node, of NULL
 *  if iteration completed and nothing to return.
 */
extern void *list_iter_next(list_iter_t *iter);

/**
 * @brief Destroy list iterator
 * 
 * @param iter Pointer to iterator.
 * @returns true if success, else false.
 */
extern bool list_iter_destroy(list_iter_t *iter);

#endif /* __LIBBICYCLES_LIST_H__ */
