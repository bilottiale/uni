#include <stdio.h>
#include <stdbool.h>

void e1(const int nRig, const int nCol, const int rags[nRig], const int mat[nRig][nCol], bool* pe, int* s) {
    bool allRowsHaveEven = true;
    int sum = 0;

    for (int r = 0; r < nRig; r++) {
        bool rowHasEven = false;

        for (int c = 0; c < nCol; c++) {
            if (mat[r][c] % 2 == 0) {
                rowHasEven = true;
            }

            if (rowHasEven && mat[r][c] < rags[r]) {
                sum += mat[r][c];
            }
        }

        if (!rowHasEven) {
            allRowsHaveEven = false;
        }
    }

    *pe = allRowsHaveEven;
    *s = allRowsHaveEven ? sum : 0;
}

int main()
{
    const unsigned int nRig = 3;
    const unsigned int nCol = 4;
    const unsigned int rags[] = {4, 2, 5};
    const int mat[3][4] = {
        {2, 5, 7, 3},
        {1, 4, 6, 8},
        {9, 1, 2, 3}};

    bool pe;
    unsigned int s;

    e1(nRig, nCol, rags, mat, &pe, &s);

    printf("pe: %s\n", pe ? "true" : "false");
    printf("s: %u\n", s);

    return 0;
}
