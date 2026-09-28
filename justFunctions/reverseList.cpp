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
    void reverse()
    {
        if (isEmpty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* current=head;
        Node* oldHead=head;
        Node* newHead=nullptr;
        while(current!=nullptr)
        {
            Node* nextNode=current->next;
            current->next=current->prev;
            current->prev=nextNode;
            newHead=current;
            current=nextNode;
        }
        head=newHead;
        tail=oldHead;
    }
};
int main()
{
    DLL dll;
    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtHead(30);
    dll.insertAtHead(40);
    dll.display();
    dll.reverse();
    dll.display();
}
