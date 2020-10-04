#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 2e5 + 10;
ll  n, k;
ll arr[mxN];

bool check(ll mid){
	int m = 0;
	for(int i = 0; i < n; i++){
		int c = arr[i] / mid;
		if(c == 0) continue;
		long double val = (arr[i] * 1.0) / (c * 1.0 );
		if(val > mid) c++;
		c--;
		m += c;
		if(m > k) return false;
	}
	return true;
}

void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	ll low = 1;
	ll  high = 1e12;
	while(low <= high){
		ll mid = ( low+ high ) / 2;
		if(check(mid)) high = mid - 1;
		else low = mid + 1;
	}
	cout << low  << "\n";
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