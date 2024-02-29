#include <stdio.h>

int main() {
    int n,a=3, d=-2;
    int x[10];  
    for (n = 0; n < 10; n++) {       
            x[n] =3-2*n  ;     
    }

    // Open a file for writing
    FILE *file = fopen("sequence.txt", "w");

    // Check if the file opened successfully
    if (file != NULL) {
        // Write the sequence to the file
        for (n = 0; n < 10; n++) {
            fprintf(file, "%d\n", x[n]);
        }

        // Close the file
        fclose(file);

        printf("Sequence has been written to sequence.txt\n");
    } else {
        printf("Error opening the file.\n");
    }

    return 0;
}


