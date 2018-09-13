# Contest 03 - Editorial

**Autores** : [Iuri Severo](https://github.com/iurisevero), [Leonardo Medeiros](https://github.com/leomedeiros1)

**Revisores**: [Matheus Faria](https://github.com/matheusfaria)

## CF80A - Panoramix's Prediction

[CF80A](http://codeforces.com/problemset/problem/80/A)

O ponto dessa questão está no limite atribuído para `N` e
`M`. Como ambos não podem passar de 50, a verificação se o
valor é primo ou não feito de modo bruto não consumiria muito
tempo. Então, para resolver bastava verificar se
M era primo mesmo e, se ele fosse, verificar se no intervalo `[N, M]`
não havia nenhum outro valor primo.

Outra solução, que pode ser adotada par várias questões que envolvem
números primos, é utilizar o [Crivo de Erastostenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes).
Quem tem uma ordem de complexidade baixa, e pré computa se o número é primo ou
não. Assim você poderia rodar o crivo, e checar se entre o número `N` e `M`
não havia nenhum outro primo.


## CF61A - Ultra-Fast Mathematician

[CF61A](http://codeforces.com/problemset/problem/61/A)

Nessa questão o input consiste em dois valores binários
de mesmo tamanho e pede como saída um valor que
represente a soma deles, onde 0 + 1 = 1 e 1 + 1 = 0.
Para solução podemos escanear o primeiro valor como
uma string e, a partir do tamanho dela, escanear os caracteres
do segundo valor e verificar se a saída deve ser 0 ou 1
comparando-os com os caracteres da string principal.
A saída pode ser feita por meio de um print direto ou da
criação de uma nova string para armazenar os valores
verificados

Outra solução, é utilizar o [bitset](https://github.com/MatheusFaria/TEP/blob/master/Introducao/STL.md#bitset),
que é uma estrutura que consegue fazer operações binárias: `&` (and), `|` (or), `^` (xor).
Estas operações são feitas bit a bit (também conhecido como `bitwise`). A operação
que estamos procurando, e a qual é descrita na questão, é a operação [xor](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) `^`,
que seja seguinte tabela

| A | B | A ^ B |
|:-:|:-:|:-----:|
| 0 | 0 |   0   |
| 0 | 1 |   1   |
| 1 | 0 |   1   |
| 1 | 1 |   0   |


Para imprimir o resultado do bitset, basta converter eles para string: `(b1 ^ b2).to_string()`.


## CF233A - Perfect Permutation

[CF233A](http://codeforces.com/problemset/problem/233/A)

Nessa questão se tem diversas condições para criação de
uma sequência e ela pede para verificar se é possível ou não
criar essa sequência a partir de um tamanho `N` e, se possível,
printar a sequência criada.

A partir dos exemplos pode-se verificar que para `N = 1`, a
sequência é inválida, para `N = 2` temos `[2, 1]` e para `N = 4` temos
`[2, 1, 4, 3]`. Nesse momento um padrão já começa a ser
apresentado, onde um valor impar resulta em uma sequência
inválida e dois valores pares consecutivos resultam em
sequências formadas por `[A1, A1-1, B1, B1-1]`.

Aumentando a sequência 1 por 1, resolvendo os pré-requisitos
manualmente, verificamos que:

```
N = 1, sequência impossível;
N = 2, [2, 1];
N = 3, sequência impossível;
N = 4, [2, 1, 4, 3];
N = 5, sequência impossível;
N = 6, [2, 1, 4, 3, 6, 5];
```

Seguindo o padrão encontrado podemos deduzir que:

```
N = 99, sequência impossível;
N = 100, [2, 1, 4, 3, ..., 100, 99];
```

E que os pré-requisitos estabelecem que toda sequência com
`N % 2 == 1` é impossível e para as sequência possíveis temos os
valores começando em `A = 2`, seguido por `A - 1` e fazendo a
sequência com `A += 2`.

As sequências `N % 2 == 1` são impossíveis, pois não é possível dispor os números
de forma que você obedeça as restrições. Por exemplo, `N = 3` os valores que
a sequência pode possuir são `[1, 2, 3]`. Para que `P(P(i)) == i` (1) e `P(i) != i` (2), temos
que trocar `1` e `2` de lugar, porém fazendo isso o `3` quebra a condição 2.
Se trocar `1` e `3` de lugar, o `2` quebra a condição 2. Se trocarmos todos
de posição, por exemplo `[3, 1, 2]`, todos quebram a condição 1. Então
dada uma sequência de tamanho impar, é impossível cumprir as condições.


## CF144A - Arrival of the General

[CF144A](http://codeforces.com/problemset/problem/144/A)

Um meio de solucionar o problema é marcar a posição do
menor soldado e a do maior, após isso ver quantos
movimentos gastaria para ir do soldado menor até o final da
fila, subtraindo o tamanho da fila pela posição, e o mesmo para
o soldado maior, que gastará a posição de movimentos para
chegar ao início. Ficando atento ao fato de que se o soldado
maior estiver numa posição mais a frente do soldado menor,
deve-se subtrair 1 dos movimentos, devido ao fato de nos dois
cálculos considerarem o movimento de troca entre o maior e o
menor soldado.


## CF200B - Drinks

[CF200B](http://codeforces.com/problemset/problem/200/B)

Média simples entre os valores. Trabalhe com número inteiros para fazer
a soma total, e apenas na divisão final use double.

## CF148A - Insomnia cure

[CF148A](http://codeforces.com/problemset/problem/148/A)

Este problema trabalha com a ideia de múltiplos, a pergunta principal é
quantos múltiplos de `k` ou `l` ou `m` ou `n` existem em `[1, d]`? Para
descobrir basta percorrer `[1, d]`, e perguntar se o número `i` é múltiplo
de algum dos `k l m n`, caso seja contabilize. Ao fim apresente o total
de números que obedecem a condição.


## CF248A - Cupboards

[CF248A](http://codeforces.com/problemset/problem/248/A)

Neste problema você deve contabilizar quantas portas fechadas `fd` e abertas `ad`
existem na direita, e na esquerda, `fe` e `ae`. A quantidade minima de tempo
vai ser a soma dos valores que tiverem menos quantidade de cada lado,
ou seja, `min(fe, ae) + min(fd, ad)`.

Este calculo dá certo pois a quantidade minima de movimentos que você irá precisar
fazer de cada lado, será a menor quantidade de porta fechada ou aberta.

## CF155A - I\_love\_%username%

[CF155A](http://codeforces.com/problemset/problem/155/A)

Nessa questão, uma das formas de solução seria criar
duas variáveis auxiliares, uma para guardar o maior score e
outra para guardar o menor score. Definir o valor inicial delas
como sendo o primeiro valor escaneado e após isso ir
verificando se os próximos valores eram maiores ou menores e
após a verificação, caso válida para um dos casos, somar 1 em
uma variável com função de contador e atualizar o valor do
auxiliar, sendo ele o maior ou o menor valor a partir daquele
instante.


## CF746C - Tram

[CF746C](http://codeforces.com/problemset/problem/746/C)

Nesta questão você deve utilizar operações matemáticas para descobir qual a opção
mais rápida. Se o menino ter uma velocidade maior que a do trem, `t2 > t1`,
então ir a pé será sempre a melhor opção. O tempo gasto indo a pé pode
ser calculado por `|x2 - x1| * t2`.

Caso o trem seja mais rápido que o menino, então deve se checar a opção mais
rápida. Caso o menino vá pegar o trem, não importa em qual estação ele vai esperar,
porque o trem sempre vai demorar um tempo `T` para chegar no ponto final. Para calcular
o tempo que o trem demorará para chegar no ponto final, primeiro deve se descobrir
o tempo que ele leva para chegar no ponto inicial. Isto deve ser feito levando
em consideração que o trem e o menino podem estar em direções opostas.

Veja o [editorial original](http://codeforces.com/blog/entry/49160)


## CF399A - Helpful Maths

[CF399A](http://codeforces.com/problemset/problem/339/A)

O ponto principal dessa questão esta na maneira de
escanear. Utilizando um `scanf("%d%c")` dentro de um loop,
você conseguiria escanear os valores, remover o `+` e, no
momento que o `%c` fosse igual a `\n`, parar loop.

Os valores escaneados pelo `%d` podem ser colocados em
um `vector<int>` que depois seria ordenado pela função `sort`.


## CF288A - Is your horseshoe on the other hoof?

[CF288A](http://codeforces.com/problemset/problem/228/A)

Nessa questão uma possível solução seria escanear os valores, inserí-los em
um [set](https://github.com/MatheusFaria/TEP/blob/master/Introducao/STL.md#set) e após
isso subtrair 4 do tamanho do set. O valor absoluto do resultado seria igual a quantidade de
sapatos repetidos.

Outra solução era ler os 4 valores em um array ou vector, ordernar este array,
e fazer uma contagem de quantos elementos eram iguais ao elemento anterior.


## CF71A - Way Too Long Words

[CF71A](http://codeforces.com/problemset/problem/71/A)

Para resolver esse problema era possível utilizar o tipo
string, escanear a palavra e com a função `.size()` determinar se
ela é muito grande ou não.
Caso ela fosse, era possível fazer o print do seguinte
modo:
`cout << w[0] << w.size() - 2 << w[w.size() - 1] << endl;`


## CF236A - Boy or Girl

[CF236A](http://codeforces.com/problemset/problem/236/A)

Nessa questão era possível utilizar um `set<char>` para
guardar os caracteres do nome sem chance deles se repetirem
e, após isso, com o operador de módulo (`%`) verificar se havia
uma quantidade ímpar ou par de letras.

Outra solução é usar um array onde cada posição é uma letra, por exemplo,
`0` é o `a`, `1` o `b`, e assim por diante. Para converter
o `char` em indice do array, você pode fazer `c - 'a'`, esta operação
vai retornar o indice correto. Feito isso você deve contabilizar no array,
toda ocorrencia de cada caractere, ou seja, `histogram[c - 'a']++`. Ao fim
você percorre o array vendo quantas posições são diferentes de zero.


## CF141A - Amusing Joke

[CF141A](http://codeforces.com/problemset/problem/141/A)

Como na questão `CF236A`, é possível fazer um histograma das duas primeiras
palavras. Onde cada letra é convertida para um indice do array `c - 'A'`,
e contabilizada `histogram[c - 'A']++`. Você deve utilizar o mesmo histograma
para todas as palavras, só que na última ao invés de incrementar a ocorrencia,
você vai decrementar `histogram[c - 'A']--`. Assim se ao fim de tudo, você
percorrer o seu histograma e alguma posição não estiver zerada, a resposta
é "NO".

O pensamento por trás dessa solução é contabilizar a ocorrencia das letras
nas duas primeiras palavras, e ver se a mesma ocorrencia acontece na segunda palavra.


## CF151A - Soft Drinking

[CF151A](http://codeforces.com/problemset/problem/151/A)

O mais difícil dessa questão é a interpretação dela. São
muitas variáveis e muitos cálculos internos antes de começar a
solução em si.

Após organizar cada parte do drink corretamente,
separando a quantidade de drinks que eram possíveis fazer
com base na quantidade de garrafas, a quantidade de fatias de
limão (e não de limões inteiros) e quantos drinks podiam ser
feitos com base na quantidade de sal, bastava pegar o menor
valor entre os 3 e dividir pela quantidade de amigos.


## CF133A - HQ9+

[CF133A](http://codeforces.com/problemset/problem/133/A)

Nessa questão bastava escanear a string e verificar se
alguma das letras dela era `H`, `Q` ou `9`, caso fosse, o print era
positivo, caso não, negativo.

## CF112A - Petya and Strings

[CF112A](http://codeforces.com/problemset/problem/112/A)

Nesse problema, uma das formas de solução é deixar
todas letras escaneadas minúsculas e depois comparar as
strings.


## CF231A - Team

[CF231A](http://codeforces.com/problemset/problem/231/A)

Nessa questão, para verificar se o problema seria
solucionado, bastava somar a linha escaneada e, se a soma
resultasse em um valor `<= 2`, incrementar um contador de
"problemas solucionados", após todas linhas escaneadas, o
contador teria a quantidade de problemas solucionados pelo
trio.


## CF282A - Bit++

[CF282A](http://codeforces.com/problemset/problem/282/A)

Um jeito para solucionar esse exercício era dar
maior atenção para o segundo caractere da string escaneada.
Como as possibilidades de string são `++X`, `X++`, `--X` ou `X--`,
o segundo caractere da string ou será `+` ou `-`, indicando assim a
operação que deverá ser realizada.

## CF227B - Effective Approach

[CF227B](http://codeforces.com/problemset/problem/227/B)


