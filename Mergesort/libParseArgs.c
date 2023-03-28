#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "libParseArgs.h"

void usage(FILE *fp){
    char * s = "mergeSort <list> \n"
    "Sort the given list using merge sort algorithm \n"
    "Options: \n"
    "  -i <input file>    : Input file to read the list from. To read from standard input, enter \"std\". \n"
    "  -o <output file>   : Output file to write the sorted list to. To write to standard output, enter \"std\". \n"
    "  -s <list size>     : Size of the list to be sorted. \n"
    "  -r                 : Reverse the order of the sorted list. \n"
    "  <list>             : List of integers to be sorted. Not needed if not reading from standard input. \n";
}

//Function to parse arguements from the command line
int parseArgs(int argc, char *argv[]){

    if (argc < 2){
        usage(stderr);
        return true;
    }

    //Initialize the parsed_args struct
    parsed_args.file_input = false;
    parsed_args.input_file = NULL;
    parsed_args.file_output = false;
    parsed_args.output_file = NULL;
    parsed_args.list_size = 0;
    parsed_args.list = NULL;
    parsed_args.reverse = false;

    //Parse the arguements
    int i = 1;
    while (i < argc){
        if (strcmp(argv[i], "-i") == 0){
            parsed_args.file_input = true;
            parsed_args.input_file = argv[i+1];
            i += 2;
        } else if (strcmp(argv[i], "-o") == 0){
            parsed_args.file_output = true;
            parsed_args.output_file = argv[i+1];
            i += 2;
        } else if (strcmp(argv[i], "-r") == 0){
            parsed_args.reverse = true;
            i++;
        } else if (strcmp(argv[i], "-s") == 0){
            parsed_args.list_size = atoi(argv[i+1]);
            i += 2;
        } else{
            i++;
            break;
        }
    }

    if (parsed_args.file_input == false){
        parsed_args.list =  malloc(parsed_args.list_size * sizeof(int));
        if (parsed_args.list == NULL){
            fprintf(stderr, "Error: Unable to allocate memory for the list. \n");
            return true;
        }
        parsed_args.list = argv[i];
    }

}