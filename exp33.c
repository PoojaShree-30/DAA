#include <stdio.h>

void insertNumber(int arr[], int *size, int num, int pos) {
    for (int i = *size - 1; i >= pos; i--)
        arr[i + 1] = arr[i];
    
    arr[pos] = num;
    (*size)++;
}

int main() {
    int arr[100] = {1, 2, 4, 5};
    int size = 4;
    int num = 3, pos = 2;
    
    insertNumber(arr, &size, num, pos);
    
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    return 0;
}
