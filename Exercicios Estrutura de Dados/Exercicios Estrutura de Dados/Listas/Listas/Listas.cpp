#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*struct node {
    int item;
    struct node* next;
};

void inserir(struct node** lista, int novoItem) {
    struct node* novoNode = (struct node*)malloc(sizeof(struct node));
    novoNode->item = novoItem;
    novoNode->next = *lista;
    *lista = novoNode;
}

void imprimir(struct node* lista) {
    struct node* p = lista;
    printf("Lista: ");
    while (p != NULL) {
        if (p->next != NULL) {
            printf("%d - ", p->item);
        }
        else {
            printf("%d", p->item);
        }
        p = p->next;  // Corrigido para avançar corretamente na lista
        
    }
    printf("\n"); // Melhorando a formatação
}

void liberar(struct node* lista) {
    struct node* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->next;
        free(temp);
    }
}
*/
int buscaBinaria(int arr[], int esquerda, int direita) {
    if (esquerda == direita) {
        return arr[esquerda];
    }

    int meio = esquerda + (direita - esquerda) / 2;
    int max_esq = buscaBinaria(arr, esquerda, meio);
    int max_dir = buscaBinaria(arr, meio + 1, direita);

    return (max_esq > max_dir) ? max_esq : max_dir;
}
int main() {
    srand(time(NULL));
    int* a;
    int n;    
    printf("Me de o tamanho do Vetor para Busca: ");
    scanf_s("%d", &n);

    a = (int*)malloc(n * sizeof(int));
    printf("Vetor:");
    printf("\n");
    for (int i = 0; i < n; i++)
    {   
        a[i] = rand() % 10 + 1;
        printf("%d-> ", a[i]);
    }

    int resultado = buscaBinaria(a,0,n-1);
    printf("\n");
    printf("O maior Elemento eh: %d", resultado);
   // int i, n;
   // struct node* Lista = NULL;

   // printf("Me de a quantidade de elementos na lista: ");
    //scanf_s("%d", &n);
    //printf("\n");

/*
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        inserir(&Lista, 1 + (rand() % 100));
    }

    imprimir(Lista);

    liberar(Lista); // Libera a memória alocada dinamicamente*/
}
