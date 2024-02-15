#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int height;
    int max = 0;
    char name[50];
    char max_name[50];

    while (scanf("%s %d", name, &height) != EOF)
    {
        for (size_t i = 0; i < 10; i++)
        {
            if (height > max)
            {
                max = height;
                for (size_t j = 0; j < 50; j++)
                    max_name[j] = name[j];
            }
            if (name[0] == '\0')
                break;
        }
    }
        printf("%s", max_name);
}