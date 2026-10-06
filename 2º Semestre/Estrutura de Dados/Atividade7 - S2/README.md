/* ===========================================================
 * Atividade - Fila Circular (baseada em vetor)
 * Esqueleto de codigo em C++ - ClasseFila
 *
 * Assim como fizemos com a ClasseLista e a ClassePilha, os dados
 * (Fila, I e F) ficam DENTRO do objeto (atributos privados), e
 * os metodos NAO precisam receber Fila/I/F por parametro - cada
 * metodo ja enxerga os atributos do proprio objeto que o chamou.
 *
 * Regras (lembrete da apostila):
 * - A fila tem tamanho fixo de 5 posicoes (TAMANHO) - pequeno
 *   de proposito, para que o "dar a volta" apareca logo.
 * - Proibido usar recursao.
 * - Use apenas o que ja vimos em aula: vetores, lacos (for/while)
 *   e if/else dentro dos metodos. 
 * - Insere SEMPRE no fim (F) e remove SEMPRE do inicio (I) -
 *   nao existe "inserir/remover do meio" aqui.
 * - Fila CIRCULAR: quando I ou F estiver na ultima posicao
 *   (TAMANHO - 1) e precisar avancar, ele volta para 0.
 * - Os metodos abaixo devem seguir exatamente as assinaturas e
 *   o comportamento descritos nos comentarios.
 * =========================================================== */

/* ===========================================================
 ### TESTE DE MESA

 ### Sequência e resultados esperados

| Passo | Operação | Resultado esperado (início → fim) | I | F |
|:-----:|----------|-----------------------------------|:-:|:-:|
| 1 | Inserir 10 | 10 | 0 | 0 |
| 2 | Inserir 20 | 10 20 | 0 | 1 |
| 3 | Inserir 30 | 10 20 30 | 0 | 2 |
| 4 | Consultar início | Mostra 10 (a fila não muda) | 0 | 2 |
| 5 | Remover | Removido 10 → 20 30 | 1 | 2 |
| 6 | Remover | Removido 20 → 30 | 2 | 2 |
| 7 | Inserir 40 | 30 40 | 2 | 3 |
| 8 | Inserir 50 | 30 40 50 | 2 | 4 |
| 9 | Inserir 60 | 30 40 50 60 (F deu a volta) | 2 | 0 |
| 10 | Inserir 70 | 30 40 50 60 70 (fila cheia) | 2 | 1 |
| 11 | Inserir 80 | Erro: fila cheia; fila inalterada | 2 | 1 |
| 12 | Remover | Removido 30 → 40 50 60 70 | 3 | 1 |
| 13 | Remover | Removido 40 → 50 60 70 | 4 | 1 |
| 14 | Remover | Removido 50 → 60 70 (I deu a volta) | 0 | 1 |
| 15 | Remover | Removido 60 → 70 | 1 | 1 |
| 16 | Remover | Removido 70 → fila vazia | -1 | -1 |
| 17 | Remover | Erro: fila vazia, sem quebrar o programa | -1 | -1 |

### Resultado obtido

Todos os 17 passos foram executados e conferem
=========================================================== */