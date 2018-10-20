# Contest 04 - Editorial

**Autores** : [Marlon Mendes](https://github.com/marlonbymendes)

**Revisores**:

## URI-1487 - Six Flags

[URI-1487](https://www.urionlinejudge.com.br/judge/pt/problems/view/1487)

**Problema**

Em um parque de diversões, você tem `T` minutos para brincar em até `N` brinquedos. Ao utilizar um brinquedo, você ganha uma pontuação mas terá gasto um tempo naquele brinquedo. É permitido utilizar um brinquedo mais de uma vez ou não utilizar um determinado brinquedo.

- Para cada um dos `N` brinquedos, nós temos dois inteiros: `D[i]` e `P[I]`:

| Atributo | Definição |
| ------------- |:-------------:|
| `P[i]` | Pontuação ganha ao utlizar o `i-`ésimo brinquedo |
| `D[i]` | Tempo de duração do brinquedo |

Qual a maior pontução possível utilizando atè `T` minutos nos brinquedos?

**Solução**

Vamos resolver a problema utilizando Programação Dinâmica.

Imagine que construíssemos uma função misteriosa `f(i, time)` que nos respondesse a seguinte pergunta:

- `f(i, time)` = qual a maior pontuação possível considerando os brinquedos apenas de `1 a i`, onde eu posso gastar até `time` minutos utilizando os brinquedos?

Se conseguirmos uma função dessa, a resposta do problema seria trivial: `f(N, T)` onde `N` e `T` são dados no input.

*O caso base:*

| Atributo | Definição |
| ------------- |:-------------:|
| `f(0, time) = 0` | Neste caso, não há mais brinquedos portanto não é possível ganhar mais pontos |

*O caso geral:* `f(i, time)`

Ao consideramos o `i-`ésimo brinquedo, temos duas opções:

1 - Não uilizar o brinquedo: nesse caso não ganhamos nenhuma pontuação, pois não brincamos, mas também não gastamos nenhum tempo. Portanto, `f(i, time) = f(i - 1, time)`.

2 - Utlizar o brinquedo: nesse caso gastaríamos `D[i]` de tempo, mas ganharíamos `P[I]` pontos. Portanto: `f(i, time) = P[i] + f(i, time - D[i])`. Note que podemos utilizar o item novamente, portanto vamos para o estado `f(i, time - D[i])`. Note que não é possível escolher a opção 2 se `time < D[i]`.

Qual das duas opções escolher? Basta tentar o máximo das duas.

`f(0, time) = 0`
`f(i, time) = max(f(i - 1, time), P[i] + f(i, time - D[i])), time >= D[i]`

Código: [link]()

## URI-1034 - Festival de Estátuas de Gelo

[URI-1034](https://www.urionlinejudge.com.br/judge/pt/problems/view/1034)

**Problema**

Você possui `n` blocos. O `i-`ésimo bloco possui altura `a[i]`. VocÊ deseja empilhar os blocos, um em cima do outro, para construir uma pilha de tamanho exatamente `M`. Qual o menor número de blocos que você pode empilhar tal que a pilha tenha soma das alturas dos blocos = `M`? Um bloco pode ser utilizado zero ou mais vezes.

**Solução recursiva utilizando Programação Dinâmica**

| Atributo | Definição |
| ------------- |:-------------:|
| `f(i, sum)` | Considerando apenas os blocos de `1` até `i`: qual o menor número de blocos, considerando os blocos `1 até i`, tal que seja possível empilhar alguns destes blocos, de alguma forma, tal que a altura da pilha seja exatamente `sum`? |
| `f(0, 0) = 0` | Neste caso queremos uma pilha de altura 0, basta não utilizar nenhum bloco e o conseguiremos. |
| `f(0, x > 0) = +INF` | Como não podemos utilizar nenhum bloco, então não há resposta: +INF |

*Transição*

Assim como no problema anterior, ao consideramos o estado `f(i, sum)` nós temos duas opções em relação ao bloco `i`:

1 - Não utilizar o bloco `i`. Neste caso, `f(i, sum) = f(i - 1, sum)`. O valor de `sum` se mantém porque não utilzamos nenhum bloco.

2 - Utilizar o bloco `i`. Neste caso, `f(i, sum) = 1 + f(i, sum - a[i])`. Somamos um na resposta porque nós utilizamos o `i-`ésimo bloco. Porém ainda podemos utilizar este bloco mais uma vez, por isso fazemos a transião para `f(i, sum - a[i])`.

Sendo assim, a solução valor da função `f` nos dois casos possívels: `min(f(i - 1, sum), 1 + f(i, sum - a[i]))`.

Infelizmente a solução recursiva é lenta demais para o limite de tempo da questão, mas ela nos ajuda a pensar numa solução iteriva (botton-up).

*Solução iterativa (botton-up)*.

Vamos construir uma solução de forma iterativa, do caso mais simples até o caso mais complexo. Guardaremos a resposta em uma tabela chamada `dp`. Primeiramente observe o código abaixo para a explicação ficar mais simples:

```
int bottom_up() {
    for(int j = 0; j <= m; j++) {
        dp[j] = INF;
    }
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = arr[i]; j <= m; j++) {
            dp[j] = min(dp[j], 1 + dp[j - arr[i]]);
        }
    }
    return dp[m];
}
```

O significado de `dp[j]` é atrelado a iteração do algoritmo. Na iteração 0 ele guarda a resposta do problema para todos os valores possíveis de `M` considerando os blocos de 1 até 0, ou seja, sem utilizar bloco.
Na i-ésima iteração ele considera todos os blocos de 1 até i, e passa em todos os `M` possíveis (segundo for). Portanto, assim como na soluçã recursiva basta testar os dois casos: utilizar ou não o bloco i.

## CF415A - Boredom

[CF415A](http://codeforces.com/contest/455/problem/A)

**Problema**

É dado `n` inteiros, `1 <= n <= 10^5`, e cada inteiro `a[i]` e `1 <= a[i] <= n`.

Vamos definir um contador `cont`:

| Atributo | Definição |
| ------------- |:-------------:|
| `cont[i]` | Número de vezes que o valor `i` apareceu no array `a` |

O problema diz o seguinte: em cada jogada, você deve escolher um inteiro `x`, ainda presente no array. Escolhendo `x`, você ganha `x * cont[x]` pontos, e deleta todos os valores `(x + 1) e (x - 1)` do array, ou seja, você não poderá escolher no futuro estes dois valores pois eles foram deletados. Enfim o problema pergunta qual a maior quantidade de pontos que é possível ganhar.

**Solução**

Há duas observações importantes sobre este problema:

1 - Escolhendo o valor `x`, ganhamos `x * cont[x]` pontos.
2 - Um valor `x` só pode ser deletado do array caso em algum momento façamos as escolhas `(x + 1) ou (x - 1)` do array.

Sendo assim construimos uma solução de programação dinâmica:

`f(i)` : a maior quantidade de pontos que é possível ganhar considerando apenas os elementos do array que são menores ou iguais a `i`. Este é o nosso estado da Programação Dinâmica.

Tamos duas opções:

1 - Escolher o valor `i`: neste caso ganhamos `i * cont[i]`. Como não podemos escolher mais o valor `(i - 1)`, pegaremos então a resposta do problema `f(i - 2)` já que com certeza podemos utilizá-la.

2 - Não escolher o valor `i`: neste caso podemos utilizar a resposta de `f(i - 1)`.

Portanto:

- `f(1) = cont[1]`
- `f(i > 2) = max(f(i - 1), i * cont[i] + f(i - 2)))`

## CF489C - Boredom Given Length and Sum of Digits...

[CF489C](http://codeforces.com/contest/489/problem/C)

**Problema**

É dado um inteiro positivo `1 <= m` e um inteiro não-negativo `s`. Calcule o menor número que tenha soma dos digitos = `s` e tamanho `m`, este número não pode ter `leading-zeros`.

**Solução**

Vamos dividir a solução deste problema em duas partes:

`Sabendo se existe ou não uma solução`

Resolveremos esta parte do problema utilizando programaçã dinâmica.

Considere que a função `f(i, j)` retorne o seguinte resultado: existe (True ou False) uma string de tamanho exatamente `i` que a soma dos digitos é exatamente `j`?

Vamos colocar os digitos da direita para a esquerda. Em cada passo noś podemos colocar um número entre `0 e 9` na posição `m`. Caso coloquemos o valor `d`, então vamos para o estado `f(i - 1, j - d)`. Lembre-se que não pode-se ter leading zeros, portanto para `i = 1` não pode-se utilizar o valor `0`.

*Caso base*:

| Atributo | Definição |
| ------------- |:-------------:|
| `f(0, s)` | Neste caso queremos constuir uma string de tamanho 0 que a some dos elementos seja exatamente `s`. A única forma possível é se `s = 0`, portanto `f(0, s) = (s == 0)` |
| `f(1, s)` | Neste caso podemos colocar apenas os digigitos `1-9`. Como necessitamos de uma soma `s`, precisamos colocar o digito "`s`". Isso só será possível se `1 <= 9 <= s`, portanto `f(1, s) = (s >= 1 and s <= 9)` |
| `f(i, s)` | Neste caso podemos colocar qualquer digito `0-9`. Portanto `f(i, s) OR= f(i - 1, s - d)` para todo `0 <= d <= 9` e `0 <= d <= s` |
