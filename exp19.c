#include <stdio.h>

struct Item {
    int value;
    int weight;
};

void knapsackGreedy(struct Item items[], int n, int capacity) {
    double ratios[n];
    for (int i = 0; i < n; i++) {
        ratios[i] = (double) items[i].value / items[i].weight;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (ratios[j] > ratios[maxIndex]) {
                maxIndex = j;
            }
        }
        
        if (maxIndex != i) {
            struct Item temp = items[i];
            items[i] = items[maxIndex];
            items[maxIndex] = temp;
            
            double tempRatio = ratios[i];
            ratios[i] = ratios[maxIndex];
            ratios[maxIndex] = tempRatio;
        }
    }
    
    int currentWeight = 0;
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            double remainingWeight = capacity - currentWeight;
            totalValue += (remainingWeight / items[i].weight) * items[i].value;
            break;
        }
    }
    
    printf("Maximum value: %.2f\n", totalValue);
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    knapsackGreedy(items, n, capacity);
    
    return 0;
}
