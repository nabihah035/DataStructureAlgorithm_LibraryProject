//MAIN.cpp
#include "LIBRARY.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Function to display the menu options
void displayMenu() {
    cout << "\n";
    cout << "\n\t*** LIBRARY SMART SYSTEM FOR STAFF ***\n\n";
    cout << "\t1) INSERT NEW BOOK INTO THE LIST\n";
    cout << "\t2) DELETE BOOK INFO FROM THE LIST\n";
    cout << "\t3) UPDATE BOOK INFO IN THE LIST\n";
    cout << "\t4) SEARCH A BOOK IN THE LIST BY TITLE\n";
    cout << "\t5) SORTING BOOK BY YEAR OF PUBLICATION\n";
    cout << "\t6) DELETE BOOK FROM UNRELAVENT YEAR\n";
    cout << "\t7) DISPLAY LIST OF THE BOOK\n";
    cout << "\t8) EXIT\n";
    cout << "\n\n";
}

// Function to pause the program and wait for user input
void pause() {
    cout << "\nPRESS ENTER TO CONTINUE...";
    cin.ignore();
    cin.get();
}

int main() {
    Library library; // Create a Library object
    int opt = 0; // Variable to store user option

    library.loadFromFile("books1.txt"); // Load book data from file

    do {
        displayMenu(); // Display the menu
        cout << "SELECT YOUR OPTION : ";
        cin >> opt;

        // Validate the user's option
        while (opt < 1 || opt > 8) {
            cout << "\nERROR. INVALID OPTION";
            cout << "\nSELECT YOUR OPTION : ";
            cin >> opt;
        }

        switch (opt) {
        case 1: { // Insert a new book
            string bookid, bookname, bookgenre, bookshelf;
            int year;
            char morebook;

            do {
                cout << "\nENTER TITLE OF THE BOOK: ";
                cin.ignore(); // Ignore the newline character left in the buffer
                getline(cin, bookname);

                cout << "ENTER GENRE OF THE BOOK: ";
                getline(cin, bookgenre);

                cout << "ENTER SHELF OF THE BOOK: ";
                getline(cin, bookshelf);

                cout << "ENTER THE BOOK ID: ";
                cin >> bookid;

                cout << "ENTER THE YEAR OF PUBLICATION: ";
                cin >> year;

                library.enqueue(bookid, bookname, bookgenre, bookshelf, year); // Add the book to the library
                cout << "BOOK ADDED SUCCESSFULLY." << endl;
                cout << "\nDO YOU WANT TO ADD ANOTHER BOOK? (Y/N) : ";
                cin >> morebook;

            } while (morebook == 'y' || morebook == 'Y');

            library.saveToFile("books2.txt"); // Save changes to file
            library.display(); // Display the current list of books
            pause(); // Pause the program
            break;
        }
        case 2: // Delete a book
            char character;
            cout << "DO YOU WANT TO VIEW LIST OF BOOKS IN LIBRARY? (Y/N):";
            cin >> character;
            if (character == 'Y' || character == 'y')
            {
                library.display();
            }
            else
                library.deleteBook();
            library.saveToFile("books2.txt"); // Save changes to file
            pause(); // Pause the program
            break;
        case 3: // Update a book
            char userinput;
            cout << "DO YOU WANT TO VIEW LIST OF BOOKS IN LIBRARY? (Y/N):";
            cin >> userinput;
            if (userinput == 'Y' || userinput == 'y')
            {
                library.display();
            }
            else
                library.updateBook();
            library.saveToFile("books1.txt"); // Save changes to file
            pause(); // Pause the program
            break;
        case 4: { // Search for a book by title
            if (library.isEmpty()) {
                cout << "NO BOOKS IN THE LIBRARY. PLEASE ADD BOOK FIRST." << endl;
            }
            else {
                string target;
                cout << "ENTER THE CHARACTERS TO SEARCH IN BOOK TITLE: ";
                cin.ignore(); // Ignore the newline character left in the buffer
                getline(cin, target);
                library.searchByCharacters(target);
            }
            char character;
            cout << "DO YOU WANT TO VIEW LIST OF BOOKS IN LIBRARY? (Y/N):";
            cin >> character;
            if (character == 'Y' || character == 'y')
            {
                library.display();
            }
            else
                pause(); // Pause the program
            break;
        }
        case 5: // Sort books by year of publication
            library.sortBooks();
            cout << "BOOKS SORTED BY YEAR OF PUBLICATION." << endl;
            library.saveToFile("books2.txt"); // Save changes to file
            library.display(); // Display the current list of books
            pause(); // Pause the program
            break;
        case 6: // Delete the front book from the queue
            char answer;
            cout << "BOOKS NEED TO SORTED BY YEAR BEFORE YOU DELETE, DO YOU WANT TO PROCEED? (Y/N):";
            cin >> answer;
            if (answer == 'Y' || answer == 'y')
            {
                library.sortBooks();
                library.dequeue();
            }
            else
                library.saveToFile("books2.txt"); // Save changes to file
            pause(); // Pause the program
            break;
        case 7: // Display the list of books
            library.display(); // Display the current list of books
            pause(); // Pause the program
            break;
        case 8: // Exit the program
            cout << "\n--------EXITING THE PROGRAM--------" << endl;
            library.saveToFile("books2.txt"); // Save book data to file
            break;
        default:
            break;
        }
    } while (opt != 8); // Continue until the user chooses to exit

    return 0;
}