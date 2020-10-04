#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll INF = 1e17 + 10;
void solve(){
	ll n, m;
	cin >> n >> m;
	ll cost[n+1];
	ll i = 1;
	while(i <= n){
		cin >> cost[i];
		i++;
	}
	ll compute[n+1][m+1];
	memset(compute, 0LL, sizeof(compute));
	ll res = -1;
	i = 1;
	while(i <= n){
		ll j = 1;
		while(j <= m) {
			if(i == 1) {
				compute[i][j] = (j == m ? 0 : -1);
			}
			else if(j == m) {
				if(cost[i] != 0) {
					
				}
				else {
					compute[i][j] = -1;
				}
			}
			else if(i-1 > 0 && j+1 <= m) {
				compute[i][j] = compute[i-1][j+1];
			}

			if(i == n && compute[i][j] != -1) {
				res = compute[i][j];
			}
			cout << compute[i][j] << " ";
			j++;
		}
		cout << endl;
		i++;
	}
	cout << res << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("running_on_fumes_chapter_1_input.txt","r",stdin);
		freopen("DOut.txt","w",stdout);
	#endif
		
	int t;
	cin>>t;

	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}