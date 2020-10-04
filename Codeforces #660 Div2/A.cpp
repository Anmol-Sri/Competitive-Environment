#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	if(n <= 30){
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	if(n == 36){
		cout << "5 6 10 15";
	}
	else if(n == 40){
		cout << "6 9 10 15";
	}
	else if(n == 44){
		cout << "6 7 10 21";
	}
	else{
		cout <<"6 10 14 "<< n -  30;	
	} 
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