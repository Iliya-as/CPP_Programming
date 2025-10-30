// shift+alt+f=formating
#include <iostream>
#include <conio.h>
#include <vector>
#include <iomanip>
using namespace std;
class Book
{
private:
    string Title;
    string Author;

public:
    void Set_Title()
    {
        string title;
        do
        {
            cout << "Enter the book title:";
            getline(cin >> ws, title);
        } while (title.empty());
        Title = title;
    }
    string Get_Title()
    {
        return Title;
    }
    void Set_Author()
    {
        string author;
        do
        {
            cout << "Enter the book Author:";
            getline(cin >> ws, author);
        } while (author.empty());
        Author = author;
    }
    string Get_Author()
    {
        return Author;
    }
};
class Managment
{
private:
    vector<Book> book;
    Book b;

public:
    void Add()
    {
        b.Set_Title();
        b.Set_Author();
        book.push_back(b);
    }
    void Search()
    {
        cout << "1)Search by book name" << setw(25) << "2)Search by author" << endl;
        cout << "Enter your choice:";
        int ch;
        vector<int> hold;
        cin >> ch;
        cin.ignore();
        switch (ch)
        {
        case 1:
        {
            string bn;
            cout << "Enter the book name:";
            getline(cin >> ws, bn);
            for (int i = 0; i < static_cast<int>(book.size()); i++)
            {
                if (bn == book[i].Get_Title())
                {
                    hold.push_back(i);
                }
                else
                {
                    continue;
                }
            }
            if (hold.empty())
            {
                cout << "Book dosen't exist" << endl;
            }
            else
            {
                cout << setw(20) << "i" << setw(20) << "Book Author " << endl;
                for (int i = 0; i < static_cast<int>(hold.size()); i++)
                {
                    cout << setw(18) << hold[i] + 1 << setw(20) << book[hold[i]].Get_Author() << endl;
                }
            }
            break;
        }
        case 2:
        {
            string an;
            cout << "Enter the author name:";
            getline(cin >> ws, an);
            for (int i = 0; i < static_cast<int>(book.size()); i++)
            {
                if (an == book[i].Get_Author())
                {
                    hold.push_back(i);
                }
                else
                {
                    continue;
                }
            }
            if (hold.empty())
            {
                cout << "author dosen't exist";
            }
            else
            {
                cout << setw(20) << "i" << setw(20) << "Book name" << endl;
                for (int i = 0; i < static_cast<int>(hold.size()); i++)
                {
                    cout << setw(18) << hold[i] + 1 << setw(20) << book[hold[i]].Get_Title() << endl;
                }
            }
            break;
        }
        }
    }
    void Remove()
    {
        Search();
        if(book.empty())
        {
            cout<<"no books to remove "<<endl;
            return ;
        }
        int index;
        cout << "Enter the book index from list:";
        cin >> index;
        if (index < 1 || index >static_cast<int>(book.size()))
        {
            cout << "Invalid input ! " << endl;
            return;
        }
        book.erase(book.begin()+(index - 1));
        cout<<"Book removed succesfully "<<endl;
    }
    void Show()
    {
        cout << setw(20) << "Book title " << setw(20) << "Book Author " << endl;
        for (int i = 0; i < static_cast<int>(book.size()); i++)
        {
            cout << i + 1 << ")" << setw(15) << book[i].Get_Title() << setw(20) << book[i].Get_Author() << endl;
        }
    }
    void Save()
    {

    }
};
bool End()
{
    string input;
    cout << "Do you want to continue?" << endl;
    getline(cin >> ws, input);
    if (input == "yes" || input == "Yes")
    {
        return true;
    }
    return false;
}
int main()
{
    Managment m;
    enum Menu
    {
        Add = 1,
        Search = 2,
        Remove = 3,
        Show = 4,
        Save = 5,
        Exit = 6
    };
    int o;
    while (true)
    {
        system("cls");
        cout << "1)Add" << endl
             << "2)Search" << endl
             << "3)Remove" << endl
             << "4)Show" << endl
             << "5)Save" << endl
             << "6)Exit" << endl;
        cout << string(40, '=');
        cout << endl
             << "Enter your option number:";
        cin >> o;
        switch (o)
        {
        case Add:
            system("cls");
            m.Add();
            break;
        case Search:
            system("cls");
            m.Search();
            break;
        case Remove:
            system("cls");
            m.Remove();
            break;
        case Show:
            system("cls");
            m.Show();
            break;
        case Save:
            system("cls");
            m.Save();
            break;
        case Exit:
            cout << "Exiting....." << endl;
            return 0;
        default:
            cout << "Invalid input";
        }
        if (End() == false)
        {
            cout << "Exiting....." << endl;
            return 0;
        }
    }
    getch();
    return 0;
}