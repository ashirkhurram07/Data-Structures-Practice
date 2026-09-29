#include<iostream>
using namespace std;
#include"Stack.h"
int main()
{
    Stack s;
    string a="[[{{}}{}{{}{{}{{))({}({()}))}}}}]]{";
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='{'||a[i]=='['||a[i]=='(')
        {
            s.push(a[i]);
        }
        if(a[i]=='}'||a[i]==']'||a[i]==')')
        {
            s.pop();
        }
    }
    if(s.isEmpty())
    {
        cout<<"Balanced."<<endl;
    }
    else
    {
        cout<<"Not balanced"<<endl;
    }
    return 0;
}