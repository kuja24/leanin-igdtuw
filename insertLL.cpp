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

Node* insertNode(Node *head, int pos, int data) {
    int len=0;
  Node* temp=head;
  while(temp!=NULL)
  {
    len++;
    temp=temp->next;
  }
  temp=head;
  if(pos>len)
    return head;
  if(pos==0)
  {
     Node* insert = new Node(data);
     insert->next = head;
    head=insert;
    return head;
  }
  int count=1;
  while(count<pos)
  {
    temp=temp->next;
    count++;
  }
  Node* insert=new Node(data);
  insert->next=temp->next;
  temp->next=insert;
  return head;

}


Node* takeinput() {
cout<<"Enter data: "<<"    ";
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
    cout<<"Enter position and data : "<<"   ";
    int pos, data;
    cin >> pos >> data;
    head = insertNode(head, pos, data);
    print(head);
    return 0;
}

