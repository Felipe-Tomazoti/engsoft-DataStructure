#include "tarefa.h"
#ifndef FILA
#define FILA

typedef struct no {
  char descricao[100];
  struct no *proximo;
} No;

typedef struct {
  No *prim;
  No *fim;
  int tam;
} Fila;

void criar_fila(Fila *fila);
void inserir_fila(Fila *fila, char descricao[100]);
No *remover_fila(Fila *fila);
void imprimir_fila(Fila *fila);

#endif
