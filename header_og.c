#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <io.h>
#include <assert.h>
#include "header_og.h"
#include <ctype.h>

void free_cal(struct Line* mystr, char *buffer, FILE* file_onegin, FILE* file_output)
{
    free(mystr);
    free(buffer);
    free(file_output);
    fclose(file_onegin);
}

int func_fl_size (FILE* og)
{
    assert(og != NULL);

    fseek (og, 0, SEEK_END);

    ssize_t size = ftell (og);

    fseek (og, 0, SEEK_SET);

    return size;
}

void swaping (char** first_smb, int str)
{
    char* t = first_smb[str];
    first_smb[str] = first_smb[str+1];
    first_smb[str+1] = t;
}

char* file_read (int file_size, FILE* og)
{
    char* buffer = (char *) calloc(file_size + 1, sizeof(char));
    if (buffer == NULL)
    {
        printf("ERROR, No free member");
        return NULL;
    }

    else
    {
        //проверка
        if (fread (buffer, sizeof(char), file_size, og) == NULL)
        {
            printf("ERROR, No symbols in text file");
            abort();
        }
        buffer[file_size] = '\0';
        return buffer;
    }
}

void line_pointer_len (int file_size, char *buffer, struct Line* mystr)
{
    // strchr()
    int symb_counter = 0, str = 0, len_counter = 0;
    for ( str = 0; symb_counter < file_size; str++)
    {
        len_counter = 0;
        mystr[str].str = &buffer[symb_counter];
        while ( buffer[symb_counter] != '\n' && symb_counter < file_size)
        {
            symb_counter++;
            len_counter++;
        }
        buffer[symb_counter] = '\0';
        symb_counter++;
        len_counter++;

        mystr[str].len = len_counter;
    }
}

int func_nstr (int file_size, char *buffer)
{
    // strchr()
    int symb_num = 0, n_str = 0, str_num = 0;
    for (str_num = 0; symb_num < file_size; str_num++)
    {
        while ( buffer[symb_num] != '\n')
        {
            symb_num++;
        }
        symb_num++;
    }
    n_str = str_num;
    return n_str;
}

char** get_string(int n_str, FILE* file_onegin)
{
    char** mystring = (char**) calloc(n_str, 40);

    for(int str = 0; str < n_str; str++)
    {
        fgets(mystring[str], 40, file_onegin);
    }

    return mystring;
}

void output_txt (FILE* file_output, int n_str, struct Line* mystr)
{
    for (int str_num = 0; str_num < n_str; str_num++)
    {
        fputs(mystr[str_num].str, file_output);
        fprintf(file_output, "\n");
    }

    for (int i = 0; i < 40; i++)
    {
        fprintf(file_output, "*");
    }
    fprintf(file_output, "\n");

}
int compare_begin (struct Line *stract1, struct Line *stract2)
{
    int elem_num_one = 0, elem_num_two = 0;

    while (!isalpha(*( (stract1->str) + elem_num_one)) && ((stract1->len) > elem_num_one))
    {
        elem_num_one++;
    }
    while (!isalpha(*( (stract2->str) + elem_num_two)) && ((stract2->len) > elem_num_two))
    {
        elem_num_two++;
    }
    if ((elem_num_one >= (stract1->len)) || (elem_num_two >= (stract2->len)))
    {
        return -((elem_num_one >= (stract1->len)) - (elem_num_two >= (stract2->len)));
    }
    while (*( (stract1->str) + elem_num_one) ==  *( (stract2->str) + elem_num_two))
    {
        elem_num_one++;
        elem_num_two++;
        
        while (!isalpha(*( (stract1->str) + elem_num_one)) && ((stract1->len) > elem_num_one))
        {
            elem_num_one++;
        }
        while (!isalpha(*( (stract2->str) + elem_num_two)) && ((stract2->len) > elem_num_two))
        {
            elem_num_two++;
        }
        if ((elem_num_one >= (stract1->len)) || (elem_num_two >= (stract2->len)))
        {
            return -((elem_num_one >= (stract1->len)) - (elem_num_two >= (stract2->len)));
        }
    }

    return *( (stract1->str) + elem_num_one) - *( (stract2->str) + elem_num_two);
}

int compare_end (struct Line *stract1, struct Line *stract2)
{
    int elem_num_one = 0, elem_num_two = 0;

    while (!isalpha(*( (stract1->str) + (stract1->len) - 1 - elem_num_one)) && (stract1->len > elem_num_one))
    {
        elem_num_one++;
    }
    while (!isalpha(*( (stract2->str) + (stract2->len) - 1 - elem_num_two)) && (stract2->len > elem_num_two))
    {
        elem_num_two++;
    }
    if ((elem_num_one >= (stract1->len) )|| (elem_num_two >= (stract2->len)))
    {
        return -((elem_num_one >= (stract1->len)) - (elem_num_two >= (stract2->len)));
    }
    while ( *( (stract1->str) + (stract1->len) - 1 - elem_num_one) ==  *( (stract2->str) + (stract2->len) - 1 - elem_num_two))
    {
        elem_num_one++;
        elem_num_two++;

        while (!isalpha(*( (stract1->str) + (stract1->len) - 1 - elem_num_one)) && (stract1->len > elem_num_one))
        {
            elem_num_one++;
        }
        while (!isalpha(*( (stract2->str) + (stract2->len) - 1 - elem_num_two)) && (stract2->len > elem_num_two))
        {
            elem_num_two++;
        }
        if ((elem_num_one >= (stract1->len)) || (elem_num_two >= (stract2->len)))
        {
            return -((elem_num_one >= (stract1->len)) - (elem_num_two >= (stract2->len)));
        }
    }

    return *((stract1->str) + (stract1->len) - 1 - elem_num_one) -  *((stract2->str) + (stract2->len) - 1 - elem_num_two);
}
