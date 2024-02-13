#include <stdio.h>

#define MAX 10

int main(int argc, char **argv) {
    char buf[MAX + 2];
    buf[MAX] = '\n';
    buf[MAX + 1] = '\0';
    printf("A Solution: \n\n");
    // a
    for (int i = 0; i < MAX; buf[i++] = ' ');
    for (int i = 0; i < MAX; i++) {
        buf[i] = '*';
        printf("%s", buf);
    }
    printf("B Solution: \n\n");
    // b
    printf("%s", buf);
    for (int i = MAX - 1; i > 0; i--) {
        buf[i] = ' ';
        printf("%s", buf);
    }
    printf("C Solution: \n\n");
    // c
    for (int i = 0; i < MAX; buf[i++] = '*');
    printf("%s", buf);
    for (int i = 0; i < MAX - 1; i++) {
        buf[i] = ' ';
        printf("%s", buf);
    }
    printf("D Solution: \n\n");
    // d
    for (int i = MAX - 1; i >= 0; i--) {
        buf[i] = '*';
        printf("%s", buf);
    }
}

