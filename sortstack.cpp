#include<bits/stdc++.h>
using namespace std;
void insert(stack<int> &s,int temp);
void sort(stack<int> &s)
{
    if(s.size()==1)
        return;
    int temp = s.top();
    s.pop();
    sort(s);
    insert(s,temp);
}
void insert(stack<int> &s,int temp)
{
    if(s.size()==0 || s.top()>=temp)
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);

}
int main()
{
    stack<int> s;
    int n;
    cout<<"Enter the size of the stack\n";
    cin >> n;
    int a;
    for(int i =0;i<n;i++)
    {
        cin >> a;
        s.push(a);
    }
    sort(s);
    for(int i =0;i<n;i++)
    {
        cout<< s.top()<< " ";
        s.pop();
    }

}