#include "pilha.h"
#include <stdio.h>

Tarefa ler_tarefa() {
  Tarefa t;
  printf("\n Digite a descrição do problema: \n");
  fgets(t.descricao, sizeof(t.descricao), stdin);
  fflush(stdin);
  return t;
}

void imprimir_tarefa(Tarefa t) {
  printf("\n Descrição do problema: \n");
  printf(" %s ", t.descricao);
}

Nop *empilhar(Nop *topo) {
  Nop *novo = malloc(sizeof(Nop));

  if (novo) {
    novo->t = ler_tarefa();
    novo->proximo = topo;
    return novo;
  } else {
    printf("\n Erro na alocação \n");
  }
  return NULL;
}

Nop *desempilhar(Nop **topo) {
  if (*topo != NULL) {
    Nop *remover = *topo;
    *topo = remover->proximo;
    return remover;
  } else {
    printf("\n pilha vazia \n");
    return NULL;
  }
}

void imprimir_pilha(Nop *topo) {
  printf("\n----------------PILHA------------------");
  while (topo) {
    imprimir_tarefa(topo->t);
    topo = topo->proximo;
  }
}
