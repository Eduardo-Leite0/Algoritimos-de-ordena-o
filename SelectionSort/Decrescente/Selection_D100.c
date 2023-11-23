#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define TAM 100000 // Define o tamanho do vetor;

void selectionSort(int vet[], int tamanho, int *trocas, int *comparacoes);
void imprimir(int vetor[], int tamanho);
time_t time(time_t *t);

int main() {
    int vVetor[TAM]; // Declara o vetor
    int trocas = 0, comparacoes = 0;
    int vAux, i, j, temp;

    // Preenche o vetor com valores aleatórios
    srand(time(NULL));
    for (vAux = 0; vAux < TAM; vAux++) {
        vVetor[vAux] = rand() % 1000 + 1;
    }

    printf("Valores originais no vetor:\n");
    imprimir(vVetor, TAM);

    // Ordena o vetor em ordem decrescente
    for (i = 0; i < TAM - 1; i++) {
        for (j = i + 1; j < TAM; j++) {
            if (vVetor[j] > vVetor[i]) {
                temp = vVetor[j];
                vVetor[j] = vVetor[i];
                vVetor[i] = temp;
            }
        }
    }
    printf("Decrescente:\n");
    imprimir(vVetor, TAM);

    LARGE_INTEGER inicio, fim, frequencia;
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&inicio); // Registra o tempo inicial

    selectionSort(vVetor, TAM, &trocas, &comparacoes); // Chama a função de Ordenação Selection Sort;

    QueryPerformanceCounter(&fim); // Registra o tempo final

    double tempo_execucao = ((double)(fim.QuadPart - inicio.QuadPart)) / frequencia.QuadPart;

    printf("\n\nValores ordenados pelo Selection Sort:\n");
    imprimir(vVetor, TAM);

    printf("\n\nTempo de execução: %f segundos\n", tempo_execucao);
    printf("Quantidade de Trocas: %d\n", trocas);
    printf("Quantidade de Comparacoes: %d\n", comparacoes);
    printf("\n\n");
    system("pause");
    return 0;
}

void selectionSort(int vet[], int tamanho, int *trocas, int *comparacoes) {
    int i, j, minIndex, temp;

    for (i = 0; i < tamanho - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < tamanho; j++) {
            (*comparacoes)++;
            if (vet[j] < vet[minIndex]) {
                minIndex = j;
            }
        }

        temp = vet[minIndex];
        vet[minIndex] = vet[i];
        vet[i] = temp;
        (*trocas)++;
    }
}

void imprimir(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf(" %d,", vetor[i]);
    }
    printf("\n");
}

