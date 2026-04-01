#include <iostream>
#include <string>
using namespace std;

struct Package {
    string packageID;
    string destinationCity;
    int dimensions[3];
};

struct Node {
    Package data;
    Node* next;
};

void push(Node*& top, Package p) {
    Node* newNode = new Node;
    newNode->data = p;
    newNode->next = top;
    top = newNode;
}
void pop(Node*& top) {
    if (top == NULL) {
        cout << "Stack bos!" << endl;
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
}

void displayStack(Node* top) {
    if (top == NULL) {
        cout << "Stack bos!" << endl;
        return;
    }

    Node* temp = top;
    while (temp != NULL) {
        cout << "Package ID: " << temp->data.packageID << endl;
        cout << "Destination City: " << temp->data.destinationCity << endl;
        cout << "Dimensions: "
             << temp->data.dimensions[0] << " x "
             << temp->data.dimensions[1] << " x "
             << temp->data.dimensions[2] << endl;
        cout << "------------------------" << endl;

        temp = temp->next;
    }
}
int main() {
    Node* top = NULL;

    Package p1;
    Package p2;
    Package p3;

    p1.packageID = "1";
    p1.destinationCity = "Istanbul";
    p1.dimensions[0] = 3;
    p1.dimensions[1] = 3;
    p1.dimensions[2] = 10;

    p2.packageID = "2";
    p2.destinationCity = "Ankara";
    p2.dimensions[0] = 15;
    p2.dimensions[1] = 15;
    p2.dimensions[2] = 30;

    p3.packageID = "3";
    p3.destinationCity = "Eskisehir";
    p3.dimensions[0] = 12;
    p3.dimensions[1] = 12;
    p3.dimensions[2] = 30;

    return 0;

};
