#include <stdio.h>

#define TAMANHO 10

class ClasseLista {
private:
    int Lista[TAMANHO];
    int F;

public:
    ClasseLista() {
        F = -1;
    }

   int ListaVazia() {
       if(F == -1){
           return 1;
       } else {
           return 0;
       }
        return -1;
    }

    int ValidaInsercao() {
        if(F+1 < TAMANHO){
            return 1;
        } else {
            return 0;
        }
        return -1;
    }

    int ValidaLimite(int k) {
        if(k >= 0 && k <= F){
            return 1;
        } else {
            return 0;
        }
        return -1;
    }

    void InserirInicio(int VALOR) {
        if(ValidaInsercao()) {
            for(int i = F; i >= 0; i --) {
                Lista[i + 1] = Lista[i];     
            }
            Lista[0] = VALOR;
            F++;
        }
    }


    void InserirFim(int VALOR) {
        if(ValidaInsercao()){
            F++;
            Lista[F] = VALOR;
        }
        
    }

    void InserirKesimo(int VALOR, int k) {
        if(ValidaInsercao() && k >= 0 && k<=F +1) {
            for(int i = F; i >= k; i--){
                Lista[i+1] = Lista[i];
            }
            Lista[k] == VALOR;
            F++;
        }
    }

    int RemoverInicio() {
        if(ListaVazia()){
            return -1;
        }
        int VALOR = Lista[0];
        
        for (int i = 0; i < F; i++){
            Lista[i] = Lista[i+1];
        }
        F--;
        return VALOR;
    }

    int RemoverFim() {
        if(ListaVazia()){
            return -1;
        }
        int VALOR = Lista[F];
        F--;

        return VALOR;
        }

    int RemoverKesimo(int k) {
        if(ListaVazia() || !ValidaLimite(k)) {
                return -1;
        } 
        int VALOR = Lista[k];

        for (int i = k; i < F; i++){
            Lista[i] = Lista[i+1];
        }
        F--;

        return VALOR;
    }

    void MostrarLista() {
        if(ListaVazia()) {
            printf("Lista vazia\n");
            return;
        }
        printf("Lista [");

        for (int i = 0; i <= F; i++) {
            printf("%d", Lista[i]);

            if (i < F){
                printf(", ");
            }
        }
        printf("]\n");
    }
};

int main() {
    ClasseLista lista;
    int opcao;
    int valor;
    int k;
    int valorRemovido;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Inserir na posicao k\n");
        printf("4 - Remover do inicio\n");
        printf("5 - Remover do fim\n");
        printf("6 - Remover da posicao k\n");
        printf("7 - Mostrar lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o valor a inserir: ");
            scanf("%d", &valor);
            lista.InserirInicio(valor);
            lista.MostrarLista();
        } else if (opcao == 2) {
            printf("Digite o valor a inserir: ");
            scanf("%d", &valor);
            lista.InserirFim(valor);
            lista.MostrarLista();
        } else if (opcao == 3) {
            printf("Digite o valor a inserir: ");
            scanf("%d", &valor);
            printf("Digite a posicao k: ");
            scanf("%d", &k);
            lista.InserirKesimo(valor, k);
            lista.MostrarLista();
        } else if (opcao == 4) {
            valorRemovido = lista.RemoverInicio();
            printf("Valor removido: %d\n", valorRemovido);
            lista.MostrarLista();
        } else if (opcao == 5) {
            valorRemovido = lista.RemoverFim();
            printf("Valor removido: %d\n", valorRemovido);
            lista.MostrarLista();
        } else if (opcao == 6) {
            printf("Digite a posicao k: ");
            scanf("%d", &k);
            valorRemovido = lista.RemoverKesimo(k);
            printf("Valor removido: %d\n", valorRemovido);
            lista.MostrarLista();
        } else if (opcao == 7) {
            lista.MostrarLista();
        } else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}

    