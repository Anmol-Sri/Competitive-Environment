#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector < bool > prime(n + 1, true);
	prime[0] = prime[1] = false;
	for(int i = 2; i <= n; i++){
		if(prime[i]){
			for(int j = 2 * i; j <= n; j += i){
				prime[j] = false;
			}
		}
	}

	vector < int > ans;
	for(int i = 1; i <= n; i++){
		if(prime[i]){
			int q = 1;
			while(q <= n / i){
				q *= i;
				ans.push_back(q);
			}
		}
	}
	cout << ans.size() << "\n";
	for(auto x : ans) cout << x << " ";
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
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}