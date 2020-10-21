#ifndef MYGL_H
#define MYGL_H

#include <stdlib.h>
#include <string.h>

#include "core.h"

typedef struct{
    int x, y;
}Point;

typedef struct{
    double RGBA[4];
}Color;

typedef struct{
    Point startPoint;
    Point endPoint;
}Line;

void InitMyGl(void); // Inicializa o frame buffer
unsigned char* GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void); // Desaloca a memória do framebuffer

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);

void PutPixel(Point point, Color color);

void DrawLine(Point startPoint, Point endPoint, Color color1, Color color2);

void DrawTriangle(Point p1, Point p2, Point p3, Color colorP1, Color colorP2, Color colorP3);

#endif  // MYGL_H
