#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector< int > arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	vector< pair < int ,  pair < int , int > > > ans ;
	for(int i =0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(arr[i] > arr[j]){
				ans.push_back(make_pair(arr[i], make_pair(i, -j)));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(auto x : ans){
		cout << x.second.first + 1 << " " << -x.second.second + 1 << "\n";
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