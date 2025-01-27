#include <stdio.h>

int main()
{
    int cnd = 1;
    if (cnd) {
        goto L1;
    }
    printf("Goodbye");
    putchar('\n');
    goto L2;
L1:
    printf("Hello");
    printf(", World");
    putchar('\n');
L2:
    return 0;
}

