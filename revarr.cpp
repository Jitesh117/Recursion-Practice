#include<bits/stdc++.h>
using namespace std;
void revarr(vector<int> & v)
{
    if(v.size() == 0)
        return;
    int temp = v[0];
    v.erase(v.begin()+0);
    revarr(v);
    v.push_back(temp);
    return;
}
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    revarr(v);
    for(int i = 0;i<n;i++)
        cout<< v[i] << " ";
}