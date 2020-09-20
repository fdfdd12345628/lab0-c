#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (q == NULL) {
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* Free queue structure */
    if (q == NULL) {
        return;
    }
    list_ele_t *ele = q->head;
    while (true) {
        if (ele == NULL) {
            break;
        }
        free(ele->value);
        free(ele);
        ele = ele->next;
    }
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    if (q == NULL) {
        return false;
    }
    newh = malloc(sizeof(list_ele_t));
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    if (newh == NULL) {
        return false;
    }
    int str_len = strlen(s);
    char *new_str = malloc(sizeof(char) * (str_len + 1));
    if (new_str == NULL) {
        free(newh);
        return false;
    }
    newh->value = new_str;
    strncpy(newh->value, s, str_len + 1);
    if (q->head == NULL) {
        q->tail = newh;
    }
    newh->next = q->head;
    q->head = newh;
    q->size += 1;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t *newh;
    if (q == NULL) {
        return false;
    }
    newh = malloc(sizeof(list_ele_t));
    if (newh == NULL) {
        return false;
    }
    newh->next = NULL;
    int str_len = strlen(s);
    char *new_str = malloc(sizeof(char) * (str_len + 1));
    if (new_str == NULL) {
        free(newh);
        return false;
    }
    newh->value = new_str;
    newh->next = NULL;
    strncpy(newh->value, s, str_len + 1);
    q->tail->next = newh;
    q->tail = newh;
    q->size += 1;
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */
    if (q == NULL) {
        return false;
    }
    if (q->head == NULL) {
        return false;
    }
    list_ele_t *temp = q->head;
    q->head = q->head->next;
    q->size -= 1;
    strncpy(sp, temp->value, bufsize);
    if (temp == q->tail) {
        q->tail = NULL;
    }
    free(temp->value);
    free(temp);
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    if (q == NULL) {
        return;
    }
    if (q->size == 0) {
        return;
    }
    list_ele_t *head = q->head;
    list_ele_t *prev = head;
    list_ele_t *current = head->next;
    while (true) {
        if (current == NULL) {
            break;
        }
        list_ele_t *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    q->head = prev;
    q->tail = head;
    q->tail->next = NULL;
    return;
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
