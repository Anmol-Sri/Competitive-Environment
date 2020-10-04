#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for(int i = 0; i <= 1000; i++){
		for(int j = 0; j <= 1000; j++){
			if( (i*i + j) == n  && (i + j*j) == m){
				ans++;
			}
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