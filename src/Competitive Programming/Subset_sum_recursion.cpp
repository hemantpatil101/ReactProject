#include<bits/stdc++.h>
using namespace std;

void distSumRec(int arr[], int n, int sum,int currindex, unordered_set<int> &s)
{
	if (currindex > n)
		return;

	if (currindex == n)
	{
        cout<<sum<<" ";
		s.insert(sum);
		return;
	}

	distSumRec(arr, n, sum + arr[currindex],
							currindex+1, s);
	distSumRec(arr, n, sum, currindex+1, s);
}


void printDistSum(int arr[], int n)
{
	unordered_set<int> s;
	distSumRec(arr, n, 0, 0, s);

	/*for (auto i=s.begin(); i!=s.end(); i++)
	cout << *i << " ";*/
}

int main()
{
	int arr[] = {2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	printDistSum(arr, n);
	return 0;
}
