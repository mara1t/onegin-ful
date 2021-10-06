#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <io.h>
#include "header_og.h"

/*void caloc_point (int n_str ,int** len_str, char*** first_smb, struct n_len_str** mystr)
{
    len_str = (int*) calloc (n_str, sizeof(int));
    first_smb = (char**) calloc (n_str, sizeof(char*));
    mystr = (struct n_len_str*) calloc (n_str, sizeof(*mystr));
}*/

void free_cal(struct n_len_str* mystr, char** first_smb, char *symbols, FILE* file_onegin)
{
    free(mystr);
    free(first_smb);
    free(symbols);
    fclose(file_onegin);
}

void copy_mass (struct n_len_str* mystr, int* len_str, char** first_smb, int n_str)
{
    for (int i_str = 0; i_str < n_str; i_str++)
        {
            mystr[i_str].ilen = len_str[i_str];
            mystr[i_str].ifirst_smb = first_smb[i_str];
        }
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

void swaping (char** first_smb, int str)
{
    char* t = first_smb[str];
    first_smb[str] = first_smb[str+1];
    first_smb[str+1] = t;
}

char* file_read (int file_size, FILE* og)
{
    char* symbols = (char *) calloc(file_size, sizeof(char));
    if (symbols == NULL)
    {
        printf("ERROR");
        return -1;
    }
    else
    {
        fread(symbols, 1, file_size, og);
        return symbols;
    }
}

void point_str (int file_size, char *symbols, char** first_smb, int* len_str)
{
    int i = 0, j = 0, counter = 0;
    for (j = 0; i < file_size; j++)
    {
        counter = 0;
        first_smb[j] = &symbols[i];
        while ( symbols[i] != '\n' && i < file_size)
        {
            i++;
            counter++;
        }
        i++;
        counter++;
        len_str[j] = counter;
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

void print_txt (int n_str, struct n_len_str *my_str)
{
    for (int istr = 0; istr < n_str; istr++)
    {
        for (int jsymb = 0; *((my_str[istr]. ifirst_smb) + jsymb) != '\n'; jsymb++)
        {
            printf("%c", *((my_str[istr]. ifirst_smb) + jsymb));
        }
        printf("\n");
    }
}

int compare_begin (struct n_len_str *maratcool1, struct n_len_str *maratcool2)
{
    int elm_str = 0;

    while (*( (maratcool1->ifirst_smb) + elm_str) ==  *( (maratcool2->ifirst_smb) + elm_str))
    {
        elm_str++;
    }

    return *( (maratcool1->ifirst_smb) + elm_str) - *( (maratcool2->ifirst_smb) + elm_str);
}

int compare_end (struct n_len_str *maratcool1, struct n_len_str *maratcool2)
{
    int elm_str = 0;

    while ( *( (maratcool1->ifirst_smb) + (maratcool1->ilen) - 1 - elm_str) ==  *( (maratcool2->ifirst_smb) + (maratcool2->ilen) - 1 - elm_str))
    {
        if (++elm_str == (maratcool1->ilen) || elm_str == (maratcool2->ilen))
        {
            return (elm_str == (maratcool1->ilen)) - (elm_str == (maratcool2->ilen));
        }
    }

    return *((maratcool1->ifirst_smb) + (maratcool1->ilen) -1 - elm_str) -  *((maratcool2->ifirst_smb) + (maratcool2->ilen)-1 - elm_str);
}
