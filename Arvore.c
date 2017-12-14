#include "Arvore.h"

void menu (head *raiz){

    int valor;
    char opcao;
    do{
        system("color 4F");
        system("pause");
        system("cls || clear");
        printf("MENU\n");
        printf("0. Sair\n");
        printf("1. Insere\n");
        printf("2. Altura\n");
        printf("3. Buscar\n");
        printf("4. Imprime\n");
        printf("5. Libera\n");
        fflush(stdin);
        scanf("%c", &opcao);

        switch(opcao){
            case '0':
                printf("Adeus :)");
                raiz->ini = libera(raiz->ini);
                free(raiz);
                break;
            case '1':
                insere(raiz);
                break;
            case '2':
                printf("Altura da arvore é %d\n", altura(raiz->ini));
                break;
            case '3':
                printf("Digite o valor que deseja buscar na arvore\n");
                scanf("%d", &valor);
                if(busca(raiz->ini,valor))
                    printf("Valor encontrado!!\n");
                else
                    printf("Valor nao encontrado\n");
                break;
            case '4':
                system("cls || clear");
                imprime(raiz->ini,0);
                break;
            case '5':
                printf("Esvaziando arvore\n");
                raiz->ini = libera(raiz->ini);
                break;
            default:
                printf("Escolha uma opção válida do menu\n");
                break;




        }
    }while(opcao != '0');
}


arv *inicializa(){

    return NULL;
}

arv *libera(arv *a){

    if(!vazia(a)){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

void insere(head *raiz){

    system("cls || clear");
    arv *novo = (arv *) malloc(sizeof(arv));
    novo->dir = inicializa();
    novo->esq = inicializa();
    printf("Digite o valor a ser inserido na arvore\n");
    scanf("%d", &novo->valor);

    if(raiz->ini == NULL)
        raiz->ini = novo;
    else
        inserindo(raiz->ini,novo);
}

void inserindo(arv *a, arv *novo){

    system("cls || clear");
    int opcao;
    do{
        if (a->esq == NULL){
            printf("1. Inserir na Esquerda\n");
        }
        if (a->dir == NULL){
            printf("2. Inserir na Direita\n");
        }
        if (a->esq != NULL || a->dir != NULL){
            printf("3. Avançar de Nó\n");
        }
        scanf("%d", &opcao);
        if(opcao == 1 && a->esq == NULL){
            a->esq = novo;
            return ;
        }
        else if(opcao == 2 && a->dir == NULL){
            a->dir = novo;
            return ;
        }
        else if(opcao == 3 && (a->esq != NULL || a->dir != NULL)){
            printf("Direita ou Esquerda Ocupada. Escolha um dos lados para avançar de nó\n");
            if(a->esq != NULL){
                printf("1. Avançar para Esquerda\n");
            }
            if(a->dir != NULL){
                printf("2. Avançar para Direita\n");
            }
            scanf("%d", &opcao);

            switch(opcao){
                case 1:
                    if(a->esq == NULL){
                        printf("\nOpção Inválida, retornando ao menu principal\n");
                        free(novo);
                        return ;
                    }
                    inserindo(a->esq, novo);
                    break;
                case 2:
                    if(a->dir == NULL){
                        printf("\nOpção Inválida, retornando ao menu principal\n");
                        free(novo);
                        return ;
                    }
                    inserindo(a->dir, novo);
                    break;
                default:
                    printf("\nOpção Inválida, retornando ao menu principal\n");
                    free(novo);
                    break;
            }
            return ;
        }
        else{
            printf("Opção invalida");
            system("cls || clear");
        }
    }while(opcao > 0 && opcao < 3);
}

int altura (arv *a) {

   if (a == NULL)
      return -1;
   else {
      int he = altura (a->esq);
      int hd = altura (a->dir);
      if (he < hd)
        return hd + 1;
      else
        return he + 1;
   }
}

int busca(arv *a, int value){

    if(vazia(a))
        return 0;
    else
        return a->valor == value || busca(a->esq, value) || busca(a->dir, value);

}

void imprime(arv *a, int b) {

    if (a == NULL) {
        imprimeNo(-1, b);
        return;
    }
    imprime(a->esq, b+1);
    imprimeNo(a->valor, b);
    imprime(a->dir, b+1);
}

void imprimeNo(int valor, int b) {
    int i;

    for (i = 0; i < b; i++) printf("   ");
    printf("%d\n", valor);
}

int vazia(arv *a){
    return a==NULL;
}
