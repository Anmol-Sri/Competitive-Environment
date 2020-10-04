#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, k, p;
	cin >> n >> k >> p;
	vector< pair < int , int > >  arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr.begin(), arr.end());
	int grp[n];
	int cur = 0;
	for(int i = 0; i < n ; i++){
		grp[arr[i].second] = cur;
		for(i++; i < n && arr[i].first <= arr[i - 1].first + k; i++){
			grp[arr[i].second] = cur;
		}
		i--;
		cur++;
	}
	while(p--){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		grp[a] == grp[b] ? cout << "Yes\n" : cout << "No\n";
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
	// cin>>t;

	while(t--){
		solve();
	}

	return 0;
}