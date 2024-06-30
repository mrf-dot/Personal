#include <stdio.h>

int main(int argc, char **argv) {
    int d;
    fputs("Enter a number: ", stdout);
    scanf("%d", &d);
    while (getchar() != '\n');
    if (!d)
        puts("0");
    else
        while (1)
            puts("1");
    return 0;
}

