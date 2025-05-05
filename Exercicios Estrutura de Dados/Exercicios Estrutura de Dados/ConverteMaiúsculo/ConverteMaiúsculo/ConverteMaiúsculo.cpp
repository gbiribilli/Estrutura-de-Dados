#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função para converter todas as palavras para maiúsculas
void converterParaMaiusculo(char** palavras, int qtd) {
    for (int i = 0; i < qtd; i++) {
        for (int j = 0; palavras[i][j] != '\n'; j++) {
            palavras[i][j] -= 32 ;
        }
    }
}

int main() {
    int tamanho;
    printf("Quantas palavras deseja inserir? ");
    scanf_s("%d", &tamanho);
   getchar(); // Limpar buffer do teclado


    char** palavras = (char**)malloc(tamanho * sizeof(char*));
    
    for (int i = 0; i < tamanho; i++) {
        palavras[i] = (char*)malloc(100 * sizeof(char));
       
        printf("Digite a palavra %d: ", i + 1);
        fgets(palavras[i], 100, stdin);
       
    }

    printf("Palavras Salvas:");
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", palavras[i]);
    }
    converterParaMaiusculo(palavras, tamanho);

    printf("Palavras em maiúsculas:");
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", palavras[i]);
    }

    for (int i = 0; i < tamanho; i++) {
        free(palavras[i]);
    }
    free(palavras);

    return 0;
}
