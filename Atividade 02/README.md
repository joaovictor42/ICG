## Rasterização de Primitivas em OpenGL

**Atividade 02 -** Introdução à Computação Gráfica - 2020.1 <br />
**Professor:** Christian Pagot <br />
**Alunos:**  João Victor Alcoforado de Araújo - 20180083830 <br />
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Matheus Rocha dos Santos Rangel - 20200095718 <br />

### Introdução
O objetivo deste trabalho é implementar algoritmos para a rasterização de pontos e linhas. 
Além disso, desenhar triângulos através da rasterização das linhas que compõem suas arestas. 
Neste trabalho, rasterização dessas primitivas foi implementada através da simulação do acesso direto à memória de vídeo, possibilitada por meio do framework fornecido pelo próprio professor.

Para tanto, as seguintes funções de rasterização foram implementadas: `PutPixel()`, `DrawLine()` e `DrawTriangle()`.<br />
Essas funções rasterizam pontos, linhas e triângulos, respectivamente.

### Rasterização de Ponto

As imagens dos monitores atuais são formadas a partir de matrizes de pixels, a qual possui x pixels de largura por y pixels de altura.
Os pixels de uma imagem são distribuídos de acordo com suas respectivas coordenadas nessa matriz. Os pixels rasterizados neste trabalho utilizam o padrão RGBA, 
ou seja, cada pixel é formado pela combinação do parâmetro alpha com 3 cores: vermelho, verde e azul.

A partir dessa lógica, criamos as seguintes estruturas:

* Point: armazena as coordenadas do pixel;
* Color: armazena os padrões de cores do pixel.

A função `PutPixel()` rasteriza um ponto na memória de vídeo recebendo como parâmetros as coordenadas (x,y) do pixel na tela (representado pelo tipo Point)
e sua cor RGBA (representado pelo tipo Color). 

Por sua vez, o algoritmo calcula a posição do ponto a ser rasterizado na matriz de pixels. 
Em seguida, escreve as cores do pixel na posicao adequada do framebuffer.

```
offset = (x*4 + y*4*IMAGE_WIDTH);

for(i = 0; i < 4; i++){
    fb_ptr[offset+i] = color.RGBA[i];
}
```

O resultado da rasterização dos pontos pode ser visualizado na imagem.

![ponto](https://github.com/joaovictor42/ICG/blob/main/images/dots_e.png?raw=true)<br/>
<sub>Pontos rasterizados: (100, 100); (200, 200); (300, 300); (400, 400).<sub>

### Rasterização de Linhas

Rasterização de linhas busca atrvés de dois pontos P (ponto inicial) Q (ponto final) determinar quais pixels devem ser rasterizados para formar um segmento de reta começando em P e terminando em Q. Assim, para obeter-se um segmento de reta, busca-se calcular as as coordenadas dos pixels que mais se aproximam do segmento de reta desejado. Atualmente, existem diversos métodos de rasterização de linhas, dentre eles a aplicação direta da equação da reta, DDA (Digital Differential Analyzer) e algoritmo do Ponto Médio (Mid-Point). 

A função `DrawLine()` rasteriza uma linha na tela, sua implementação utiliza como base o algoritmo do Ponto Médio. 
Para isso, a função recebe como parâmetros o ponto incial e final, e as cores (no formato RGBA) de cada ponto. Adicionalmente, as cores dos pixels ao longo da linha rasterizada foram interpolados com as cores dos vértices da reta.

O algoritmo desenvolvido generaliza a solução do Ponto Médio para todos octantes. Afim de encontrar uma solução elegante e eficiente para o problema, procuramos extensivamente 
websites e artigos que apresentassem algoritmos com essas características, uma vez que a nossa solução inicial verificava as condições de cada octante para encontrar simetria.

Dessa forma apresentamos abaixo uma versão simplificada do algortimo desenvolvido, que toma decisão com base no sinal do ponto médio e na variação dos eixos x e y.

```
// Verifica se inclinação da reta é maior do que 45°.
if(dy > dx){
    temp = dx; dx = dy; dy = temp; swap = 1;
}
    
for(i = 0; i < dx; i++){
    if(midPoint <= 0){ // Verifica o sinal da variável de decisão no ponto médio.
        if(swap){ // Verifica se houve troca.
            currentPoint.y += dySinal; // Incrementa y de acordo com o sinal de da veriação de y.
        }else{
            currentPoint.x += dxSinal; // Incrementa x de acordo com o sinal de da veriação de x.
        }
        midPoint += eastPixel; 
    }else{
        currentPoint.y += dySinal;
        currentPoint.x += dxSinal;
        midPoint += northeastPixel;
    }
    PutPixel(currentPoint, color);
}
```
Linhas renderizadas com o algortimo:

![line2](https://github.com/joaovictor42/ICG/blob/main/images/lines2_e.png?raw=true)<br/>
<sub>Segmentos de reta rasterizados entre os pontos: <sub> <br/>
<sub> (0, 511),(511, 0); (0, 0),(511, 511); (255, 0),(255, 511); (0, 255),(511, 255); <sub> <br/>
<sub> (256, 256), (511, 450); (256, 256),(270, 511); (255, 255),(50, 511); (255, 255),(0, 300); <sub> <br/>
<sub> (255, 255), (0, 180); (255, 255),(150, 0); (255, 255),(400, 0); (255, 255),(511, 200). <sub> <br/>
    

A principal dificuldade foi encontrar e/ou desenvolver um algortimo capaz de generalizar a lógica do ponto médio.
Além disso, todas as soluções encontradas verificam explicitamente o octante que a reta pertence.
Porém, depois de muito esforço encontramos uma lógica que realiza menos verificações.
Para tanto, x e y são incrementados/decrementados de acordo com o sinal da sua respectiva variação. 

#### Interpolação de cores na rasterização da reta

A interpolação linear das cores significa começar a rasterização da linha utilizando uma cor e incrementalmente modificar essa cor para no fim da rasterização obtermos outra cor. 
O efeito dessa interpolação é a formação de um degradê de cores, a partir de uma cor inicial para uma cor final. 

Dessa forma como as rasterização funciona pixel a pixel, calculamos um valor de incremento para ser adicionado a sucessivamente a cor do pixel recém rasterizado.
Para calcular o valor do incremento utilizamos os valores das componentes R, G, B, do sistema RGBA na seguinte formula:
`Incremento do Componente = (Componente Final - Componente Inicial) / Maior Variação Absoluta`
Com esses valores pré-caculados podemos incrementá-los aos valores dos componentes RGBA do pixel recém rasterizado.
Repete-se o último passo até o último pixel ser rasterizado.

![line1](https://github.com/joaovictor42/ICG/blob/main/images/line1_e.png?raw=true)<br/>
<sub>Pontos da reta: (20, 491); (491, 20).<sub>
    
### Rasterização de Triângulos

A função `DrawTriangle()` desenha as arestas de um triângulo na tela e recebe como parâmetros três pontos, que representam os vértices do triângulo, bem como suas respectivas cores (RGBA).

A função utiliza como base a renderização de linhas, dessa forma os vétices do triangulos são apenas passados para `DrawLine()`.

![tri1_e](https://github.com/joaovictor42/ICG/blob/main/images/tri1_e.png?raw=true)<br/>
<sub>Vértices do triângulo: (20, 20); (256, 491); (491, 20).<sub>

![tri2_e](https://github.com/joaovictor42/ICG/blob/main/images/tri2_e.png?raw=true)<br/>
<sub>Vértices do triângulo: (20, 20); (256, 491); (491, 20).<sub>
    
### Referências
