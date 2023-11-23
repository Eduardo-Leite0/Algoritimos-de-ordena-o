#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define TAM 1000 // Define o tamanho do vetor;

void shellSort(int *vet, int size, int *comparacoes, int *trocas);
void imprimir(int vetor[], int tamanho);

int main() {
    int vVetor[TAM]; // Declara o vetor
    int comparacoes = 0, trocas = 0;
    int vAux;

    // Preenche o vetor em ordem decrescente
    for (vAux = 0; vAux < TAM; vAux++) {
        vVetor[vAux] = TAM - vAux; // Preenche o vetor em ordem decrescente
    }

    printf("Valores originais no vetor (em ordem decrescente):\n");
    imprimir(vVetor, TAM);

    LARGE_INTEGER inicio, fim, frequencia;
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&inicio); // Registra o tempo inicial

    shellSort(vVetor, TAM, &comparacoes, &trocas); // Chama a função de Ordenação;

    QueryPerformanceCounter(&fim); // Registra o tempo final

    double tempo_execucao = ((double)(fim.QuadPart - inicio.QuadPart)) / frequencia.QuadPart;

    printf("\n\nValores ordenados pelo Shell Sort (em ordem crescente):\n");
    imprimir(vVetor, TAM);

    printf("\n\nQuantidade de Comparações: %d\n", comparacoes);
    printf("Quantidade de Trocas: %d\n", trocas);
    printf("\n\nTempo de execução: %f segundos\n", tempo_execucao);
    printf("\n\n");
    system("pause");
    return 0;
}

void shellSort(int *vet, int size, int *comparacoes, int *trocas) {
    int i, j, value;
    int gap = 1;
    while (gap < size) {
        gap = 3 * gap + 1;
    }
    while (gap > 1) {
        gap /= 3;
        for (i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            (*comparacoes)++;
            while (j >= 0 && value < vet[j]) {
                vet[j + gap] = vet[j];
                j -= gap;
                (*comparacoes)++;
            }
            vet[j + gap] = value;
            (*trocas)++;
        }
    }
}

void imprimir(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf(" %d,", vetor[i]);
    }
    printf("\n");
}

