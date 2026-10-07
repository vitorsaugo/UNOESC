#include <stdio.h>

#define TAMANHO 50

class ClasseFila {
private:

    char Fila[TAMANHO];
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
        }
        else {
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

    void Insere(char VALOR) {

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

    char Remove() {

        if(FilaVazia()){
            printf("Erro! fila vazia!\n");
            return '\0';
        }

        char VALOR = Fila[I];

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

    char InicioFila() {

        if(FilaVazia()){
            printf("Erro! fila vazia!\n");
            return '\0';
        }

        return Fila[I];
    }

    int Quantidade() {

        if(FilaVazia()){
            return 0;
        }

        if(F >= I){
            return F - I + 1;
        }

        return TAMANHO - I + F + 1;
    }
};


int main() {

    int n;

    while(scanf("%d", &n) && n != 0){

        ClasseFila fila;
        ClasseFila descartadas;

        for(int i = 0; i < n; i++){

            char carta;

            scanf(" %c", &carta);

            fila.Insere(carta);
        }

        while(fila.Quantidade() >= 2){

            char carta = fila.Remove();

            descartadas.Insere(carta);

            int quantidade;

            if(carta >= '0' && carta <= '9'){
                quantidade = 1;
            }
            else if(carta == 'P'){
                quantidade = 2;
            }
            else {
                quantidade = 0;
            }

            for(int i = 0; i < quantidade; i++){

                if(fila.Quantidade() <= 1){
                    break;
                }

                char mover = fila.Remove();

                fila.Insere(mover);
            }
        }

        printf("Cartas descartadas: ");

        int primeira = 1;

        while(!descartadas.FilaVazia()){

            char carta = descartadas.Remove();

            if(primeira){
                printf("%c", carta);
                primeira = 0;
            }
            else {
                printf(", %c", carta);
            }
        }

        printf("\n");

        printf("Carta restante: %c\n", fila.InicioFila());
    }

    return 0;
}