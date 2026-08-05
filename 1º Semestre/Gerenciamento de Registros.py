dados = [0]*10
controle = [0]*10

opcao = -1

while opcao != 8:
    print("\n===== MENU =====")
    print("1 - Inserir valor")
    print("2 - Inserir valor em índice específico")
    print("3 - Remover valor")
    print("4 - Buscar valor")
    print("5 - Mostrar registros ativos")
    print("6 - Mostrar posições livres")
    print("7 - Mostrar conteúdo completo")
    print("8 - Sair")

    opcao = int(input('digite sua opção: '))

    if opcao == 1:
        valor = int(input('digite um valor: '))
        inserido = False

        for i in range(10):
            if controle[i] == 0:
                dados[i] = valor
                controle[i] = 1
                inserido = True
                print(f'\nvalor armazenado na posição {i}')
                break

        if not inserido:
            print('Armazenamento sem espaço disponivel.')

    elif opcao == 2:
        valor = int(input('valor a ser armazenado: '))
        indice = int(input('digite o indice: '))

        if indice < 0 or indice > 9:
            print('indice invalido')
        elif controle[indice]:
            print('Armazenamento já está sendo utilizado')
        else:
            dados[indice] = valor
            controle[indice] = 1
            print("Valor inserido com sucesso.")
    
    elif opcao == 3:
        valor = int(input('Digite o valor: '))
        encontrou = False

        for i in range(10):

            if dados[i] == valor and controle[i] == 1:
                
                controle[i] = 0
                encontrou = True

                print('Valor removido')
                break
        
        if not encontrou:
            print('valor não encontrado')

    elif opcao == 4:
        valor = int(input('digite o valor a ser buscado: '))
        encontrou = False
        
        for i in range(10):
            if dados[i] == valor and controle[i] == 1:
                print(f'Valor encontrado no indice {i}')
                encontrou = True
                break
            if not encontrou:
                print('Valor não encontrado')

    elif opcao == 5:

        print('Registros Ativos: ')
        
        for i in range(10):
            if controle[i] == 1:
                print(f'indice {i}: {dados[i]}')

    elif opcao == 6:
        
        print('Posições livres: ')

        for i in range(10):

            if controle[i] == 0:
                print(i)
    
    elif opcao == 7:

        print('Dados: ')
        print(dados)

        print('Controle: ')
        print(controle)

    elif opcao == 8:
        print('programa encerrado')

    else:
        print('Opção invalida')
