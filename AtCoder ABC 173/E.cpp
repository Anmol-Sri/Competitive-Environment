#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll MOD = 1e9 + 7;

void solve(){
	ll n, k;
	cin >> n>> k;
	vector< ll > arr(n);
	vector< ll > pos;
	vector< ll > neg;
	ll zero = 0;
	for( ll i =0; i < n; i++){
		cin >> arr[i];
		if(arr[i] > 0) pos.push_back(arr[i]);
		else if(arr[i] < 0) neg.push_back(abs(arr[i]));
		else zero++;
		arr[i]=abs(arr[i]);
	}
	ll szp = (ll)pos.size();
	ll szn = (ll)neg.size();
	sort(pos.begin(), pos.end(),greater<int>());
	sort(neg.begin(), neg.end(),greater<int>());
	ll ans = 1;
	if(szp + szn/2*2 >= k && (k%2 == 0 || szp > 0)){
		ll p_idx = 0;
		ll n_idx = 0;
		if(k  & 1){
			ans = pos[0];
			p_idx++;
			k--;
		}
		while(k){

			ll val1 = (szp - p_idx >= 2 ? pos[p_idx] * pos[p_idx + 1] : 0);
			ll val2 = (szn - n_idx >= 2 ? neg[n_idx] * neg[n_idx + 1] : 0);

			if(val1 >= val2){
				ans = (ans * (val1%MOD)) % MOD;
				p_idx += 2;
			}
			else{
				ans = (ans * (val2%MOD)) % MOD;
				n_idx += 2;
			}
			k-=2;	
		}
	}
	else if(zero > 0){
		ans = 0;
	}
	else{
		sort(arr.begin(), arr.end());
		for(int i = 0; i < k; i++){
			ans = (ans * arr[i]) % MOD;
		}
		ans = (MOD - ans) % MOD;
	}
	cout << ans % MOD << "\n";
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