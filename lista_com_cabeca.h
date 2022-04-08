//Aluno: Renzo Prats Silva Souza     Matrícula: 11921ECP004
//Arquivo que define o protótipo das funções da lista

# ifndef LISTA_HEAD_H
# define LISTA_HEAD_H

//Dados
typedef struct no {
    char dado[100];
    struct no *prox;
} No;

//Funcoes
No* criar_lista();
void destruir_lista(No **L);

//Adicionar
void adicionar_inicio(No *L, char val[]);

//Remover
void remover_inicio(No *L);

//Retorna dado do inicio da lista
char* lista_dado_inicio(No *p);

# endif