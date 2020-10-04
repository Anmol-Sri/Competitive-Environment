#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e3 + 1;
int n;
int  arr[mxN];

int calc_mex(){
	bool vis[n+1] = {false};
	for(int i = 0; i < n; i++){
		vis[arr[i]]  = true;
	}
	for(int i = 0; i <=n ; i++){
		if(!vis[i]){
			return i;
		}
	}
	return -1;
}

void solve(){
	cin >> n;
	set<int > s;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] != i) s.insert(i);
	}
	vector< int > ans;
	int mex;
	while(s.size() != 0){
		mex = calc_mex();
		auto it = s.begin();
		if(mex == n){
			arr[*it] = n;
			ans.push_back(*it + 1);
			continue;
		}
		ans.push_back(mex + 1);
		arr[mex] = mex;
		s.erase(mex);
	}
	cout << ans.size() << "\n";
	for(int i : ans){
		cout << i << " ";
	}
	cout << "\n";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}