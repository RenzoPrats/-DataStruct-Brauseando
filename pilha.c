//Aluno: Renzo Prats Silva Souza     Matrícula: 11921ECP004
//arquivo com as funções
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* pilha_criar() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->tam = 0;
    p->L = criar_lista();
    return p;
}

void pilha_destruir(Pilha **p) {
    destruir_lista(&((*p)->L));
    free(*p);
    *p = NULL;
}

void pilha_adicionar(Pilha **p, char val[]) {
    adicionar_inicio((*p)->L, val);
    (*p)->tam++;
}

//acessa o topo da pilha
void acessar_primeiro(No *p, int atual){
    //se não tiver elemento nenhum, só o nó cabeça, retorna vazio
    if(p->prox==NULL){
        printf("Vazio\n");
    }else{
        //caso o elemento que vai ser printado seja onde está a pagina, imprime --> junto com a url do site
        if(atual == 1){
            printf("--> %s\n",(p->prox)->dado);
        }else{
            printf("%s\n",(p->prox)->dado);
        } 
    }
}

void pilha_topo(Pilha *p, int atual) {
    acessar_primeiro(p->L, atual);
}

void pilha_remover(Pilha **p) {
    remover_inicio((*p)->L);
    (*p)->tam--;
}

//funcao que imprime os valores da pilha
void imprimir_pilha(Pilha *p, int posicao) {
    //cria uma pilha auxiliar
    Pilha *aux = pilha_criar();
    int vezes = 1;
    int atual = 0;
    
    //enquanto o tamanho da pilha original for maior que 0, transfere os dados para pilha aux
    while(p->tam > 0){
        pilha_adicionar(&aux, lista_dado_inicio(p->L));
        pilha_remover(&p);
    }
    
    while(aux->tam > 0){
        //se a posicao for igual ao numero de vezes removido(para printar), atual recebe 1 para mostrar que é verdadeiro
        //portanto deve-se printar -->
        if (vezes == posicao){
            atual = 1;
        }else{
            atual = 0;
        }

        //printa o valor que está no topo da pilha;
        pilha_topo(aux, atual);

        //adiciona novamente na pilha original
        pilha_adicionar(&p, lista_dado_inicio(aux->L));
        //remove da pilha aux
        pilha_remover(&aux);
        vezes++;
    }
    //destroi a pilha auxiliar, liberando memoria
    pilha_destruir(&aux);

    //se tiver alguma coisa para printar, printara tambem os espacos para formatacao
    if(p->tam > 0){
        printf("\n");
    }
}

//funcao que adiciona um site na pilha
void adicionar_site(Pilha **P, char site[], int posicao){
    int n = (*P)->tam + 1 - posicao;
    // remove os sites que estão a frente do site atual
    while(n > 0){
        pilha_remover(P);
        n--;
    }
    //adiciona o site
    pilha_adicionar(P, site);
}