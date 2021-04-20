#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
void push(Node **head, int data){
    struct Node *temp = new Node();
    temp->data=data;
    temp->next=(*head);
    (*head) = temp;
}
bool isCycle(Node **head){
    struct Node *slow=*head,*fast=*head;
    fast=fast->next;
    while(slow&&fast&&fast->next){
        if(slow==fast)
            return true;
        slow=slow->next;
        fast=fast->next->next;
    }
    return false;
}
int main()
{
    struct Node *head=NULL;
    push(&head,11);
    push(&head,13);
    push(&head,15);
    push(&head,11);
    push(&head,17);
//    head->next->next->next->next->next=head;
    if(isCycle(&head))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
