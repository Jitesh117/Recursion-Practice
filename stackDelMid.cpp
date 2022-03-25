#include<bits/stdc++.h>
using namespace std;
void solve(stack<int> &s,int k)
{
    if(k==1)
    {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    solve(s,k-1);
    s.push(temp);
    return;
}
stack <int> DelMid(stack<int> &s,int size)
{
    if(size==0)
        return s;
    solve(s,size/2 +1);
    return s;
}


int main()
{
    int size;
    stack<int> s;
    cout<<"Enter the size of the stack\n";
    cin >> size;
    cout<<"Enter the elements of the stack:\n";
    int val;
    for(int i = 0;i<size;i++)
    {
        cin >> val;
        s.push(val);
    }
    solve(s,size/2+1);
    cout<<"\nStack after deleting middle element:\n";
    for(int i = 0;i<size-1;i++)
    {
        cout << s.top()<< " ";
        s.pop();
    }
    return 0;
}