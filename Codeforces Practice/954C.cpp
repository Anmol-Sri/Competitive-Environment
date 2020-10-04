#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;	
	int arr[n + 1];
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	int y = -1;
	int x = 1e9;
	for(int i = 2; i <= n; i++){
		if(arr[i] == arr[i-1]){
			cout<<"NO"<<endl;
			return ;
		}
		int ab = abs(arr[i] - arr[i-1]);
		if(ab == 1)continue;
		if(y == -1) y = ab;
		else{
			if(y != ab){
				cout<<"NO"<<endl;
				return ;
			}
		}
	}
	if(y == -1){
		cout<<"YES"<<endl;
		cout<<1000000000<<" "<<1000000000<<endl;
		return ;
	}
	for(int i = 2; i <= n; i++){
		int ab = abs(arr[i] - arr[i-1]);
		if(ab != 1)continue;
		int x1 = (arr[i-1] - 1) / y;
		int x2 = (arr[i] - 1) / y;
		if(x1 != x2){
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout << "YES\n";
	cout << int(1e9) << " " << y << "\n";
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

	while( t-- ){
		solve();
	}

	return 0;
}