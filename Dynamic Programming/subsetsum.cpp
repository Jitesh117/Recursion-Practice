#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size:\n";
    cin>> n;
    int arr[n];
    cout <<"Enter the values:\n";
    for(int i = 0;i<n;i++)
        cin >> arr[i];
     int sum;
    cout<<"Enter the sum value:\n";
    cin >> sum;
    bool t[n+1][sum+1];
  for (int i = 0; i <= n; i++) { 
		for (int j = 0; j <= sum; j++) { 
			if (i == 0)// when array(i) is empty than there is no meaning of sum of elements so return false
				t[i][j] = false;
			if (j == 0) // when sum(j) is zero and there is always a chance of empty subset so return it as true;
				t[i][j] = true;
		}
	}

        for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j) 
       
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j]; 
			else 
				t[i][j] = t[i - 1][j];
		}
	}

    t[n][sum] ? cout<< "True\n" : cout << "False\n";
    return 0;
}