#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include<stdio.h>
#include<stdlib.h>

/*
Struct that serves as our ArrayList object
*/
typedef struct {
    int * array;
    size_t size;
} ArrayList;

/*
Creates an (instance) of our ArrayList struct, allocating memory for the int * array member and setting size_t size to the
initial size.
*/
void createArrayList(ArrayList * list, size_t initialSize);

/*
Returns the current size of the ArrayList (instance)
*/
size_t size(ArrayList * list);

/*
Gets the element in the ArrayList at the specifed index. If present, returns the element else returns NULL
*/
int get(ArrayList * list, int index);

/*
Sets the specified value at the specified index to the value of element. Only sets to value if within array bounds.
*/
void set(ArrayList * list, int index, int element);

/*
Adds an element to the array in our ArrayList.
*/
void add(ArrayList * list, int element);

/*
Frees memory previously dynamically allocated to the array pointer member in our ArrayList struct.
*/
void deleteArrayList(ArrayList * list);

/*
Function that prints the elements present in our ArrayList.
*/
void printElements(ArrayList * list);

#endif