#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	ll half = (n + 1)/2;
	if( half >= k){
		cout << (k - 1) * 2 + 1 << "\n";
	}
	else{
		cout << (k - half) * 2 << "\n";
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
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}