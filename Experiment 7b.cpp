#include <iostream>
using namespace std;

class Book {
private:
    static int bookCount;
    static int nextBookID;
    int bookID;
    string title;

public:
    Book(string t) : title(t) {
        bookID = ++nextBookID;
        bookCount++;
    }

    static int getBookCount() {
        return bookCount;
    }

    void displayBookDetails() {
        cout << "Book ID: " << bookID << ", Title: " << title << endl;
    }
};

int Book::bookCount = 0;
int Book::nextBookID = 1000;

int main() {
    Book b1("OOPS: Ek Prem katha ");
    Book b2("DSA: One Man Army ");

    b1.displayBookDetails();
    b2.displayBookDetails();

    cout << "Total Books Created: " << Book::getBookCount() << endl;

    return 0;
}


