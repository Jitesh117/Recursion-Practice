#include<bits/stdc++.h>
using namespace std;
void subseq(vector<int>v,vector<int>temp,int i)
{
    if(i == v.size())
    {
        for(auto i: temp)
            cout << i << " ";
        cout << endl;
        return;
    }
    temp.push_back(v[i]);
    subseq(v, temp, i + 1);
    temp.pop_back();
    subseq(v, temp, i + 1);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> temp;
    for (int i = 0; i < n;i++)
        cin >> v[i];
    subseq(v, temp, 0);
    return 0;
}