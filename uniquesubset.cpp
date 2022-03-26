#include<bits/stdc++.h>
using namespace std;
set <string> result;
void solve(string input,string output)
{
    if(input.size()==0)
        {
            result.insert(output);
            return;
        }
    string output1=output,output2=output;
    output2.push_back(input[0]);
    input.erase(input.begin()+0);
    solve(input,output1);
    solve(input,output2);

    return;
}
int main()
{
    string input,output ="";
    cout <<"Enter a string:\n";
    cin >> input;
    solve(input,output);
    for(auto i = result.begin();i!=result.end();i++)
    {
        cout <<  *i << " ";
    }
    return 0;
}