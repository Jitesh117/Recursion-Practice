#include<bits/stdc++.h>
using namespace std;
void solve(string input,string output)
{
   if(input.size()==0)
   {
       cout << output << " ";
       return;
   }
   string output1 = output, output2 = output;
   output2.push_back(input[0]);
   output1.push_back(toupper(input[0]));
   input.erase(input.begin()+0);
   solve(input,output1);
   solve(input,output2);
}
int main()
{
    string input,output="";
    cout<<"Enter a string:\n";
    cin >> input;
    solve(input,output);
    return 0;
}