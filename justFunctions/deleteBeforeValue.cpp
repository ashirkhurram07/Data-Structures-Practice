// This is only the function. To test it put it in Circular single linked list
    void deleteBeforeValue(int val)
    {
        if(isEmpty())
        {
            cout<<"List is empty."<<endl;
            return;
        }
        if(tail->next==tail)
        {
            cout<<"The list has only 1 element."<<endl;
            return;
        }
        Node* temp=tail->next;  
        bool isFound=false;
        do
        {
            if(temp->next->next->data==val)
            {
                isFound=true;
                break;
            }
            temp=temp->next;
        }while(temp!=tail->next);
        if(!isFound)
        {
            cout<<"Value not found"<<endl;
            return;
        }
        Node* temp2=temp->next;
        if(temp2==tail)
        {
            tail=temp;
        }
        temp->next=temp2->next;
        delete temp2;
    }