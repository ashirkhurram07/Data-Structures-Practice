// This is only the function. To see the implementation add it to the single list list.
void moveLastToHead()
{
    if(isEmpty())
    {
        cout<<"List is empty."<<endl;
    }
    if(head->next==nullptr)
    {
        cout<<"Nothing to move"<<endl;
        return;
    }
    Node* oldHead=head;
    Node* current=head;
    Node* previous=nullptr;
    while(current->next!=nullptr)
    {
        previous=current;
        current=current->next;
    }
    head=current;
    current->next=oldHead;
    previous->next=nullptr;
}

int main()
{
    Linkedlist ll;

    ll.insertAtHead(15);
    ll.insertAtHead(12);
    ll.insertAtHead(13);
    ll.insertAtHead(19);
    ll.insertAtHead(10);
    ll.insertAtHead(20);
    ll.insertAtHead(30);
    ll.insertAtHead(40);
    ll.display();
    cout<<endl;
    ll.moveLastToHead();
    ll.display();
}