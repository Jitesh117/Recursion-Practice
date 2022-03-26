#include<bits/stdc++.h>
using namespace std;

vector<string> result;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open =n,close = n;
       
        string output = "";
        solve(open,close,output,result);
        
        return result;
    }
    void solve(int open, int close, string output, vector<string> &result)
    {
        if(open == 0 && close == 0)
        {
            result.push_back(output);
            return;
        }
        if(open!=0)
        {
            string output1 = output;
            output1.push_back('(');
            solve(open-1,close,output1,result);
        }
        if(close>open)
        {
            string output2 = output;
            output2.push_back(')');
            solve(open,close-1,output2,result);
        }
    }
};

int main()
{
    int n;
    Solution s;
    string input,output="";
    cout<<"Enter the number of parentheses:\n";
    cin >> n;
    s.generateParenthesis(n);
    for(int i = 0;i<result.size();i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}