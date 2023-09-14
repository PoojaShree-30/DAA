#include <stdio.h>

int isPerfect(int num) {
    int sum = 1; // 1 is always a divisor
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            if (i * i != num)
                sum += i + num/i;
            else
                sum += i;
        }
    }
    return sum == num;
}
