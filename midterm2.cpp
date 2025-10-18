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

    void push_back(const string& name, bool isVIP) {// method to add a customer at the end of the list
        Node* newNode = new Node(name, isVIP);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // add the customer at front
    void push_front(const string& name, bool isVIP=false) {
        Node* newNode = new Node(name, isVIP);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
};

string pick_random_name(const vector<string>& names) {
    int index = rand() % names.size();
    return names[index];
}

int main (){
    srand(time(0)); // seed for randomness

    vector<string> names;
    ifstream fin("names.txt");// open the file
    string line;

    while (getline(fin, line)) 
    if (!line.empty()) {
        names.push_back(line);// store each name in the vector
    }

    DoublyLinkedList line;
    int TIME_STEPS = 20; // number of time steps to simulate
    for (const string& name : names) {
        bool isVIP = (rand() % 2 == 0); // Randomly assign VIP status
    }


    return 0;
}