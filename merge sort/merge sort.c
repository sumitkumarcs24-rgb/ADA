#include <stdio.h>

// Function to merge two sorted halves
void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int c[100]; // Temporary array

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left half
    while (i <= mid) {
        c[k++] = a[i++];
    }

    // Copy remaining elements of right half
    while (j <= high) {
        c[k++] = a[j++];
    }

    // Copy sorted elements back to original array
    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }
}

void mergesort(int a[], int low, int high) {
    if (low < high) {
        // Find the middle point
        int mid = low + (high - low) / 2;

        // Recursive calls
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);

        // Merge the sorted halves
        merge(a, low, mid, high);
    }
}

int main() {
    int a[100], n, i;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    mergesort(a, 0, n - 1);

    printf("Sorted elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
