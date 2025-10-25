#include<iostream>
#include<conio.h>
#include<vector>
#include<iomanip>
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
                cout<<"Enter the book title:";
                getline(cin>>ws,title);
            }
            while(title.empty());
            Title=title;
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
                cout<<"Enter the book Author:";
                getline(cin>>ws,author);
            }
            while(author.empty());
            Author=author;
        }
        string Get_Author()
        {
            return Author;
        }
};
class Managment
{
    private:
        vector <Book> book;
        Book b;
    public:
        void Add()
        {
            b.Set_Title();
            b.Set_Author();
            book.push_back(b);
        }
`       void Search()
        {
            
        }

        void Show()
        {
            cout<<setw(20)<<"Book title "<<setw(20)<<"Book Author "<<endl;
            for(int i=0; i<static_cast<int>(book.size()); i++)
            {
                cout<<i+1<<")"<<setw(15)<<book[i].Get_Title()<<setw(20)<<book[i].Get_Author()<<endl;
            }
        }

};
bool End()
{
    string input;
    cout<<"Do you want to continue?"<<endl;
    getline(cin>>ws,input);
    if(input=="yes" || input=="Yes")
        {
            return true;
        }
    return false;
}
int main()
{
    Managment m;
    enum Menu { Add=1 , Search=2 , Remove=3 , Show=4 , Save=5 , Exit=6};
    int o;
    while(true)
    {
        system("cls");
        cout<<"1)Add"<<endl<<"2)Search"<<endl<<"3)Remove"<<endl<<"4)Show"<<endl<<"5)Save"<<endl<<"6)Exit"<<endl;
        cout<<string(40 , '=');
        cout<<endl<<"Enter your option number:";
        cin>>o;
        switch (o)
        {
        case Add:
            system("cls");
            m.Add();
            break;
        case Search:   
            system("cls");
            break;
        case Remove:
            system("cls");
            break;
        case Show:
            system("cls");
            m.Show();
            break;
        case Save:
            system("cls");
            break;
        case Exit:
            cout<<"Exiting....."<<endl;
            return 0;
        default:
            cout<<"Invalid input";
        }
        if(End()==false)
            {
                cout<<"Exiting....."<<endl;
                return 0;
            }
    }
}