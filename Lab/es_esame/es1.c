#include <stdio.h>
#include <stdbool.h>

int e1(const size_t rows, const size_t cols,
       const int mat[rows][cols], const size_t rags[rows])
{
    int result = 0;
    bool allRowsSatisfyCriteria = true;

    for (size_t i = 0; i < rows && allRowsSatisfyCriteria; i++)
    {
        bool found = false;
        int sum = 0;

        for (size_t j = 0; j < cols && !found; j++)
        {
            if (mat[i][j] % 7 == 0)
            {
                found = true;
                sum += mat[i][j];
            }
        }

        if (!found || sum < rags[i])
        {
            allRowsSatisfyCriteria = false;
        }
        else
        {
            result += sum;
        }
    }

    return (allRowsSatisfyCriteria) ? result : 0;
}

int main()
{
    const size_t rows = 5, cols = 11;
    int mat[5][11] = {
        {8, 2, 2, 0, 0, 8, 0, 9, 8, 1, 2},
        {3, 7, 8, 7, 5, 4},
        {8, 1, 5, 5, 21, 1, 7, 5, 8, 2, 0},
        {2, 3, 28, 9, 5},
        {7, 3, 8, 5, 7, 1, 5, 1, 6}
    };
    size_t rags[5] = {11, 6, 11, 5, 9};

    printf("%d\n", e1(rows, cols, mat, rags));
}
