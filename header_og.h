struct Line {
    int len;
    char* str;
};
char* file_read (const int file_size, const FILE* og);

int File_size (const FILE* og);
int Nstr (const int file_size, const char *buffer);

void line_pointer_len (const int file_size, char *buffer, struct Line* mystr);

int compare_begin (const struct Line *stract1, const struct Line *stract2);
int compare_end (const struct Line *stract1, const struct Line *stract2);

void free_member(struct Line* mystr, char *buffer, FILE* file_onegin, FILE* file_output);
void output_txt (const FILE* file_output, const int n_str, const struct Line* mystr);


