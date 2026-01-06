//LIBRARY.cpp
#include "LIBRARY.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Constructor
Library::Library() {
    front = 0;
    rear = -1;
    count = 0;
}

// Check if the queue is empty
bool Library::isEmpty() {
    return count == 0;
}

// Check if the queue is full
bool Library::isFull() {
    return count == MAX;
}

// Add a book to the queue
void Library::enqueue(string id, string name, string genre, string shelf, int year) {
    if (isFull()) {
        cout << "LIST IS FULL. CANNOT ADD MORE BOOKS." << endl;
        return;
    }
    rear = (rear + 1);
    books[rear].id = id;
    books[rear].name = name;
    books[rear].genre = genre;
    books[rear].shelf = shelf;
    books[rear].year = year;
    count++;
}

// Remove a book from the front of the queue
void Library::dequeue() {
    if (isEmpty()) {
        cout << "LIST IS EMPTY. CANNOT DELETE BOOK." << endl;
        return;
    }
    cout << "BOOK WITH ID " << books[front].id << " DELETED." << endl;
    front = (front + 1);
    count--;
}

// Display all books in the queue
void Library::display() {
    if (isEmpty()) {
        cout << "LIST IS EMPTY." << endl;
        return;
    }
    cout << "\nBOOKS IN THE LIST : \n";
    int j = front;
    for (int i = 0; i < count; i++) {
        cout << "\n\tBOOK ID: " << books[j].id << ", TITLE: " << books[j].name << ", GENRE: " << books[j].genre << ", SHELF: " << books[j].shelf << ", YEAR: " << books[j].year << endl;
        j = (j + 1);
    }
}

// Delete a book by ID
void Library::deleteBook() {
    char moredelete;

    if (isEmpty()) {
        cout << "\nTHE BOOK LIST IS EMPTY!\n";
        return;
    }

    bool found = false;
    string bookID;

    cout << "ENTER THE BOOK ID: ";
    cin >> bookID;

    int index = front;
    for (int i = 0; i < count; i++) {
        if (books[index].id == bookID) {
            found = true;
            break;
        }
        index = (index + 1);
    }

    if (found) {
        cout << "\nBOOK ID: " << books[index].id
            << "\nBOOK TITLE: " << books[index].name
            << "\nBOOK GENRE: " << books[index].genre
            << "\nBOOK DELETED SUCCESSFULLY!\n";

        for (int i = index; i != rear; i = (i + 1)) {
            books[i] = books[(i + 1)];
        }

        rear = (rear - 1 + MAX);
        count--;
    }
    else {
        cout << "\nTHE BOOK IS NOT FOUND!\n";
    }

}

// Update book information
void Library::updateBook() {
    char moreupdate;

    if (isEmpty()) {
        cout << "\nTHE BOOK LIST IS EMPTY!\n";
        return;
    }

    string bookId;
    cout << "ENTER BOOK ID: ";
    cin >> bookId;
    cin.ignore();

    int index = front;
    for (int i = 0; i < count; i++) {
        if (books[index].id == bookId) {
            cout << "\nBOOK ID: " << books[index].id << endl;
            cout << "ENTER UPDATED BOOK TITLE: ";
            getline(cin, books[index].name);
            cout << "ENTER UPDATED BOOK GENRE: ";
            getline(cin, books[index].genre);
            getline(cin, books[index].shelf);
            cout << "ENTER UPDATED YEAR OF PUBLICATION: ";
            cin >> books[index].year;
            cout << "\nBOOK RECORD UPDATED SUCCESSFULLY!" << endl;
            return;
        }
        index = (index + 1);
    }
    cout << "\nBOOK NOT FOUND!" << endl;
}

// Search for a book by ID
bool Library::searchByCharacters(const string& characters) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        int index = (front + i);
        if (books[index].name.find(characters) != string::npos) {
            cout << "BOOK FOUND:\n";
            cout << "\tBOOK ID: " << books[index].id << ", TITLE: " << books[index].name << ", GENRE: " << books[index].genre << ", SHELF: " << books[index].shelf << ", YEAR: " << books[index].year << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "NO BOOKS FOUND WITH THE GIVEN CHARACTERS." << endl;
    }
    return found;
}


// Sort books by ID
void Library::sortBooks()
{
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = 0; j < count - i - 1; ++j)
        {
            int currentIndex = (front + j);
            int nextIndex = (front + j + 1);
            if (books[currentIndex].year > books[nextIndex].year)
            {
                swap(books[currentIndex], books[nextIndex]);
            }

        }
    }
}

// Load books from a file
void Library::loadFromFile(string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string id, name, genre, shelf;
        int year;
        while (getline(file, id) && getline(file, name) && getline(file, genre) && getline(file, shelf) && (file >> year)) {
            enqueue(id, name, genre, shelf, year);
            file.ignore(); // Ignore newline character
        }
        file.close();
    }
    else {
        cout << "ERROR OPENING FILE." << endl;
    }
}
// Save books to a file
void Library::saveToFile(string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        int j = front;
        for (int i = 0; i < count; i++) {
            file << books[j].id << endl;
            file << books[j].name << endl;
            file << books[j].genre << endl;
            file << books[j].shelf << endl;
            file << books[j].year << endl;
            j = (j + 1);
        }
        file.close();
    }
    else {
        cout << "ERROR OPENING FILE." << endl;
    }
}
