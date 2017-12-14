#include "Arvore.h"

void main(){
setlocale(NULL,"portuguese");
head *raiz = (head *) malloc(sizeof(head));
raiz->ini = inicializa();

menu(raiz);
}
