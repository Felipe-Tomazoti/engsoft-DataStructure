#include "fila.h"
#include <stdio.h>
#include <string.h>

void criar_fila(Fila *fila) {
  fila->prim = NULL;
  fila->fim = NULL;
  fila->tam = 0;
}

void inserir_fila(Fila *fila, char descricao[100]) {
  No *novo = malloc(sizeof(No));
  if (novo) {
    strcpy(novo->descricao, descricao);
    novo->proximo = NULL;
    if (fila->prim == NULL) {
      fila->prim = novo;
      fila->fim = novo;
    } else {
      fila->fim->proximo = novo;
      fila->fim = novo;
    }
    fila->tam++;
  } else
    printf("\n ERRO AO ALOCAR MEMÓRIA.\n");
}

No *remover_fila(Fila *fila) {
  No *remove = NULL;

  if (fila->prim) {
    remove = fila->prim;
    fila->prim = remove->proximo;
    fila->tam--;
  } else
    printf("\nFila vazia.\n");
  return remove;
}
void imprimir_fila(Fila *fila) {
  printf("\n----------------FILA------------------");
  No *aux = fila->prim;
  while (aux) {
    printf("\n Descrição do problema: \n");
    printf("%s ", aux->descricao);
    aux = aux->proximo;
  }
  printf("\n");
}