#include <stdio.h>
#include <stdlib.h>

// DefiniÃ§Ã£o do tipo link como ponteiro para struct node
typedef struct node* link;

typedef struct nodes* pilhando;
// DefiniÃ§Ã£o da estrutura node
struct nodes {
    int item;
    pilhando next; // Ponteiro para o prÃ³ximo nÃ³
};

// Estrutura chamada PILHA para representar a pilha
typedef struct {
   pilhando topo; // Ponteiro para o topo da pilha
} PILHA;

// FunÃ§Ã£o para inicializar a pilha vazia
void inicializar(PILHA* p) {
    p->topo = NULL; // Indica que a pilha estÃ¡ vazia
}
// FunÃ§Ã£o para empilhar (push) um elemento na pilha
void empilhar(PILHA* p, int x) {
    pilhando novoNode = (pilhando)malloc(sizeof(struct nodes)); // Aloca novo nÃ³
    novoNode->item = x; // Armazena x no novo nÃ³
    novoNode->next = p->topo; // O novo nÃ³ aponta para o topo da pilha
    p->topo = novoNode; // O topo da pilha aponta para o novo nÃ³  
}

// FunÃ§Ã£o para desempilhar (pop) um elemento da pilha
void desempilhar(PILHA* p, int* t) {
    if (p->topo == NULL) // Verifica se a pilha estÃ¡ vazia
        printf("Pilha Vazia!\n");
    else { // A pilha tem pelo menos um elemento
        *t = p->topo->item; // Faz uma cÃ³pia do elemento no topo
        pilhando tmp = p->topo; // Guarda o endereÃ§o do topo
        p->topo = p->topo->next; // Atualiza o topo para o prÃ³ximo
        free(tmp);
    }
}
// DefiniÃ§Ã£o da estrutura node
struct node {
    int chave;
    link esq; // Ponteiro para filho esquerdo (subÃ¡rvore)
    link dir; // Ponteiro para filho direito (subÃ¡rvore)
};

// FunÃ§Ã£o para inserir um elemento na Ã¡rvore binÃ¡ria de busca
link inserir(link raiz, int valor) {
    if (raiz == NULL) { // Verifica se a Ã¡rvore estÃ¡ vazia
        link novoNode = (link)malloc(sizeof(struct node)); // Aloca novo nÃ³
        novoNode->chave = valor; // Valor chave
        novoNode->esq = NULL; // Filho esquerdo
        novoNode->dir = NULL; // Filho direito
        return novoNode; // Retorna ponteiro para o novo nÃ³
    }
    if (valor < raiz->chave) // Se o valor for menor que a chave da raiz
        raiz->esq = inserir(raiz->esq, valor); // Inserir na subÃ¡rvore esquerda
    else // Se o valor for maior que a chave da raiz
        raiz->dir = inserir(raiz->dir, valor); // Inserir na subÃ¡rvore direita
    return raiz; // Retornar a raiz atualizada
}

// FunÃ§Ã£o para buscar uma chave na Ã¡rvore binÃ¡ria de busca
link buscar(link raiz, int chave) {
    // Se a Ã¡rvore estiver vazia ou encontrou a chave
    if (raiz == NULL || raiz->chave == chave)
        return raiz;
    if (chave < raiz->chave) // Se a chave for menor que a chave na raiz
        return buscar(raiz->esq, chave); // Buscar na subÃ¡rvore esquerda
    else  // Se a chave for maior que a chave na raiz
        return buscar(raiz->dir, chave); // Buscar na subÃ¡rvore direita
}

// FunÃ§Ã£o auxiliar para remoÃ§Ã£o: Caso 1 (nÃ£o tem filho) ou caso 2 (tem 1 filho)
link removerCaso1ou2(link raiz) {
    link q = raiz;
    if (raiz->esq == NULL) {
        q = raiz->dir; // Caso 1 (se dir == NULL) ou Caso 2 (se dir != NULL)  
        free(raiz);
        return q; // Retornar a raiz atualizada
    }
    else if (raiz->dir == NULL) {
        q = raiz->esq; // Caso 2: esq != NULL e dir == NULL 
        free(raiz);
        return q; // Retornar a raiz atualizada
    }
}

// FunÃ§Ã£o auxiliar para remoÃ§Ã£o: Caso 3 (tem 2 filhos)
link removerCaso3(link raiz) {
    link p = raiz; // Ponteiro para rastrear o nÃ³ pai do sucessor
    link q = raiz->dir; // Ponteiro para o sucessor lÃ³gico

    // Encontrar o sucessor lÃ³gico (o menor nÃ³ da subÃ¡rvore direita)
    while (q->esq != NULL) {
        p = q;
        q = q->esq;
    }

    // Transferir o valor do sucessor para a raiz
    raiz->chave = q->chave;

    // Remover o sucessor usando a funÃ§Ã£o removerCaso1ou2
    if (p->esq == q) // Verifica se o sucessor q Ã© filho esquerdo de p
        p->esq = removerCaso1ou2(q); // Atualiza p->esq 
    else // Se o sucessor q Ã© filho direito de p
        p->dir = removerCaso1ou2(q); // Atualiza p->dir

    return raiz; // Retornar a raiz atualizada  
}

// FunÃ§Ã£o para remover uma chave na Ã¡rvore binÃ¡ria de busca
link remover(link raiz, int chave) {
    if (raiz == NULL) return NULL; // NÃ£o encontrou a chave
    if (chave == raiz->chave) // Encontrou a chave
        if (raiz->esq == NULL || raiz->dir == NULL) // Caso 1 ou caso 2
            raiz = removerCaso1ou2(raiz);
        else // Caso 3
            raiz = removerCaso3(raiz);
    else // Ainda nÃ£o encontrou a chave    
        if (chave < raiz->chave) // Se a chave for menor que a chave na raiz
            raiz->esq = remover(raiz->esq, chave); // Remover na subÃ¡rvore esquerda
        else // Se a chave for maior que a chave na raiz
            raiz->dir = remover(raiz->dir, chave); // Remover na subÃ¡rvore direita
    return raiz; // Retornar a raiz atualizada
}

// FunÃ§Ã£o para o percurso prÃ©-ordem
void percursoPreOrdem(link raiz) {
    if (raiz != NULL) { // Verifica se a Ã¡rvore Ã© vazia
        printf("%i ", raiz->chave); // Visita a raiz
        percursoPreOrdem(raiz->esq); // Percorre a subÃ¡rvore esquerda
        percursoPreOrdem(raiz->dir); // Percorre a subÃ¡rvore direita  
    }
}
void percursopreOrdemPilha(link raiz) {
    PILHA p;
    inicializar(&p);

    while (raiz != NULL||p.topo != NULL) {
        while (raiz != NULL) {
            printf("%d ", raiz->chave);     // Visita o nó
           
            raiz = raiz->esq;
        }
       
    }
}
// FunÃ§Ã£o para o percurso in-ordem
void percursoInOrdem(link raiz) {
    if (raiz != NULL) { // Verifica se a Ã¡rvore Ã© vazia
        percursoInOrdem(raiz->esq); // Percorre a subÃ¡rvore esquerda
        printf("%i ", raiz->chave); // Visita a raiz
        percursoInOrdem(raiz->dir); // Percorre a subÃ¡rvore direita   
    }
}

// FunÃ§Ã£o para o percurso pÃ³s-ordem
void percursoPosOrdem(link raiz) {
    if (raiz != NULL) { // Verifica se a Ã¡rvore Ã© vazia
        percursoPosOrdem(raiz->esq); // Percorre a subÃ¡rvore esquerda
        percursoPosOrdem(raiz->dir); // Percorre a subÃ¡rvore direita
        printf("%i ", raiz->chave); // Visita a raiz
    }
}

// FunÃ§Ã£o para visualizaÃ§Ã£o unidimensional da Ã¡rvore
void imprimirPreOrdem(link raiz) {
    printf("(");
    if (raiz != NULL) {
        printf("% i ", raiz->chave);
        imprimirPreOrdem(raiz->esq);
        imprimirPreOrdem(raiz->dir);
    }
    printf(")");
}

// FunÃ§Ã£o para visualizaÃ§Ã£o bidimensional da Ã¡rvore
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

int main(void) {
    link Arvore = NULL; // Inicializar a ABB vazia
    int chave;

    Arvore = inserir(Arvore, 50); // Inserir 50 na ABB
    Arvore = inserir(Arvore, 40); // Inserir 40 na A
    Arvore = inserir(Arvore, 60); // Inserir 60 na ABB
    Arvore = inserir(Arvore, 35); // Inserir 35 na ABB
    Arvore = inserir(Arvore, 45); // Inserir 45 na ABB
    Arvore = inserir(Arvore, 55); // Inserir 55 na ABB
    Arvore = inserir(Arvore, 65); // Inserir 65 na ABB

    imprimirPreOrdem(Arvore); // VisualizaÃ§Ã£o bidimensional

    //percursopreOrdemPilha(Arvore);
    printf("\n\nInforme o valor que deseja procurar: ");
    scanf_s("%d", &chave);
    if (buscar(Arvore, chave) != NULL) // Buscar chave
        printf("O elemento %d foi encontrado na Ã¡rvore.\n", chave);
    else
        printf("O elemento %d nÃ£o foi encontrado na Ã¡rvore.\n", chave);

    printf("\nInforme o valor que deseja remover: ");
    scanf_s("%d", &chave);
    Arvore = remover(Arvore, chave); // Remover chave

    imprimirInOrdem(Arvore, 0); // VisualizaÃ§Ã£o bidimensional

    return 0;
}
