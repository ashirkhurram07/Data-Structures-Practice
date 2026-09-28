// This is only the function. For implementation put in linked list
void swapPairs()
{
   if(head==nullptr||head->next==nullptr)
   {
    return;
   }
   Node* current=head;
   Node* previousTail=nullptr;
   while(current!=nullptr&&current->next!=nullptr)
   {
        Node* second=current->next;
        Node* nextPair=second->next;

        second->next=current;
        current->next=nextPair;

        if(previousTail==nullptr)
        head=second;
        else 
        previousTail=current;
        current=nextPair;
   }
}