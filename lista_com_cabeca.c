//Aluno: Renzo Prats Silva Souza     Matrícula: 11921ECP004
//Arquivo com as funções da lista
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_com_cabeca.h"

No* criar_lista() {
    No *q = (No*) malloc(sizeof(No));
    strcpy(q->dado, "");
    q->prox = NULL;
    return q;
}

void adicionar_inicio(No *p, char val[]) {
    No* q = (No*) malloc(sizeof(No));
    strcpy(q->dado, val);
    q->prox = p->prox;
    p->prox = q;
}

void remover_inicio(No *p) {
    No* q = p->prox;
    if(q==NULL) return;
    p->prox = q->prox;
    free(q);
}

void destruir_lista(No **p) {
    No *q;
    while(*p != NULL){
        q = *p;
        *p = (*p)->prox;
        free(q);
    }
}

char* lista_dado_inicio(No *p) {
    return p->prox->dado;
}