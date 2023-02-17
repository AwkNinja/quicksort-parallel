//to run use `gcc -o test -fopenmp quicksort.c`
//then ./test
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 16000000

void quicksort(int *array, int left, int right)
{
    if (left >= right)
        return;

    int pivot = array[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    }

#pragma omp task
    quicksort(array, left, j);

#pragma omp task
    quicksort(array, i, right);
}

int main()
{
    omp_set_num_threads(4); // set number of threads
    int serial_time = 2.681000;
    int *array = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        array[i] = rand();
    }

    double start_time = omp_get_wtime();
#pragma omp parallel
    {
#pragma omp single
        quicksort(array, 0, N - 1);
    }

    double elapsed_time = omp_get_wtime() - start_time;
    printf("Elapsed time: %f seconds\n", elapsed_time);

    // calculating speed-up
    double speedup = serial_time / elapsed_time;
    printf("Speed-up: %f\n", speedup);

    // Calculate the efficiency
  int num_threads = omp_get_max_threads();
  double efficiency = (speedup) / num_threads;
  printf("Efficiency: %.2f%%\n", efficiency * 100);

    // Check if the array is sorted
    for (int i = 0; i < N - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            printf("Error: array is not sorted!\n");
            return 1;
        }
    }

    printf("Array is sorted!\n");
    free(array);
    return 0;
}
