#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int ind,vector<int> temp)
{
    if(ind == v.size())
    {
        if(temp.size() == 0)
            cout << "{}";
        for(auto i:temp)
            cout << i << " ";
            cout << endl;
        
            return;
        
    }

    temp.push_back(v[ind]);
    solve(v,ind+1,temp);
    temp.pop_back();
    solve(v,ind+1,temp);
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
    cout << endl;
    solve(v,0,{});
    return 0;
}