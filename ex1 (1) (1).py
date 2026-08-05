vet1 = []
vet2 = []
resultado = []

print('VALORES DE X: ')
for a in range(1,11):
    print(f'VALOR {a}')
    vet1.append(int(input(f'X: ')))

print('VALORES DE Y: ')
for a in range(1,11):
    print(f'VALOR {a}')
    vet2.append(int(input(' Y: ')))

for a in vet1:
        if a in vet2 and a not in resultado:
            resultado.append(a)


print(f'VETOR DE X: {vet1}')
print(f'VETOR DE Y: {vet2}')
print(f'RESULTADO: {resultado}')