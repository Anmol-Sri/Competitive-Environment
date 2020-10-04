#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	if(c < v0){
		cout << "1\n";
		return ;
	}
	int ans = 1;
	int cur = v0;
	int temp = v0;
	while(cur < c){
		ans++;
		temp = min(temp + a, v1);
		cur += temp - l;
	}
	cout << ans << "\n";
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