// Pilha.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 42 // Valor mÃ¡ximo de elementos que a pilha pode armazenar

// Define uma estrutura chamada PILHA para representar a pilha
typedef struct {
	int A[MAX]; // Vetor/arranjo para armazenar os elementos da pilha
	int topo; // Ãndice do topo da pilha
} PILHA;

// FunÃ§Ã£o para inicializar a pilha vazia
void inicializar(PILHA* p) {
	p->topo = -1; // Indica que a pilha estÃ¡ vazia
}

// FunÃ§Ã£o para empilhar (push) um elemento na pilha
void empilhar(PILHA* p, char x) {
	if (p->topo == MAX - 1) // Verifica se a pilha estÃ¡ cheia
		printf("Pilha Cheia!\n");
	else { // Pilha tem espaÃ§o para armazemar o elemento x 
		p->topo = p->topo + 1; // Atualiza a posiÃ§Ã£o do topo
		p->A[p->topo] = x; // Insere o elemento x no topo
	}
}

// FunÃ§Ã£o para desempilhar (pop) um elemento da pilha
void desempilhar(PILHA* p, char* t) {
	if (p->topo == -1) // Verifica se a pilha estÃ¡ vazia
		printf("Pilha Vazia!\n");
	else { // A pilha tem pelo menos um elemento
		*t = p->A[p->topo]; // Faz uma cÃ³pia do elemento do topo
		p->topo = p->topo - 1; // Atualiza a posiÃ§Ã£o do topo
	}
}

// FunÃ§Ã£o para imprimir os elementos da pilha
void imprimir(PILHA p) {
	int i;
	printf("Pilha: \" ");
	for (i = p.topo; i >= 0; i--) { // Percorre a pilha do topo atÃ© a base
		printf("%d ", p.A[i]); // Exibe os elementos na ordem de desempilhamento
	}
	printf("\"\n");
}

int somaPares(int n) {
	if (n == 1) {
		return 0;
	}
	else if(n%2 == 0){
		return n + somaPares(n - 1);
	}
	else {
		return somaPares(n - 1);
	}
}
/*bool bemFormada(char* sequencia) {
	PILHA p;
	inicializar(&p);
	char c;

	for (int i = 0; sequencia[i] != '\0'; i++) {
		switch (sequencia[i]) {
		case '(':
		case '[':
			empilhar(&p, sequencia[i]); // Empilha apenas aberturas
			break;

		case ')':
			if (p.topo == -1) return false; // Pilha vazia (parêntese sem abertura)
			desempilhar(&p, &c);
			if (c != '(') return false; // Erro de correspondência
			break;

		case ']':
			if (p.topo == -1) return false; // Pilha vazia (colchete sem abertura)
			desempilhar(&p, &c);
			if (c != '[') return false; // Erro de correspondência
			break;
		}
	}
	return (p.topo == -1); // Retorna verdadeiro se a pilha estiver vazia
}*/
void palindromo(PILHA n,char *str) {
	
	char c;
	int z = 0,i=0;
	while (str[i] != '\0') {
		desempilhar(&n, &c);
		if (str[i] != c) {
			z = 1;
			break;
		}
		i++;
	}


	if (z == 0) {
		printf("e palindromo");
	}
	else {
		printf("nao e palindromo");
	}
 }
void binario() {

}
void inverter(int* vetor, int inicio, int fim) {
	if (inicio >= fim) {
		return;
	}
	else {
		int aux = vetor[inicio];
		vetor[inicio] = vetor[fim];
		vetor[fim] = aux;
		inverter(vetor, inicio + 1, fim - 1);
	}
}
int main()
{
	int v[6];
	int n = 6;
	for (int i = 0; i < n; i++) {
		v[i] = i + 2;

		printf("%d", v[i]);
	}
	printf("\n");
	inverter(v, 0, 5);

	for (int i = 0; i < n; i++) {
		printf("%d", v[i]);
	}

	/*char sequencia[MAX] = "(([]))";

	bool formado = bemFormada(sequencia);
	
	printf("%s",formado? "Bem formado":"Mal formado");*/
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
