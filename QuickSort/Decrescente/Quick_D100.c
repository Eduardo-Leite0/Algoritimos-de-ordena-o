#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define TAM 100000 // Define o tamanho do vetor;

void quick(int vet[], int esq, int dir, int *comparacoes, int *trocas);
void imprimir(int vetor[], int tamanho);

int main() {
    int vVetor[TAM]; // Declara o vetor
    int comparacoes = 0, trocas = 0;
    int vAux;
    
    srand(time(NULL));
    for (vAux = 0; vAux < TAM; vAux++) {
        vVetor[vAux] = (rand() % 1000) + 1; // Preenche o vetor aleatoriamente;
    }

    printf("Valores originais no vetor (em ordem decrescente):\n");

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

    imprimir(vVetor, TAM);

    LARGE_INTEGER inicio, fim, frequencia;
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&inicio); // Registra o tempo inicial

    quick(vVetor, 0, TAM - 1, &comparacoes, &trocas); // Chama a fun��o de Ordena��o;

    QueryPerformanceCounter(&fim); // Registra o tempo final

    double tempo_execucao = ((double)(fim.QuadPart - inicio.QuadPart)) / frequencia.QuadPart;

    printf("\n\nValores ordenados pelo Quick Sort (em ordem crescente):\n");
    imprimir(vVetor, TAM);
    printf("\n\nQuantidade de Compara��es: %d\n", comparacoes);
    printf("Quantidade de Trocas: %d\n", trocas);
    printf("\n\nTempo de execu��o: %f segundos\n", tempo_execucao);
    printf("\n\n");
    system("pause");
    return 0;
}

void quick(int vet[], int esq, int dir, int *comparacoes, int *trocas) {
    int ch, j;
    int pivo = esq;
    int i;

    // Quantidade de compara��es
    (*comparacoes)++;

    if (esq < dir) {
        // Escolhe o piv�
        ch = vet[esq];

        // Particiona o vetor
        for (i = esq + 1; i <= dir; i++) {
            (*comparacoes)++;
            if (vet[i] < ch) {
                // Troca os elementos
                j = i;
                while (j > esq) {
                    vet[j] = vet[j - 1];
                    j--;
                    (*trocas)++;
                }

                vet[j] = ch;
                (*trocas)++;
                pivo++;
            }
        }

        // Recurs�o para a sub�rvore esquerda
        quick(vet, esq, pivo - 1, comparacoes, trocas);

        // Recurs�o para a sub�rvore direita
        quick(vet, pivo + 1, dir, comparacoes, trocas);
    }
}

void imprimir(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf(" %d,", vetor[i]);
    }
    printf("\n");
}

