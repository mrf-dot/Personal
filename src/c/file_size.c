#include <stdio.h>

int main(int argc, char *argv[]) {
        FILE *f = fopen(argv[1], "r");
        fseek(f, 0, SEEK_END);
        printf("The size of %s is %d", argv[1], ftell(f));
        return 0;
}

