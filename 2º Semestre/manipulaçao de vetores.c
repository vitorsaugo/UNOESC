#include <stdio.h>

int N = 10;

void CadastrarVetor(int V[], int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &V[i]);
    }
}

void MostrarVetor(int V[], int N)
{
    int i;

    printf("\n--- Vetor ---\n");

    for (i = 0; i < N; i++)
    {
        printf("Posicao %d: %d\n", i, V[i]);
    }
}

int AlterarVetor(int V[], int N, int procurado, int novo)
{
    int i;
    int quantidade = 0;

    for (i = 0; i < N; i++)
    {
        if (V[i] == procurado)
        {
            V[i] = novo;
            quantidade++;
        }
    }

    return quantidade;
}

int main()
{
    int V[N];
    int procurado, novo;
    int quantidade;

    CadastrarVetor(V, N);

    MostrarVetor(V, N);

    printf("\nDigite o valor a ser procurado: ");
    scanf("%d", &procurado);

    printf("Digite o novo valor: ");
    scanf("%d", &novo);

    quantidade = AlterarVetor(V, N, procurado, novo);

    if (quantidade > 0)
    {
        printf("\nForam alteradas %d posicoes.\n", quantidade);
    }
    else
    {
        printf("\nO valor nao foi encontrado. Nenhuma posicao foi alterada.\n");
    }

    MostrarVetor(V, N);

    return 0;
}