#include <stdio.h>

void subsetSum(int set[], int n, int target, int subset[], int size, int sum, int index) {
    if (sum == target) {
        for (int i = 0; i < size; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return;
    }
    
    for (int i = index; i < n; i++) {
        if (sum + set[i] <= target) {
            subset[size] = set[i];
            subsetSum(set, n, target, subset, size + 1, sum + set[i], i + 1);
        }
    }
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20};
    int n = sizeof(set) / sizeof(set[0]);
    int target = 35;
    int subset[100];
    
    subsetSum(set, n, target, subset, 0, 0, 0);
    
    return 0;
}
