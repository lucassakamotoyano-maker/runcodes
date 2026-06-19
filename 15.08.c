#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Modelagem de Dados
typedef struct {
    char nome[105]; // 100 caracteres + segurança
    int ano;
    float nota;
} Filme;

// Função de Comparação 1: Ordem Alfabética (NOME)
int cmp_nome(const void *a, const void *b) {
    // Fazemos o cast do ponteiro genérico (void*) para o nosso struct (Filme*)
    Filme *f1 = (Filme *)a;
    Filme *f2 = (Filme *)b;
    
    // strcmp já resolve ordem lexicográfica crescente
    return strcmp(f1->nome, f2->nome); 
}

// Função de Comparação 2: Ordem Decrescente (NOTA) com desempate
int cmp_nota(const void *a, const void *b) {
    Filme *f1 = (Filme *)a;
    Filme *f2 = (Filme *)b;
    
    // Lógica para nota decrescente (Maior vem primeiro)
    if (f1->nota > f2->nota) return -1; 
    if (f1->nota < f2->nota) return 1;
    
    // Se a nota for igual, desempata pela ordem lexicográfica crescente do nome
    return strcmp(f1->nome, f2->nome);
}

int main() {
    char criterio[10];
    int indice_buscado;

    // Leitura das duas linhas do terminal
    if (scanf("%s", criterio) != 1) return 1;
    if (scanf("%d", &indice_buscado) != 1) return 1;

    Filme filmes[105];
    int qtd_filmes = 0;

    // FASE 1: Leitura do banco de dados original
    FILE *in = fopen("catalogo.txt", "r");
    if (in == NULL) {
        return 1; // Proteção contra falha ao abrir arquivo
    }

    // Usamos o espaço inicial no fscanf para ignorar quebras de linha e o %[^,] para os nomes
    while (fscanf(in, " %[^,],%d,%f", filmes[qtd_filmes].nome, &filmes[qtd_filmes].ano, &filmes[qtd_filmes].nota) == 3) {
        qtd_filmes++;
    }
    fclose(in);

    // FASE 2: Processamento (Ordenação em Memória)
    if (strcmp(criterio, "NOME") == 0) {
        qsort(filmes, qtd_filmes, sizeof(Filme), cmp_nome);
    } else if (strcmp(criterio, "NOTA") == 0) {
        qsort(filmes, qtd_filmes, sizeof(Filme), cmp_nota);
    }

    // FASE 3: Persistência (Salvando o novo catálogo)
    FILE *out = fopen("catalogo_ordenado.txt", "w");
    if (out == NULL) return 1;

    for (int i = 0; i < qtd_filmes; i++) {
        fprintf(out, "%s,%d,%.1f\n", filmes[i].nome, filmes[i].ano, filmes[i].nota);
    }
    fclose(out);

    // FASE 4: Releitura e Busca
    if (indice_buscado < 0 || indice_buscado >= qtd_filmes) {
        printf("INDICE_INVALIDO\n");
    } else {
        // Obrigatório reabrir conforme o enunciado
        FILE *reaberto = fopen("catalogo_ordenado.txt", "r");
        if (reaberto != NULL) {
            Filme f_temp;
            int indice_atual = 0;
            
            // Lemos linha por linha até encontrar o índice desejado
            while (fscanf(reaberto, " %[^,],%d,%f", f_temp.nome, &f_temp.ano, &f_temp.nota) == 3) {
                if (indice_atual == indice_buscado) {
                    printf("%s - %d - %.1f\n", f_temp.nome, f_temp.ano, f_temp.nota);
                    break;
                }
                indice_atual++;
            }
            fclose(reaberto);
        }
    }

    return 0;
}