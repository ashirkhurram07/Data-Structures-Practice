// This is only the function. To check its working add it to the single linked list 
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
        Node* previous=nullptr;
        while(temp!=nullptr)
        {
            if(i%k==0)
            {
                Node* nodetodel=temp;
                temp=temp->next;
                if(previous==nullptr)
                {
                    head=temp;
                }
                else
                {
                    previous->next=temp;
                }
                delete nodetodel; 
            }
            else
            {
                previous=temp;
                temp=temp->next;
            }
            i++;
        }
    }
int main()
{
    Linkedlist ll;
    ll.insertAtHead(15);
    ll.insertAtHead(12);
    ll.insertAtHead(13);
    ll.insertAtHead(19);
    ll.insertAtHead(20);
    ll.insertAtHead(45);
    ll.insertAtHead(15);
    ll.insertAtHead(12);
    ll.insertAtHead(13);
    ll.insertAtHead(19);
    ll.insertAtHead(20);
    ll.insertAtHead(45);
    ll.display();
    cout<<endl;
    ll.removeKthNode(3);
    ll.display();
} 