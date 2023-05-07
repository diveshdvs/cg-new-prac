#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void bezier(const int *x, const int *y)
{
    double t;
    for (t = 0.0; t < 1.0; t += 0.0005)
    {
        double xt = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
        double yt = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];
        putpixel(xt, yt, BLUE);
    }
    setcolor(YELLOW);
    for (int i = 1; i < 4; i++)
        line(x[i - 1], y[i - 1], x[i], y[i]);
}
int main()
{
    int gdriver = DETECT, gmode;
    int x[4] = {100, 300, 300, 200};
    int y[4] = {300, 400, 200, 100};

    initgraph(&gdriver, &gmode, NULL);
    bezier(x, y);
    getch();
    closegraph();
}
