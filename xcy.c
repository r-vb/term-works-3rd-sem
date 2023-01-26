#include <stdio.h>
#include <string.h>

int main() {
    char x[100], y[100];
    printf("Enter a string of the form xCy: ");
    scanf("%s", x);

    int length = strlen(x);
    int c_index = -1;
    for (int i = 0; i < length; i++) {
        if (x[i] == 'C') {
            c_index = i;
            break;
        }
    }

    if (c_index == -1) {
        printf("Not a valid input string.\n");
        return 0;
    }

    int y_index = 0;
    for (int i = c_index + 1; i < length; i++) {
        y[y_index] = x[i];
        y_index++;
    }

    int is_valid = 1;
    for (int i = 0; i < c_index; i++) {
        if (x[i] != 'A' && x[i] != 'B') {
            is_valid = 0;
            break;
        }
    }

    if (!is_valid) {
        printf("Not a valid input string.\n");
        return 0;
    }

    int is_same = 1;
    for (int i = 0; i < c_index; i++) {
        if (x[i] != y[c_index - 1 - i]) {
            is_same = 0;
            break;
        }
    }

    if (is_same) {
        printf("It is a valid input string of the form xCy.\n");
    } else {
        printf("Not a valid input string.\n");
    }

    return 0;
}