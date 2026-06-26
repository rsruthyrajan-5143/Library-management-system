#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool issued;
};

void addBook()
{
    Book b;
    ofstream file("library.txt", ios::app);

    cout << "\nEnter Book ID: ";
    cin >> b.id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, b.title);

    cout << "Enter Author Name: ";
    getline(cin, b.author);

    b.issued = false;

    file << b.id << endl;
    file << b.title << endl;
    file << b.author << endl;
    file << b.issued << endl;

    file.close();

    cout << "\nBook Added Successfully!\n";
}

void displayBooks()
{
    Book b;
    ifstream file("library.txt");

    if (!file)
    {
        cout << "\nNo Books Found!\n";
        return;
    }

    while (file >> b.id)
    {
        file.ignore();
        getline(file, b.title);
        getline(file, b.author);
        file >> b.issued;

        cout << "\n------------------------";
        cout << "\nBook ID : " << b.id;
        cout << "\nTitle   : " << b.title;
        cout << "\nAuthor  : " << b.author;
        cout << "\nStatus  : ";

        if (b.issued)
            cout << "Issued";
        else
            cout << "Available";

        cout << endl;
    }

    file.close();
}

void searchBook()
{
    Book b;
    string search;

    cout << "\nEnter Book Title: ";
    cin.ignore();
    getline(cin, search);

    ifstream file("library.txt");
    bool found = false;

    while (file >> b.id)
    {
        file.ignore();
        getline(file, b.title);
        getline(file, b.author);
        file >> b.issued;

        if (b.title == search)
        {
            cout << "\nBook Found!";
            cout << "\nID : " << b.id;
            cout << "\nAuthor : " << b.author;
            cout << "\nStatus : ";

            if (b.issued)
                cout << "Issued";
            else
                cout << "Available";

            found = true;
        }
    }

    if (!found)
        cout << "\nBook Not Found!";

    file.close();
}

void issueBook()
{
    cout << "\nIssue Book feature can be implemented using file update.\n";
}

void returnBook()
{
    cout << "\nReturn Book feature can be implemented using file update.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n====== LIBRARY MANAGEMENT SYSTEM ======\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}
