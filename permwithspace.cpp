#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op)
{
    if(ip.size()==0)
        {
            cout<< op << " ";
            return;
        }
    string op2 = op,op1=op;
    op2.push_back('-');
    op2.push_back(ip[0]);
    op1.push_back(ip[0]);

    ip.erase(ip.begin()+0);
    solve(ip,op1);
    solve(ip,op2);

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