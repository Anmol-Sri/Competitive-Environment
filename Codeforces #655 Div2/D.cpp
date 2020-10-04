#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll n;
	cin >> n;
	ll x;
	vector< ll > odd, even;
	for(int i = 0;  i < n; i++){
		cin  >> x;
		if(i & 1) odd.push_back(x);
		else even.push_back(x);
	}
	vector< ll > arr = even;
	arr.insert(arr.end(), odd.begin(), odd.end());
	vector < ll >  temp = arr;
	arr.insert(arr.end(), temp.begin(), temp.end());

	ll mx = 0;
	for(int i = 0; i < (n + 1) / 2; i++){
		mx += arr[i];
	}
	// cout << mx << "\n";
	ll cur = mx;
	for(int i = (n + 1) / 2; i < arr.size(); i++){
		cur = cur + arr[i] - arr[i - (n + 1) / 2];
		mx = max(mx, cur);
	}
	cout << mx << "\n";
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
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}