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
    bool isVIP;
    Node* prev;
    Node* next;
    Node(string n, bool v, Node* p = nullptr, Node* ne = nullptr)// constructor
    : name(n), isVIP(v), prev(p), next(ne) {}
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

        string pop_front(bool& wasVIP) {
        if (!head) return "";
        Node* temp = head;
        string nm = temp->name;
        wasVIP = temp->isVIP;
        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        } else {
            head = tail = nullptr;
        }
        delete temp;
        return nm;
        }

        string pop_back(bool& wasVIP) {
            if (!tail) return "";
            Node* temp = tail;
            string nm = temp->name;
            wasVIP = temp->isVIP;
            if (tail->prev) {
                tail = tail->prev;
                tail->next = nullptr;
            } else {
                head = tail = nullptr;
            }
            delete temp;
            return nm;
        }

        string remove_random(bool& wasVIP) {
        int sz = size();
        if (sz <= 2) return "";
        int pos = rand() % (sz-2) + 2; // skip head and tail
        Node* temp = head;
        for (int i = 1; i < pos; ++i)
            temp = temp->next;
        string nm = temp->name;
        wasVIP = temp->isVIP;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        return nm;
    }

        int size() const {
                int count = 0;
                Node* current = head;
                while (current) {
                    count++;
                    current = current->next;
                }
                return count;
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
        cout << cname << " joins the line\n";
    }
    cout << "Resulting line:\n";


     for (int t = 2; t <= TIME_STEPS; ++t) {
        cout << "Time step #" << t << ":\n";
        // 40%: customer is served at front
        int prob = rand() % 100 + 1;
        if (prob <= 40 && !line.empty()) {
            bool wasVIP;

        }
     }

    return 0;
}