#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("test.txt", "r");
    char filename[100];
    char word[100];
    int count = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    if (file == NULL) {
        printf("File not found or cannot be opened.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word) != EOF) {
        count++;
    }

    fclose(file);

    printf("Number of words in file: %d\n", count);

    return 0;
}
