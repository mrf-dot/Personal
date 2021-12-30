#include <stdio.h>
#include <string.h>

char get_string[50]() {
        printf("Enter a string: ");
        char str[50];
        scanf("%s", &str);
        return str;
}

void permute(char str[50]) {
        printf("%lu\n", strlen(str));
        for (int i = 0; i < strlen(str); i++) {
                printf("%c\n", str[i]);
        }
}

int main() {
        permute(get_string());
        return 0;
}

