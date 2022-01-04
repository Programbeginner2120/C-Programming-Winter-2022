#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

/*
Struct that contains an int array and an unsigned int to keep track of the array size
*/
typedef struct {
    int * array;
    unsigned int numElements;
} ArrayContainer;


/*
Takes in a floating point number x and int n and returns x^n
*/
float question1a(float x, int n){
    float res = x;
    for (int i = 1; i < n; i++)
        res *= x;
    return res;
}


/*
Prints an n x n square of the given char c
*/
void question1b(char c, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%c", c);
        printf("\n");
    }
}


/*
Takes a poiner to an ArrayContainer (instance) and fills the array with random numbers in range 0-49 inclusive
*/
void fillArrayWithRandoms(ArrayContainer * randArr){
    time_t t;
    srand((unsigned) time(&t));

    for (int i = 0; i < randArr->numElements; i++)
        randArr->array[i] = rand() % 50; // Generating numbers between 0 and 49 inclusive
}


/*
Prompts the user to input the desired size of the array
*/
unsigned int getSizeOfArray(){
    unsigned int arraySize;
    printf("Enter the size of the array: ");
    scanf("%u", &arraySize);

    return arraySize;
}


/*
Dynamically allocates memory for our ArrayContainer and the inner array and calls fillArrayWithRandoms(), then returns the
ArrayContainer pointer
*/
ArrayContainer * allocateArray(){
    unsigned int arraySize = getSizeOfArray();

    ArrayContainer * randArr = (ArrayContainer *)malloc(sizeof(ArrayContainer));
    randArr->array = (int *)malloc(arraySize * sizeof(int));
    randArr->numElements = arraySize;

    fillArrayWithRandoms(randArr);

    return randArr;
}


/*
Frees the memory allocated for the ArrayContainer pointer and the pointer to the array member
*/
void deconstructArray(ArrayContainer * randArr){
    free(randArr->array);
    free(randArr);
}


/*
Linearly searches for int desiredElement. If found, returns the index of it in the array, else -1.
*/
int question2a(ArrayContainer * randArr, int desiredNumber){
    for (int i = 0; i < randArr->numElements; i++){
        if (randArr->array[i] == desiredNumber)
            return i;
    }
    return -1;
}


/*
Takes in ArrayContainer pointer and sorts the elements that the array pointer points to using insertion sort
*/
void insertionSort(ArrayContainer * randArr){
    for(int i = 1; i < randArr->numElements; i++){
        int key = randArr->array[i];
        int currentIdx = i;
        int prevIndex = currentIdx - 1;
        while (currentIdx > 0 && key < randArr->array[prevIndex]){
            int temp = randArr->array[prevIndex];
            randArr->array[prevIndex] = key;
            randArr->array[currentIdx] = temp;
            currentIdx--;
            prevIndex--;
            key = randArr->array[currentIdx];
        }
    }
}


/*
Takes in pointer to ArrayContainer and uses a binary search to find the int desiredElement in the array member of the 
ArrayContainer. If the element is found, the index is returned, If not, returns -1.
*/
int question2b(ArrayContainer * randArr, int desiredNumber){
    int start = 0;
    int end = randArr->numElements - 1;
    int * arr = randArr->array;

    int midIndex;
    while(start <= end){
        midIndex = start + (end - start) / 2;
        if (arr[midIndex] == desiredNumber)
            return midIndex;
        if (arr[midIndex] < desiredNumber)
            start = midIndex + 1;
        if (arr[midIndex] > desiredNumber)
            end = midIndex - 1;
    }

    return -1;
}

/*
Prints the list of primes found when calling the sieve() function
*/
void printPrimes(int arr [], int numElements){
    for (int i = 0; i < numElements; i++)
        printf("%d\n", arr[i]);
}


/*
Implementation of the famous sieve algorithm, which identifies all primes from 1 to num
*/
void sieve(int arr [], int num){
    arr[0] = 2;
    int numElements = 1;
    for (int i = 3; i <= num; i += 2){
        if (i == 3 || i == 5 || i == 7 || (3 + i) % 3 != 0 && (5 + i) % 5 != 0 && (7 + i) % 7 != 0){
            arr[numElements] = i;
            numElements++;
        }
    }

    printPrimes(arr, numElements);
}


int main(int argc, char * argv[]){
    printf("%.2f\n", question1a(2, 4));
    printf("%.2f\n", question1a(9, 3));
    printf("%.2f\n", question1a(8, 2));
    question1b('A', 9);

    ArrayContainer * randArr = allocateArray();

    for (int i = 0; i < randArr->numElements; i++)
        printf("%d\n", randArr->array[i]);

    int indexOfFound1 = question2a(randArr, 3);
    printf("indexOfFound1: %d\n", indexOfFound1);

    insertionSort(randArr);

    for (int i = 0; i < randArr->numElements; i++)
        printf("%d\n", randArr->array[i]);

    int indexOfFound2 = question2b(randArr, 6);
    printf("indexOfFound2: %d\n", indexOfFound2);

    deconstructArray(randArr);

    int num = 121;
    int arr [num];

    sieve(arr, num);

}