#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll arr[3];
	for(int i = 0; i < 3; i++){
		cin >> arr[i];
	}
	sort(arr, arr + 3);
	cout << min(arr[0] + arr[1] , (arr[0] + arr[1] + arr[2]) / 3) << "\n";
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