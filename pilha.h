//Aluno: Renzo Prats Silva Souza     Matrícula: 11921ECP004
//Arquivo que define o protótipo das funções da pilha
#ifndef PILHA_H
#define PILHA_H

#include "lista_com_cabeca.h"

typedef struct {
    int tam;
    No *L;
} Pilha;


Pilha* pilha_criar();
void pilha_destruir(Pilha **P);

//Adicionar
void pilha_adicionar(Pilha **P,char val[]);

//Acessar
void pilha_topo(Pilha *P, int atual);

//Remover
void pilha_remover(Pilha **P);

//imprime
void imprimir_pilha(Pilha *P, int atual);

//adicionar site na pilha
void adicionar_site(Pilha **P, char site[], int posicao);

#endif