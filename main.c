#include <stdio.h>
#define FINALLY "FUCK YOU"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <io.h>
#include "header_og.h"
#include <ctype.h>

int main()
{
    FILE* file_onegin = fopen ("R_and_j.txt", "r");
    FILE* file_output = fopen ("onegin_out.txt", "w");

    int file_size = File_size (file_onegin);
    char* buffer = file_read (file_size, file_onegin);

    int n_str = Nstr (file_size, buffer);

    struct Line* mystr = (struct Line*) calloc (n_str, sizeof(*mystr));

    line_pointer_len (file_size, buffer, mystr);

    output_txt (file_output, n_str, mystr);

    qsort (mystr, n_str, sizeof (*mystr), compare_begin);
    output_txt (file_output, n_str, mystr);

    qsort (mystr, n_str, sizeof (*mystr), compare_end);
    output_txt (file_output, n_str, mystr);

    printf("%s", FINALLY);

    free_cal (mystr, buffer, file_onegin, file_output);

    return 0;
}

