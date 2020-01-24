#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;

Node* deleteNode(Node *head, int i) {
  Node* temp=head;
      Node* temp2=head;
    int len=0;
    while(temp2!=NULL)
    {
        temp2=temp2->next;
        len++;
    }
  if(i==0)
  {
    Node*p=head;
    head=head->next;
    delete p;
    return head;
  }
    if(i==len)
        return head;
    temp = head;
    int pos=0;
    while(pos<i-1){
        temp = temp->next;
    pos++;
    }
    if(temp->next->next ==NULL){
        Node* x = temp->next;
        temp->next = NULL;
        delete x;
        return head;
    }
    else
    {
        Node * x = temp->next;
        temp->next = temp->next->next;
        delete x;
        return head;
    }

}


Node* takeinput() {
cout<<"Enter data";
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    cout<<"Enter position:  ";
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);
    return 0;
}

