skip = True

while True:
    if not skip:
        input()

    N = int(input())

    if N == 0:
        break

    if not skip:
        print('')

    skip = False

    candidato = [0] * (10**4 + 1)

    while N:
        N -= 1

        v = int(input())
        candidato[v] += 1

    maior = 0
    n_candidatos = 0

    for i in range(len(candidato)):
        if candidato[i] > candidato[maior]:
            maior = i;

        if candidato[i] != 0:
            n_candidatos += 1

    print("Mais votado foi {} com {} votos".format(maior, candidato[maior]))
    print("No total foram {} candidatos".format(n_candidatos))
