#include "list.h"
#include <stdlib.h>
#include <stdbool.h>


list_t *list_new() {
  list_t *list = malloc(sizeof(list_t));
  if (list == NULL) return NULL;

  list->head = NULL;
  list->tail = NULL;
  list->length = 0;

  return list;
}

bool list_destroy(list_t *list, bool needs_free) {
  if (list == NULL) return false;
  if (list->length == 0) {
    free(list);
    return true;
  }

  list_node_t *node;
  while ((node = list->head)) {
    if (needs_free && node->data != NULL)
      free(node->data);
    list->head = node->next;
    list->length--;
    free(node);
  }
  free(list);

  return true;
}

size_t list_length(list_t *list) {
  if (list == NULL) return 0;
  return list->length;
}

bool list_push(list_t *list, void *data) {
  if (list == NULL || data == NULL) return false;
  list_node_t *node = malloc(sizeof(node));
  if (node == NULL) return false;

  node->data = data;
  node->next = list->head;
  node->prev = NULL;

  if (list->head != NULL)
    list->head->prev = node;
  list->head = node;
  if (list->length == 0)
    list->tail = node;
  list->length++;

  return true;
}

void *list_pop(list_t *list) {
  if (list == NULL) return NULL;
  if (list->length == 0) return NULL;

  list_node_t *to_free = list->head;
  void *data = to_free->data;
  list->head = to_free->next;
  list->length--;
  free(to_free);

  return data;
}

bool list_append(list_t *list, void *data) {
  if (list == NULL || data == NULL) return false;

  list_node_t *node = malloc(sizeof(list_node_t));
  if (node == NULL) return false;

  node->data = data;
  node->prev = list->tail;
  node->next = NULL;

  if (list->tail != NULL)
    list->tail->next = node;
  list->tail = node;
  if (list->length == 0)
    list->head = node;
  list->length++;

  return true;
}

void *list_shift(list_t *list) {
  if (list == NULL) return NULL;
  if (list->length == 0) return NULL;

  list_node_t *to_free = list->tail;
  void *data = to_free->data;
  list->tail = to_free->prev;
  list->length--;
  free(to_free);

  return data;
}

bool list_extern(list_t *list, list_t *source) {
  if (list == NULL || source == NULL) return false;
  
  list_node_t *node = source->head;
  while (node) {
    list_append(list, node->data);
    node = node->next;
  }
  
  return true;
}

bool list_pcontains(list_t *list, void *data) {
  if (list == NULL || data == NULL) return false;
  if (list->length == 0) return false;

  list_node_t *node = list->head;
  while (node) {
    if (node->data == data)
      return true;
    node = node->next;
  }

  return false;
}

bool list_contains(list_t *list, void *data, equals_t eq) {
  if (list == NULL || data == NULL || eq == NULL) return false;
  if (list->length == 0) return false;

  list_node_t *node = list->head;
  while (node) {
    if (eq(node->data, data))
      return true;
    node = node->next;
  }

  return false;
}

bool list_premove(list_t *list, void *data, bool needs_free) {
  if (list == NULL || data == NULL) return false;
  if (list->length == 0) return false;

  if (list->length == 1) {
    if (list->head->data == data) {
      if (needs_free)
        free(list->head->data);
      list_node_t *node = list->head;
      list->head = NULL;
      list->tail = NULL;
      list->length--;
      free(node);
      return true;
    }
    return false;
  }

  list_node_t *node = list->head;
  while (node) {
    if (node->data == data) {
      if (needs_free)
        free(node->data);
      list_node_t *next = node->next;
      list_node_t *prev = node->prev;

      if (next)
        next->prev = prev;
      if (prev)
        prev->next = next;
      
      if (list->head == node && next)
        list->head = next;
      if (list->tail == node && prev)
        list->tail = prev;
      free(node);
      list->length--;
      return true;
    }
  }

  return false;
}

bool list_remove(list_t *list, void *data, equals_t eq, bool needs_free) {
  if (list == NULL || data == NULL) return false;
  if (list->length == 0) return false;

  if (list->length == 1) {
    if (eq(list->head->data, data)) {
      if (needs_free)
        free(list->head->data);
      list_node_t *node = list->head;
      list->head = NULL;
      list->tail = NULL;
      list->length--;
      free(node);
      return true;
    }
    return false;
  }

  list_node_t *node = list->head;
  while (node) {
    if (eq(node->data, data)) {
      if (needs_free)
        free(node->data);
      list_node_t *next = node->next;
      list_node_t *prev = node->prev;

      if (next)
        next->prev = prev;
      if (prev)
        prev->next = next;
      
      if (list->head == node && next)
        list->head = next;
      if (list->tail == node && prev)
        list->tail = prev;
      free(node);
      list->length--;
      return true;
    }
  }

  return false;
}

bool list_premove_all(list_t *list, void *data, bool needs_free) {
  if (list == NULL || data == NULL) return false;
  if (list->length == 0) return false;

  if (list->length == 1) {
    if (list->head->data == data) {
      if (needs_free)
        free(list->head->data);
      list_node_t *node = list->head;
      list->head = NULL;
      list->tail = NULL;
      list->length--;
      free(node);
      return true;
    }
    return false;
  }

  list_node_t *node = list->head;
  bool found = false;
  while (node) {
    if (node->data == data) {
      found = true;
      if (needs_free)
        free(node->data);
      list_node_t *next = node->next;
      list_node_t *prev = node->prev;

      if (next)
        next->prev = prev;
      if (prev)
        prev->next = next;
      
      if (list->head == node && next)
        list->head = next;
      if (list->tail == node && prev)
        list->tail = prev;
      free(node);
      list->length--;
    }
  }

  return found;
}

bool list_remove_all(list_t *list, void *data, equals_t eq, bool needs_free) {
  if (list == NULL || data == NULL) return false;
  if (list->length == 0) return false;

  if (list->length == 1) {
    if (eq(list->head->data, data)) {
      if (needs_free)
        free(list->head->data);
      list_node_t *node = list->head;
      list->head = NULL;
      list->tail = NULL;
      list->length--;
      free(node);
      return true;
    }
    return false;
  }

  list_node_t *node = list->head;
  bool found = false;
  while (node) {
    if (eq(node->data, data)) {
      found = true;
      if (needs_free)
        free(node->data);
      list_node_t *next = node->next;
      list_node_t *prev = node->prev;

      if (next)
        next->prev = prev;
      if (prev)
        prev->next = next;
      
      if (list->head == node && next)
        list->head = next;
      if (list->tail == node && prev)
        list->tail = prev;
      free(node);
      list->length--;
    }
  }

  return found;
}

list_iter_t *list_iter_new(list_t *list) {
  if (list == NULL) return NULL;
  if (list->length == 0) return NULL;

  list_iter_t *iter = malloc(sizeof(list_iter_t));
  if (iter == NULL) return NULL;

  iter->current = list->head;
  return iter;
}

void *list_iter_next(list_iter_t *iter) {
  if (iter == NULL) return NULL;
  if (iter->current == NULL) return NULL;
  
  void *data = iter->current->data;
  iter->current = iter->current->next;

  return data;
}

bool list_iter_destroy(list_iter_t *iter) {
  if (iter == NULL) return false;
  free(iter);
  return true;
}
