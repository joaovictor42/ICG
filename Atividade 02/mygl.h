#ifndef MYGL_H
#define MYGL_H

#include <stdlib.h>
#include <string.h>

#include "core.h"


typedef struct{
    int x, y;
}Point;

typedef struct{
    float Red;
    float Green;
    float Blue;
    float Alpha;
}RGBA;


typedef struct{
    Point pi;
    Point pf;
}Line;

void InitMyGl(void); // Inicializa o frame buffer
unsigned char* GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void); // Desaloca a memória do framebuffer

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);

//
// >>> Caro aluno: declare aqui as funções que você implementar <<<
//

void PutPixel(int x, int y, RGBA color);



void DrawLine(Point startPoint, Point endPoint, RGBA color1, RGBA color2);

#endif  // MYGL_H
