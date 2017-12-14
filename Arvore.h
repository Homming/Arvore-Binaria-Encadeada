#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct arvore{
int valor;
struct arvore *esq;
struct arvore *dir;
}arv;

typedef struct Head{
struct arvore *ini;
}head;

void menu(head *raiz);
arv *inicializa();
arv *libera(arv *a);
void insere(head *raiz);
void inserindo(arv *a, arv *novo);
int altura (arv *a);
int busca(arv *a, int value);
void imprime(arv *a, int b);
void imprimeNo(int valor, int b);
int vazia(arv *a);
