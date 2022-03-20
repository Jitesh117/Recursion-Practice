#include<bits/stdc++.h>
using namespace std;
void deletestack(stack<int> &s, int k)
{
   if(k==1)
     {
         s.pop();
         return;
     }
     int temp = s.top();
     s.pop();
     deletestack(s,k-1);
     s.push(temp);
     return;
}
int main()
{
    stack<int> s;
    int n;
    cout<<"Enter the size of stack\n";
    cin>>n;
    int a;
    cout<<"Enter the elements of the stack: \n";
    for(int i =0;i<n;i++)
    {
        cin >> a;
        s.push(a);
    }
    
    deletestack(s,n/2+1);
    cout<<"Stack after deleting middle element:\n";
    for(int i =0;i<n-1;i++)
    {
        cout<< s.top()<< " ";
        s.pop();
    }
}
