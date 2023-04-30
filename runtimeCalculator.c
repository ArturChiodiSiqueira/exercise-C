#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 10000
#define MAX_LENGTH 100000
#define VARIANCE_LENGTH 10000

void bubbleSort(int v[], int n) {
    int a, b, aux;
    for (a=n-1; a>=1; a--) {
        for (b=0; b<a; b++) {
            if (v[b]>v[b+1]) {
                aux = v[b];
                v[b] = v[b+1];
                v[b+1] = aux;
            }
        }
    }
}

char* RandomName() {
    char* name;
    int i, length = rand() % 10 + 5; //Random name size between 5 and 15
    name = (char*)malloc(length + 1); //Allocate space for name
    for (i = 0; i < length; i++) {
        name[i] = 'a' + rand() % 26; //Random characters from 'a' to 'z'
    }
    name[length] = '\0'; //Add null character at the end
    return name;
}

int RandomAge(int length) {
    RandomName();
    return rand() % length;
}

double CalculateSortTime(int length) {
    int *array = malloc(sizeof(int) * length); //Dynamically allocate variable length array
    int i;
    for (i = 0; i < length; i++) {
        array[i] = RandomAge(length); //Fill array with random numbers
    }  
    clock_t start = clock();
    bubbleSort(array, length);
    clock_t end = clock();
    double runtime = (double)(end - start) / CLOCKS_PER_SEC; //Calculate the running time
    free(array); //Free up memory
    return runtime;
}

int main() {
    int length;
    for (length = MIN_LENGTH; length <= MAX_LENGTH; length += VARIANCE_LENGTH) {
        double runtime = CalculateSortTime(length);
        printf("Time to sort %d records: %lf seconds!\n", length, runtime);
    }
    return 0;
}