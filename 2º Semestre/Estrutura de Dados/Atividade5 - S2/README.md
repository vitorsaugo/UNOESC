ATIVIDADE 
Listas Simples usando vetores como estrutura de dados.

TESTE DE MESA

| Passo | Instrução executada      | i | Teste do laço | Efeito em Lista                  | F |
|-------|--------------------------|---|---------------|----------------------------------|---|
| 1     | VALOR ← Lista[k]         | — | —             | sem alterar (VALOR=22)           | 4 |
| 2     | i ← k                    | 0 | —             | sem alterar                      | 4 |
| 3     | teste do laço            | 0 | 0 < 4 → sim   | sem alterar                      | 4 |
| 4     | Lista[i] ← Lista[i+1]    | 0 | —             | [8, 50, 78, 78, 9, ...]          | 4 |
| 5     | i ← i+1                  | 1 | —             | sem alterar                      | 4 |
| 6     | teste do laço            | 1 | 1 < 4 → sim   | sem alterar                      | 4 |
| 7     | Lista[i] ← Lista[i+1]    | 1 | —             | [8, 50, 78, 78, 9, ...]          | 4 |
| 8     | i ← i+1                  | 2 | —             | sem alterar                      | 4 |
| 9     | teste do laço            | 2 | 2 < 4 → sim   | sem alterar                      | 4 |
| 10    | Lista[i] ← Lista[i+1]    | 2 | —             | [8, 50, 78, 78, 9, ...]          | 4 |
| 11    | i ← i+1                  | 3 | —             | sem alterar                      | 4 |
| 12    | teste do laço            | 3 | 3 < 4 → sim   | sem alterar                      | 4 |
| 13    | Lista[i] ← Lista[i+1]    | 3 | —             | [8, 50, 78, 9, 9, ...]           | 4 |
| 14    | i ← i+1                  | 4 | —             | sem alterar                      | 4 |
| 15    | teste do laço            | 4 | 4 < 4 → não   | laço encerra                     | 4 |
| 16    | F ← F-1                  | 4 | —             | sem alterar                      | 3 |

VALOR = 22
F = 3
Lista = [8, 50, 78, 9, 9, ...]

