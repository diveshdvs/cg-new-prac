#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

void plot8(int x, int y, int cx, int cy)
{
    putpixel(x + cx, y + cy, GREEN);
    putpixel(y + cx, x + cy, GREEN);
    putpixel(y + cx, -x + cy, GREEN);
    putpixel(x + cx, -y + cy, GREEN);
    putpixel(-x + cx, -y + cy, GREEN);
    putpixel(-y + cx, -x + cy, GREEN);
    putpixel(-y + cx, x + cy, GREEN);
    putpixel(-x + cx, y + cy, GREEN);
}

void midPointCircleDraw(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 1 - r;
    plot8(x, y, xc, yc);
    while (y > x)
    {
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
        plot8(x, y, xc, yc);
    }
}

int main()
{
    int cx, cy, r;
    int gdriver = DETECT, gmode;

    cout << "\n\n Practical 2 \n";
    cout << "\nEnter centre(x): ";
    cin >> cx;
    cout << "\nEnter centre(y): ";
    cin >> cy;
    cout << "\nEnter radius: ";
    cin >> r;

    initgraph(&gdriver, &gmode, NULL);
    midPointCircleDraw(cx, cy, r);
    getch();
    closegraph();
}
