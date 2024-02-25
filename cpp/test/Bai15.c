#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    int number, max = 0;

    // Mo tep input.txt de doc
    inputFile = fopen("Input.txt", "r");
    if (inputFile == NULL) {
        printf("Khong the mo tep Input.txt.\n");
        return 1;
    }
    // Doc 10 so tu tep va tim so lon nhat
    for (int i = 0; i < 10; i++) {
        fscanf(inputFile, "%d", &number);
        if (i == 0 || number > max) {
            max = number;
        }
    }
    // Dong tep input
    fclose(inputFile);

    // Mo tep Output de ghi
    outputFile = fopen("Output.txt", "w");
    if (outputFile == NULL) {
        printf("Khong the mo tep Output.txt.\n");
        return 1;
    }
    // Ghi so lon nhat vao tep
    fprintf(outputFile, "So lon nhat la: %d\n", max);
    // Dong tep
    fclose(outputFile);

    return 0;
}