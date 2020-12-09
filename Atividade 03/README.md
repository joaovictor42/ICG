## Rasterização de Primitivas em OpenGL

**Atividade 03 -** Introdução à Computação Gráfica - 2020.1 <br />
**Professor:** Christian Pagot <br />
**Alunos:**  João Victor Alcoforado de Araújo - 20180083830 <br />
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Matheus Rocha dos Santos Rangel - 20200095718 <br />

### Introdução
O objetivo deste trabalho é compreender a estrutura do pipeline gráfico através da implementação das transformações geométricas que o compõe. Essa implementação utiliza como base o código template C++17 disponibilizado pelo professor, disponível no <a href="https://github.com/capagot/icg/tree/master/03_transformations">repositório da disciplina</a>.

Além disso, utiliza a biblioteca <a href="https://glm.g-truc.net/0.9.9/index.html">GLM</a> e os shaders do OpenGL.

Como todas as questões do trabalho utilizavam como base o mesmo código, para facilitar a visualização, optou-se por gravar os respectivos códigos de solução no histórico de commits do repositório, como segue abaixo:

* Questao 1
* Questao 2
* Questao 3 [retificada]
* Questao 4 [retificada]
* Questao 5 [retificada]

###  Exercício 1: Escala

A fim de alterar as proporções dos objetos da cena para a escala solicitada (1/3, 3/2, 1), construiu-se a seguinte matriz Model:

```
float model_array[16] = {1.0/3.0f, 0.0f, 0.0f, 0.0f,
                         0.0f, 3.0/2.0f, 0.0f, 0.0f,
                         0.0f, 0.0f, 1.0f, 0.0f,
                         0.0f, 0.0f, 0.0f, 1.0f};
```
#### Resultado:
![Atividade1](https://github.com/joaovictor42/ICG/blob/main/images/Atividade_1.png?raw=true)<br/>
<sub>Resultado: Atividade 1.<sub>
    
###  Exercício 2: Translação

Para transladar os objetos da cena em (1, 0, 0), construiu-se a seguinte matriz Model:

```
float model_array[16] = {1.0f, 0.0f, 0.0f, 0.0f,
                         0.0f, 1.0f, 0.0f, 0.0f,
                         0.0f, 0.0f, 1.0f, 0.0f,
                         1.0f, 0.0f, 0.0f, 1.0f};
```
#### Resultado:
![Atividade2](https://github.com/joaovictor42/ICG/blob/main/images/Atividade_2.png?raw=true)<br/>
<sub>Resultado: Atividade 2.<sub>

###  Exercício 3: Projeção Perspectiva

Para modificar a distorção perspectiva da cena, utilizando como parâmetro a distância entre o centro de projeção e a origem do sistema de coordenadas, d = 1/8, construiu-se a seguinte matriz Projection: 
```
float proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f,
                        0.0f, 1.0f, 0.0f, 0.0f,
                        0.0f, 0.0f, 1.0f, -8.0f,
                        0.0f, 0.0f, 0.125f, 0.0f};
```
#### Resultado:
![Atividade3](https://github.com/joaovictor42/ICG/blob/main/images/Atividade_3.png?raw=true)<br/>
<sub>Resultado: Atividade 3.<sub>

###  Exercício 4: Posição da Câmera

A primeira etapa da solução consistiu em decidir como as informações fornecidas pela questão seriam representadas.

* Posição da câmera = (-1/10, 1/10, 1/10)
* Up da câmera = (0, 1, 0)
* Ponto para o qual a câmera está apontando = (0, 0, -1)

A representação desses vetores é importante, pois eles são usados no cálculo dos vetores da base da câmera, que necessita de funções auxiliares para efetuar produtos e normas vetoriais. Dessa forma, pesquisou-se exaustivamente quais funções poderiam ser utilizadas para efetuar esses cálculos, atendo-se aos tipos de seus parâmetros. Por conseguinte, por meio da biblioteca GLM, as informações da câmera foram representadas em vetores `vec3`. Além disso, as funções `normalize()` e `cross()` foram utilizadas para calcular os vetores `X_cam`, `Y_cam` e `Z_cam`. Por fim, esses vetores e o vetor `Posição da câmera` foram utilizados para criar as matrizes `Bt` e `T`, respectivamente. Seguindo-se o padrão do código, essas matrizes foram implementadas utilizando-se a função `make_mat4()`, que retorna um objeto do tipo `mat4`. Assim, garantiu-se legibilidade e reuso de código, além de facilitar a, posterior, multiplicação de matrizes para a obtenção da matriz View.

```
//Criação dos vetores da base da câmera
glm::vec3 z_cam = glm::normalize(cam_pos - cam_look_at);
glm::vec3 x_cam = glm::normalize(glm::cross(glm::normalize(cam_up), z_cam));
glm::vec3 y_cam = glm::cross(z_cam, x_cam);
```

```
//Construção da matriz View como produto das matrizes Bt e T.
glm::mat4 view_mat = Bt_mat * T_mat;
```
#### Resultado:
![Atividade4](https://github.com/joaovictor42/ICG/blob/main/images/Atividade_4.png?raw=true)<br/>
<sub>Resultado: Atividade 4.<sub>

###  Exercício 5: Transformações Livres

Neste exercício objetivou-se modificar as matrizes Model, View e Projection, a fim de renderizar um cubo com face de cores diferentes. 
Dessa forma, compreendeu-se que outras geometrias poderiam ser formadas por combinações de triângulos. Para tanto, foram criados 12 triângulos, de maneira que
cada par compõe uma face. Por fim, alterou-se a escala, posição da câmera e distorção a fim de obter-se a seguinte imagem do cubo.
#### Resultado:
![Atividade5](https://github.com/joaovictor42/ICG/blob/main/images/Atividade_5.png?raw=true)<br/>
<sub>Resultado: Atividade 5.<sub>

### Conclusão

Este trabalho proporcionou muitos aprendizados e possibilitou uma sólida compreensão da estrutura do pipeline gráfico. 
A principal dificuldade foi a manipulação da biblioteca GLM na linguagem C++, visto que a dupla não possuía experiência com a linguagem de programação.

### Referências
MARSCHNNER, S.; SHIRLEY, P. Transformation  Matrices. In: FUNDA-MENTALS of Computer Graphics. 3. ed. rev. [S. l.]: CRC Press, 2009. cap. 6, p. 111-135.
http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/
