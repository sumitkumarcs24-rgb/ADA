#include <stdio.h>
int partition(int a[], int low, int high) {
    int i, j, temp, pivot;

    pivot = a[low]; // Choosing the first element as pivot
    i = low + 1;
    j = high;

    while (i <= j) {
        // Find element greater than pivot
        while (i <= high && a[i] <= pivot) {
            i++;
        }
        // Find element smaller than pivot
        while (a[j] > pivot) {
            j--;
        }

        if (i < j) {
            // Swap a[i] and a[j]
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Swap pivot with a[j] to put pivot in correct sorted position
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j; // Return the partition index
}

// Recursive function to perform Quick Sort
void qsort_custom(int a[], int low, int high) {
    int mid;

    if (low < high) {
        mid = partition(a, low, high);
        qsort_custom(a, low, mid - 1);  // Sort left of pivot
        qsort_custom(a, mid + 1, high); // Sort right of pivot
    }
}

int main() {
    int a[100], n, i;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Call the quicksort function
    qsort_custom(a, 0, n - 1);

    printf("\nSorted elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
