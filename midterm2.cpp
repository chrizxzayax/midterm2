// comsc 210 | midterm2 | Christian Molina

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct Node {
    string name;// customer's name
    bool VIP;
    Node* prev;
    Node* next;
    Node(string n, bool v, Node* p = nullptr, Node* ne = nullptr)// constructor
    : name(n), VIP(v), prev(p), next(ne) {}
};
class DoublyLinkedList {
private:
    Node* head;// pointer to the start of the list
    Node* tail;// pointer to the end of the list

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // ill add here all the methods needed for the doubly linked list
};


int main (){
    srand(time(0)); // seed for randomness

    vector<string> names;
    ifstream infile("names.txt");// open the file
    if (!infile) {
        cerr << "Unable to open file names.txt";
        return 1; // exit with error
    }
    string line;

    while (getline(infile, line)) {
        names.push_back(line);
    }
    DoublyLinkedList nameList;
    for (const string& name : names) {
        bool isVIP = (rand() % 2 == 0); // Randomly assign VIP status
    }


    return 0;
}