#include <stdio.h>
#include <string.h>

#define debug(x) printf("")

typedef struct 
{
    char nome[50];
    int pontos;
    int gols_marcados;
    int gols_sofridos;

} Selecao;

Selecao s[100];

int num_selecao = 0;

Selecao *consulta( char nome[])
{
    for(int i = 0; i < num_selecao; i++)
    {
        debug(s[i].nome);
        debug(nome);
        if(strcmp(s[i].nome, nome) == 0)
            return &s[i];
    }
    return NULL;
}

int load(char nome_arq[])
{
    FILE *f = fopen(nome_arq, "r");

    if(f==NULL) //(!f) se f for falso
    {
        return 0;
    }

    int N;

    scanf("%d", &N);

    char nome[50];
    for(int i = 0; i < N; i++)
    {
        fscanf(f, "%s", nome);

        Selecao *ps = consulta(nome);

        if(ps ==NULL)
        {
            ps = &s[num_selecao];

            strcpy(ps->nome, nome);
            num_selecao++;
        }
        /* scanf("%s %d %d %d", 
            s[num_selecao],
            &s[num_selecao].pontos,
            &s[num_selecao].gols_marcados,
            &s[num_selecao].gols_sofridos);
        num_selecao++; */
        scanf("%d %d %d",
            &ps->pontos,
            &ps->gols_marcados,
            &ps->gols_sofridos);
    }

    fclose(f);
    return 1;
}

int main()
{
    int Q;
    char op[10], atr1[50], atr2[50];
    scanf("%d", &Q);

    for(int i = 0; i < Q; i++)
    {
        scanf("%s", op);

        if(strcmp(op,"load"==0))
        {
            scanf("%s", atr1);

            if(load(atr1))
            {
                printf("Arquivo %s Carregado\n", atr1);
            }else
            {
                printf("Arquivo %s Indexistente\n", atr1);
            }
        }else if(strcmp(op, "consulta"))
        {
            scanf("%s %s", atr1, atr2);
            
            Selecao *ps = consulta(atr1);

            if(ps == NULL)
            {
                printf("Consulta Invalida\n");
            }else
            {
                if(strcmp(atr2, "pontos"))
                {
                    printf("%d\n", ps->pontos);
                }else if(strcmp(atr2, "gols_marcados"))
                {
                    printf(" ");
                }
            }

        }

    }
    return 0;
}