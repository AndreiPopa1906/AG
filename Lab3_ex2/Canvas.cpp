#include "Canvas.h"
#include <cmath>
#include <stdio.h>
#include <iostream>
#define pi 3.14159265358979323846 
void Canvas::fill(int x, int y,char ch)
{
    if (x < 0 || x >= this->h || y < 0 || y >= this->w) return;
    if (this->a[x][y] == ch || this->a[x][y] != ' ') return;
    this->a[x][y] = ch;
    if (x > 0 && this->a[x - 1][y] == ' ') fill(x - 1, y, ch);
    if (y > 0 && this->a[x][y - 1] == ' ') fill(x, y - 1, ch);
    if (x < this->h - 1 && this->a[x + 1][y] == ' ') fill(x + 1, y, ch);
    if (y < this->w - 1 && this->a[x][y + 1] == ' ') fill(x, y + 1, ch);
}
Canvas::Canvas(int width, int height)
{
    this->h = height;
    this->w = width;
    this->a = new char* [height];
    for (int i = 0; i < height; i++)
        this->a[i] = new char[width];
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            this->a[i][j] = ' ';
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int cx, cy;
    for (int i = 0; i <= 359; i++)
    {
        cx = (int)(x + sin(i)* ray);
        cy = (int)(y + cos(i) * ray);
        this->SetPoint(cx, cy, ch);
    }
}
/*void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    int cx, cy;
    for (double i = 0; i <= 360; i+=0.1)
    {
        cx = (int)(x + sin(i * 3.14 / 180.0) * ray);
        cy = (int)(y + cos(i * 3.14 / 180.0) * ray);
        this->DrawLine(x, y, cx, cy, ch);
    }
}*/
/*
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int cx = ray;
    int cy = 0;
    int d = 1 - ray;
    while (cx >= cy)
    {
        SetPoint(x + cx, y + cy, ch);
        SetPoint(x + cy, y + cx, ch);
        SetPoint(x - cy, y + cx, ch);
        SetPoint(x - cx, y + cy, ch);
        SetPoint(x - cx, y - cy, ch);
        SetPoint(x - cy, y - cx, ch);
        SetPoint(x + cy, y - cx, ch);
        SetPoint(x + cx, y - cy, ch);
        cy++;
        if (d < 0)
            d += 2 * cy + 1;
        else
        {
            cx--;
            d += 2 * (cy - cx) + 1;
        }
    }
}*/
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    Canvas::DrawCircle(x, y, ray, ch);
    Canvas::fill(x, y, ch);
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int x = x1;
    int y = y1;

    while (true)
    {
        this->SetPoint(x, y, ch);
        if (x == x2 && y == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
}
void Canvas::Print()
{
    for (int i = 0; i < this->h; i++) 
    {
        for (int j = 0; j < this->w; j++) 
        {
            printf("%c ", this->a[i][j]);
        }
        printf("\n");
    }
}
void Canvas::Clear()
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            a[i][j] = ' ';
}
void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < this->h && y >= 0 && y < this->w) 
        this->a[y][x] = ch;
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    Canvas::DrawLine(left, top, right, top, ch);
    Canvas::DrawLine(right, top, right, bottom, ch);
    Canvas::DrawLine(right, bottom, left, bottom, ch);
    Canvas::DrawLine(left, bottom, left, top, ch);
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = left; i <= right; i++)
        Canvas::DrawLine(i, top, i, bottom, ch);
}