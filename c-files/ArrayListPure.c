#include "ArrayList.h"

/*
Creates an (instance) of our ArrayList struct, allocating memory for the int * array member and setting size_t size to the
initial size.
*/
void createArrayList(ArrayList * list, size_t initialSize){
    list->size = initialSize;
    list->array = (int *)malloc(sizeof(int) * list->size);
}

/*
Returns the current size of the ArrayList (instance)
*/
size_t size(ArrayList * list){
    return list->size;
}

/*
Gets the element in the ArrayList at the specifed index. If present, returns the element else returns -1
*/
int get(ArrayList * list, int index){
    int rv = index >= 0 && index < list->size ? list->array[index] : -1;
    return rv;
}

/*
Sets the specified value at the specified index to the value of element. Only sets to value if within array bounds.
*/
void set(ArrayList * list, int index, int element){
    int rv = get(list, index);
    if (rv != -1)
        list->array[index] = element;
}

/*
Adds an element to the array in our ArrayList.
*/
void add(ArrayList * list, int element){
    list->array[list->size] = element;
    list->size++;
    list->array = (int *)realloc(list->array, sizeof(int) * list->size);
    
}

/*
Frees memory previously dynamically allocated to the array pointer member in our ArrayList struct.
*/
void deleteArrayList(ArrayList * list){
    free(list->array);
}

/*
Function that prints the elements present in our ArrayList.
*/
void printElements(ArrayList * list){
    for (int i = 0; i < list->size; i++)
        printf("%d\n", list->array[i]);
}