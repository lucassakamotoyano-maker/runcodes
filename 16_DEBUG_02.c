#include <stdio.h>

// Comente esta linha para desabilitar os DEBUGs
#define DEBUG_MODE 

#ifdef DEBUG_MODE
    #define DEBUG(msg)  printf("[%s:%d] %s\n", __FILE__, __LINE__, msg)
#else
    #define DEBUG(msg)
#endif

#define MAX(a,b) ((a) > (b) ? (a) : (b))
//if (a>b) a else b is equivalent
//MACROS with multiple instructions
#define PERMUTE (a,b) do {\
    int tmp = (a);        \
     (a) = (b);           \
     (b) = tmp;          \
    }while(0)
//ao definir o escopo, as instruções são protegidas caso 
//,por exemplo, uma variável chamada tmp seja inicializada dentro do main

 

int soma(int a, int b) {
    DEBUG("Entrou na função soma");

    int resultado = a + b;

    DEBUG("Calculou o resultado da soma");

    return resultado;
}

int main(void) {
    DEBUG("Início do programa");

    int a = 10;
    int b = 20;
    //int a = 50; gera erro de redefinição de variável
    //{int a = 50;} não gera erro, pois o escopo é limitado ao bloco

    DEBUG("Antes de chamar a função soma");

    int resultado = soma(a, b);

    DEBUG("Depois de chamar a função soma");

    printf("%d\n", resultado);

    DEBUG("Fim do programa");

    return 0;
}

