#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	a += "0";
	b += "0";
	vector < int > ans1;
	vector < int > ans2;
	for(int i = 0; i < n; i++){
		if(a[i] != a[i + 1]) ans1.push_back(i + 1);
	}
	for(int i = 0; i < n; i++){
		if(b[i] != b[i + 1]) ans2.push_back(i + 1);
	}
	reverse(ans2.begin(), ans2.end());
	ans1.insert(ans1.end(), ans2.begin(), ans2.end());
	cout << ans1.size() << " ";
	for(auto x : ans1) cout << x << " ";
	cout << "\n";
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
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}