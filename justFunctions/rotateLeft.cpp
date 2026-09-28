// // This is just the function. For implementation put it in single linked list
void rotateLeft(int n)
    {
        if(isEmpty())
        {
            cout<<"List is empty."<<endl;
        }
        Node* temp=tail->next;
        if(temp->next==tail)
        {
            cout<<"List has only 1 node"<<endl;
            return;
        }
        for(int i=0;i<n;i++)
        {
            tail=tail->next;
        }
    }