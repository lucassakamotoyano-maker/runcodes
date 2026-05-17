# include <stdio.h>

int main(void)
{
    int i;

    printf("Tabela ASCII\n");
    printf("Decimal\tHexadecimal\tOctal\tCharacter\n");
    for (i = 0; i < 128; i++) {
        printf("%d\t%X\t\t%o\t%c\n", i, i, i, i);
    }
    return 0;
}