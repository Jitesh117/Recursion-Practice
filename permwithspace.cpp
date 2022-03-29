#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op)
{
   if(ip.size()==0)
    {
        cout << op << " ";
        return;
    }
    string output1 = op, output2 = op;
    output1.push_back('-');
    output1.push_back(ip[0]);
    output2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,output1);
    solve(ip,output2);

    return;
}
int main()
{
    string ip,op="";
    cout<<"Enter a string: \n";
    cin >> ip;
    op.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op);
    return 0;
}