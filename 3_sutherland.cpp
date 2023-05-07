// Cohen Sutherland Line Clipping Algorithm

#include <graphics.h>
#include <iostream>

using namespace std;

typedef const int cpixel;

enum _position // region codes
{
	INSIDE = 0x0, // 0000
	LEFT = 0x1,	  // 0001
	RIGHT = 0x2,  // 0010
	BOTTOM = 0x4, // 0100
	TOP = 0x8	  // 1000
};

// Define window parameters
cpixel X_MIN = 100;
cpixel Y_MIN = 100;
cpixel X_MAX = 400;
cpixel Y_MAX = 300;

struct point2d
{
	int x, y;

	point2d(cpixel &a, cpixel &b) : x(a), y(b) {}
	friend ostream &operator<<(ostream &os, const point2d &p)
	{
		os << "( " << p.x << " , " << p.y << " )";
		return os;
	}
};

// Define function to get region code for a point
int getRegionCode(const point2d &p)
{
	int code = INSIDE;
	if (p.x < X_MIN)
		code |= LEFT;
	else if (p.x > X_MAX)
		code |= RIGHT;
	if (p.y < Y_MIN)
		code |= BOTTOM;
	else if (p.y > Y_MAX)
		code |= TOP;
	return code;
}

// Define function to clip a line using Cohen-Sutherland algorithm
void cohenSutherlandLineClip(point2d &p1, point2d &p2)
{
	int regionCode1 = getRegionCode(p1);
	int regionCode2 = getRegionCode(p2);
	bool accept = false;

	while (true)
	{
		if (!(regionCode1 | regionCode2)) // Both points inside window
		{
			accept = true;
			break;
		}
		else if (regionCode1 & regionCode2) // Both points outside same region
		{
			break;
		}
		else
		{
			int x, y;
			int regionCodeOut = regionCode1 ? regionCode1 : regionCode2;

			if (regionCodeOut & TOP)
			{
				x = p1.x + (p2.x - p1.x) * (Y_MAX - p1.y) / (p2.y - p1.y);
				y = Y_MAX;
			}
			else if (regionCodeOut & BOTTOM)
			{
				x = p1.x + (p2.x - p1.x) * (Y_MIN - p1.y) / (p2.y - p1.y);
				y = Y_MIN;
			}
			else if (regionCodeOut & RIGHT)
			{
				y = p1.y + (p2.y - p1.y) * (X_MAX - p1.x) / (p2.x - p1.x);
				x = X_MAX;
			}
			else if (regionCodeOut & LEFT)
			{
				y = p1.y + (p2.y - p1.y) * (X_MIN - p1.x) / (p2.x - p1.x);
				x = X_MIN;
			}

			if (regionCodeOut == regionCode1)
			{
				p1.x = x;
				p1.y = y;
				regionCode1 = getRegionCode(p1);
			}
			else
			{
				p2.x = x;
				p2.y = y;
				regionCode2 = getRegionCode(p2);
			}
		}
	}
	if (accept)
	{
		// Draw the clipped line
		setcolor(GREEN);
		line(p1.x, p1.y, p2.x, p2.y);
	}
}

int main()
{
	int gd = DETECT, gm;
	point2d p1(50, 70), p2(170, 150);

	initgraph(&gd, &gm, NULL);
	// Draw the window
	setcolor(WHITE);
	rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
	setcolor(RED);
	line(p1.x, p1.y, p2.x, p2.y);

	cout << "\n Practical 3\n";
	cout << "\nInitial Line:\np1 : " << p1 << "\tp2: " << p2 << endl;

	cohenSutherlandLineClip(p1, p2);
	cout << "\nClipped Line:\np1 : " << p1 << "\tp2: " << p2 << endl;

	getch();
	closegraph();
	return 0;
}