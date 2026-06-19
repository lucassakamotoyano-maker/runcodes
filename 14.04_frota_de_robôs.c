#include <stdio.h>

typedef struct
{
    int id;
    char modelo[31];
    int bateria; // nível de bateria em porcentagem de 0 a 100
    char status; // 'A' para ativo, 'M' para manutenção e 'D' para desativado
} Robo;

int main(void)
{
    int quantidade_de_robos;
    Robo robos[20];

    scanf("%d", &quantidade_de_robos);

    if (quantidade_de_robos < 0 || quantidade_de_robos > 20)
    {
        return 0;
    }

    for (int i = 0; i < quantidade_de_robos; i++)
    {
        scanf("%d %31s %d %c",
              &robos[i].id,
              robos[i].modelo,
              &robos[i].bateria,
              &robos[i].status);
    }

    int mais_carregado = -1;
    int em_manutencao = 0;

    for (int i = 0; i < quantidade_de_robos; i++)
    {
        if (robos[i].status == 'M')
        {
            em_manutencao++;
        }

        if (robos[i].status == 'A' &&
            (mais_carregado == -1 ||
             robos[i].bateria > robos[mais_carregado].bateria))
        {
            mais_carregado = i;
        }
    }

    if (mais_carregado == -1)
    {
        printf("Nenhum robo ativo\n");
    }
    else
    {
        printf("Mais carregado: %s\n", robos[mais_carregado].modelo);
    }

    printf("Em manutencao: %d\n", em_manutencao);

    return 0;
}
