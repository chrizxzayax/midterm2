// comsc 210 | midterm2 | Christian Molina

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    bool VIP;
    Node* prev;
    Node* next;
    Node(string n, bool v, Node* p = nullptr, Node* ne = nullptr)
    : name(n), VIP(v), prev(p), next(ne) {}
};