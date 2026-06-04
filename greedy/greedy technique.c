#include <stdio.h>

struct Item {
    int weight, value;
    float ratio;
};

int main() {
    int i, j, n, capacity;
    struct Item temp;

    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];

    printf("Enter weights and values:\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Sort by ratio (descending)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    float totalValue = 0.0;

    for(i = 0; i < n; i++) {
        if(capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum value = %.2f\n", totalValue);

    return 0;
}
