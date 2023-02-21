#include <GL/glut.h>
#include <iostream>
#define Round(x) ((int)(x+0.5))
using namespace std;

void plot(int x, int y, int xc, int yc) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
    glEnd();
    glFlush();
    
}

void Line(float xa, float ya, float xb, float yb) { // Using DDA

        int dx = xb - xa;
        int dy = yb - ya;
        int step, k;
        float x = xa, xi;
        float y = ya, yi;



        if (abs(dx) > abs(dy))
            step = abs(dx);
        else
            step = abs(dy);


        xi = dx / float(step);
        yi = dy / float(step);
        glBegin(GL_POINTS);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1, 1, 0);
        glVertex2s(Round(x), Round(y));
        for (k = 0; k < step; k++) {
            x = x + xi;
            y = y + yi;
            glVertex2s(Round(x), Round(y));

        }
        glEnd();
        glFlush();
    }



void Circle(int xc, int yc, int r) { // Using Bresenham
    int d, x, y;
    x = 0;
    y = r;
    d = 3 - 2 * r;
    while (x <= y) {
        plot(x, y, xc, yc);
        if (d < 0) {
            d = d + 4 * x + 6;
            x = x + 1;
        }
        if (d >= 0) {
            d = d + 4 * (x - y) + 10;
            x = x + 1;
            y = y - 1;
        }
    }
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(25);
    glColor3f(1, 0, 1);
    glPointSize(3.0);
    Circle(50, 110, 8);
    Line(30, 70, 70, 70);//1
    Line(30, 130, 70, 130);//2
    Line(30, 70, 30, 130);//3
    Line(70, 70, 70, 130);//4
    Line(10, 70, 30, 70);//5
    Line(10, 70, 10, 130);//6
    Line(10, 130, 30, 130);//7
    Line(10, 130, 20, 160);//8
    Line(20, 160, 30, 130);//9
    Line(20, 160, 60, 160);//10
    Line(60, 160, 70, 130);//11
    Line(15, 70, 15, 95);//12
    Line(25, 70, 25, 95);//13
    Line(15, 95, 25, 95);//14

}

void Init(void)
{
    glClearColor(0, 0, 0, 0);
    glColor3f(1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 100, 0, 200);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //glutInitWindowSize(500,500);
    glutInitWindowSize(500, 700);
    glutInitWindowPosition(50, 100);
    glutCreateWindow("Hut is Here!!");
    glutDisplayFunc(display);
    Init();
    glutMainLoop();
}