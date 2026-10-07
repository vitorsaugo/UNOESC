# Jogando Cartas Coloridas Fora

Inspirado no problema **1110 do beecrowd** e no jogo UNO.

## Descrição

Um grupo de amigos criou uma brincadeira solitária com as cartas de um jogo no estilo UNO.

Eles formam um monte com `n` cartas, onde a primeira carta está no topo e a última está na base.

Enquanto houver **2 ou mais cartas** no monte, a seguinte operação é realizada:

1. A carta do topo é jogada fora e vai para o descarte.
2. Dependendo da carta descartada, algumas cartas do topo são movidas, uma a uma, para a base do monte.

### Regras

| Carta descartada     | Cartas movidas para a base |
| -------------------- | -------------------------: |
| Numérica (`0` a `9`) |                          1 |
| `P` (Pular)          |                          2 |
| `C` (Coringa)        |                          0 |

As cores das cartas não interferem na brincadeira. Cada carta é representada apenas pelo seu símbolo.

### Exemplo

Para o monte:

```text
5 1 2 3
```

A carta `5` é descartada.

Como `5` é uma carta numérica, uma carta do topo (`1`) é movida para a base:

```text
2 3 1
```

A próxima carta descartada será `2`.

O monte funciona como uma **fila**:

* A carta do topo é removida do início;
* As cartas movidas são inseridas no final.

Se restar apenas uma carta no monte, ela não é mais movimentada.

## Entrada

A entrada contém vários casos de teste.

Cada caso começa com uma linha contendo um inteiro `n`:

```text
2 ≤ n ≤ 50
```

Na linha seguinte são informadas as `n` cartas, do topo para a base, separadas por espaços.

Cada carta pode ser:

* Um dígito de `0` a `9`;
* `P`, representando **Pular**;
* `C`, representando **Coringa**.

A entrada termina quando for informado:

```text
0
```

Esse caso não deve ser processado.

## Saída

Para cada caso de teste, devem ser impressas duas linhas.

A primeira deve apresentar as cartas descartadas, na ordem em que foram retiradas:

```text
Cartas descartadas: 
```

As cartas devem ser separadas por uma vírgula e um espaço.

A segunda linha deve apresentar a carta que permaneceu no monte:

```text
Carta restante: 
```

Não devem existir espaços extras no início ou no final das linhas.

## Exemplo de Entrada

```text
7
1 2 3 4 5 6 7
8
3 P 7 C 0 P 2 9
6
C 4 C 8 P 1
2
P 3
0
```

## Exemplo de Saída

```text
Cartas descartadas: 1, 3, 5, 7, 4, 2
Carta restante: 6
Cartas descartadas: 3, 7, 0, 2, P, 9, P
Carta restante: C
Cartas descartadas: C, 4, 8, 1, P
Carta restante: C
Cartas descartadas: P
Carta restante: 3
```

## Funcionamento do exemplo com `P` e `C`

Considere o seguinte monte:

```text
3 P 7 C 0 P 2 9
```

O funcionamento das rodadas é:

| Rodada | Monte antes       | Descartada | Cartas movidas para a base | Monte depois    |
| ------ | ----------------- | ---------- | -------------------------- | --------------- |
| 1      | `3 P 7 C 0 P 2 9` | `3`        | `P`                        | `7 C 0 P 2 9 P` |
| 2      | `7 C 0 P 2 9 P`   | `7`        | `C`                        | `0 P 2 9 P C`   |
| 3      | `0 P 2 9 P C`     | `0`        | `P`                        | `2 9 P C P`     |
| 4      | `2 9 P C P`       | `2`        | `9`                        | `P C P 9`       |
| 5      | `P C P 9`         | `P`        | `C` e `P`                  | `9 C P`         |
| 6      | `9 C P`           | `9`        | `C`                        | `C P`           |
| 7      | `C P`             | `C`        | nenhuma                    | `P`             |

A sequência de cartas descartadas será:

```text
3, 7, 0, 2, P, 9, P
```

E a carta restante será:

```text
C
```

## Estrutura utilizada

O problema pode ser resolvido utilizando uma **fila (queue)**, pois o comportamento do monte segue o princípio:

**FIFO — First In, First Out**

Ou seja:

* A carta que está no início da fila é descartada;
* As cartas movidas para a base são inseridas no final da fila.

Em C++, a estrutura `queue` da **STL (Standard Template Library)** pode ser utilizada para representar o monte.
