// This is just the function. To see its implementation add it to Double linked list
void reverse()
{
   if(isEmpty())
   {
        cout<<"List is empty"<<endl;
        return;
   }
   if(head->next==nullptr)
   {
        cout<<"List has only 1 element"<<endl;
        return;
   }

   Node* oldHead=head;
   Node* newHead=nullptr;
   Node* current=head;
   while(current!=nullptr)
   {
        Node* nextNode=current->next;
        current->next=current->prev;
        current->prev=nextNode;

        newHead=current;
        current=newNode;
   }
   head=newHead;
   tail=oldHead; 
}