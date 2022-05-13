#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int ind,vector<int> temp,int sum)
{
    if(ind == v.size())
    {
        if(sum == 0)
        {if(temp.size() == 0)
            cout << "{}";
            for(auto i:temp)
                cout << i << " ";
                cout << endl;
        }
            return;
        
    }

    temp.push_back(v[ind]);
    solve(v,ind+1,temp,sum-v[ind]);
    temp.pop_back();
    solve(v,ind+1,temp,sum);
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
    int sum;
    cout <<"Enter sum value: ";
    cin >> sum;
    cout << endl;
    solve(v,0,{},sum);
    return 0;
}