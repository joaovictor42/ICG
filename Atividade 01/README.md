**Atividade 01 -** Introdução a Computação Gráfica - 2020.1 <br />
**Professor:** Christian Pagot <br />
**Alunos:** João Victor Alcoforado de Araújo e Matheus Rocha dos Santos Rangel <br />

## Descrição

Este trabalho consiste em compilar um programa OpenGL moderno, para isso utilizamos o programa disponível abaixo: 
https://github.com/capagot/icg/tree/master/01_hello_world_gl/modern_opengl 

Esta atividade tem o intuito de <br />
* Validar instalação e configuração do ambiente de desenvolvimento em OpenGL 3.3;
* Mostrar a compilação de um programa OpenGL moderno.

## Estratégias 

* Pesquisa de tutoriais de intalação e compilação do OpenGL;
* Utilização de sistema Linux para facilitar o processo de instalação e configuração.

## Discussão
Instalamos o OpenGL através do tutorial mencionado nas referências, utilizando os seguintes comandos:
```
$ sudo apt-get update
$ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

Após a instalação, verificou-se que poderia-se executar um arquivo OpenGL com o seguinte comando:

`$ ./moderngl_hello_world`

Para atingir o objetivo da atividade, realizamos o download do arquivo indicado pelo professor e buscamos executá-los como mencionado. 
Dessa forma, utilizamos o make para gerar o executável e posteriormente executá-lo, como mostrado abaixo:

![alt text](https://github.com/joaovictor42/ICG/blob/main/images/executable.jpeg?raw=true)

Finalmente, a janela OpenGL abaixo demonstra que o programa foi compilado e executado com sucesso.

![triangulo](https://github.com/joaovictor42/ICG/blob/main/images/triangulo.jpeg?raw=true)

Nenhuma dificuldade foi encontrada durante a realização da atividade.

## Referências
http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/
https://github.com/capagot/icg/tree/master/01_hello_world_gl/modern_opengl 
