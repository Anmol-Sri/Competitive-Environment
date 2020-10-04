#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int one = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] == 1) one++;
		else break;
	}
	if(one == n){
		if(n & 1) cout << "First\n";
		else cout << "Second\n";
		return ;
	}
	else{
		if(one & 1) cout << "Second\n";
		else cout << "First\n";
		return ;
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