# Contest 01 - Editorial

**Autores** : [Elmar Roberto](https://github.com/)

**Revisores** : [Matheus Faria](https://github.com/matheusfaria)

## CF20C - Dijkstra?

Tome `s` como o vertice inicial e `w` o vertice final.

Para a resolução desta questão é necessário apenas o uso de Algoritmo de Dijkstra.
A adaptação necessária e pontual para o caminho mínimo é a criação de um vetor
de predecessores, `pred`,  qualquer de tamanho máximo (relacionado ao input máximo da questão), onde ​ pred[ w
]  é o nó que antecede w no caminho mínimo que vai de s a w .
Inicialmente, todos os valores do vetor ​ pred ​ devem ser iguais a um valor sentinela,
exceto o vértice s , que será pred[ s ] = s .
Se a aresta( u , v ) atualizar a distância ​ dist[ v ] ​ , então o predecessor deve ser
atualizado também: ​ pred[ v ] ​ = u .
Se o predecessor de u for o valor sentinela, então não há caminho.


2. UVA - 10954
Não é preciso utilizar nenhum algoritmo em específico.
Para a resolução é necessário guardar os valores de ​ input ​ em ordem crescente para
ir somando os dois menores valores possíveis em cada iteração do loop, ou seja, ordenar e
somar de forma crescente.
Uma das estruturas que pode ser usada é a ​ priority_queue , ​ onde os valores podem
ser guardados de forma negativa ou com o uso do parâmetro ​ greater ​ .
Durante toda iteração, deve-se guardar de volta na pilha o valor da soma atual e
somá-lo ao custo final.
3. CodeForces - 545E Paths and Trees
Encontre todos os caminhos mais curtos de u para outros vértices.
Defina d i como o comprimento do caminho mais curto de u para i , d é o vetor que
guarda os menores caminhos do algoritmo de Dijkstra.
Exclua uma aresta com extremidades em x e y e peso w se | d x − d y | = / w , pois
esta não está contida em nenhum caminho mais curto, por isso não pode estar contida em
uma futura árvore de caminho mais curto.
Direcione todas as arestas dos vértices com menor distância para os vértices com
maior distância. É fácil provar que, se tomarmos uma aresta que entra em cada vértice,
temos uma árvore de caminho mais curto.
Deve-se tomar para cada vértice mínimo do vértice, que entra nesse vértice. Por
quê? Porque nós temos que pegar pelo menos uma borda, que entra em cada vértice para
fazer um gráfico conectado. Não podemos pegar bordas com menos peso que o mínimo. Ese pegarmos arestas mínimas, que entrarão em cada vértice, teremos uma árvore de
caminho mais curta. Portanto, esse é o peso total mínimo possível da árvore de caminho
mais curto.
4. URI - 1931 Mania de Par
Para a resolução dessa questão deve ser utilizado o algoritmo de Dijkstra.
Deve-se gerar dois grafos, um com os valores normais de ​ input ​ e outro grafo auxiliar
gerado a partir do grafo principal.
Cada vértice do grafo auxiliar guarda como adjacente apenas vértices que tenham
duas arestas de distâncias para garantir a paridade.
Usa-se então o Dijkstra no grafo auxiliar em que os pesos desse grafo estarão ligado
apenas a distâncias pares.
Se a distância for infinita, então não tem resposta.
