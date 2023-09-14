#include <stdio.h>
#include <string.h>

void copyString(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main() {
    char source[100], destination[100];
    printf("Enter a string: ");
    scanf("%s", source);
    
    copyString(destination, source);
    
    printf("Copied string: %s\n", destination);
    
    return 0;
}
