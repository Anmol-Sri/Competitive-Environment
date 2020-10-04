#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll l, r, m;
	cin >> l >> r >> m;
	ll a, b , c;
	for(ll i = l; i <= r; i++){
		ll n = m / i;
		ll rem = m - (n * i);
		if(n > 0 && rem >= l - r && rem <= r - l){
			a = i;
			if(rem <= 0){
				b = l;
			}
			else{
				b = r;
			}
			c = b - rem;
			break;
		}
		else if(m - i * (n + 1) >= l - r &&  m - i * (n + 1) <= r - l){
			a = i;
			if(m - i * (n + 1) <= 0){
				b = l;
			}
			else{
				b = r;
			}
			c = b - m + i * (n + 1);
			break;
		}
	}
	cout << a << " " << b << " " << c << "\n";
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