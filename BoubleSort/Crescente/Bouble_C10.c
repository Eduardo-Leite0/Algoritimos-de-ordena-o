#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>

void imprimir();
int i, aux, troca, comparacoes, trocas;
int numero[10000]; // Alterado para suportar 10000 números

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("\n--------------------------------------------");
    printf("\nEXEMPLO BUBBLE SORT CRESCENTE");
    printf("\n--------------------------------------------");
    printf("\nInicializando o Array");

    for (i = 0; i < 10000; i++) {
        numero[i] = 0;
    }

    imprimir();
    printf("\n--------------------------------------------");
    printf("\nInserindo valores no Array\n");

    // Removido o loop de entrada do usuário
    // Adicionando manualmente 10000 números ao array
    for (i = 0; i < 10000; i++) {
        numero[i] = i + 1; // Adicionando números de 1 a 10000
    }

    printf("\n--------------------------------------------");
    printf("\nValores armazenados no array");
    imprimir();
    printf("\n--------------------------------------------");
    printf("\nOrdenando o Array");

    LARGE_INTEGER inicio, fim, frequencia;
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&inicio); // Registra o tempo inicial

    troca = 1;
    comparacoes = 0;
    trocas = 0;
    while (troca == 1) {
        troca = 0;
        for (i = 0; i < 9999; i++) {
            comparacoes++;
            if (numero[i] > numero[i + 1]) {
                troca = 1;
                aux = numero[i];
                numero[i] = numero[i + 1];
                numero[i + 1] = aux;
                trocas++;
            }
        }
    }

    QueryPerformanceCounter(&fim); // Registra o tempo final

    double tempo_execucao = ((double)(fim.QuadPart - inicio.QuadPart)) / frequencia.QuadPart;

    printf("\n--------------------------------------------");
    printf("\nValores ordenados");
    imprimir();
    printf("\n--------------------------------------------");

    printf("\nTempo de execução: %.6f segundos\n", tempo_execucao);
    printf("\nQuantidade de Comparações: %d\n", comparacoes);
    printf("Quantidade de Trocas: %d\n", trocas);

    return 0;
}

void imprimir() {
    printf("\n--------------------------------------------");
    for (i = 0; i < 10000; i++) {
        printf("\n|Posicao: %d | Número: %d|", i, numero[i]);
    }
}

