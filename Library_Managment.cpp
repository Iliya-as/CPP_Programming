#include<iostream>
#include<conio.h>

using namespace std;
class Book
{
    private:
        string Title;
        string Author;
        bool Is_Available;
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
int main()
{

}