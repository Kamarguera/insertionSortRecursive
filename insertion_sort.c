#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define ARRAYSIZE 5     // size of array
#define RANDOMLIMIT 100 // maximum number
void swapRightIfBigger();
void fillArrayWithRandomNumbers();
void printArray();
void insertionSort();
void printArray();

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  int *arr;
  arr = (int *)malloc(ARRAYSIZE * sizeof(int)); // Dynamically allocate memory using malloc() by the size of numrand variable

  fillArrayWithRandomNumbers(arr, ARRAYSIZE, RANDOMLIMIT); // Fill a previously allocated array with random numbers
  printArray(arr, ARRAYSIZE);                              // Print x array elements quantified by variable ARRAYSIZE
  insertionSort(arr, ARRAYSIZE, 0);                        // Insert
  printArray(arr, ARRAYSIZE);                              // Print x array elements quantified by variable ARRAYSIZE

  return 0;
}

void fillArrayWithRandomNumbers(int arr[], int ArraySize, int limit)
{
  for (int i = 0; i < ArraySize; i++)
  {
    arr[i] = rand() % limit; // generate random number between 0 and X
    // printf("%d ", arr[i]);
  }
  // printf("\n");
}
void printArray(int arr[], int ArraySize)
{
  for (int i = 0; i < ArraySize; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
void insertionSort(int arr[], int ArraySize, int key)
{
  if (key == ArraySize - 1)
    return;

  if (arr[key + 1] < arr[key])
  {
    int swap = arr[key + 1];
    arr[key + 1] = arr[key];
    arr[key] = swap;
    if (key > 0)
      key--;
    return insertionSort(arr, ArraySize, key);
  }
  printf("a:%d b:%d \n", arr[key], arr[key + 1]);
  key++;
  return insertionSort(arr, ArraySize, key);
}
