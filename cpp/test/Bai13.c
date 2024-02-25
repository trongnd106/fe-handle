#include <stdio.h>
#include <math.h>

// Ham kiem tra so chinh phuong ?
int isPerfectSquare(int n) {
    int root = sqrt(n);
    return (root * root == n);
}

int main() {
    FILE *inputFile, *outputFile;
    int number, count = 0;

    // Mo tep input.txt de doc
    inputFile = fopen("Input.txt", "r");
    if (inputFile == NULL) {
        printf("Khong the mo tep Input.txt.\n");
        return 1;
    }
    // Doc 10 so tu tep va dem so luong so chinh phuong
    for (int i = 0; i < 10; i++) {
        fscanf(inputFile, "%d", &number);
        if (isPerfectSquare(number)) {
            count++;
        }
    }
    // Dong tep
    fclose(inputFile);

    // Mo tep Output.txt de ghi
    outputFile = fopen("Output.txt", "w");
    if (outputFile == NULL) {
        printf("Khong the mo tep Output.txt.\n");
        return 1;
    }
    // Ghi so luong so chinh phuong 
    fprintf(outputFile, "So luong so chinh phuong la: %d\n", count);
    // Dong tep output
    fclose(outputFile);

    return 0;
}