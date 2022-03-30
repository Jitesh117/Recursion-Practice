#include<bits/stdc++.h>
using namespace std;
void solve(string input,string op)
{
   if(input.size()==0)
    {
        cout << op << " ";
        return;
    }
    string output1 = op, output2 = op;
    output1.push_back(input[0]);
    output2.push_back(input[0]);
    output2.push_back('_');
    input.erase(input.begin()+0);
    solve(input,output1);
    solve(input,output2);

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