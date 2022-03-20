#include<bits/stdc++.h>
using namespace std;
void insert(stack<int> &s,int temp)
{
    if(s.size()==0)
       {
            s.push(temp);
            return;
       }
    int val = s.top();
    s.pop();
    insert(s,temp);
    
}
void revstack(stack<int> &s)
{
    if(s.size()==1)
        return;
    int temp = s.top();
    s.pop();
    revstack(s);
    insert(s,temp);

    return;
}
int main()
{
    stack<int> s;
    int n;
    cout<<"Enter the size of the stack\n";
    cin >> n;
    cout <<"Enter the elements of the stack\n";
    int a;
    for(int i = 0;i<n;i++)
    {
        cin >> a;
        s.push(a);
    }
    revstack(s);
    cout<<"Stack after reversing:\n";
    for(int i =0;i<n;i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
}