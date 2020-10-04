#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN  = 1e5 + 10;
void solve(){
	int n;
	cin >> n;
	int arr[n];
	unordered_map < int , int > mp;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		mp[arr[i]]++;
	}
	int  unique = 0;
	for(auto x : mp){
		if(x.second == 1){
			unique++;
		}
	}
	int 
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
	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}