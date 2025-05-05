#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 42

typedef struct {
    char A[MAX][MAX]; // Fila de strings
    int inicio;
    int qtdElementos;
} FILA;

void inicializar(FILA* f) {
    f->inicio = -1;
    f->qtdElementos = 0;
}

void enfileirar(FILA* f, char* x) {
    if (f->qtdElementos == MAX) {
        printf("Fila Cheia!\n");
        return;
    }

    int posicao;
    if (f->inicio == -1) {
        f->inicio = 0;
        posicao = 0;
    }
    else {
        posicao = (f->inicio + f->qtdElementos) % MAX;
    }

    strcpy(f->A[posicao], x); // Copia a string para a fila
    f->qtdElementos++;
}

void desenfileirar(FILA* f, char* i) {
    if (f->qtdElementos == 0) {
        printf("Fila Vazia!\n");
        return;
    }
    strcpy(i, f->A[f->inicio]); // Copia a string da fila para a variável i
    f->inicio = (f->inicio + 1) % MAX;
    f->qtdElementos--;
}


void binario(int n) {
    FILA p;
    char frente[MAX];
    char tmp[MAX];
     
    inicializar(&p);
    enfileirar(&p, "1"); // Correção: "1" como string válida

    for (int i = 0; i < n; i++) {
        desenfileirar(&p, frente);
        printf("%s\n", frente);

        strcpy(tmp, frente);
        strcat(tmp, "0");
        enfileirar(&p, tmp);

        strcpy(tmp, frente);
        strcat(tmp, "1");
        enfileirar(&p, tmp);
    }
}

int main(void) {
    int n;
    printf("Quantidade de elementos: ");
    scanf("%d", &n);

    binario(n);

    return 0;
}
