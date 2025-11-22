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
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input ! \n";
            }
            else
            {
                break;
            }
        }
        m = new int *[r];
        for (int i = 0; i < r; i++)
        {
            m[i] = new int[c];
        }
    }
    void Set_Input()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                while (true)
                {
                    cout << "Enter A[" << i + 1 << "][" << j + 1 << "] : ";
                    cin >> m[i][j];
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input ! \n";
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    void Show()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << "A[" << i + 1 << "][" << j + 1 << "] : " << m[i][j] << "\t";
            }
            cout << endl;
        }
    }
    Matrix Add(const Matrix &b)
    {
        Matrix Res;
        if (this->r != b.r || this->c != b.c)
        {
            cout << "Dimensions are not match " << endl;
            return Res;
        }
        Res.r = r;
        Res.c = c;
        Res.m = new int *[Res.r];
        for (int i = 0; i < Res.r; i++)
        {
            Res.m[i] = new int[Res.c];
        }
        for(int i=0 ; i<r ; i++)
        {
            for(int j=0;j<c;j++)
            {
                Res.m[i][j]=m[i][j]+b.m[i][j];
            }
        }
        return Res;
    }
};
int main()
{
    Matrix a,b;
    a.Create_Matrix();
    a.Set_Input();
    a.Show();
    cout<<endl<<endl;
    b.Create_Matrix();
    b.Set_Input();
    b.Show();
    cout<<endl<<endl;
    Matrix c=a.Add(b);
    cout<<endl;
    c.Show();
}