
#include <stdio.h>
#include <string.h>

/* #define debug(x) printf("%s:%d %s\n", __func__, __LINE__, x)
#define debug_int(x) printf("%s:%d %d\n", __func__, __LINE__, x)
 */
typedef struct
{
    char nome[50];
    int pontos;
    int gols_marcados;
    int gols_sofridos;
    
}Selecao;


Selecao s[100];
int num_selecao=0;

// Recebe o nome da selecao e retorna o ponteiro para selecao encontrada ou retorna null caso a selecao nao exista
Selecao *consulta( char nome[] )
{
    for(int i =0; i < num_selecao; i++)
    {
        /* debug(s[i].nome);
        debug(nome); */
        
        if( strcmp(s[i].nome, nome) == 0)
            return &s[i];
    }
    return NULL;
}

// Recebe o nome de um arquivo, em caso de sucesso carrega o arquivo no vetor s (global) e retorna 1, em caso de fracaso(arquivo nao existente), retorna 0
int load(char nome_arq[])
{
    FILE *f = fopen(nome_arq, "r");
    
    /* debug(nome_arq); */
    
    if(f == NULL)
        return 0;

    int N;
    
    fscanf(f,"%d", &N);  // Nao esquecer de colocar f no scanf quando ler arquivo
    
    char nome[50];    
    for(int i=0; i < N; i++)
    {
        fscanf(f,"%s", nome);
        /* debug(nome); */
        Selecao *ps = consulta(nome);
        
        if(ps == NULL)
        {
            ps = &s[num_selecao];
           /*  debug(nome); */
            
            strcpy(ps->nome, nome );
            
            num_selecao++;
        }
        
        fscanf(f,"%d %d %d",
            &ps->pontos,
            &ps->gols_marcados,
            &ps->gols_sofridos);  
        /* debug_int(ps->pontos);  */
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
        /* debug(op); */
        
        // Verifica qual a operacao
        if( strcmp(op,"load") == 0 )    // Nao esquecer de compara com zero ao usar strcmp()     
        {   // Executa operacao load
            scanf("%s" , atr1);
            
            if(load(atr1))
            {
                printf("Arquivo %s Carregado\n", atr1);
            }else
            {
                printf("Arquivo %s Indexistente\n", atr1);                
            }
                                            
        }else if( strcmp(op,"consulta") == 0)  // Nao esquecer de compara com zero ao usar strcmp()
        {   // Executa operacao consulta
            scanf("%s %s" , atr1, atr2);
            /* debug(atr1);
            debug(atr2); */
            
            Selecao *ps = consulta(atr1);
            
            if(ps == NULL)
            {
                printf("Consulta Invalida\n");
            }else
            {

                if(strcmp(atr2, "pontos") == 0)
                {
                    printf("%d\n", ps->pontos);
                    
                }else if (strcmp(atr2, "gols_marcados") == 0)
                {
                    printf("%d\n", ps->gols_marcados);
                
                }else if (strcmp(atr2, "gols_sofridos") == 0)
                {
                    printf("%d\n", ps->gols_sofridos);
                
                }else if (strcmp(atr2, "saldo") == 0)
                {
                    printf("%d\n", ps->gols_marcados - ps->gols_sofridos);                
                }else
                {
                    printf("Consulta Invalida\n");
                }
            }
                    
        }else
        {
            printf("Operacao %s invalida!\n", op);       
        }
    }
    
    return 0;
}

