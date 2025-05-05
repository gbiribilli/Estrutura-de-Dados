#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// DefiniÃ§Ã£o do tipo link como ponteiro para struct node
typedef struct node* link;

// DefiniÃ§Ã£o da estrutura node
struct node {
    int item;
    link next; // Ponteiro para o prÃ³ximo nÃ³
};

// FunÃ§Ã£o para inserir um item na lista com cabeÃ§a
void inserir(link* lista, int novoItem) {
    link novoNode = (link)malloc(sizeof(struct node));
    novoNode->item = novoItem; // Atribui o valor ao item do nÃ³ criado
    novoNode->next = (*lista)->next; // Aponta para o antigo primeiro nÃ³
    (*lista)->next = novoNode; // Atualiza o ponteiro da lista para o novo nÃ³
}

// FunÃ§Ã£o para buscar um item na lista com cabeÃ§a
link buscar(link lista, int chave) {
    link p = lista->next; // Ponteiro auxiliar comeÃ§a no primeiro nÃ³ real (depois da cabeÃ§a)

    // Percorre a lista enquanto nÃ£o chegar ao final e nÃ£o encontrar o elemento
    while (p != NULL && p->item != chave)
        p = p->next; // AvanÃ§a para o prÃ³ximo nÃ³

    return p; // Retorna o ponteiro para o nÃ³ encontrado ou NULL se nÃ£o achou
}

// FunÃ§Ã£o para remover um item na lista com cabeÃ§a
link remover(link lista, int chave) {
    link p = lista->next; // Ponteiro p inicia no primeiro nÃ³ real (depois da cabeÃ§a)
    link q = lista;  // Ponteiro q Ã© o nÃ³ anterior (cabeÃ§a) de p

    // Percorre a lista procurando o nÃ³ com o valor chave
    while (p != NULL && p->item != chave) {
        q = p;      // Armazena o nÃ³ atual p em q (nÃ³ anterior ao nÃ³ p)
        p = p->next; // AvanÃ§a para o prÃ³ximo nÃ³
    }

    // Se o elemento nÃ£o foi encontrado, a lista permanece inalterada
    if (p == NULL)
        return lista; // Retorna a lista original, sem remoÃ§Ã£o

    // Remove p da lista, ajustando o ponteiro do nÃ³ anterior
    q->next = p->next;

    free(p); // Libera a memÃ³ria do nÃ³ removido
    return lista;
}

// FunÃ§Ã£o para imprimir a lista com cabeÃ§a
void imprimir(link lista) {
    link p = lista->next; // ComeÃ§a no primeiro nÃ³ real (depois da cabeÃ§a)
    printf("Lista: ");
    while (p != NULL) { // Itera sobre todos os nÃ³s da lista
        if (p->next != NULL)
            printf("%d -> ", p->item); // Exibe o item seguido de "->"
        else
            printf("%d", p->item); // Exibe o Ãºltimo item sem "->"
        p = p->next; // AvanÃ§a para o prÃ³ximo nÃ³
    }
}
void inverterLista(link* lista){
    link p = (*lista)->next;
    link q = NULL;
    link r;
    while (p!= NULL) {
        r = p;
        p = p->next;
        r->next = q;
        q = r;

    }
    (*lista)->next = q;

}


int main(void) {
    int i, n;
    link Lista = (link)malloc(sizeof(struct node)); // Cria a cabeÃ§a da lista
    Lista->next = NULL; // Inicializar a lista com cabeÃ§a vazia
    int chave; // VariÃ¡vel para armazenar o valor a ser buscado/removido

    printf("Quantidade de nÃ³s da lista: ");
    scanf_s("%d", &n);
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        inserir(&Lista, i);
    }
    printf("Lista: \n");
    imprimir(Lista);

    inverterLista(&Lista);

    printf("Lista invertida:\n");
    imprimir(Lista);

    return 0;
}



