#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;
	int arr[k][n];
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	


	int n;
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
    for(int j=0;j<n;j++)
    	cout<<num[j]<<" ";
    return 0;
}