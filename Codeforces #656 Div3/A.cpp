#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int x, y, z;
	cin >> x >> y >> z;
	if(x== y && y == z){
		cout << "YES\n";
		cout << x << " " << y << " " << z << " " << "\n";
		return ;
	}
	if(x == y && x > z){
		cout << "YES\n";
		cout << x << " " << z << " " << z << " " << "\n";
	}
	else if(y == z && x < z){
		cout << "YES\n";
		cout << x << " " << x << " " << z << " " << "\n";
	}
	else if(x == z && x > y){
		cout << "YES\n";
		cout << y << " " << x << " " << y << " " << "\n";
	}
	else{
		cout << "NO\n";
	}
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