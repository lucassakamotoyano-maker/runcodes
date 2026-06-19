#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // ---------------------------------------------------------
    // FASE 1: Concatenação (Anexar notas2 no final de notas1)
    // ---------------------------------------------------------
    FILE *arquivo1_app = fopen("notas1.txt", "a"); // "a" = append (anexar no final)
    FILE *arquivo2_read = fopen("notas2.txt", "r"); // "r" = read (apenas leitura)

    // Verifica se os arquivos foram abertos com sucesso antes de operar
    if (arquivo1_app != NULL && arquivo2_read != NULL) {
        char caractere;
        // Lê do notas2 até chegar no Fim do Arquivo (EOF - End Of File)
        while ((caractere = fgetc(arquivo2_read)) != EOF) {
            fputc(caractere, arquivo1_app); // Escreve no final do notas1
        }
    }

    // Libera os recursos do sistema operacional
    if (arquivo1_app != NULL) fclose(arquivo1_app);
    if (arquivo2_read != NULL) fclose(arquivo2_read);

    // ---------------------------------------------------------
    // FASE 2: Ler a entrada do usuário
    // ---------------------------------------------------------
    int indice_desejado;
    scanf("%d", &indice_desejado);

    // ---------------------------------------------------------
    // FASE 3: Buscar o aluno na lista unificada
    // ---------------------------------------------------------
    FILE *arquivo_unificado = fopen("notas1.txt", "r");
    if (arquivo_unificado == NULL) {
        return 1; // Falha de segurança se o arquivo não existir
    }

    char nome[55]; // 50 caracteres (teto do problema) + margem para o '\0'
    float nota1, nota2;
    int indice_atual = 0;
    int encontrou = 0; // Flag de controle (0 = falso, 1 = verdadeiro)

    // O fscanf retorna a quantidade de variáveis preenchidas.
    // Como queremos preencher nome, nota1 e nota2, ele deve retornar 3 enquanto houver dados.
    while (fscanf(arquivo_unificado, " %[^,],%f,%f", nome, &nota1, &nota2) == 3) {
        
        // Se a linha atual for a que o usuário pediu
        if (indice_atual == indice_desejado) {
            float media = (nota1 + nota2) / 2.0f;
            // %.2f restringe o float a 2 casas decimais (ex: 5.46)
            printf("%s - %.2f\n", nome, media);
            encontrou = 1;
            break; // Otimização: Achou o aluno, não precisa ler o resto do arquivo
        }
        indice_atual++; // Se não é o aluno, vai para a próxima linha
    }

    fclose(arquivo_unificado);

    // ---------------------------------------------------------
    // FASE 4: Tratamento de exceção (Índice inexistente)
    // ---------------------------------------------------------
    if (encontrou == 0) {
        printf("Indice fora da lista de alunos\n");
    }

    return 0;
}