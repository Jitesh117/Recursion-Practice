#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int ind,vector<int> temp,int sum,int &count)
{
    if(ind == v.size())
    {
        if(sum== 0)
        {
            count++;
        }
            return;
        
    }

    temp.push_back(v[ind]);
    solve(v,ind+1,temp,sum-v[ind],count);
    temp.pop_back();
    solve(v,ind+1,temp,sum,count);
}
int main()
{
    vector<int> v;
    int n;
    cout <<"Enter size: ";
    cin >> n;
    cout <<"Enter array: ";
    for(int i = 0;i<n;i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    cout <<"Enter the sum: ";
    int sum;
    cin>> sum;
    cout << endl;
    int count =0;
    solve(v,0,{},sum,count);
    cout << count;
    return 0;
}