#include "mygl.h"

Color red = {255, 0, 0, 255};
Color green = {0, 255, 0, 255};
Color blue = {0, 0, 255, 255};
Color white = {255, 255, 255, 255};

unsigned char* fb_ptr = NULL;

void InitMyGl(void) {
    fb_ptr = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * 4 * sizeof(char));

    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; ++i) {
        fb_ptr[i * 4] = 0;
        fb_ptr[i * 4 + 1] = 0;
        fb_ptr[i * 4 + 2] = 0;
        fb_ptr[i * 4 + 3] = 255;
    }
}

unsigned char* GetFBMemPtr(void) {
	return fb_ptr;
}

void CloseMyGl(void) {
    if (!fb_ptr)
        free(fb_ptr);
}

//
// >>> Caro aluno: defina aqui as funções que você implementar <<<
//

void PutPixel(Point point, Color color){
    int x, y, offset, i;

    x = point.x;
    y = point.y;

    if((x>=0 && x<IMAGE_HEIGHT) && (y>=0 && y<IMAGE_WIDTH)){

        offset = (x*4 + y*4*IMAGE_WIDTH);

        for(i = 0; i < 4; i++){
            fb_ptr[offset+i] = color.RGBA[i];
        }
    }
}

int Sign(int value){
    if(value > 0){
        return 1;
    }else if(value < 0){
        return -1;
    }
    return 0;
}


void DrawLine(Point startPoint, Point endPoint, Color color1, Color color2){
    int dxSinal, dySinal, temp, i, j;
    double dx, dy, midPoint, eastPixel, northeastPixel;
    int swap = 0;

    Point currentPoint = startPoint;

    dx = endPoint.x - startPoint.x;
    dy = endPoint.y - startPoint.y;

    dxSinal = Sign(dx);
    dySinal = Sign(dy);

    dx = abs(dx);
    dy = abs(dy);

    if(dy > dx){
        temp = dx; dx = dy; dy = temp; swap = 1;
    }

    midPoint = 2*dy - dx;
    eastPixel = 2*dy;
    northeastPixel = 2*(dy - dx);

    Color color = color1;
    Color colorIncrement;

    for(i = 0; i < 4; i++){
        colorIncrement.RGBA[i] = (color2.RGBA[i] - color1.RGBA[i])/dx;
    }

    PutPixel(currentPoint, color);

    for(i = 0; i < dx; i++){
        if(midPoint <= 0){
            if(swap){
                currentPoint.y += dySinal;
            }else{
                currentPoint.x += dxSinal;
            }
            midPoint += eastPixel;
        }else{
            currentPoint.y += dySinal;
            currentPoint.x += dxSinal;
            midPoint += northeastPixel;
        }
        for(j = 0; j < 4; j++){
            color.RGBA[j] += colorIncrement.RGBA[j];
        }

        PutPixel(currentPoint, color);
    }
}

void DrawTriangle(Point p1, Point p2, Point p3, Color colorP1, Color colorP2, Color colorP3){

    DrawLine(p1, p2, colorP1, colorP2);
    DrawLine(p2, p3, colorP2, colorP3);
    DrawLine(p1, p3, colorP1, colorP3);

}


// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {

    Point p1 = {20, 20};
    Point p2 = {256, 491};
    Point p3 = {491, 20};

    DrawTriangle(p1, p2, p3, green, red, blue);

}
