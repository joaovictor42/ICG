#include "mygl.h"


RGBA red = {255, 0, 0, 255};
RGBA green = {0, 255, 0, 255};
RGBA blue = {0, 0, 255, 255};
RGBA white = {255, 255, 255, 255};

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

void PutPixel(int x, int y, RGBA color){

    if((x>=0 && x<IMAGE_HEIGHT) && (y>=0 && y<IMAGE_WIDTH)){

        int frameBufferPosition = (x*4 + y*4*IMAGE_WIDTH);

        fb_ptr[frameBufferPosition] = color.Red;
        fb_ptr[frameBufferPosition+1] = color.Green;
        fb_ptr[frameBufferPosition+2] = color.Blue;
        fb_ptr[frameBufferPosition+3] = color.Alpha;
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


void DrawLine(Point startPoint, Point endPoint, RGBA color1, RGBA color2){
    int x, y, s1, s2, temp;
    double dx, dy;
    double D, inc_L, inc_NE;
    int swap = 0;

    x = startPoint.x;
    y = startPoint.y;

    dx = abs(endPoint.x - startPoint.x);
    dy = abs(endPoint.y - startPoint.y);

    s1 = Sign(endPoint.x - startPoint.x);
    s2 = Sign(endPoint.y - startPoint.y);

    /* Check if dx or dy has a glp2reater range */
    /* if dy has a greater range than dx swap dx and dy */
    //inclanação maior que 1
    if(dy > dx){
        temp = dx; dx = dy; dy = temp; swap = 1;
    }

    D = 2*dy - dx;
    inc_L = 2*dy; //A
    inc_NE = 2*(dy - dx); //B

    RGBA color = color1;

    float dr = (color2.Red - color1.Red)/dx;
    float dg = (color2.Green - color1.Green)/dx;
    float db = (color2.Blue - color1.Blue)/dx;
    //float da = (color2.Alpha - color1.Alpha)/dx;

    PutPixel(x, y, color1);

    int i;
    for(i = 0; i < dx; i++){
        if(D < 0){ //Ponto medio ta abaixo da reta, deveria ir para nordeste ?
            if(swap){
                y += s2; //Se ocorreu troca eu mexo em Y, SE deltay for maior que delta x
            }else{
                x += s1;
            } //Seno mexo em x
            D += inc_L; //Nessa condição mexo no pixel leste
        }else{
            y += s2; // Mexo em x e em y.
            x += s1;
            D += inc_NE; //Se D for maior que 0 então vou para leste?
        }

        color.Red += dr; // incrementa cor por pixel  ate a cor final no ultimo pixel
        color.Green += dg;
        color.Blue += db;
        //color.Alpha += da;
        PutPixel(x, y, color);
    }
}


// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {

    Point p1 = {20, 20};
    Point p2 = {256, 491};
    Point p3 = {491, 20};

    DrawTriangulo(p1, p2, p3);

    //Teste_Script();

}


void Teste_Script(void){

    Point p1 = {256, 256};
    Point p2 = {511, 450};

    Line line1 = {p2, p1};

    //2 octante

    Point p3 = {256, 256};
    Point p4 = {270, 511};

    Line line2 = {p4, p3};

    //3 octante

    Point p5 = {255, 255};
    Point p6 = {50, 511};

    Line line3 = {p6, p5};

    //4 octante

    Point p7 = {255, 255};
    Point p8 = {0, 300};

    Line line4 = {p8, p7};

    //5 octante

    Point p9 = {255, 255};
    Point p10 = {0, 180};

    Line line5 = {p10, p9};

    //6 octante

    Point p11 = {255, 255};
    Point p12 = {150, 0};

    Line line6 = {p12, p11};

    //7 octante

    Point p13 = {255, 255};
    Point p14 = {400, 0};

    Line line7 = {p14, p13};

    //8 octante

    Point p15 = {255, 255};
    Point p16 = {511, 200};

    Line line8 = {p16, p15};

    DrawLine(line1.pi, line1.pf, white, red);
    DrawLine(line2.pi, line2.pf, red, green);
    DrawLine(line3.pi, line3.pf, red, blue);
    DrawLine(line4.pi, line4.pf, red, green);
    DrawLine(line5.pi, line5.pf, red, white);
    DrawLine(line6.pi, line6.pf, blue, green);
    DrawLine(line7.pi, line7.pf, green, blue);
    DrawLine(line8.pi, line8.pf, green, red);
}

void DrawTriangulo(Point p1, Point p2, Point p3){

    DrawLine(p1, p2, red, green);
    DrawLine(p2, p3, green, blue);
    DrawLine(p1, p3, red, blue);

}

