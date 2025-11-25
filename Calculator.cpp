#include <iostream>
#include <conio.h>
#include <math.h>
#include <limits>
#include <iomanip>
#include <windows.h>
using namespace std;
class Matrix
{
private:
    int r, c;
    int **m;

public:
    Matrix()
    {
        r = 0;
        c = 0;
        m = nullptr;
    }
    ~Matrix()
    {
        if (m != nullptr)
        {
            for (int i = 0; i < r; i++)
            {
                delete[] m[i];
            }
            delete[] m;
        }
    }
    void Create_Matrix()
    {
        while (true)
        {
            cout << "Enter the row & col numbers : ";
            cin >> r >> c;
            if (r <= 0 || c <= 0 || cin.fail())
            {
    