// comsc 210 | midterm2 | Christian Molina

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

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

        void push_back(const string& name, bool VIP) {// method to add a customer at the end of the list
            Node* newNode = new Node(name, VIP);
            if (!tail) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        // add the customer at front
        void push_front(const string& name, bool VIP=false) {
            Node* newNode = new Node(name, VIP);
            if (!head)
                head = tail = newNode;
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        void pop_front(bool& wasVIP) {// method to remove the customer at the front of the list
            if (!head) return "";
            Node* temp = head;
            string nm = temp->name;
                cout << "Line is empty." << endl;
                return;
            }
            Node* temp = head;
            wasVIP = temp->VIP;
            if (head->next) {
                head = head->next;
                head->prev = nullptr;
            } else
                head = tail = nullptr;
            delete temp;
            return nm;
        }

        bool empty () const {
            return head == nullptr;
        }
};

string pick_random_name(vector<string>& names) {
    if (names.empty()) return "Anonymous";
    int idx = rand() % names.size();
    string name = names[idx];
    names.erase(names.begin() + idx);
    return name;
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

    int TIME_STEPS = 20; // number of time steps to simulate
    
    cout << "store opens: \n";
    for (int i = 0; i < 5; ++i) {
        string cname = pick_random_name(names);
        line.push_back(cname);
        cout << cname << " joins the line\n";
    }
    cout << "Resulting line:\n";
    line.print();

    return 0;
}