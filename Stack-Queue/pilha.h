#include "tarefa.h"
#ifndef PILHA
#define PILHA

typedef struct nop {
  Tarefa t;
  struct nop *proximo;
} Nop;

Nop *empilhar(Nop *topo);
Nop *desempilhar(Nop **topo);
void imprimir_pilha(Nop *topo);

#endif
