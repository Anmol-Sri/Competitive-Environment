#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e5 + 1;
int used[mxN];
void solve(){
	int n;
	cin >> n;
	for(int q = 1; q <= n; q++){
		int ans = 0;
		int x, y;
		cin >> x >> y;
		for(int i = 1; i * i <= x; i++){
			if(x % i == 0){
				if(y == 0 || used[i] == -1 || used[i] < q - y) ans++;
				used[i] = q;
				if(i * i == x) continue;
				if(y == 0 || used[x/i] == -1 || used[x/i] < q - y) ans++;
				used[x/i] = q;
			}
		}
		cout << ans << "\n";
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
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}