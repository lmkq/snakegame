// conran32cm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "library.h"
using namespace std;

int X[100*20], Y[100*20];
int snake[32] = { 4,8,0,7,2,1,1,2 };
int len=4;

void buildsnake();
void buildwall();
void snakemove();
void movee(int x, int y);
bool dungtuong();
void food(int& xfood, int& yfood);
bool ktan(int xfood, int yfood);
bool ktanduoi();
int main()
{
    srand(time(NULL));
    ShowCur(0);
    buildwall();
    buildsnake();
    int x = X[0];
    int y = Y[0];
    int xfood, yfood;
    food(xfood, yfood);
    gotoXY(xfood, yfood); cout << char(3);
    int check = 2;
    while (true)
    {   
        gotoXY(X[len], Y[len]);
        cout << " ";
        snakemove();
        if (_kbhit())
        {
            char c = _getch();
            if (c == 'w' && check!=3)
            {
                check = 1;
            }
            else if (c == 'd' && check !=4)
            {
                check = 2;
            }
            else if (c == 's' && check !=1)
            {
                check = 3;
            }
            else if (c == 'a' && check!=2)
            {
                check = 4;
            }
        }
        if (check == 1)
            {
                y--;
            }
            else if (check == 2)
            {
                x++;
            }
            else if (check == 3)
            {
                y++;
            }
            else if (check == 4)
            {
                x--;
            }
        if (ktan(xfood,yfood))
        {
            len++;
            food(xfood, yfood);
            gotoXY(xfood, yfood); cout << char(3);
        }
        if (ktanduoi()) break;
        if (dungtuong()) break;
        movee(x,y);
        Sleep(150);
        
    }
    _getch();
}

void buildwall()
{
    SetColor(11);
    for (int x = 1; x <=100; x++)
    {
        gotoXY(x,0);
        cout <<char(196);
        gotoXY(x,20);
        cout <<char(196);
    }
    for (int y = 0; y <=20; y++)
    {
        gotoXY(0,y);
        cout <<char(179);
        gotoXY(100,y);
        cout <<char(179);
    }
    gotoXY(0,20); cout << char(192);
    gotoXY(100,0); cout << char(191);
    gotoXY(100, 20); cout << char(217);
    gotoXY(0,0); cout << char(218);
}
void buildsnake() //randautien
{
    int x = 50;
    int y = 10;
    for (int i = 0; i < len; i++)
    {
        X[i] = x;
        Y[i] = y;
        x--;
    }
}
void snakemove()
{
    for (int i = 0; i < len; i++)
    {
        gotoXY(X[i], Y[i]);
        cout << snake[i];
    }
}
void movee(int x, int y)
{
    for (int i = len; i > 0; i--)
    {
        X[i] = X[i - 1];
        Y[i] = Y[i - 1];
    }
    X[0] = x;
    Y[0] = y;
}
bool dungtuong()
{
    if (X[0] == 100 || X[0] == 0 || Y[0] == 0 || Y[0] == 20) return true;
    else return false;
}
void food(int &xfood,int &yfood)
{
    xfood = rand() % (99) + 1;
    yfood = rand() % (19) + 1;
    for (int i = 0; i < len; i++)
    {
        if (xfood == X[i] && yfood == Y[i]) food(xfood, yfood);
    }
}
bool ktan(int x,int y)
{
    if (X[0] == x && Y[0] == y) return true;
    else return false;
}
bool ktanduoi()
{
    for (int i = 1; i < len; i++)
        if (X[0] == X[i] && Y[0] == Y[i]) return true;
    return false;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
