n = int(input())

for i in range(n):
    line = input()

    line1 = line.replace(' ', '')

    if line1 == line1[::-1]:
        words = line.split(' ')
        for j in range(len(words)//2 + len(words) % 2):
            if words[j] != words[j][::-1] or words[j] != words[-(j + 1)]:
                print("Frase palindromo")
                break
        else:
            print("Palindromo completo")
    else:
        print("Nada")
