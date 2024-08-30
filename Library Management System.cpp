// Library Management System (Eguia, Ross Simon S - 08/28/2024)

#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 10;

class Detail{
public:

    string title;
    string author;
    int year;

    Detail() : title(""), author(""), year(0) {}
};

class Library{
private:
	
    Detail books[MAX_BOOKS];
    int bookCount;

public:
    Library() : bookCount(0) {}

    void addBook(const string& title, const string& author, int year) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount].title = title;
            books[bookCount].author = author;
            books[bookCount].year = year;
            bookCount++;
            cout << "\nBook added successfully!\n";
        } else {
            cout << "Library is now full, cannot add more books.\n";
        }
    }

    void displayBooks() const {
        cout << "\nBook List:\n\n";
        cout << "Title                           Author           		      Year\n";
        cout << endl; 
        for (int i = 0; i < bookCount; i++) {
            cout << books[i].title << "           	        " << books[i].author << "    		              " << books[i].year << "\n";
        }
    }

    void searchBook(const string& title) const {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].title == title) {
                cout << "\nBook found!\n";
                cout << "Title: " << books[i].title << "\n";
                cout << "Author: " << books[i].author << "\n";
                cout << "Year: " << books[i].year << "\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n\nMenu\n";
        cout << "1 - Add Book\n";
        cout << "2 - Display Books\n";
        cout << "3 - Search Book\n";
        cout << "4 - Exit\n\n";
        cout << "Enter your choice [1-4]: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author;
                int year;
                cout << "\n[Adding a Book]";
                cout << "\n\nEnter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter year of publication: ";
                cin >> year;
                lib.addBook(title, author, year);
                break;
            }
            case 2:
                lib.displayBooks();
                break;
            case 3: {
                string title;
                cout << "\nEnter a book to search: ";
                cin.ignore();
                getline(cin, title);
                lib.searchBook(title);
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}