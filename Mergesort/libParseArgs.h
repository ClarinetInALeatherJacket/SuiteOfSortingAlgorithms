typedef struct {

    int file_input;
    char * input_file;
    int file_output;
    char * output_file;
    int list_size;
    int * list;
    int reverse;
} PARSED_ARGS;

extern PARSED_ARGS parsed_args;

int parse_args(int argc, char *argv[]);