// Exercicios Estrutura de Dados.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>
void converteHoras(int total_segundos, int* horas, int* min, int* seg){
    *horas = total_segundos / 3600;
    total_segundos %= 3600;
    *min = total_segundos / 60;
    *seg = total_segundos % 60;

}
int main()
{
    /*int x, * p, ** q;
    x = 42;
    p = &x;
    q = &p;   
    printf("\n%d\n", **q); */

    /* char a[] = "Abacaxiss";
        char b[] = "Abacate";

        if (strcmp(a, b) < 0)
            printf("%s eh lexicograficamente menor que %s\n", a, b);
        else
            printf("%s eh lexicograficamente maior que %s\n", a, b);*/
    int segundos, horas, minutos, seg;
    printf("Me de os segundos: ");
    scanf_s("%d", &segundos);
  

    converteHoras(segundos, &horas, &minutos, &seg);

    printf("Conversao: %dH: %dM : %dS", horas, minutos, seg);

    
        return 0;
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
