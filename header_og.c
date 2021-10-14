#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <io.h>
#include <assert.h>
#include "header_og.h"
#include <ctype.h>

void free_member(struct Line* mystr, char *buffer, FILE* file_onegin, FILE* file_output)
{
    free(mystr);
    free(buffer);
    free(file_output);
    fclose(file_onegin);
}

int File_size (const FILE* og)
{
    assert(og != NULL);

    fseek (og, 0, SEEK_END);

    ssize_t size = ftell (og);

    fseek (og, 0, SEEK_SET);

    return size;
}

char* file_read (const int file_size, const FILE* og)
{
    assert(og != NULL && file_size >= 1);

    char* buffer = (char *) calloc(file_size + 1, sizeof(char));
    if (buffer == NULL)
    {
        printf("ERROR, No free member");
        return NULL;
    }

    else
    {
        if (fread (buffer, sizeof(char), file_size, og) == 0) // ToDo: != file_sizen
        {
            printf("ERROR, No symbols in text file");
            abort();
        }
        buffer[file_size] = '\0';
        return buffer;
    }
}

void line_pointer_len (const int file_size, char *buffer, struct Line* mystr)
{
    assert(buffer != NULL && file_size >= 1 && mystr != NULL);
    int symb_counter = 0, str = 0, len_counter = 0;
    for ( str = 0; symb_counter < file_size; str++)
    {
        len_counter = 0;
        mystr[str].str = &buffer[symb_counter]; // (&buf[symb] = &*(buf + symb) = buf + symb
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

int Nstr (const int file_size, const char *buffer)
{
    assert(buffer != NULL && file_size >= 1);
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

void output_txt (const FILE* file_output, const int n_str, const struct Line* mystr)
{
    assert(file_output != NULL && n_str >= 1 && mystr != NULL);
    for (int str_num = 0; str_num < n_str; str_num++)
    {
        if (*(mystr[str_num].str) != '\0')
        {
            fputs(mystr[str_num].str, file_output);
            fprintf(file_output, "\n");
        }
    }

    for (int i = 0; i < 40; i++)
    {
        fprintf(file_output, "*");
    }
    fprintf(file_output, "\n");

}
int compare_begin (const struct Line *stract1, const struct Line *stract2)
{

    int elem_num_one = -1, elem_num_two = -1;
    do
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
    } while (*( (stract1->str) + elem_num_one) ==  *( (stract2->str) + elem_num_two));// ToDo: do while

    return *( (stract1->str) + elem_num_one) - *( (stract2->str) + elem_num_two); // ToDo: []
}

int compare_end (const struct Line *stract1, const struct Line *stract2)
{

    int elem_num_one = -1, elem_num_two = -1;


    do
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
            return -(elem_num_one >= (stract1->len) ) + (elem_num_two >= (stract2->len) );
        }
    } while ( *( (stract1->str) + (stract1->len) - 1 - elem_num_one) ==  *( (stract2->str) + (stract2->len) - 1 - elem_num_two));

    return *((stract1->str) + (stract1->len) - 1 - elem_num_one) -  *((stract2->str) + (stract2->len) - 1 - elem_num_two);
}

