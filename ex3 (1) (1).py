vet1 = []
vet2 = []

n = int(input('digite um valor até 40: '))

while n > 40 or n <= 0:
    n = int(input('valor invalido. insira um valor entre 1 e 40: '))

contador = 1

for a in range(n):
    valor = int(input(f'Elemento {a}: '))

    while valor not in (0,1):
        valor = int(input('digite apenas 0 ou 1: '))

    vet1.append(valor)

for a in range (1,n):
    if vet1[a] == vet1[a-1]:
        contador += 1
    else:
        vet2.append(contador)
        contador = 1

vet2.append(contador)

if vet1[0] == 1:
    vet2.insert(0,0)

print(f'val 1: {vet1}')
print(f'val 2: {vet2}')