// This is just the function. For implementation put it in double linked list
void deleteBetween(int first,int second)
    {
        Node* current=head;
        while(current!=nullptr&&current->data!=first)
        current=current->next;
        if(current==nullptr)
        {
            cout<<"First value not found."<<endl;
            return;
        }
        Node* firstNode=current;
        current=current->next;
        while(current!=nullptr&&current->data!=second)
        current=current->next;
        if(current->data!=second)
        {
            cout<<"Second value not found"<<endl;
            return;
        }
        Node* secondNode=current;
        while(firstNode->next!=secondNode)
        {
            Node* temp=firstNode->next;
            firstNode->next=firstNode->next->next;
            firstNode->next->prev=firstNode;
            delete temp;
        }
    }