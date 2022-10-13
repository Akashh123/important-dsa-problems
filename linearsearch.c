#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int LinearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
    }
    return -1;
}

int BinarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    // Unsorted array for linear search
    // int arr[] = {1, 2, 54, 5, 9, 8, 7, 75, 55, 66, 6};
    // int size = sizeof(arr)/sizeof(int);
    // Sorted array for binary search
    int arr[] = {1, 2, 4, 5, 8, 9, 18, 54, 88, 99, 108, 188};
    int size = sizeof(arr) / sizeof(int);
    int element = 88;
    int searchIndex = BinarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
    return 0;
}