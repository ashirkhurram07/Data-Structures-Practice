// This is just the code. For implementation put it in single linked list.
void sortDesc()
    {
        if(isEmpty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        if(head->next==nullptr)
        {
            cout<<"Nothing to sort."<<endl;
            return;
        }
        else
        {
            Node* temp=head;
            while(temp!=nullptr)
            {
                Node* temp2=temp;
                while(temp2!=nullptr)
                {
                    if(temp2->data>temp->data)
                    {
                        int Temp;
                        Temp=temp2->data;
                        temp2->data=temp->data;
                        temp->data=Temp;
                    }
                    temp2=temp2->next;
                }
                temp=temp->next;
            }
        }
    }
    void sortAsc()
    {
        if(isEmpty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        if(head->next==nullptr)
        {
            cout<<"Nothing to sort."<<endl;
            return;
        }
        else
        {
            Node* temp=head;
            while(temp!=nullptr)
            {
                Node* temp2=temp;
                while(temp2!=nullptr)
                {
                    if(temp2->data<temp->data)
                    {
                        int Temp;
                        Temp=temp2->data;
                        temp2->data=temp->data;
                        temp->data=Temp;
                    }
                    temp2=temp2->next;
                }
                temp=temp->next;
            }
        }
    }