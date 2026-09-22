#include <stdio.h>
#define TAMANHO 10

class ClassePilha {
private:
    int Pilha[TAMANHO];
    int Topo;
    
public:
    ClassePilha() {
        Topo = -1;
    }

    int PilhaVazia() {
        if(Topo == -1){
            return 1;
        }
        return 0;
    }

    int PilhaCheia() {
        if(Topo == TAMANHO -1){
            return 1;
        }
        return 0;
    }
    void Empilha(int VALOR) {
        if (PilhaCheia()) {
            printf("ERRO! PILHA CHEIA, Nao foi possivel empilhar %d\n", VALOR);
            return;
        }
        Topo = Topo + 1;
        Pilha[Topo] = VALOR;
}

    int Desempilha() {
    int valor;
        if (PilhaVazia()) {
            printf("Erro! Pilha vazia, nao foi possivel desempilhar.\n");
            return -1;
        }
        valor = Pilha[Topo];
        Topo = Topo - 1;
        return valor;
    }

    int TopoPilha() {
        if(PilhaVazia()){
            printf("pilha vazia! Nao ha topo para consultar.\n");
            return -1;
        }
        return Pilha[Topo];
    }
    void MostrarPilha() {
      if (PilhaVazia()) {
          printf("Pilha: [ vazia ]\n");
          return;
      }
        printf("Pilha: [ ");
        
        for (int i = 0; i <= Topo; i++) {
            printf("%d", Pilha[i]);
            if (i == Topo) {
                printf(" <- TOPO");
            } else {
                printf(", ");
            }
        }
        printf(" ]\n");
    }
};
int main() {
    ClassePilha pilha;
    int opcao;
    int valor;
    int valorRemovido;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Empilhar (push)\n");
        printf("2 - Desempilhar (pop)\n");
        printf("3 - Consultar o topo (sem remover)\n");
        printf("4 - Mostrar pilha\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o valor a empilhar: ");
            scanf("%d", &valor);
            pilha.Empilha(valor);
            pilha.MostrarPilha();
        } else if (opcao == 2) {
            valorRemovido = pilha.Desempilha();
            printf("Valor desempilhado: %d\n", valorRemovido);
            pilha.MostrarPilha();
        } else if (opcao == 3) {
            printf("Valor do topo: %d\n", pilha.TopoPilha());
        } else if (opcao == 4) {
            pilha.MostrarPilha();
        } else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
