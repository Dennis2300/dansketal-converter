#include <stdio.h>
#include "number_to_text.h"

// Danish number arrays
const char* ones[] = {
    "", "et", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni"
};

const char* teens[] = {
    "ti", "elleve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"
};

const char* tens[] = {
    "", "", "tyve", "tredive", "fyrre", "halvtreds", "tres", "halvfjerds", "firs", "halvfems"
};

// Function to convert a number to Danish text
void number_to_text(int num) {
    if (num == 0) {
        printf("nul\n");
        return;
    }
    
    int hundreds = num / 100;
    int remainder = num % 100;
    int tens_digit = remainder / 10;
    int ones_digit = remainder % 10;

    // Print hundreds
    if (hundreds > 0) {
        if (hundreds == 1) {
            printf("et-hundred");
        } else {
            printf("%s-hundred", ones[hundreds]);
        }
        
        if (remainder > 0) {
            printf("-og-");
        }
    }

    // Handle numbers between 11 and 19 (teens)
    if (remainder >= 10 && remainder < 20) {
        printf("%s", teens[remainder - 10]);
    } else {
        // Print tens and ones
        if (tens_digit > 1) {
            printf("%s", ones[ones_digit]);
            if (ones_digit > 0) {
                printf("-og-");
            }
            printf("%s", tens[tens_digit]);
        } else if (ones_digit > 0) {
            printf("%s", ones[ones_digit]);
        }
    }

    printf("\n");
}
