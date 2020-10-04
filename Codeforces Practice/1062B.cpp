#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	int ans = 1, mn = 0;
	int prev = 0, ok = 0;
	for(int i = 2; i <= n; i++){
		int t = 0;
		while(n % i == 0){
			t++;
			n = n / i;
		}
		if(t > 0){
			ans = ans * i;
			int rem = 0;
			int cur = 1;
			while(cur < t){
				cur = cur * 2;
				rem++;
			}
			if(t != cur || (t != prev && prev != 0)){
				ok = 1;
			}
			prev = t;
			mn = max(mn, rem);
		}
	}
	cout << ans << " " << mn + ok << "\n";
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

	while( t-- ){
		solve();
	}

	return 0;
}