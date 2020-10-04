#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e6 + 10;
int n,sz;
int arr[mxN], bit[mxN], tot[mxN], cnt[mxN], rem[mxN];

void add(int k, int x){
	for(k++; k <= mxN; bit[k] += x, k += k&-k);
}

int get(int  x){
	int ans = 0;
	for(; x > 0; ans += bit[x], x -= x&-x);
	return  ans;
}

int sum(int x, int y){
	return  get(y) - get(x);
}

void solve(){
	int n;
	cin >> n;
	for(int  i = 0; i < n; i++){
		cin >> arr[i];
		tot[sz++] = arr[i];
	}
	sort(tot, tot + sz);
	sz = unique(tot, tot + sz) - tot;
	// cout  << "size = " << sz << "\n";
	for(int i = 0; i < n; i++){
		arr[i] = lower_bound(tot, tot + sz , arr[i]) - tot;
	}
	for(int i = n - 1;  i >= 0; i--){
		cnt[arr[i]]++;
		add(cnt[arr[i]], 1);

		rem[i] = cnt[arr[i]];
	}
	/*for(int i = 0; i < n; i++){
		cout << arr[i] << " " << cnt[i] << " " << tot[i] << " " << rem[i] << " " << bit[i] << "\n";
	}*/
	memset(cnt, 0, sizeof cnt);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		add(rem[i], -1);
		cnt[arr[i]]++;
		ans += sum(1, cnt[arr[i]]);
	}
/*	cout << "------------------------------\n";
	for(int i = 0; i < n; i++){
		cout << arr[i] << " " << cnt[i] << " " << tot[i] << " " << rem[i] << " " << bit[i] << "\n";
	}*/
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
	// cin>>t;

	while(t--){
		solve();
	}

	return 0;
}