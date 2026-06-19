#include <stdio.h>

// 1. Modelagem dos Dados
// Criando o tipo Ponto3D
typedef struct {
    double x;
    double y;
    double z;
} Ponto3D;

// Criando o tipo Particula (aninhando o Ponto3D)
typedef struct {
    Ponto3D posicao;
    double massa;
} Particula;

int main(void) {
    int n;
    Particula particulas[50]; // Vetor para armazenar até 50 partículas

    // Lendo a quantidade de partículas
    if (scanf("%d", &n) != 1) {
        return 1; // Proteção caso a leitura falhe
    }

    // Variáveis acumuladoras para a massa total e para os somatórios (posição * massa)
    // Devem obrigatoriamente iniciar em 0.0
    double massa_total = 0.0;
    double soma_mx = 0.0;
    double soma_my = 0.0;
    double soma_mz = 0.0;

    // 2. O Ciclo de Acumulação
    for (int i = 0; i < n; i++) {
        // Lendo as coordenadas e a massa diretamente para dentro da struct
        // Note o uso do ponto (.) para acessar os membros aninhados
        scanf("%lf %lf %lf %lf", 
              &particulas[i].posicao.x, 
              &particulas[i].posicao.y, 
              &particulas[i].posicao.z, 
              &particulas[i].massa);

        // Somando a massa da partícula atual à massa total do sistema
        massa_total += particulas[i].massa;

        // Calculando a parte de cima da fração (posição * massa) e acumulando
        soma_mx += particulas[i].posicao.x * particulas[i].massa;
        soma_my += particulas[i].posicao.y * particulas[i].massa;
        soma_mz += particulas[i].posicao.z * particulas[i].massa;
    }

    // 3. O Cálculo Final (Média Ponderada)
    // Evitando divisão por zero (boa prática em engenharia de software)
    if (massa_total > 0.0) {
        double x_cm = soma_mx / massa_total;
        double y_cm = soma_my / massa_total;
        double z_cm = soma_mz / massa_total;

        // Imprimindo com duas casas decimais
        printf("Centro de Massa: X=%.2lf, Y=%.2lf, Z=%.2lf\n", x_cm, y_cm, z_cm);
    }

    return 0;
}