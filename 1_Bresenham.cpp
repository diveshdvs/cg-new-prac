#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void bresenhamLine(int x0, int y0, int x1, int y1, int val)
{
  if (x0 == x1 && y0 == y1)
  {
    putpixel(x1, y1, val);
  }
  else
  {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = 2 * dy - dx;
    int del_E = 2 * dy;
    int del_NE = 2 * (dy - dx);
    int x = x0;
    int y = y0;
    putpixel(x, y, val);

    while (x < x1)
    {
      if (d <= 0)
      {
        d += del_E;
        x += 1;
      }
      else
      {
        d += del_NE;
        x += 1;
        y += 1;
      }

      putpixel(x, y, val);
    }
  }
}

int main(void)
{
  int x0, y0, x1, y1;

  cout << "\n Practical 1\n";
  cout << "\nEnter Left Endpoint (x0 y0): ";
  cin >> x0 >> y0;
  cout << "Enter Right Endpoint (x1 y1): ";
  cin >> x1 >> y1;
  cout << "Drawing Line..." << endl;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  bresenhamLine(x0, y0, x1, y1, WHITE);
  getch();
  closegraph();
  return 0;
}
