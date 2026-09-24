*Atividade Avaliativa - URNA ELETRONICA*
O Brasil é referência mundial em votação eletrônica, e por trás de cada urna existem exatamente os
elementos que estudamos nesta disciplina: botões de entrada, um display de saída, um sinal sonoro
de confirmação e regras rígidas de controle de acesso. Neste trabalho, cada grupo implementará
uma urna eletrônica simplificada para 4 candidatos usando o Arduino Uno, em que o voto é dado
por botões, exibido em um display LCD 16×2 e confirmado por um buzzer — com a vota

*Visão geral do sistema*
Os quatro candidatos são Pedro, Paulo, João e Maria, com um botão para cada um, ligado às
entradas A2 a A5 do Arduino (usadas como pinos digitais). O LCD opera em modo 4 bits e o buzzer
fica em um pino digital livre. A Figura 1 mostra o esquema de referência — os rótulos dos botões na
figura são meramente ilustrativos; no código, use os nomes dos candidatos definidos aqui.


*Requisitos funcionais*
RF01 — Ao ligar, o sistema inicializa a comunicação serial (9600 bps) e o LCD, exibindo uma
mensagem de urna bloqueada (ex.: “Aguardando mesário”).
RF02 — A votação inicia bloqueada. O mesário libera um voto enviando a senha “Vote” pelo monitor
serial.
RF03 — Com a senha correta, o sistema libera exatamente um voto e o LCD indica “Votação
liberada”.
RF04 — O eleitor vota pressionando o botão do seu candidato; o sistema incrementa o total daquele
candidato.
RF05 — Após o voto, o LCD exibe o nome do candidato votado por alguns segundos e o buzzer emite
o som de “voto confirmado”.
RF06 — Qualquer pressionamento de botão sem nova liberação deve ser ignorado — cada senha
“Vote” vale um único voto (1 eleitor = 1 voto).
RF07 — A qualquer momento, o comando “Display” pelo serial apresenta a apuração parcial no LCD:
cada candidato com seu número de votos (alternando telas, já que são 4 candidatos em 2 linhas).
RF08 — O comando “Fim” encerra a votação: o sistema exibe o resultado final com o vencedor e não
aceita mais votos nem liberações.
RF09 — Senhas ou comandos incorretos devem ser rejeitados com um aviso pelo monitor serial, sem
travar o sistema.
RF10 — O código deve ser organizado em funções, com constantes para os pinos e comentários
explicando as decisões.

*LINK DO PROJETO TINKERCAD*
https://www.tinkercad.com/things/iX1T9qW4a8W-amazing-kup?sharecode=-GG-okcaLsiQ3v4Yiir33OIkIGFibkqp07gEprV4X1M