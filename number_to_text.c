#include <stdio.h>
#include "number_to_text.h"

// Danish number arrays
// Define the ones for later assembly
const char* ones[] = {
    "", "et", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni"
};

// Define the teens for later assembly
const char* teens[] = {
    "ti", "elleve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"
};

// Define the tens for later assembly
const char* tens[] = {
    "tyve", "tredive", "fyrre", "halvtreds", "tres", "halvfjerds", "firs", "halvfems"
};

// Function to convert a number to Danish text
void number_to_text(int num) {
    // handle if the input number is 0
    if (num == 0) {
        printf("nul\n"); // Print zero
        return;
    }
    
    int hundreds = num / 100; // Get the hundreds digit
    int remainder = num % 100; // Get the remainder
    int tens_digit = remainder / 10; // Get the tens digit
    int ones_digit = remainder % 10; // Get the ones digit

    // Print hundreds
    if (hundreds > 0) { // If the number is greater than 100
        if (hundreds == 1) { // If the number is 100
            printf("et-hundred"); // Print one-hundred
        } else { // If the number is greater than 100
            printf("%s-hundred", ones[hundreds]); // Print the hundreds digit
        }
        
        if (remainder > 0) { // If the remainder is greater than 0
            printf("-og-"); // Print -and-
        }
    }

    // Handle numbers between 11 and 19 (teens)
    if (remainder >= 10 && remainder < 20) { // If the number is between 10 and 19
        printf("%s", teens[remainder - 10]); // Print the teens
    } else { // Handle numbers between 20 and 99
        if (tens_digit > 1) { // If the tens digit is greater than 1
            printf("%s", ones[ones_digit]); // Print the ones digit
            if (ones_digit > 0) { // If the ones digit is greater than 0
                printf("-og-"); // Print -and-
            }
            printf("%s", tens[tens_digit]); // Print the tens digit
        } else if (ones_digit > 0) { // If the ones digit is greater than 0
            printf("%s", ones[ones_digit]); // Print the ones digit
        }
    }

    printf("\n"); // Print a newline
}
