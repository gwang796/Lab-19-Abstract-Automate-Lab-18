//
//  main.cpp
//  COMSC-210 | Lab 19: Abstract & Automate Lab 18 | Guo An Wang
//  IDE: Xcode
//  Created by Guo An Wang on 10/4/25.
//

#include <iostream>
#include <iomanip>
using namespace std;
// declaring Movie struct with
struct Movie{
    double rating;
    string comment;
    Movie *next;
    
};
//const for setw()
const int WIDTH = 5;

//function output displays data of linked list Movies
//argument: pointer to head of linked list
//return: none
void output(Movie *);

//function addFront adds data to head of linked list
//argument: reference to head of linked list, double, string
//return: none
void addFront(Movie *&, double, string);

//function addBack adds data of tail of linked list
//argument: reference to head of linked list, double, string
//return: none
void addBack(Movie *&, double, string);

//function deleteAll deallocates data, resets to nullptr
//argument: reference to head of linked list
//return: none
void deleteAll(Movie *&);

int main(int argc, const char * argv[]) {
    Movie *head = nullptr; //pointer to head of linked list
    //declaring local variables
    int user;
    double rating;
    string comment;
    char cont;
    //asking user for what node method
    cout << "Which linked list method should we use?" << endl;
    cout << setw(WIDTH) << "" << "[1] New nodes are added at the head of the linked list" << endl;
    cout << setw(WIDTH) << "" << "[2] New nodes are added at the tail of the linked list" << endl;
    cout << setw(WIDTH) << "" << "Choice: ";
    cin >> user;
    //makes sure user input is within bounds
    if (user > 2) {
        cout << "Invalid Choice" << endl;
        return 1;
    }
    cin.ignore();
    //gathering data
    while (true) {
        cout << "Enter review rating (0.0 - 5.0): ";
        cin >> rating;
        if (rating > 5.0) { //checking within bounds
            cout << "Invalid Choice" << endl;
            return 1;
        }
        cin.ignore();
        cout << "Enter review comment: ";
        getline(cin,comment);
        if (user==1) {
            addFront(head,rating,comment); //calling addFront function
        } else {
            addBack(head,rating,comment); //calling addBack function
        }
        cout << "Enter another review (Y/N): ";
        cin >> cont;
        cin.ignore();
        if (cont == 'N' || cont == 'n') { //continue or break loop
            break;
        }
    }
    output(head); //calling output function
    deleteAll(head); //calling deleteAll function
    return 0;
}

void output(Movie *head){
    int count = 1;
    double total = 0.0;
    Movie *current = head; //start of linked list
    while (current) { //loop until nullptr
        cout << setw(WIDTH) << "" <<"> Review #" << count++ << ": " << current->rating << ": " << current->comment << endl;
        total += (current->rating);
        current = current->next;
    }
    cout << setw(WIDTH) << "" << "> Average: " << total/(count - 1) << endl;
    cout << endl;
}
void addFront(Movie *&head, double rating, string comment){
    Movie *newMovie = new Movie;
    newMovie->rating = rating;
    newMovie->comment = comment;
    if (!head) { //first node
        newMovie->next = nullptr;
        head = newMovie;
    } else { //multiple nodes
        newMovie->next = head; //link new node to head of linked list
        head = newMovie;
    }
}
void addBack(Movie *&head, double rating, string comment){
    Movie *newMovie = new Movie;
    newMovie->rating = rating;
    newMovie->comment = comment;
    newMovie->next = nullptr; //new node will be last
    if (!head) { //first node
        head = newMovie;
    } else{ //multiple nodes
        Movie *current = head;
        while (current->next) { //moving to end of linked list
            current = current->next;
        }
        current->next = newMovie; //link new node to end of linked list
    }
}
void deleteAll(Movie *&head){
    Movie *current = head;
    while (current) { //loop until nullptr;
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}
