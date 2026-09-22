/* ===========================================================
 * Atividade - Pilha Sequencial (baseada em vetor)
 * Esqueleto de codigo em C++ - ClassePilha
 *
 * Assim como fizemos com a ClasseLista, os dados (Pilha e Topo)
 * ficam DENTRO do objeto (atributos privados), e os metodos
 * NAO precisam receber Pilha/Topo por parametro - cada metodo
 * ja enxerga os atributos do proprio objeto que o chamou.
 *
 * Regras (lembrete da apostila):
 * - A pilha tem tamanho fixo de 10 posicoes (TAMANHO).
 * - Proibido usar recursao.
 * - Use apenas o que ja vimos em aula: vetores, lacos (for/while)
 *   dentro dos metodos. Sem alocacao dinamica, sem bibliotecas
 *   alem de cstdio.
 * - So se acessa o TOPO da pilha - nao existe "inserir/remover
 *   do meio" aqui (essa e a diferenca para a ClasseLista).
 * - Os metodos abaixo devem seguir exatamente as assinaturas e
 *   o comportamento descritos nos comentarios.
 * - O "main" ja esta pronto com o menu interativo - voce so
 *   precisa completar o corpo de cada metodo (onde esta escrito
 *   "TODO"). Nao altere as chamadas dentro do main.
 * =========================================================== */


1. Objetivo
Implementar, em C ou em Python, um TAD/POO de Pilha Sequencial (baseada em vetor de tamanho
fixo com 10 posições), com as operações estudadas nesta apostila: empilhar, desempilhar, consultar o
topo e verificar se a pilha está vazia ou cheia.

2. Regras
O vetor tem tamanho fixo de 10 posições (em Python, use uma lista comum, mas trate-a como
um vetor de tamanho fixo, controlando manualmente o índice Topo).
 Proibido usar métodos prontos de lista em Python (append, pop, insert, remove, del, extend, etc.),
a lógica deve ser escrita manualmente.
 Desenvolva em C OU em Python, não é necessário entregar nas duas linguagens (escolha uma).

Teste de Mesa
                          Pilha       Topo        Retorno
1 InicializaPilha         [  ]        -1          Topo = -1


2 Empilha(Pilha,10,Topo)  [10]         0          Topo = 0  


3 Empilha(Pilha,20,Topo)  [10,20]      1          Topo = 1


4 Empilha(Pilha,30,Topo)  [10,20,30]   2          Topo = 2


5 Topo Pilha(Pilha,Topo)  [10,20,30]   2          retorna 30(altera nada)


6 Desempilha(Pilha,&Topo) [10,20]      1          retorna 30  


7 Empilha(Pilha,40,Topo)  [10,20,40]   2          Topo = 2   


8 Desempilha(Pilha,&Topo) [10,20]      1          retorna 40


9 Desempilha(Pilha,&Topo) [10]         0          retorna 20


10 Desempilha(Pilha,&Topo)[]          -1          retorna 10


11 PilhaVazia(Topo)       []          -1          retorna 1


12 Desempilha(Pilha,&Topo)[]          -1          erro(pilha vazia)