#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	int arr[n][m];
	bool ok =true;
	for( int i =0; i < n; i++){
		for(int j = 0; j < m ; j++){
			cin >> arr[i][j];
			if((i == 0|| i==n-1) && (j==m-1||j == 0)){
				if(arr[i][j] > 2) ok =false;
			}
			else if(i == 0 || j== 0 || i == n -1 || j == m-1){
				if(arr[i][j] > 3) ok =false;
			}
			else{
				if(arr[i][j] > 4) ok =false;
			}
		}
	}
	if(!ok){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i = 0; i< n ; i++){
		for(int j = 0; j < m; j++){
			if((i == 0|| i==n-1) && (j==m-1||j == 0)){
				cout << "2 ";
			}
			else if(i == 0 || j== 0 || i == n -1 || j == m-1){
				cout << "3 ";
			}
			else{
				cout << "4 ";
			}
		}
		cout << "\n";	
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}