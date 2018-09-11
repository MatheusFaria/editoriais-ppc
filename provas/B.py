n = int(input())

for i in range(n):
    line = input()

    pilha = []
    for c in line:
        if c in '{([':
            pilha.append(c)
        elif c in '})]':
            if len(pilha) == 0:
                print("Erro de compilacao")
                break

            if c == '}' and pilha[-1] == '{':
                pilha.pop()
            elif c == ']' and pilha[-1] == '[':
                pilha.pop()
            elif c == ')' and pilha[-1] == '(':
                pilha.pop()
            else:
                print("Erro de compilacao")
                break
    else:
        if len(pilha) == 0:
            print("Compilou")
        else:
            print("Erro de compilacao")
