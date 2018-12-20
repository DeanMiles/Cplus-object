#include <string>
#include <cstdio>

using namespace std;

class Book
{
    string author;
    string title;
    string category;
    unsigned int page_number;
    bool avalibility;

    public:

    Book(string au, string tit, string cat, unsigned int pages):author(au), title(tit), category(cat), page_number(pages)//lista inicjacyjna
    {
        avalibility = true ;
    }

    Book& rent() 
    {
        avalibility = false; 
	cout<< " The is not available book"<<endl;
	return *this;
    }

    friend ostream& operator<<(ostream& s, Book toDisp);
};

ostream& operator << (ostream& out, Book toDisp)
{
    out << "\nauthor: " << toDisp.author << "\ntitle: " << toDisp.title;
    out << "\ncategory: " << toDisp.category << ", pages: " << toDisp.page_number;
    out << ", status: " << (toDisp.avalibility ? "available" : "rented" )<<"\n";
    return out;
}


