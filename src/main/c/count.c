#include <stdio.h>

int count_lines(char *filename) {
        FILE *file;
        if (file = fopen(filename, "r")) {
                int lines = 0;
                for (char i= getc(file); i != EOF; i = getc(file))
                        lines += (i == '\n') ? 1 : 0;
                return lines;
        } else {
                return -1;
        }
}

int main(int argc, char *argv[]) {
        if (argc < 2)
                printf("Please supply a filename\n");
        else if (argc > 2)
                printf("Too many arguments\n");
        else
                printf("There are %d lines in %s", count_lines(argv[1]), argv[1]);
}

