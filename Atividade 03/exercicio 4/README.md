## Rasterização de Primitivas em OpenGL

**Atividade 03 -** Introdução à Computação Gráfica - 2020.1 <br />
**Professor:** Christian Pagot <br />
**Alunos:**  João Victor Alcoforado de Araújo - 20180083830 <br />
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Matheus Rocha dos Santos Rangel - 20200095718 <br />

### Introdução
O objetivo deste trabalho é compreender a estutura do pipeline gráfico através da implementação das transformações geométricas que o compõem. Esta implementação utiliza a biblioteca GLM e sua execução nos shaders do OpenGL.
A implementação utiliza como base o código template C++17 disponibilizado pelo professor, disponível no respositório da disciplina:

https://github.com/capagot/icg/tree/master/03_transformations

Como todas as questões do trabalho utilizavam como base o mesmo código, para facilitar a visualização, optou-se por deixar os códigos de solução, disponíveis através do histórico de commites do respositório.

###  Exercício 1: Escala

Para alterar as proporções dos objetos da cena para a escala solicitada $ (1/3, 3/2, 1) $, constriu-se a seguinte matriz Model:

$$

Model = 

$$

![line1](https://github.com/joaovictor42/ICG/blob/main/images/line1_e.png?raw=true)<br/>
<sub>Resultado: Atividade 1.<sub>
    
###  Exercício 2: Translação

Para transladar os objetos da cena em $ (1, 0, 0) $, constriu-se a seguinte matriz Model:

$$

Model = 

$$

![line1](https://github.com/joaovictor42/ICG/blob/main/images/line1_e.png?raw=true)<br/>
<sub>Resultado: Atividade 2.<sub>

###  Exercício 3: Projeção Perspectiva

Para modificar a distorção perspectiva da cena, utilizando como distância entre o centro de projeção e a origem do sistema de coordenadas, $ d = 1/2 $, construiu-se a seguinte matriz Projection: 

$$

Projection = 

$$

![line1](https://github.com/joaovictor42/ICG/blob/main/images/line1_e.png?raw=true)<br/>
<sub>Resultado: Atividade 3.<sub>

###  Exercício 4: Posição da Câmera

A primeira etapa de solução desta questão consistiu em construir os vetores da base do espaço da câmera:
* Posição da câmera = $(-1/10, 1/10, 1/10)$ 
* Up da câmera = $(0, 1, 0)$
* Ponto para o qual a câmera está apontando = $(0, 0, -1)$

Porém, precisou-se ater-se ao fato que de que posteriormente esses vetores deveriam usados para calcular $X_cam$, $Y_cam$ e $Z_cam$, <b> vetores da base da câmera </b>.
Para tanto, seria necessário cálcular produtos vetoriais e normas vetoriais. Dessa forma, pesquisou-se de forma exaustiva quais funções poderiam ser utilizadas
para efetuar esses calculos e quais os respectivo tipos de dados esperados por elas. Essa foi a parte mais difícil, visto a presente dupla possuia conhecimentos
de C++ e queria-se evitar criar funções para auxiliar o processo de obtensão da matriz View, a fim de manter a legibilidade do código. Por conseguinte, as funções  
`tan`, `tan` e `ran` da biblioteca GLM foram utilizadas para obter os <b> vetores da base </b>. Adicionalmente, criarem-se as matrizes $B^t$ e $T$ para facilitar o calculo da 
multiplicação de matrizes e obter-se, finalmente, a matriz View. 

```
Código vetores
```

```
Código matrizes
```

![line1](https://github.com/joaovictor42/ICG/blob/main/images/line1_e.png?raw=true)<br/>
<sub>Resultado: Atividade 4.<sub>

###  Exercício 5: Transformações Livres

Neste exercício objetivou-se modificar as matrizes Model, View e Projection, a fim de renderizar um cubo com face de cores diferentes. 
Dessa forma, compreendeu-se que outras geometrias poderiam ser formadas por combinações de triângulos. Para tanto, foram criados 12 triângulos, de maneira que
cada par compõe uma face. Por fim, alterou-se a escala, posição da câmera e distorção a fim de obter-se a seguinte imagem do cubo.

![line1](https://github.com/joaovictor42/ICG/blob/main/images/line1_e.png?raw=true)<br/>
<sub>Resultado: Atividade 5.<sub>

### Conclusão

Este trabalho proporcionou muitos aprendizados e possibilitou uma sólida compreensão da estrutura do pipiline gráfico. 
A principal dificuldade foi a manipulação da biblioteca GLM na linguagem C++, visto a dupla não possuia experiência com a linguagem.

### Referências
