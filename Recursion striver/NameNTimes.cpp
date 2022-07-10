#include <bits/stdc++.h>
using namespace std;
void printname(string name, int counter, int n)
{
    if (counter == n)
        return;
    cout << name << endl;
    printname(name, counter + 1, n);
}
int main()
{
    string name;
    int n;
    cout << "Enter the name:";
    cin >> name;
    cout << "Enter n";
    cin >> n;
    printname(name, 0, n);
    return 0;
}