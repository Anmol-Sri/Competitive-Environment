#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	int temp = n;
	ll num = 0;
	int ans = 0;
	while(temp){
		ans++;
		temp /= 10;
		num *= 10;
		num += 7;
		while(true){
			if(num % n == 0){
				ans++;
				// break;
			}
			ans++;
			num = num % k;
			num *= 10;
			num += 7;
			vis[num] = true;
		}
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
	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}