# Contest 01 - Editorial

## URI2139 - Natal de Pedrinho

[URI2139](https://www.urionlinejudge.com.br/repository/UOJ_2139.html)

Neste problema podia se usar a linguagem Python, que já possui uma [biblioteca
de calendário](https://github.com/MatheusFaria/TEP/blob/master/Introducao/introducao.md#python-como-ferramenta).
Com esta biblioteca, bastava fazer a subtração das datas para saber quantos dias
faltavam até o natal.
Lembre-se que o ano pedido pela questão é o ano de 2016, que é bissexto. A parte
da leitura dos dados, devia ser feita até o [EOF](https://github.com/MatheusFaria/TEP/blob/master/Introducao/introducao.md#io-no-python).
Já saída poderia usar o `format`, da seguite forma `print("Faltam {} dias para o natal!".format(x))`

## URI1234 - Sentença Dançante

[URI1234](https://www.urionlinejudge.com.br/repository/UOJ_1234.html)

Neste problema deve ser utilizada a [leitura por de linha com o getline](https://github.com/MatheusFaria/TEP/blob/master/Introducao/introducao.md#leitura-de-strings),
para poder capturar a linha toda com espaços. Então deve-se converter cada caractere
da linha que não fosse espaço, para forma maiuscula ou minuscula. Para saber
se um caractere é maiusculo, você pode fazer essa operação
`'A' <= c && c >= 'Z'`, neste caso você está checando se o caractere `c` está
entre `[A, Z]`, ou seja, se é uma letra maiuscula.

Para converter o caractere `c` para minusculo você pode fazer a seguinte operação.
`c = c - 'A' + 'a'`, desta forma você utiliza do fato que o caractere `c`, sendo
do tipo `char`, também é representado com um número, sendo o número, a linha da
tabela ASCII que este caractere ocupa. Deste modo a expressão `c = c - 'A' + 'a'`,
pode ser interpretada assim `c = c - 65 + 97`, já que `A` esta na linha `65` e
`a` esta na linha `97`.

O mesmo pensamento pode ser aplicado na conversão de maiusculo para minusculo.


## URI1984 - O Enigma do Pronalândia

[URI1984](https://www.urionlinejudge.com.br/repository/UOJ_1984.html)

Neste problema você deve ler uma string, no caso como é uma linha
sem espaços e apenas uma palavra, você pode ler normalmente: `cin >> palavra;`
ou `scanf("%s", palavra);`.

Após isto você deve usar a função de [reverse](https://github.com/MatheusFaria/TEP/blob/master/Introducao/STL.md#algoritmos-de-modifica%C3%A7%C3%A3o)
para inverter a string. E imprimir o resultado.


## URI1259 - Pares e Ímpares

[URI1259](https://www.urionlinejudge.com.br/repository/UOJ_1259.html)

Neste problema você deve ler os números em dois `vector` diferentes,
um vai guardar os números pares e o outro os impares. O `vector` de números
pares deve ser ordenado com a função [sort](https://github.com/MatheusFaria/TEP/blob/master/Introducao/STL.md#algoritmos-de-ordena%C3%A7%C3%A3o).

Já os impares poderia ser ordenados de duas formas para ficarem em ordem descrescente:

1. Impares negativos: antes de adiconar o número do `vector` você poderia
adicionar o número negativo `v_impar.push_back(-x)`. Assim quando você
utilizasse a função `sort`, os números iriam ficar na ordem crescente, porém
como todos os números eram negativos, eles estariam em ordem descrescente
ao remover o sinal. Para remover o sinal, basta fazer-lo na impressão
`cout << -x << "\n";`

1. Greater: você pode adicionar os números no `vector` de impares normalmente,
e ao utilizar o `sort` você informa que a ordem será descrescente, da seguinte
forma `sort(v.begin(), v.end(), greater<int>())`. A função `greater<int>`,
vai fazer com que a ordem do `sort` mude para descrescente.


## URI1062 - Trilhos

[URI1062](https://www.urionlinejudge.com.br/repository/UOJ_1062.html)

Neste problema você deve analisar se é possível o trem se reorganizar, sendo
que ele te dá a ordem final, e a ordem inicial é a ordem `1..N`. Para isso
você deve entender a ordem em que os vagões entram e saem da estação.

- Os vagões sempre irão entrar na ordem `1..N`, onde `1` é o primeiro vagão a chegar na
estação e `N` é o último.
- Os vagões saem da estação na ordem de uma [pilha](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)),
ou seja, o último vagão que entrou é o primeiro a sair. Por exemplo, se entrarem os vagões `1 2 3` na estação,
a ordem de saída será `3 2 1`.

**Analisando as entradas**

`5 4 3 2 1`, nesta entrada todos os vagões entram na estação (`1 2 3 4 5`),
 e depois saem, seguindo a ordem da pilha.

`1 2 3 4 5`, nesta entrada o primeiro vagão (`1`) entra, e logo depois ele sai.
Depois o segundo vagão (`2`) entra, e logo depois sai. E assim por diante,
cada vagão entra e sai da estação. Assim eles saem na ordem correta.

`5 4 1 2 3`, nesta entrada a organização mais próxima seria, todos os vagões entram
na estação, e depois saem, respectivamente, o `5` e `4`. Porém o resto da ordem
pedida não é possível de ser feita, pois o próximo vagão que pode sair é `3`,
e a ordem pedida está esperando o `1`. Por isto neste caso não é possivel colocar
os vagões na ordem pedida.

`1 3 2 5 4 6`, nesta entrada o primeiro vagão (`1`) entra, e logo depois ele sai.
Depois os vagões `2 3` entram, e sai o `3` e depois o `2`. Então entram os
vagões `4 5`, e sai o `5` e depois o `4`. Por fim entra e sai o vagão `6`.

**Algoritmo**

Uma das soluções possíveis para esta questão é ter 3 containers (array, vector, stack...),
um para representar a ordem quem os vagões chegam, outro para representar a estação,
e outro para representar a ordem desejada na saída.
O de entrada deve ser preenchido com a ordem em que os vagões irão entrar, o
da estação deve estar vazio no inicio, e o de saida deve ter a ordem de saída
esperada.

Para cada vagão entrando,
ele sai do container de entrada, e vai para o de estação. Caso o último vagão
que entrou corresponda ao próximo vagão aguardado na saída, ele sai da estação
e da saída também. Caso no fim todos os containers estejam vazios, quer dizer
que deu certo, todos os vagões entrando conseguem sair do jeito esperado.
Agora se em algum momento esgotar todos os de entrada, e o último que entrou
não corresponde com o próximo da saída, não é possível chegar na saída esperada.


## URI1162 - Organizador de Vagões

[URI1162](https://www.urionlinejudge.com.br/repository/UOJ_1162.html)

Neste problema o algoritmo descrito pelo contexto é o [bubble sort](https://en.wikipedia.org/wiki/Bubble_sort)
([implementação](https://rosettacode.org/wiki/Sorting_algorithms/Bubble_sort#C) e [visualização](https://visualgo.net/en/sorting)).
Ao implementar o algoritmo você terá vários passos de `swap`, a questão pede para
saber o número de passos que foram feitos os `swap`, este será o número
ótimo de trocas neste contexto.
