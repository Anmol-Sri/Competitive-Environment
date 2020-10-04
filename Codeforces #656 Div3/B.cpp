#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	bool vis[n + 1] = {false};
	vector < int > arr;
	for(int i = 0; i < 2*n; i++){
		int x;
		cin >> x;
		if(!vis[x]){
			vis[x] = true;
			arr.push_back(x);
		}
	}
	for(int i : arr){
		cout << i << " ";
	}
	cout << "\n";
	return ;
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