﻿// ЛБ№2_ЗД1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
    int a=12, b=64, c=16, d=34;
    int x, x2, x3, y, y2, y3;

    x = ((((a << 7) + (a << 6) + (a << 3)) + ((c << 8) + (c << 6) - (c << 3)))>> 4);
    x2 = (((d << 7) - (d << 3)) + ((c << 7) - (c << 2)));
    x3 = (x - x2);
    cout << "Solution: " << x3 << endl;
 //======================================//
    y = (((200 * 12) + (312 * 16)) / 16);
    y2 = ((34 * 120) + (16 * 124));
    y3 = (y - y2);
    cout << "Check: " << y3;
}
