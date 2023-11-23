#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define TAM 100000 // Define o tamanho do vetor;

void mergeSort(int *vetor, int posicaoInicio, int posicaoFim, int *comparacoes, int *trocas);
void imprimir(int vetor[], int tamanho);

int main() {
    int vVetor[TAM]; // Declara o vetor
    int comparacoes = 0, trocas = 0;
    int vAux;

    // Preenche o vetor com 1000 valores em ordem decrescente
    for (vAux = 0; vAux < TAM; vAux++) {
        vVetor[vAux] = TAM - vAux - 1; // Gera um número decrescente entre 0 e TAM - 1
    }

    printf("Valores originais no vetor (em ordem decrescente):\n");
    imprimir(vVetor, TAM);

    LARGE_INTEGER inicio, fim, frequencia;
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&inicio); // Registra o tempo inicial

    mergeSort(vVetor, 0, TAM - 1, &comparacoes, &trocas); // Chama a função de Ordenação;

    QueryPerformanceCounter(&fim); // Registra o tempo final

    double tempo_execucao = ((double)(fim.QuadPart - inicio.QuadPart)) / frequencia.QuadPart;

    printf("\n\nValores ordenados pelo Merge Sort (em ordem decrescente):\n");
    imprimir(vVetor, TAM);

    printf("\n\nQuantidade de Comparações: %d\n", comparacoes);
    printf("Quantidade de Trocas: %d\n", trocas);
    printf("\n\nTempo de execução: %f segundos\n", tempo_execucao);
    printf("\n\n");
    system("pause");
    return 0;
}

void mergeSort(int *vetor, int posicaoInicio, int posicaoFim, int *comparacoes, int *trocas) {
    int i, j, k, metadeTamanho, *vetorTemp;
    if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho, comparacoes, trocas);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim, comparacoes, trocas);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        (*comparacoes)++;
        if (i == metadeTamanho + 1 ) { 
            (*trocas)++;
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                (*trocas)++;
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                (*comparacoes)++;
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    (*trocas)++;
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }
    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

void imprimir(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf(" %d,", vetor[i]);
    }
    printf("\n");
}

