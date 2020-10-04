#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e5 + 1;
int fre[mxN];
int cat[mxN];

void solve(){
	int n;
	cin >> n;
	int ans = 0;
	int val = 0;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		cat[fre[x]]--;
		fre[x]++;
		cat[fre[x]]++;
		val= max(val, fre[x]);
		if(cat[1] == i) ans = i;
		if(cat[i] == 1) ans = i;
		if(cat[val] * val == i - 1 && cat[1] == 1) ans = i;
		if(cat[val - 1] * (val - 1) == i - val && cat[val] == 1) ans = i;
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