#include <stdio.h>
#define TAMANHO 5

class ClasseFila {
private:

    int Fila[TAMANHO];
    int I;
    int F;

public:
    ClasseFila() {
        I = -1;
        F = -1;
    }

    int FilaVazia() {
        if(I == -1){
            return 1;
        } else {
            return 0;
        }
    }

    int FilaCheia() {

        if(FilaVazia()){
            return 0;
        }

        if(F == TAMANHO - 1 && I == 0){
            return 1;
        }

        if(F + 1 == I){
            return 1;
        }

        return 0;
    }

    void Insere(int VALOR) {

        if(FilaCheia()){
            printf("Erro! fila cheia!\n");
            return;
        }

        if(FilaVazia()){
            I = 0;
            F = 0;
        }
        else {
            if(F == TAMANHO - 1){
                F = 0;
            }
            else {
                F++;
            }
        }

        Fila[F] = VALOR;
    }

    int Remove() {

        if(FilaVazia()){
            printf("Erro! fila vazia!\n");
            return -1;
        }

        int VALOR = Fila[I];

        if(I == F){
            I = -1;
            F = -1;
        }
        else {
            if(I == TAMANHO - 1){
                I = 0;
            }
            else {
                I++;
            }
        }

        return VALOR;
    }

    int InicioFila() {

        if(FilaVazia()){
            printf("Erro! fila vazia!\n");
            return -1;
        }

        return Fila[I];
    }

    void MostrarFila() {

        if(FilaVazia()){
            printf("Fila vazia!\n");
            printf("I = %d\n", I);
            printf("F = %d\n", F);
            return;
        }

        int posicao = I;

        printf("Fila: ");

        while(true){

            printf("%d ", Fila[posicao]);

            if(posicao == F){
                break;
            }

            if(posicao == TAMANHO - 1){
                posicao = 0;
            }
            else {
                posicao++;
            }
        }

        printf("\n");
        printf("I = %d\n", I);
        printf("F = %d\n", F);
    }
};

int main() {

    ClasseFila fila;

    printf("1. Inserir 10\n");
    fila.Insere(10);
    fila.MostrarFila();

    printf("\n2. Inserir 20\n");
    fila.Insere(20);
    fila.MostrarFila();

    printf("\n3. Inserir 30\n");
    fila.Insere(30);
    fila.MostrarFila();

    printf("\n4. Consultar inicio\n");
    printf("Inicio: %d\n", fila.InicioFila());
    fila.MostrarFila();

    printf("\n5. Remover\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();

    printf("\n6. Remover\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();

    printf("\n7. Inserir 40\n");
    fila.Insere(40);
    fila.MostrarFila();

    printf("\n8. Inserir 50\n");
    fila.Insere(50);
    fila.MostrarFila();

    printf("\n9. Inserir 60\n");
    fila.Insere(60);
    fila.MostrarFila();

    printf("\n10. Inserir 70\n");
    fila.Insere(70);
    fila.MostrarFila();

    printf("\n11. Inserir 80\n");
    fila.Insere(80);
    fila.MostrarFila();

    printf("\n12. Remover\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();

    printf("\n13. Remover\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();

    printf("\n14. Remover\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();

    printf("\n15. Remover\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();

    printf("\n16. Remover\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();

    printf("\n17. Remover\n");
    printf("Removido: %d\n", fila.Remove());
    fila.MostrarFila();

    return 0;
}