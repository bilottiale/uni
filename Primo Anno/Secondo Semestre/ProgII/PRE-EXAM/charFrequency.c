#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int frequency[256] = {0}; // Assuming ASCII characters

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("File not found or cannot be opened.\n");
        exit(1);
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch != ' ' && ch != '\n' && ch != '\t') {
            frequency[ch]++;
        }
    }

    fclose(file);

    printf("Character Frequency:\n");
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            printf("%c : %d\n", i, frequency[i]);
        }
    }

    return 0;
}
