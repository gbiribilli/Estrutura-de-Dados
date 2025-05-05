#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 42 // Valor mÃ¡ximo de elementos que a fila pode armazenar

typedef struct {
    int A[MAX]; // Vetor/arranjo para armazenar os elementos da fila
    int inicio; // Ãndice do topo da fila
    int qtdElementos; // Quantidade de elementos armazenados na fila
} FILA;

// FunÃ§Ã£o para inicializar a fila vazia
void inicializar(FILA* f) {
    f->inicio = -1; // Indica que a fila estÃ¡ vazia
    f->qtdElementos = 0; // A fila vazia tem 0 elementos
}

// FunÃ§Ã£o para enfileirar (enqueue) um elemento na fila
void enfileirar(FILA* f, int x) {
    int posicao;
    if (f->qtdElementos == MAX) { // Verifica se a fila estÃ¡ cheia
        printf("Fila Cheia!\n");
        return;
    }
    // A fila tem espaÃ§o para inserir um novo elemento
    if (f->inicio == -1) // Verifica se Ã© a primeira inserÃ§Ã£o na fila
        posicao = ++(f->inicio); // posicao = 0
    else
        posicao = (f->inicio + f->qtdElementos) % MAX; // PosiÃ§Ã£o apÃ³s o final da fila
    f->A[posicao] = x; // Insere o elemento x no final da fila
    f->qtdElementos++; // Atualiza a quantidade de elementos
}

// FunÃ§Ã£o para desenfileirar (dequeue) um elemento da fila
void desenfileirar(FILA* f, int* i) {
    if (f->qtdElementos == 0) { // Verifica se a fila estÃ¡ vazia
        printf("Fila Vazia!\n");
        return;
    }
    // A fila tem pelo menos um elemento
    *i = f->A[f->inicio]; // Faz uma cÃ³pia do elemento no inÃ­cio
    f->inicio = (f->inicio + 1) % MAX; // Atualiza a posiÃ§Ã£o do inÃ­cio
    f->qtdElementos--; // Incrementa a quantidade de elementos 
}

// FunÃ§Ã£o para imprimir os elementos da fila
void imprimir(FILA f) {
    int i = f.inicio;
    int j;
    printf("Fila: \" ");
    for (j = 1; j <= f.qtdElementos; j++) { // Percorre a fila do inÃ­cio atÃ© o final
        printf("%d ", f.A[i]); // Exibe os elementos na ordem de enfileiramento
        i = (i + 1) % MAX; // AvanÃ§a circularmente no vetor, retornando ao inÃ­cio se necessÃ¡rio
    }
    printf("\"\n");
}

void furaFila(FILA* f, int x) {
    if (f->qtdElementos == MAX) {
        printf("Fila Cheia!\n");
        return;
    }
    if (f->inicio == -1) {
        f->inicio = 0;
        f->A[0] = x;
    }
    else {
        f->inicio = (f->inicio - 1 + MAX) % MAX;
        f->A[f->inicio] = x;
    }
    f->qtdElementos++;
}

int main(void) {
    int i, n, c;
    FILA f; // Cria uma fila
    inicializar(&f); // Inicializa a fila vazia

    // Solicita ao usuÃ¡rio a quantidade de elementos a serem inseridos na fila
    printf("Quantidade de elementos: ");
    scanf_s("%d", &n); // LÃª o valor de n fornecido pelo usuÃ¡rio
    printf("\n");

    // Inserir n elementos (pseudo)aleatÃ³rios na fila
    srand((unsigned)time(NULL));

    for (i = 0; i < n; i++)
        enfileirar(&f, 1 + (rand() % 100));
    printf("Fila:\n");
    imprimir(f);
    
    printf("Fila após furar fila\n");
    furaFila(&f, 1245);
    imprimir(f);
    desenfileirar(&f, &c); 
    printf("Elemento removido do inÃ­cio: %d\n", c);


    imprimir(f);

    return 0;
}



