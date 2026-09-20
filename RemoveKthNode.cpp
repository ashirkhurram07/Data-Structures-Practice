// This is only the function. To test it add it to the single linked list file.
void removeKthNode(int k)
{
    Node* temp=head;
    if(isEmpty())
    {
        cout<<"List is empty."<<endl;
        return;
    }
    if(temp->next==nullptr)
    {
        cout<<"Nothing to remove only 1 node."<<endl;
        return;
    }
    int i=1;
    while(temp!=nullptr)
    {
        if(k%i==0)
        {
            Node* temp2=temp->next;
            temp->next=temp2->next;
            delete temp2;
        }
        temp=temp->next;
        i++;
    }
}