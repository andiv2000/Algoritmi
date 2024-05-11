#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10000]; // Larger array size
    int n = sizeof(arr)/sizeof(arr[0]);

    srand(time(0)); // Seed for random number generation

    // Generate random elements
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Generate random numbers between 0 and 9999
    }

    // Print the unsorted array
    printf("Unsorted array: \n");
    printArray(arr, n);

    // Timing the sorting process
    clock_t start, end;
    double cpu_time_used = 0;

    int num_iterations = 10; // Number of iterations to calculate average time

    for (int i = 0; i < num_iterations; i++) {
        // Copy the original array to restore it for each iteration
        int temp_arr[n];
        for (int j = 0; j < n; j++) {
            temp_arr[j] = arr[j];
        }

        start = clock();
        bubbleSort(temp_arr, n);
        end = clock();
        cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
    }

    cpu_time_used /= num_iterations;

    printf("Bubble Sort took %f seconds on average\n", cpu_time_used);

    return 0;
}
