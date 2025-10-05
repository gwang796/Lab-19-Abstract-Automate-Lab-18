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
        MovieNode *next;
        
    };
    MovieNode *head;
public:
    Movie(string t) {title = t; head = nullptr;}
    ~Movie() {deleteAll();}
    
    
    //function output displays data of linked list Movies
    //argument: pointer to head of linked list
    //return: none
    void output() const{
        cout << "Movie Title: " << endl;
        int count = 1;
        double total = 0.0;
        MovieNode *current = head; //start of linked list
        while (current) { //loop until nullptr
            cout << setw(WIDTH) << "" <<"> Review #" << count++ << ": " << current->rating << ": " << current->comment << endl;
            total += (current->rating);
            current = current->next;
        }
        cout << setw(WIDTH) << "" << "> Average: " << total/(count - 1) << endl;
        cout << endl;
    }
    
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
    
}

