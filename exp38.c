#include <stdio.h>
#include <stdbool.h>

#define N 4

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

bool rowUsed[N] = {false};
bool colUsed[N] = {false};
int assignment[N] = {-1};

int minCost = 999;

void calculateCost() {
    int totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }
    if (totalCost < minCost) {
        minCost = totalCost;
    }
}

void assignJobs(int worker) {
    if (worker == N) {
        calculateCost();
        return;
    }
    for (int job = 0; job < N; job++) {
        if (!rowUsed[worker] && !colUsed[job]) {
            assignment[worker] = job;
            rowUsed[worker] = true;
            colUsed[job] = true;
            assignJobs(worker + 1);
            rowUsed[worker] = false;
            colUsed[job] = false;
            assignment[worker] = -1;
        }
    }
}

int main() {
    assignJobs(0);
    printf("Minimum Cost: %d\n", minCost);

    return 0;
}
