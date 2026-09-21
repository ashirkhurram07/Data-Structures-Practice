#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    Node()
    {
        prev=next=NULL;
    }
};
class DLL
{
    public:
    Node* head;
    Node* tail;

    DLL()
    {
        head=tail=nullptr;
    }
    bool isEmpty()
    {
        return head==nullptr&&tail==nullptr;
    }
    Node *createNode(int val)
    {
        Node* newNode=new Node();
        newNode->data=val;
        return newNode;
    }
    void insertAtHead(int val)
    {
        Node* nn=createNode(val);
        if(isEmpty())
        {
            head=nn;
            tail=nn;
        }
        else
        {
            nn->next=head;
            head->prev=nn;
            head=nn;
        }
    }
    void insertAtTail(int val)
    {
        Node* nn=createNode(val);
        if(isEmpty())
        {
            head=nn;
            tail=nn;
        }
        else
        {
            nn->prev=tail;
            tail->next=nn;
            tail=nn;
        }
    }
    void insertAtLoc(int data,int loc)
    {
        if(loc==1)
        {
          insertAtHead(data);
		  return;
        }
        else
        {
			Node* newNode=createNode(data);
			Node* temp=head;
            for(int i=1;i<loc&&temp!=nullptr;i++)
			{
                temp=temp->next;
                if(i+1==loc&&temp==nullptr)
                {
                    insertAtTail(data);
                    delete newNode;
                    return;
                }
            }
			if(temp!=nullptr)
			{
				newNode->next=temp;
				newNode->prev=temp->prev;
				newNode->prev->next=newNode;
				temp->prev=newNode;
                return;
			}
			else 
            {
                cout<<"Location doesn't exist"<<endl;
                delete newNode;
            }
        }
    }
	void insertBeforeValue(int data,int val)
	{
		Node* temp=head;
		if(temp->data==val)
		{
			insertAtHead(data);
		}
		else
		{
			Node* nn=createNode(data);
			while(temp!=NULL&&temp->data!=val)
			{
				temp=temp->next;
			}
			if(temp!=nullptr)
			{
				nn->next=temp;
				nn->prev=temp->prev;
				nn->prev->next=nn;
				temp->prev=nn;
			}
			else
			{
				cout<<"Value not found."<<endl;
                delete nn;
			}
		}
	}
	void insertAfterValue(int data,int val)
	{
		Node* temp=tail;
		if(temp->data==val)
		{
			insertAtTail(data);
		}
		else
		{
            temp=head;
			Node* nn=createNode(data);
			while(temp!=tail&&temp->data!=val)
			temp=temp->next;
			if(temp!=tail)
			{
				nn->next=temp->next;
				nn->prev=temp;
				temp->next=nn;
				nn->next->prev=nn;
			}
            else
            {
                cout<<"Value not found"<<endl;
                delete nn;
                return;
            }
		}
	}
    void deleteAtHead()
    {
        if(isEmpty())
        {
            cout<<"List is already empty."<<endl;
            return;
        }
        else
        {
            if(head->next==nullptr)
            {
                delete head;
                head=nullptr;
                tail=nullptr;
            }
            else
            {
                head=head->next;
                delete head->prev;
                head->prev=nullptr;
            }
        }
    }
    void deleteAtTail()
    {
        if(isEmpty())
        {
            cout<<"List is already empty."<<endl;
            return;
        }
        else
        {
            if(tail->prev==nullptr)
            {
                delete tail;
                head=nullptr;
                tail=nullptr;
            }
            else
            {
                tail=tail->prev;
                delete tail->next;
                tail->next=nullptr;
            }
        }
    }
    void deleteAtLoc(int loc)
    {
        if(isEmpty())
        {
            cout<<"List is already empty"<<endl;
            return;
        }
        if(loc==1)
        {
            deleteAtHead();
        }
        else
        {
            Node* temp=head;
            for(int i=1;i<loc&&temp!=nullptr;i++)
            {
                temp=temp->next;
            }
            if(temp!=tail&&temp!=nullptr)
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
            }
            else if(temp==tail)
            {
                deleteAtTail();
            }
            else cout<<"Loc not found"<<endl;
        }
    }
    void deleteAtVal(int val)
    {
        if(isEmpty())
        {
            cout<<"The list is already empty."<<endl;
            return;
        }
        if(head->data==val)
        {
            deleteAtHead();
        }
        else if(tail->data==val)
        {
            deleteAtTail();
        }
        else
        {
            Node* temp=head->next;
            while(temp!=tail&&temp->data!=val)
            {
                temp=temp->next;
            }
            if(temp!=tail)
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
            }
            else cout<<"Value not found."<<endl;
        }
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        else
        {
            Node* temp=head;
            while(temp!=nullptr)
            {
                cout<<temp->data<<"<->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }
    void deleteBetween(int first,int second)
    {
        Node* current=head;
        while(current->data!=first&&current!=nullptr)
        current=current->next;
        if(current==nullptr)
        {
            cout<<"First value not found."<<endl;
            return;
        }
        Node* firstNode=current;
        while(current->data!=second&&current!=tail)
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
        if(first==nullptr||second==nullptr)
        {
            cout<<"One or both values not found."<<endl;
            return;
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
            head=second;

            if(afterSecond!=nullptr)
            afterSecond->prev=first;
            else
            tail=first;

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
        firstNext->prev=second;
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
};
int main()
{
    DLL dll;
    dll.display();
    dll.insertAtTail(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);
    dll.insertAtTail(50);
    dll.insertAtTail(60);
    dll.display();
    dll.swapNodes(50,20);
    dll.display();
}