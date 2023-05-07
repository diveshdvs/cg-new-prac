
#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

template <class T>
void draw(T x[][4], int size, _color c)
{
    setcolor(c);
    for (int i = 0; i < size; ++i)
    {
        line(round(200 + x[i % size][0]),
             round(200 + x[i % size][1]),
             round(200 + x[(i + 1) % size][0]),
             round(200 + x[(i + 1) % size][1]));
    }
}

class matrix
{
    int nodes[10][4];
    float T[4][4];
    int size, angle;

public:
    matrix(int s)
    {
        size = s;
        cout << "\nThe number of nodes are : \n"
             << size;
        for (int i = 0; i < size; ++i)
            nodes[i][3] = 1;
    }
    void input()
    {
        cout << endl;
        for (int i = 0; i < size; ++i)
        {
            cout << "Enter P" << i << " : ";
            for (int j = 0; j < 3; ++j)
                cin >> nodes[i][j];
        }
        cout << "\nEnter angle along x axis : ";
        cin >> angle;
    }

    void rotation()
    {

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                cout << nodes[i][j] << " ";
            }
            cout << endl;
        }
        float r = angle * (3.14 / 180);
        float T[4][4] = {0};

        T[0][0] = 1;
        T[3][3] = 1;

        T[1][1] = cos(r);
        T[1][2] = sin(r);
        T[2][1] = -1 * sin(r);
        T[2][2] = cos(r);

        cout << "\n\n";
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                cout << T[i][j] << " ";
            }
            cout << endl;
        }
        float rr[3][4] = {0};
        int n = size;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                rr[i][j] = 0;
                for (int k = 0; k < 4; k++)
                    rr[i][j] += nodes[i][k] * T[k][j];
            }
        }
        cout << "\n\n";
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < 4; ++j)
                cout << rr[i][j] << " ";
            cout << endl;
        }

        draw(nodes, size, WHITE);
        setcolor(RED);
        draw(rr, size, BLUE);
    }
};
int main()
{
    int gdriver = DETECT, gmode;

    cout << "\n Practical 7\n";
    matrix m(3);
    m.input();

    initgraph(&gdriver, &gmode, NULL);
    m.rotation();
    getch();
    closegraph();
    return 0;
}
