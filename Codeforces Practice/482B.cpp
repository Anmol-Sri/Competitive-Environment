#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e5 + 10;
int l[mxN];
int r[mxN];
int q[mxN];
int s[mxN], ss[mxN];
int ans[mxN];
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> l[i] >> r[i] >> q[i];
		l[i]--;
		r[i]--;
	}
	for(int bit = 0; bit < 30; bit++){
		for(int i = 0; i <= n; i++) s[i] = 0;
		for(int i = 0; i < m; i++) if(q[i] & (1LL << bit)) s[l[i]]++, s[r[i] + 1]--;
		for(int i = 1; i < n; i++) s[i] += s[i - 1];
		for(int i = 0; i < n; i++) if(s[i] > 0) s[i] = 1;
		for(int i = 0; i < n; i++) ans[i] += (1 << bit) * s[i];
		ss[0] = 0;
		for(int i = 0; i < n; i++) ss[i + 1] = ss[i] + s[i];
		for(int i = 0; i < m; i++){
			if(!(q[i] & (1 << bit))){
				int a = ss[r[i] + 1] - ss[l[i]];
				int b = r[i] - l[i] + 1;
				if(a == b){
					cout << "NO\n";
					exit(0);
				}
			}
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
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