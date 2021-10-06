struct n_len_str {
        int ilen;
        char* ifirst_smb;
    };
int fl_size (FILE* og);
void swaping (char** psymbols, int str);
char* file_read (int file_size, FILE* og);
void point_str (int file_size, char *symbols, char** first_smb, int* len_str);
void print_txt (int n_str, struct n_len_str *mystr);
int nstr (int file_size, char *symbols);
int compare_begin (struct n_len_str *maratcool1, struct n_len_str *maratcool2);
int compare_end (struct n_len_str *maratcool1, struct n_len_str *maratcool2);
//void caloc_point (int n_str ,int* len_str, char** first_smb, struct n_len_str* mystr);
void free_cal(struct n_len_str* mystr, char** first_smb, char *symbols, FILE* file_onegin);
void copy_mass (struct n_len_str* mystr, int* len_str, char** first_smb, int n_str);
