// This is just the code. For implementation put in Double linekd list
void swapNodes(int val1,int val2)
{
    Node* temp=head;
    Node* first=nullptr;
    Node* second=nullptr;
    if(val1==val2)
    {
        return;
    }
    while(temp!=nullptr)
    {
        if(temp->data==val1&&first==nullptr)
        {
            first=temp;
        }
        if(temp->data==val2&&second==nullptr)
        {
            second=temp;
        }
        temp=temp->next;
    }

    if(second->next==first)
    {
        Node* swap=second;
        second=first;
        first=swap;
    }

    if(first->next==second)
    {
        Node* beforeFirst=first->prev;
        Node* afterSecond=second->next;
        if(beforeFirst!=nullptr)
        beforeFirst->next=second;
        else
        head=second

        if(afterSecond!=nullptr)
        afterSecond->prev=first;
        else
        tail=first

        second->prev=beforeFirst;
        second->next=first;

        first->prev=second;
        first->next=afterSecond;

        return;                                     
    }

    Node* firstNext=first->next;
    Node* firstPrev=first->prev;
    Node* secondNext=second->next;
    Node* secondPrev=second->prev;

    if(firstPrev!=nullptr)
    firstPrev->next=second;
    else
    head=second;

    if(firstNext!=nullptr)
    firstNext->prev=second
    else
    tail=second;


    if(secondPrev!=nullptr)
    secondPrev->next=first;
    else
    head=first;

    if(secondNext!=nullptr)
    secondNext->prev=first;
    else 
    tail=first;

    first->prev=secondPrev;
    first->next=secondNext;

    second->prev=firstPrev;
    second->next=firstNext;
    
}