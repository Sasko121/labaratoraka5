#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROWS 3
#define COLS 4


#define INIT_DOUBLE_ARRAY(a, rows, cols) \
{ \
    for (int i = 0; i < rows; ++i) \
    { \
        for (int j = 0; j < cols; ++j) \
        { \
            a[i][j] = NAN; \
        } \
    } \
}

int main()
{
    char* src_strs[] =
    {
        "-12.3;33.05;45.0;12.1",
        "55.04;0.0;12.5;7.8",
        "-124.7;99.99;88.88;0.1"
    };

    double matrix[ROWS][COLS];
    INIT_DOUBLE_ARRAY(matrix, ROWS, COLS);

    for (int i = 0; i < ROWS; i++)
    {
        char* delim = ";";
        char* token = NULL;
        char src_str[100];
        strncpy(src_str, src_strs[i], sizeof(src_str) - 1);
        src_str[sizeof(src_str) - 1] = '\0'; 

        token = strtok(src_str, delim);
        int j = 0;

        while (token && j < COLS)
        {
            matrix[i][j++] = atof(token);
            token = strtok(NULL, delim);
        }
    }

    double max = NAN, avg = 0.0;
    int count = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (!isnan(matrix[i][j]))
            {
                printf("Scanned: %.3f\n", matrix[i][j]);
                if (isnan(max) || fabs(matrix[i][j]) > fabs(max)) 
                {
                    max = matrix[i][j];
                }
                avg += matrix[i][j];
                count++;
            }
        }
    }

    printf("\nProcessed %d items\n", count);
    if (count > 0)
    {
        printf("Average %.3f\n", avg / count);
    }
    if (!isnan(max))
    {
        printf("Absolute maximum %.3f\n", max);
    }

    return 0;
}