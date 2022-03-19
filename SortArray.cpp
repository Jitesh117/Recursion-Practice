#include<bits/stdc++.h>
using namespace std;
void insert(vector<int> &v,int temp);
void sort(vector<int> &v)
{
    if(v.size()==1)
      return;
    int temp =v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,temp);
}
void insert(vector<int> &v,int temp)
{
    if(v.size()==0 || v[v.size()-1]<=temp)
       {
            v.push_back(temp);
            return;
       }
       int val = v[v.size()-1];
       v.pop_back();
       insert(v,temp);
       v.push_back(val);
    
    // return;

}
int main()
{
    vector<int> v;
    int n;int a;
    cout<<"Enter the size of the array\n";
    cin >> n;
    cout<<"Enter the elements of the array\n";
    for(int i =0;i<n;i++)
     {
         cin>> a;
         v.push_back(a);
     }
    cout<<"The entered array is:";
    for(int i = 0;i<n;i++)
        cout<< v[i] << " ";
    sort(v);
    cout<<"\nSorted arary is\n";
    for(int i = 0;i<n;i++)
        cout<< v[i] << " ";
}