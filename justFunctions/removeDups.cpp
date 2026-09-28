// This is only the function. For testing it put it in single list list
void removeDuplicates()
{
    if(isEmpty())
    {
        cout<<"List is empty."<<endl;
        return;
    }
    if(head->next==nullptr)
    {
        cout<<"List contains only 1 element."<<endl;
        return;
    }
    Node* current=head->next;
    Node* previous=head;
    while(current!=nullptr)
    {
        if(previous->data==current->data)
        {
            Node* temp=current;
            current=current->next;
            previous->next=current;
            delete temp;
        }
        else
        {
            previous=current;
            current=current->next;
        }
    }
}