#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void TriAngle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void Rotate(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int x, y, a1, b1, a2, b2, a3, b3;
    float Angle;
    printf("Enter the angle for rotation: ");
    scanf("%f", &Angle);
    cleardevice();
    Angle = (Angle * 3.14) / 180;
    a1 = x2 + (x1 - x2) * cos(Angle) - (y1 - y2) * sin(Angle);
    b1 = y2 + (x1 - x2) * sin(Angle) + (y1 - y2) * cos(Angle);
    a2 = x2 + (x2 - x2) * cos(Angle) - (y2 - y2) * sin(Angle);
    b2 = y2 + (x2 - x2) * sin(Angle) + (y2 - y2) * cos(Angle);
    a3 = x2 + (x3 - x2) * cos(Angle) - (y3 - y2) * sin(Angle);
    b3 = y2 + (x3 - x2) * sin(Angle) + (y3 - y2) * cos(Angle);
    printf("Rotated: ");
    TriAngle(a1, b1, a2, b2, a3, b3);
}

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    initgraph(&gd, &gm, (char *)" ");
    printf("Enter the 1st point for the triangle: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the 2nd point for the triangle: ");
    scanf("%d%d", &x2, &y2);
    printf("Enter the 3rd point for the triangle: ");
    scanf("%d%d", &x3, &y3);
    TriAngle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();
    Rotate(x1, y1, x2, y2, x3, y3);
    setcolor(5);
    TriAngle(x1, y1, x2, y2, x3, y3);
    getch();
    return 0;
}