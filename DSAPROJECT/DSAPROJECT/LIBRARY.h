//LIBRARY.h
#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define MAX 100 // Maximum number of books that can be stored

// Structure to represent a book
struct Book {
    string id;
    string name;
    string genre;
    string shelf;
    int year; // Year of publication
};

class Library {
public:
    Book books[MAX]; // Array to store books
    int front; // Index of the front of the queue
    int rear; // Index of the rear of the queue
    int count; // Number of books in the queue

    Library(); // Constructor
    bool isEmpty(); // Check if the queue is empty
    bool isFull(); // Check if the queue is full
    void enqueue(string id, string name, string genre, string shelf, int year); // Add a book to the queue
    void dequeue(); // Remove a book from the front of the queue
    void display(); // Display all books in the queue
    void deleteBook(); // Delete a book by ID
    void updateBook(); // Update book information
    bool searchByCharacters(const string& characters); // Search for a book by characters in title
    void sortBooks(); // Sort books by year of publication
    void loadFromFile(string filename); // Load books from a file
    void saveToFile(string filename); // Save books to a file
};

#endif