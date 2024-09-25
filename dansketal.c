#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dansketal.h"

const char* units[] = {
    "nul", "en", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni"
};

const char* tens[] = {
    "", "ti", "tyve", "tredive", "fyrre", "femogfyrre", "halvtreds", "tres", "halvfjerds", "firs", "halvfems"
};

const char* teens[] = {
    "elleve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"
};

char* dansketal(int number) {
    static char result[100];
    result[0] = '\0';  // Initialize the result string
    
    if (number < 0 || number > 999) {
        strcpy(result, "Number out of range");
        return result;
    }

    if (number >= 100) {
        int hundreds = number / 100;
        strcat(result, (hundreds == 1) ? "et hundrede" : units[hundreds]);
        strcat(result, " hundrede");
        number %= 100;
        if (number > 0) {
            strcat(result, " og ");
        }
    }

    if (number >= 20) {
        int tens_value = number / 10;
        int units_value = number % 10;
        strcat(result, tens[tens_value]);
        if (units_value > 0) {
            strcat(result, "og");
            strcat(result, units[units_value]);
        }
    } else if (number >= 11) {
        strcat(result, teens[number - 11]);
    } else if (number > 0) {
        strcat(result, units[number]);
    } else if (number == 0 && result[0] == '\0') {
        strcat(result, "nul");
    }

    return result;
}
