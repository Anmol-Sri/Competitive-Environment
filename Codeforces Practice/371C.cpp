#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	string s;
	cin >> s;
	ll rb = 0, rs = 0, rc = 0;	
	for(int i =  0; i < s.size(); i++){
		if(s[i] == 'B') rb++;
		else if(s[i] == 'S') rs++;
		else rc++;
	}
	ll nb = 0, ns = 0, nc = 0, pb = 0, ps = 0, pc = 0, r = 0;
	cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;
	ll start = 1;
	ll end = 1e15 + 1;
	ll ans = 0;
	while(start <= end){
		ll mid = (start + end) >> 1;
		ll temp = max(0LL, rb*mid - nb) * pb + max(0LL, rs*mid - ns) * ps + max(0LL, rc*mid - nc) * pc;
		if(temp > r){
			end = mid - 1;
		}
		else{
			ans = max(ans , mid);
			start = mid + 1;
		}
	}
	cout << ans << "\n";
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