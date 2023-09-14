#include <stdio.h>

struct MinMax {
    int min;
    int max;
};

struct MinMax findMinMax(int arr[], int left, int right) {
    struct MinMax result, leftResult, rightResult;
    int mid;
    
    if (left == right) {
        result.min = arr[left];
        result.max = arr[left];
        return result;
    }
    
    if (right == left + 1) {
        if (arr[left] > arr[right]) {
            result.min = arr[right];
            result.max = arr[left];
        } else {
            result.min = arr[left];
            result.max = arr[right];
        }
        return result;
    }
    
    mid = (left + right) / 2;
    leftResult = findMinMax(arr, left, mid);
    rightResult = findMinMax(arr, mid + 1, right);
    
    if (leftResult.min < rightResult.min) {
        result.min = leftResult.min;
    } else {
        result.min = rightResult.min;
    }
    
    if (leftResult.max > rightResult.max) {
        result.max = leftResult.max;
    } else {
        result.max = rightResult.max;
    }
    
    return result;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct MinMax result = findMinMax(arr, 0, size - 1);
    
    printf("Minimum value: %d\n", result.min);
    printf("Maximum value: %d\n", result.max);
    
    return 0;
}
