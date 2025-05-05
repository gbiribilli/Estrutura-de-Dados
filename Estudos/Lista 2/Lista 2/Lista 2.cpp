// Lista 2.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*int verificacao(int a[], int t) {
	int cont = 0;
	int decrescente = 0;
	int conts = 0;
	for (int i = 0; i < t; i++) {
		if (a[i] < a[i + 1]) {
			cont++;
		}
	}
	for (int i = 0; i <t-1; i++) {
		if (a[i] > a[i + 1]) {
			decrescente++;
		}
	}

	for (int i = 0; i < t; i++) {
		if (a[i] == a[i + 1]) {
			conts++;
		}
	}

	if (cont == t-1) {
		return 1;
	}
	if (decrescente == t-1) {
		return 2;
	}
	if (conts == t-1) {
		return 3;
	
	}

	return 4;

}
*/
int mdcRecursivo(int n, int p) {
	
	if (p == 0) {
		return n;
	}
	mdcRecursivo(p, n % p);
	
}
int MDC(int n, int p) {
	int r = 1;
	while (r != 0) {
		r = n % p;
		n = p;
		p = r;
	}
	return n;
}
void inverter(int *a, int n) {
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

}
int main()
{
	int* a;
	int n;
	printf("Me de o tamanho do vetor: ");
	scanf_s("%d", &n);
	a = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		a[i] = rand() % 50 + 1;
		printf("%d -", a[i]);
	}
	printf("\n");

	inverter(a, n);
	printf("Após inversao: \n");
	for (int i = 0; i < n; i++) {
		
		printf("%d -", a[i]);
	}
	/*srand(time(NULL));
	int* a;
	int n;
	printf("Me de o tamanho do vetor: ");
	scanf_s("%d", &n);
	a = (int*)malloc(n*sizeof (int));
	int numero = 5;
	for (int i = 0; i < n; i++) {
		a[i] = numero;
		numero--;
	}

	
	int retorno = verificacao(a, n);
	switch (retorno)
	{
	case 1:
		printf("Estão ordenados");
		break;
	case 2:
		printf("Estão em ordem descrescente");
		break;
	case 3: 
		printf("São constantes");
		break;
	case 4:
		printf("Estão desordenados");
		break;
	}*/
}

