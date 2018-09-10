# Contest 01 - Editorial

**Autores** : [Matheus Faria](https://github.com/matheusfaria)

## URI1001 - Extremamente Básico

[URI1001](https://www.urionlinejudge.com.br/repository/UOJ_1001.html)

Esta questão é composta por uma soma simples, o que deveria ser obervado
com mais cuidade é a formatação da saída que deveria ser `X = 10`, onde
`10` representa o resultado de uma soma.

## URI1866 - Conta

[URI1866](https://www.urionlinejudge.com.br/repository/UOJ_1866.html)

Nesta questão, pode ser utilizada [a leitura de casos de testes](https://github.com/MatheusFaria/TEP/blob/master/Introducao/introducao.md#parada-pelo-n%C3%BAmero-de-casos)
citado na aula, em conjunto com um teste de paridade. Ou seja, caso o número
fosse impar o resultado seria `1`, caso o número fosse par o resultado seria
`0`. Para execução do teste de paridade, você pode utilizar o operador
de módulo `%`.

## URI1021 - Notas e Moedas

[URI1021](https://www.urionlinejudge.com.br/repository/UOJ_1021.html)

Nesta questão, para evitar trabalhar com número fracionário, o melhor jeito para
a leitura era:

```cpp
scanf("%d.%d", &reais, &centavos);
```

Quando se tem duas unidades de medida, sempre se trabalha com a menor unidade
para evitar o uso de números fracionários. Então os reais deveriam ser convertidos
em centavos, e o total seria `total = reais * 100 + centavos`.

Como a unidade de trabalho agora são os centavos você deve prestar atenção
para descobrir quantas notas deveriam haver, fazendo a devida conversão.
Então `5 reais` passam a ser `500 centavos`.

O problema central se trata de descobrir quantas notas de `X reais` cabem
no valor total. Para descobrir isso você pode utilizar a divisão inteira, por
exemplo, se você tem `57673 centavos` e divir por `10000 centavos`, você teria o número
`5`, que no caso representa `5 notas` de `100.00 reais`. Para o cálculo das
outras quantias, você não iria considerar o valor total, você deveria considerar
o valor descontando as `5 notas` de `100`. Para fazer isso há duas formas:

1. você subtrai as notas do total `total -= 5 * 10000`, tendo como resultado `total = 7673`
1. você utiliza o operador de módulo para saber o resto da divisão, ou seja,
`57673 / 10000 = 5` logo `57673 % 10000 = 7673`

O pensamento deve ser repetir para todos os valores de notas e moedas.

## URI1198 - O Bravo Guerreiro Hashmat

[URI1198](https://www.urionlinejudge.com.br/repository/UOJ_1198.html)

Nesta questão, você deve fazer a [leitura até o EOF](https://github.com/MatheusFaria/TEP/blob/master/Introducao/introducao.md#end-of-file-eof).
Apesar de parecer simples a questão exige que você conheça os limites dos tipos
na linguagem `C++`, porque o enunciado da entrada te explica que os números
não irão exceder `2**32`. O tipo `int`, sem modificadores, consegue representar
todos os números de `-2**31` até `2**31 - 1`. Isso significa que para usar o
tipo `int` na questão, você deveria modifica-lo, para isso você tem
duas opções:

1. `unsigned int` cujo o limite de representação é `[0, 2**32]`, ou seja,
ele não representa números negativos
1. `long long int` cujo o limite de representação é `[-2**63, 2**63 - 1]`

Após a leitura você deveria fazer a subtração absoluta dos exércitos, ou seja,
não poderia dar negativo. Caso você tivesse escolhido o tipo `unsigned int`
para representar seu dado, você deveria tomar cuidado com a ordem da subtração,
pois como o `unsigned int` não representa os números negativos ele não chegaria
a resposta correta.

Agora, caso você tenha escolhido o tipo `long long int`, a subtração final,
caso negativa, poderia ser multiplicada por `-1`.

## URI2057 - Fuso Horário

[URI2057](https://www.urionlinejudge.com.br/repository/UOJ_2057.html)

Nesta questão, você deve ler os três valores e somar eles. Porém
ao somar, você pode obter um número negativo ou um número maior que 23. Para
contornar isso, você pode utilizar o operador de módulo `%` (resto da divisão).

Toda operação em que você quer que fique fechada em um ciclo de número, pode
ser feita com o operador de módulo, porque ele sempre vai estar te informando
o resto da divisão por `N`, que sempre irá variar de `0`, quando o número é
múltiplo de `N`, a `N - 1`. Por exemplo:

```
0 % 3 = 0
1 % 3 = 1
2 % 3 = 2
3 % 3 = 0
4 % 3 = 1
5 % 3 = 2
6 % 3 = 0
7 % 3 = 1
8 % 3 = 2
9 % 3 = 0
```

Como pode ser visto acima, os números variam de `0` a `2`, como dito anteriormente.
Outra propriedade que pode se perceber, é que caso você some um múltiplo de `N`
ao número `A`, ou seja, `(A + x) % N = y`, você vai obter o mesmo resultado
que `A % N = y`, ou seja, `(A + x) % N = A % N`.

```
(0 + 3) % 3 = 0
(1 + 6) % 3 = 1
(2 + 9) % 3 = 2
(3 + 6) % 3 = 0
(4 + 9) % 3 = 1
(5 + 3) % 3 = 2
(6 + 3) % 3 = 0
(7 + 6) % 3 = 1
(8 + 9) % 3 = 2
(9 + 3) % 3 = 0
```

Tendo estas duas propriedades em mente, a questão pede que o horário esteja
dentro do intervalo `[0, 23]`. Para resolver o problema do horário ultrapassar
as 23 horas, podemos usar o `%`, por exemplo `horario % 24`. Agora para
resolver o problema da hora negativa, precisamos colocar deixa o horário
positivo antes de fazer a operação de módulo. Para isso, podemos somar
um múltiplo de `24` para deixar o horário positivo e não afetar no
resultado final, por exemplo, `(horario + 24) % 24`.


## URI1238 - Combinador

[URI1238](https://www.urionlinejudge.com.br/repository/UOJ_1238.html)

Nesta questão, você pode fazer a [leitura de N-casos de teste](https://github.com/MatheusFaria/TEP/blob/master/Introducao/introducao.md#parada-pelo-n%C3%BAmero-de-casos). Para ler as `strings` em C++ você pode utilizar duas variáveis do
tipo `string` e usar o `cin` pra ler ambas, por exemplo, `cin >> p1 >> p2;`.
Para combinar as strings em uma só você pode percorrer ambas as strings
até chegar na menor delas. Chegando ao fim da menor você vai se encontrar
em uma das seguintes situações:

1. Ambas as strings são do mesmo tamanho, ou seja, chegando no fim de uma
você chega no fim da outra também.
1. Uma string é maior que a outra, ou seja, a maior string ainda vai ter letras
a serem percorridas.

Caso você esteja na primeira situação, você não precisa fazer mais nada
após o primeiro loop de impressão. Agora caso você esteja na segunda opção
deve-se terminar de percorrer a maior string do ponto onde parou até o final. O
ponto onde parou vai ser exatamente o tamanho da menor string.

Percorrer uma string em C++, é semelhate a percorrer uma string em C. Segue o
exemplo:

```cpp
for(int i = 0; i < p1.size(); ++i) {
    cout << p1[i] << " ";
}
```

A string em C++ também possui o operador `[]` de acesso, onde você informa,
de `0..N - 1`, a posição da string que quer acessar. E para saber o tamanho
você pode utilizar o método `.size()` da string para saber o tamanho da sua
string.
