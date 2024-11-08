/**
* 
* Author: Akanksha Adhikary
* Roll Number: 2522202
* Date: 07/11/2024
* File: dynamic_array.c
* git: https://github.com/ladyhart/BPPIMT/tree/master/week-05/dynamic_array.c
* Compiler: GCC 14, Clang 18
* Language: C17 (Standard 2017) 
* Description: Implementing a dynamic array with functions to insert,
* delete by index, and delete by value.
**/
#include <stdio.h>
#include <stdlib.h>

/* Maximum size of an array */
#define SIZE 5

/* Global variable to keep track of current position in the array */
int current_pos = -1;

void array_print(const int *);
void insert(int *restrict, const int);
void delete_index(int *restrict, const size_t);
void delete_value(int *restrict, const int);

int main(const int argc, const char *argv[]) {

  int *array = calloc(sizeof(int), 5);

  insert(array, 115);
  array_print(array);
  insert(array, 4);
  insert(array, 23);
  array_print(array);
  delete_value(array, 23);
  array_print(array);
  delete_index(array, 1);
  array_print(array);
  insert(array, 20);
  array_print(array);

  free(array);
  array = NULL;
  return 0;
}

void array_print(const int *pArray) {
  int i = 0;
  const int last = SIZE-1;

  printf("[");
  for (; i < last; i++) {
    printf("%d, ", pArray[i]);
  }
  printf("%d]\n", pArray[last]);
}

void insert(int *restrict pArray, const int value) {
  current_pos++;
  if (current_pos >= SIZE) {
    printf("\nERROR: array \'index\' out of range.");
    return;
  }
  pArray[current_pos] = value;
}

void delete_index(int *restrict p, const size_t index) {

  int i = 0;
  int matched_index = index;
  if (index >= SIZE) {
    printf("\nERROR: array \'index\' out of range.");
    return;
  }

  /** left shift */
  for (i = matched_index + 1; i < SIZE; i++) {
    p[matched_index] = p[i];
    matched_index++;
  }
  current_pos--;
  p[SIZE - 1] = 0;
}

void delete_value(int *restrict pArray, const int value) {

  int i = 0;
  int matched_index = -1;

  /** search element  */
  for (i; i < SIZE; i++) {
    if (pArray[i] == value) {
      matched_index = i;
      break;
    }
  }

  if (matched_index == -1) {
    printf("\nERROR: No \'element\' found.");
    return;
  }

  delete_index(pArray, matched_index);
}

