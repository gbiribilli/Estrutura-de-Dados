#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void converteHoras(int Total_segundos, int* horas, int* min, int* seg) {
	*horas = Total_segundos / 3600;
	*min = (Total_segundos % 3600) / 60;
	*seg = Total_segundos % 60;
}
void conversaoMetros(float metros, float* decimetro, float* centimetro, float* milimetro) {
	
	*decimetro = metros * 10;
	*centimetro = metros * 100;
	*milimetro = metros * 1000;
}


void aux(int* n, int* x) {
	int temp;
	temp = *n;
	*n = *x;
	*x = temp;
}

void bubbleSort(int *arr,int n) {
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (arr[j] > arr[j + 1]) {
				aux(&arr[j], &arr[j + 1]);
			}
		}
	}
}

int main(void) {
	srand(time(NULL));

	/*int x, * p, ** q;
	p = &x;
	q = &p;
	x = 42;
	printf("\n%d\n", **q);
	*/

	/*char* a, * b;
	a == "Abacaxi";
	b == "Abacate";
	if (strcmp(a,b) < 0)
		printf("%s é lexicograficamente menor que %s\n", *a, *b);
	else
		printf("%s é lexicograficamente maior que %s\n", *a, *b);
		*/

	/*int totalSegundos, horas, min, seg;
	printf("Me de a quantidade de segundos para conversão: ");
	scanf_s("%d", &totalSegundos);
	

	converteHoras(totalSegundos,&horas,&min,&seg);

	printf("%d Horas : %d Minutos : %d Segundos",horas,min,seg);

	printf("  Horas: %d", horas);*/

	/*float metros, decimetro, centimetro, milimetro;

	printf("Me de o valor em Metros: ");
	scanf_s("%f", &metros)	;
	conversaoMetros(metros, &decimetro, &centimetro, &milimetro);
	printf("%f Metrose Em:\n%f - Decimetro\n%f - Centimetro\n%f - Milimetro",metros,decimetro,centimetro,milimetro); */

	
	/*
	printf("Ordenando vetores");
	int* array, n;
	printf("Me de o tamanho do array: \n");
	scanf_s("%d", &n);

	array = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 50 + 1;
		printf("%d ", array[i]);
	}
	bubbleSort(array, n);
	printf("\n");
	printf("Vetor ordenado:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	free(array);*/
	
	//ajsdhandasjsd
	return 0;
}