#include <iostream>
#include <string>
using namespace std;

struct Node{
    string data;
    Node* next;
};

void add(Node*& head, string word){

    Node* newNode=new Node;
    newNode->data=word;
    newNode->next=NULL;

    if (head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;

    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next =newNode;
}

void showList(Node* head) {
Node* temp =head;
while(temp != NULL){
    cout<<temp->data<<" - ";
    temp=temp->next;
}
}

void List(Node*& head){
    while (head != NULL){
        Node*temp =head;
        head = head->next;
        delete temp;
    }
}

int main(){
    Node* head=NULL;
    string word;

    cout<<"       ENTER WORDS\nEXIT to quit:"<<endl;

    while(true){
        cin>>word;

        if(word=="EXIT"){
            break;
        }
        else{
            add(head, word);
        }
        showList(head);
    }

    List(head);
    return 0;
}
