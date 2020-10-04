#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	int fre[1001] = {0};
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(fre[x] == 0) fre[x]++;
	}
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		if(fre[x] == 1) fre[x]++;
	}
	for(int i = 1; i <= 1000; i++){
		if(fre[i] >= 2){
			cout << "YES\n";
			cout << "1 "<< i <<"\n";
			return ;
		}
	}
	cout << "NO\n";
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