#include "ArrayList.h"

int main(){

    ArrayList * list = (ArrayList * )malloc(sizeof(ArrayList));

    createArrayList(list, 0);

    add(list, 1);
    add(list, 5);
    add(list, 99);

    size_t arrSize= size(list);
    printf("Size of array: %zu\n", arrSize);

    printElements(list);

    int res1 = get(list, 0);
    printf("res1: %d\n", res1);
    int res2 = get(list, 55);
    printf("res2: %d\n", res2);

    set(list, 2, 101);

    printElements(list);

    set(list, 55, 102);

    printElements(list);


    deleteArrayList(list);
    free(list);
}