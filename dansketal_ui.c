#include <stdio.h>
#include "dansketal.h"

int main() {
    int number;

    printf("Enter a number between 0-999: ");
    scanf("%d", &number);

    printf("The number %d in Danish is: %s\n", number, DANSKETAL(number));

    return 0;
}