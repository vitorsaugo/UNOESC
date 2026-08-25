#include <stdio.h>

struct cliente{
    char nome[50];
    int codigo;
};
    int main(){
        int i;
        struct cliente clientes[10];

        for(i=0;i<9;i++){
            printf("digite o codigo do cliente %d: ", i + 1);
            scanf("%d", &clientes[i].codigo);

            printf("nome %d: ", i + 1);
            scanf("%49s", clientes[i].nome);
        }
        printf("\nCODIGO\tNOME\n");
        for(i=0;i<9;i++){
            printf("%d\t%s\n", clientes[i].codigo, clientes[i].nome);
        }
        return 0;
    }