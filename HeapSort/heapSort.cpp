#include "heapSort.h"

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int *a, int N, int i)
{
    // Find largest among root,
    // left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < N && a[left] > a[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    if (right < N && a[right] > a[largest])

        largest = right;

    // Swap and continue heapifying
    // if root is not largest
    // If largest is not root
    if (largest != i)
    {

        std::swap(a[i], a[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(a, N, largest);
    }
}
void heapifyCompare(int *a, int N, int i, int &compare)
{
    // Find largest among root,
    // left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (++compare && left < N && ++compare && a[left] > a[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    if (++compare && right < N && ++compare && a[right] > a[largest])

        largest = right;

    // Swap and continue heapifying
    // if root is not largest
    // If largest is not root
    if (++compare && largest != i)
    {

        std::swap(a[i], a[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapifyCompare(a, N, largest, compare);
    }
}
void heapSortCompare(int *a, int N, int &compare)
{
    compare = 0;
    // Build max heap
    for (int i = N / 2 - 1; ++compare && i >= 0; i--)

        heapifyCompare(a, N, i, compare);

    // Heap sort
    for (int i = N - 1; ++compare && i >= 0; i--)
    {

        std::swap(a[0], a[i]);

        // Heapify root element
        // to get highest element at
        // root again
        heapifyCompare(a, i, 0, compare);
    }
}
// Main function to do heap sort
void heapSort(int *a, int N)
{

    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(a, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--)
    {

        std::swap(a[0], a[i]);

        // Heapify root element
        // to get highest element at
        // root again
        heapify(a, i, 0);
    }
}

void heapSortTime(int *a, int n, double &time)
{
    time = 0;
    clock_t start, end;

    start = clock();
    heapSort(a, n);
    end = clock();

    // Measuring time
    time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
}