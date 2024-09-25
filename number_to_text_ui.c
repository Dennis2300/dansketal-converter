#include <stdio.h>
#include "number_to_text.h"

int main() {
    int number;

    do {
        printf("--------------------------------------------\n");
        printf("No negative numbers or the program will quit\n");
        printf("Enter a number (0-999):\n");
        printf("Chosen number: ");
        scanf("%d", &number);

        if (number >= 0 && number <= 999) {
            printf("--------------------------------------------\n");
            printf("Number in text:\n");
            number_to_text(number);  // Call the function from number_to_text.c
        } else if (number < 0) {
            printf("Exiting the program...\n");
        } else {
            printf("--------------------------------------------\n");
            printf("Number out of range.\n");
        }

    } while (number >= 0);  // Continue looping while the number is non-negative

    return 0;
}
