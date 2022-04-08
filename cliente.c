//Aluno: Renzo Prats Silva Souza     Matrícula: 11921ECP004
//Arquivo com a função main
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){
    Pilha *L = pilha_criar();

    //armazena toda entrada
    char *ordem = (char *) malloc(110 * sizeof(char));
    //armazena apenas  url do site
    char *site = (char *) malloc(100 * sizeof(char));
    //armazena a posicao do site
    int posicao = 0;

    while(scanf("%s", ordem) && strcmp(ordem, "encerra") != 0){
        if(strcmp(ordem, "acessa") == 0){
            //acessa
            scanf("%s", site);

            posicao++;
            adicionar_site(&L, site, posicao);
        
        }else if(strcmp(ordem, "imprime") == 0){
            //imprime
            imprimir_pilha(L, posicao);
        
        }else if(strcmp(ordem, "volta") == 0){
            //volta 
            //se tiver alguma posicao para voltar
            if(posicao > 1){
                posicao--;
            }
        }else if(strcmp(ordem, "avanca") == 0){
            //avanca
            //se for possivel avancar
            if(L->tam > posicao){
                posicao++;
            }
        }
    }
    //desaloca a memoria usada na variavel ordem
    free(ordem);
    
    //desaloca a memoria usada na variavel site
    free(site);

    //desaloca a pilha 
    pilha_destruir(&L);   
}