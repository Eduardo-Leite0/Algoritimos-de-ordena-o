#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define TAM 100000 // Define o tamanho do vetor;

void insertionSort(int vet[], int tamanho, int *comparacoes, int *trocas);
void imprimir(int vetor[], int tamanho);
time_t time(time_t *t);

int main() {
    int vVetor[TAM]; // Declara o vetor
    int comparacoes = 0, trocas = 0;
    int vAux;

    // Preenche o vetor com valores aleatórios
    srand(time(NULL));
    for (vAux = 0; vAux < TAM; vAux++) {
        vVetor[vAux] = rand() % 1000 + 1;
    }

    printf("Valores originais no vetor:\n");
    imprimir(vVetor, TAM);

    // Ordena o vetor em ordem decrescente
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = i + 1; j < TAM; j++) {
            if (vVetor[i] < vVetor[j]) {
                int temp = vVetor[i];
                vVetor[i] = vVetor[j];
                vVetor[j] = temp;
            }
        }
    }

    printf("\nValores ordenados em ordem decrescente:\n");
    imprimir(vVetor, TAM);

    LARGE_INTEGER inicio, fim, frequencia;
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&inicio); // Registra o tempo inicial

    insertionSort(vVetor, TAM, &comparacoes, &trocas); // Chama a função de Ordenação Insertion Sort;

    QueryPerformanceCounter(&fim); // Registra o tempo final

    double tempo_execucao = ((double)(fim.QuadPart - inicio.QuadPart)) / frequencia.QuadPart;

    printf("\n\nValores ordenados pelo Selection Sort em ordem crescente:\n");
    imprimir(vVetor, TAM);

    printf("\n\nTempo de execução: %f segundos\n", tempo_execucao);
    printf("\n\n");
    printf("\n\nQuantidade de Comparações: %d\n", comparacoes);
    printf("Quantidade de Trocas: %d\n", trocas);
    printf("\n\n");
    system("pause");
    return 0;
}

void insertionSort(int vet[], int tamanho, int *comparacoes, int *trocas) {
    int i, j, aux;

    for (i = 1; i < tamanho; i++) {
        aux = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > aux) {
            (*comparacoes)++;
            vet[j + 1] = vet[j];
            j--;
        }

        vet[j + 1] = aux;
        (*trocas)++;
    }
}

void imprimir(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf(" %d,", vetor[i]);
    }
    printf("\n");
}

