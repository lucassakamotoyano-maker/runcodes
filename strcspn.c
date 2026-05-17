#include <stdio.h>
#include <string.h>

size_t count_vowels(const char *s) {
    const char *vowels = "aeiouAEIOU";
    size_t count = 0;

    while (*s != '\0') {
        size_t skip = strcspn(s, vowels);
        s += skip;
        if (*s == '\0')
            break;
        count++;
        s++;
    }

    return count;
}

void reverse_string(char *s) {
    size_t i = 0;
    size_t j = strlen(s);

    if (j == 0)
        return;

    j--;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

int main(void) {
    char texto[] = "hello, world";

    printf("Texto original: %s\n", texto);
    printf("Vogais: %zu\n", count_vowels(texto));

    reverse_string(texto);
    printf("Texto invertido: %s\n", texto);

    return 0;
}
