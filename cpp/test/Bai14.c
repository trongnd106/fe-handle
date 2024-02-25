#include <stdio.h>
#include <math.h>

// Ham kiem tra so nguyen to ?
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    FILE *inputFile, *outputFile;
    int number, sum = 0;

    // Mo tep input.txt de doc
    inputFile = fopen("Input.txt", "r");
    if (inputFile == NULL) {
        printf("Khong the mo tep Input.txt.\n");
        return 1;
    }
    // Doc 10 so tu tep va tinh tong so nguyen to
    for (int i = 0; i < 10; i++) {
        fscanf(inputFile, "%d", &number);
        if (isPrime(number)) {
            sum += number;
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
    // Ghi tong cac so nguyen to 
    fprintf(outputFile, "Tong cac so nguyen to la: %d\n", sum);
    // Dong tep output
    fclose(outputFile);

    return 0;
}