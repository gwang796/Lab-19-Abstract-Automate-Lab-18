//
//  main.cpp
//  COMSC-210 | Lab 19: Abstract & Automate Lab 18 | Guo An Wang
//  IDE: Xcode
//  Created by Guo An Wang on 10/4/25.
//

#include <iostream>
#include <iomanip>
using namespace std;

//const for setw()
const int WIDTH = 5;

class Movie {
private:
    string title;
    // declaring Movie struct with
    struct MovieNode{
        double rating;
        string comment;
        Movie *next;
        
    };
    MovieNode *head;
public:
    Movie(string t) {title = t; head = nullptr;}
    ~Movie() {deleteAll();}
    
    //function output displays data of linked list Movies
    //argument: pointer to head of linked list
    //return: none
    void output(Movie *);
    
    //function deleteAll deallocates data, resets to nullptr
    //argument: reference to head of linked list
    //return: none
    void deleteAll(){
        MovieNode *current = head;
        while (current) { //loop until nullptr;
            MovieNode *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};


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
