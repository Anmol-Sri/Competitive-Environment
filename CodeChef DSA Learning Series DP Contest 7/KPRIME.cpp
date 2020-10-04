#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 100001;
int factor[mxN];

void calc(){
	for(int i = 2; i < mxN; i++){
		if(factor[i]  == 0){
			for(int j = i; j < mxN; j+=i){
				factor[j]++;
			}
		}
	}
}

void solve(){
	int a,b,k;
	int ans = 0;
	cin >> a >> b >> k;
	for(int i = a; i <= b; i++){
		// cout << i << " - " << factor[i] << "\n"; 
		if(factor[i] == k){
			ans++;
		}
	}
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
		
	calc();

	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}