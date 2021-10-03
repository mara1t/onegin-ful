#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <io.h>
#include "RENAME_ME.h"

int fl_size (FILE* og);

int min (int a, int b);
int max (int a, int b);
void swaping (char** psymbols, int str);
char* file_read (int file_size, FILE* og);
void point_str (int file_size, char *symbols, char** psymbols);
void print_txt (int n_str, char** psymbols);
void str_compare (int n_str, char* symbols, char** psymbols);
int nstr (int file_size, char *symbols);
int compare (const char** psymbols1, const char** psymbols2);

int main()
{
    char* swaps = NULL;

    FILE* og = fopen("C:\\Users\\User\\Desktop\\ОнегинCB\\R_and_j.txt", "r");

    int file_size = fl_size (og);

    char* symbols = file_read (file_size, og);

    int n_str = nstr (file_size, symbols);

    char* psymbols = (char*) calloc(n_str, sizeof(char*));

    point_str (file_size, symbols, psymbols);

   // str_compare (n_str, symbols, psymbols) ;

    qsort( psymbols, n_str, sizeof( char *), compare );

    printf("***\nNOW PRINT SORTED ONEGIN:\n***");

    print_txt (n_str, psymbols);

    free(psymbols);
    free(symbols);
    fclose(og);
    return 0;
}

int fl_size (FILE* og)
{
    if (og == NULL)
    {
        printf ("ERROR");
        return -1;
    }

    fseek (og, 0, SEEK_END);

    int size = ftell (og);

    fseek (og, 0, SEEK_SET);

    return (size);
}

void swaping (char** psymbols, int str)
{
    char* t = psymbols[str];
    psymbols[str] = psymbols[str+1];
    psymbols[str+1] = t;
}

void str_compare (int n_str, char* symbols, char** psymbols)
{
    int elm_str = 0;

    char* swaps = NULL;

    for (int i = n_str - 2; i >= 0; i--)
    {
        for (int str = 0; str <= i; str++)
        {
            elm_str = 0;
            while (1)
            {
                if ( *(psymbols[str]+elm_str) > *(psymbols[str+1]+elm_str))
                {
                    swaping (psymbols, str);
                    break;
                }
                else if (*(psymbols[str]+elm_str) < *(psymbols[str+1]+elm_str))
                {
                    break;
                }
                    elm_str++;
            }
        }
    }

}

char* file_read (int file_size, FILE* og)
{
    char* symbols = (char *) calloc(file_size, sizeof(char)); // ToDo: check return value
    fread(symbols, 1, file_size, og);
    return symbols;
}

void point_str (int file_size, char *symbols, char** psymbols)
{
    int i = 0, j = 0;
    for (j = 0; i < file_size; j++)
    {
        psymbols[j] = &symbols[i];
        while ( symbols[i] != '\n')
        {
            i++;
        }
        i++;
    }
}

int nstr (int file_size, char *symbols)
{
    int i = 0, n_str = 0, j = 0;
    for (j = 0; i < file_size; j++)
    {
        while ( symbols[i] != '\n')
        {
            i++;
        }
        i++;
    }
    n_str = j;
    return n_str;
}

void print_txt (int n_str, char** psymbols)
{
    for (int i = 0; i < n_str; i++)
    {
        for (int j = 0; *(psymbols[i]+j) != '\n'; j++)
        {
            printf("%c", *(psymbols[i]+j));
        }
        printf("\n");
    }
}

int min (int a, int b)
{
    return (a>b)? b:a;
}

int max (int a, int b)
{
    return (a>b) ? a:b;
}

int compare (const char** psymbols1, const char** psymbols2)
{
    int elm_str = 0, counter = 0;
            while (*((*psymbols1) + elm_str) == *((*psymbols2) + elm_str))
            {
                elm_str++;
            }
    return *((*psymbols1) + elm_str) - *((*psymbols2) + elm_str);
}

