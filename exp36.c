#include <stdio.h>

void containerLoader(int containers[], int n, int weights[], int m) {
    int loadedContainers[n];
    
    for (int i = 0; i < n; i++) {
        loadedContainers[i] = -1;
    }
    
    int j = 0;
    for (int i = 0; i < n && j < m; i++) {
        if (containers[i] <= weights[j]) {
            loadedContainers[i] = j;
            j++;
        }
    }
    
    printf("Loaded Containers:\n");
    for (int i = 0; i < n; i++) {
        if (loadedContainers[i] != -1) {
            printf("Container %d loaded in Truck %d\n", i, loadedContainers[i]);
        }
    }
}

int main() {
    int containers[] = {4, 6, 2, 7, 3};
    int n = sizeof(containers) / sizeof(containers[0]);
    int weights[] = {8, 6, 10, 7};
    int m = sizeof(weights) / sizeof(weights[0]);
    
    containerLoader(containers, n, weights, m);
    
    return 0;
}
