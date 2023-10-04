#include "fila.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Nop *remover, *topo = NULL;
  No *r;
  Fila fila;
  int opcao;
  int prioridade;
  char descricao[100];
  int c;

  criar_fila(&fila);

  printf("Qual o nível de prioridade da tarefa (0 ou 1)?: ");
  scanf("%d", &prioridade);

  if (prioridade == 1) {
    do {
      printf("\n");
      printf("0 - sair da pilha\n");
      printf("1 = empilhar na pilha\n");
      printf("2 = desempilhar na pilha\n");
      printf("3 = imprimir a pilha\n");
      printf("4 = Limpar tela\n");
      printf("5 = Adicionar tarefa de prioridade 0\n");
      scanf("%d", &opcao);
      getchar();
      printf("\n opcao = %d", opcao);
      switch (opcao) {
      case 1:
        topo = empilhar(topo);
        system("clear");
        break;
      case 2:
        remover = desempilhar(&topo);
        if (remover != NULL) {
          printf("\n Removido com sucesso \n");
          imprimir_tarefa(remover->t);
        } else {
          printf("\n sem nó a remover \n");
        }
        break;
      case 3:
        imprimir_pilha(topo);
        break;
      case 4:
        system("clear");
        break;
      case 5: 
        if (topo == NULL) {
          prioridade = 0;
          topo = NULL;
          system("clear");
          do {
            printf("\n");
            printf("0 - sair da fila\n");
            printf("1 - inserir na fila\n");
            printf("2 - remover da fila\n");
            printf("3 - imprimir a fila\n");
            printf("4 = Limpar tela\n");
            scanf("%d", &opcao);
            switch (opcao) {
            case 1:
              while ((c = getchar()) != '\n' && c != EOF)
                ;
              printf("Digite uma descrição para o problema (prioridade = 0): ");
              fgets(descricao, sizeof(descricao), stdin);
              inserir_fila(&fila, descricao);
              system("clear");
              break;
            case 2:
              r = remover_fila(&fila);
              if (r != NULL) {
                printf("Removido com sucesso!\n");
                free(r);
              }
              break;
            case 3:
              imprimir_fila(&fila);
              break;
              case 4:
                system("clear");
              break;
            default:
              if (opcao != 0) {
                printf("Opção inválida\n");
              }
              break;
            }
          } while (opcao != 0);
        } else {
          printf(" Para adicionar uma tarefa na fila, é preciso que a pilha "
                 "esteja esteja vazia!, escolhe a opção 2: Desempilha! ");
          break;
        }
      default:
        if (opcao != 0) {
          printf("\n opcao invalida\n");
        }
      }
    } while (opcao != 0);
    return 0;
  }
  if (prioridade == 0 && topo == NULL) {
    do {
      printf("\n");
      printf("0 - sair da fila\n");
      printf("1 - inserir na fila\n");
      printf("2 - remover da fila\n");
      printf("3 - imprimir a fila\n");
      printf("4 = Limpar tela\n");
      printf("5 = Adicionar tarefa de prioridade 1\n");
      scanf("%d", &opcao);
      switch (opcao) {
      case 1:
        while ((c = getchar()) != '\n' && c != EOF)
          ;
        printf("Digite uma descrição para o problema (prioridade = 0): ");
        fgets(descricao, sizeof(descricao), stdin);
        inserir_fila(&fila, descricao);
        system("clear");
        break;
      case 2:
        r = remover_fila(&fila);
        if (r != NULL) {
          printf("Removido com sucesso!\n");
          free(r);
        }
        break;
      case 3:
        imprimir_fila(&fila);
        break;
      case 4:
        system("clear");
        break;
      case 5:
        prioridade = 1;
        do {
          printf("\n");
          printf("0 - sair da pilha\n");
          printf("1 = empilhar na pilha\n");
          printf("2 = desempilhar na pilha\n");
          printf("3 = imprimir a pilha\n");
          printf("4 = Limpar tela\n");
          scanf("%d", &opcao);
          getchar();
          printf("\n opcao = %d", opcao);
          switch (opcao) {
          case 1:
            topo = empilhar(topo);
            system("clear");
            break;
          case 2:
            remover = desempilhar(&topo);
            if (remover != NULL) {
              printf("\n Removido com sucesso \n");
              imprimir_tarefa(remover->t);
            } else {
              printf("\n sem nó a remover \n");
            }
            break;
          case 3:
            imprimir_pilha(topo);
            break;
          case 4:
            system("clear");
            break;
          default:
            if (opcao != 0) {
              printf("\n opcao invalida\n");
            }
          }
        } while (opcao != 0);
      default:
        if (opcao != 0) {
          printf("Opção inválida\n");
        }
        break;
      }
    } while (opcao != 0);
    return 0;
  }
}
