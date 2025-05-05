#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Definição da estrutura node
typedef struct node {
    int chave;
    struct node* esq;
    struct node* dir;
    int h; // altura
} node;

typedef node* link;

// Função que retorna a altura de um nó
int altura(link raiz) {
    return (raiz == NULL) ? -1 : raiz->h;
}

// Função que retorna o maior entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Rotações
link rotacaoDireita(link p) {
    link u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->h = max(altura(p->esq), altura(p->dir)) + 1;
    u->h = max(altura(u->esq), p->h) + 1;
    return u;
}

link rotacaoEsquerda(link p) {
    link z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->h = max(altura(p->esq), altura(p->dir)) + 1;
    z->h = max(p->h, altura(z->dir)) + 1;
    return z;
}

link rotacaoEsquerdaDireita(link p) {
    p->esq = rotacaoEsquerda(p->esq);
    return rotacaoDireita(p);
}

link rotacaoDireitaEsquerda(link p) {
    p->dir = rotacaoDireita(p->dir);
    return rotacaoEsquerda(p);
}

// Inserção na AVL
link inserirAVL(link raiz, int valor) {
    if (raiz == NULL) {
        link novo = (link)malloc(sizeof(node));
        novo->chave = valor;
        novo->esq = novo->dir = NULL;
        novo->h = 0;
        return novo;
    }
    if (valor < raiz->chave)
        raiz->esq = inserirAVL(raiz->esq, valor);
    else
        raiz->dir = inserirAVL(raiz->dir, valor);

    raiz->h = max(altura(raiz->esq), altura(raiz->dir)) + 1;

    int fb = altura(raiz->esq) - altura(raiz->dir);

    if (fb == 2) {
        if (valor < raiz->esq->chave)
            return rotacaoDireita(raiz);
        else
            return rotacaoEsquerdaDireita(raiz);
    }
    else if (fb == -2) {
        if (valor > raiz->dir->chave)
            return rotacaoEsquerda(raiz);
        else
            return rotacaoDireitaEsquerda(raiz);
    }
    return raiz;
}

// Remover um nó com 0 ou 1 filhos
link removerCaso1ou2(link raiz) {
    link q;
    if (raiz->esq == NULL)
        q = raiz->dir;
    else
        q = raiz->esq;
    free(raiz);
    return q;
}

// Remover um nó com 2 filhos
link removerCaso3(link raiz) {
    link p = raiz;
    link q = raiz->dir;
    while (q->esq != NULL) {
        p = q;
        q = q->esq;
    }
    raiz->chave = q->chave;
    if (p->esq == q)
        p->esq = removerCaso1ou2(q);
    else
        p->dir = removerCaso1ou2(q);
    return raiz;
}

// Remoção na AVL
link remover(link raiz, int chave) {
    if (raiz == NULL)
        return NULL;
    if (chave == raiz->chave) {
        if (raiz->esq == NULL || raiz->dir == NULL)
            raiz = removerCaso1ou2(raiz);
        else
            raiz = removerCaso3(raiz);
    }
    else if (chave < raiz->chave)
        raiz->esq = remover(raiz->esq, chave);
    else
        raiz->dir = remover(raiz->dir, chave);

    if (raiz == NULL) // <- Verifica depois de remover
        return NULL;

    raiz->h = max(altura(raiz->esq), altura(raiz->dir)) + 1;

    int fb = altura(raiz->esq) - altura(raiz->dir);

    if (fb == 2) {
        if (altura(raiz->esq->esq) >= altura(raiz->esq->dir))
            return rotacaoDireita(raiz);
        else
            return rotacaoEsquerdaDireita(raiz);
    }
    else if (fb == -2) {
        if (altura(raiz->dir->dir) >= altura(raiz->dir->esq))
            return rotacaoEsquerda(raiz);
        else
            return rotacaoDireitaEsquerda(raiz);
    }

    return raiz;
}

// Impressão da árvore (visualização)
void imprimirInOrdem(link p, int b) {
    int i;
    if (p == NULL) {
        for (i = 0; i < b; i++) printf("-----");
        printf("NULL\n");
        return;
    }
    imprimirInOrdem(p->dir, b + 1);
    for (i = 0; i < b; i++) printf("-----");
    printf("%i\n", p->chave);
    imprimirInOrdem(p->esq, b + 1);
}

// Programa principal
int main(void) {
    srand(time(NULL));
    link Arvore = NULL;

    for (int i = 0; i < 10; i++) {
        Arvore = inserirAVL(Arvore, rand() % 50 + 1);
    }
    printf("Arvore antes da remocao\n");
    imprimirInOrdem(Arvore, 0);
    printf("\n");
    printf("Arvore pos remocao\n");
    Arvore = remover(Arvore, 3);

    imprimirInOrdem(Arvore, 0);

    return 0;
}
