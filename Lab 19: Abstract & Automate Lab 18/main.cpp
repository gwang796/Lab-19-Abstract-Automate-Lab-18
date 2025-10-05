//
//  main.cpp
//  COMSC-210 | Lab 19: Abstract & Automate Lab 18 | Guo An Wang
//  IDE: Xcode
//  Created by Guo An Wang on 10/4/25.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
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
    
    //function addFront adds data to head of linked list
    //argument: const string pass by reference
    //return: none
    void addFront(const string& comment){
        double rating = (rand() % 41 + 10) / 10.0; //produces 1.0 - 5.0
        MovieNode *newNode = new MovieNode;
        newNode->rating = rating;
        newNode->comment = comment;
        newNode->next = head;
        head = newNode;
    }
    
    //function loadReview access an input file where there are comments that get added to Node of linked list, each is added
    // as new Node
    //arguments : const string pass by reference
    //return : none
    void loadReview(const string& file){
        string comment;
        int count = 0;
        ifstream inputfile(file);
        if (inputfile.good()) {
            while (getline(inputfile,comment) && count < 3) {
                if (!comment.empty()) {
                    addFront(comment);
                    count++;
                }
                inputfile.close()
            }
        } else {
            cout << "Error cannot open Input File" << endl;
            return;
        }
    }
    
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

