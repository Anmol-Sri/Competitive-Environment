#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(ll n){
	if(n == 0 || n == 1) return false;
	if(((n + 1) & n) == 0) return true;
	return false;
}
void solve(){
	int n;
	cin >> n;
	ll arr[n];
	bool ok = true;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < 52; i++){
		if()
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