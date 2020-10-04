#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(int temp){
	while( temp > 0){
		int rem = temp % 10;
		if (rem != 4 && rem != 7){
			return false;
		}
		temp /= 10;
	}
	return true;
}

void solve(){
	int n;
	cin >> n;

	for(int i = 1; i<=n; i++){
		if(check(i) && n%i==0){
			cout << "YES\n";
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
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}