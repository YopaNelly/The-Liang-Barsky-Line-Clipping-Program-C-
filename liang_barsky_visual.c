#include <GL/glut.h>
#include <stdio.h>

float xmin = 30, ymin = 30, xmax = 80, ymax = 70;
float x_start = 20, y_start = 20;
float x_end   = 100, y_end   = 80;

void liangBarsky(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float p[4] = { -dx, dx, -dy, dy };
    float q[4] = { x1 - xmin, xmax - x1, y1 - ymin, ymax - y1 };

    float u1 = 0.0, u2 = 1.0;
    float r;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0 && q[i] < 0)
            return;

        if (p[i] != 0) {
            r = q[i] / p[i];
            if (p[i] < 0 && r > u1) u1 = r;
            if (p[i] > 0 && r < u2) u2 = r;
        }
    }

    if (u1 > u2) return;

    float cx1 = x1 + u1 * dx;
    float cy1 = y1 + u1 * dy;
    float cx2 = x1 + u2 * dx;
    float cy2 = y1 + u2 * dy;

    // Draw clipped line (green)
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(cx1, cy1);
    glVertex2f(cx2, cy2);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw clipping window (white)
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();

    // Draw original line (red)
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(x_start, y_start);
    glVertex2f(x_end, y_end);
    glEnd();

    // Draw clipped line
    liangBarsky(x_start, y_start, x_end, y_end);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Liang-Barsky Line Clipping");

    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 120, 0, 120);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

