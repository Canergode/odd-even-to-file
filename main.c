#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    int N, i, ch;

    // Open file in write mode
    file = fopen("odd-even.txt", "w");

    if (file == NULL)
    {
        printf("File could not be created.");
    }
    else
    {
        printf("Enter a number:\n");
        scanf("%d", &N);

        // Write odd/even labels to file
        for (i = 1; i <= N; i++)
        {
            if (i % 2 == 0)
            {
                fprintf(file, "%d = EVEN\n", i);
            }
            else
            {
                fprintf(file, "%d = ODD\n", i);
            }
        }
    }

    fclose(file);
    printf("Data written to file.\n");

    // Re-open file for reading
    printf("Reading file...\n");
    file = fopen("odd-even.txt", "r");

    do
    {
        ch = getc(file);
        if (ch != EOF)
        {
            putchar(ch);
        }
    }
    while (ch != EOF);

    fclose(file);

    return 0;
}
