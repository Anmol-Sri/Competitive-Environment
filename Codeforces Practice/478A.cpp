#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int arr[5];
	int sum = 0;
	for(int i = 0; i < 5; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	if(sum % 5 != 0 || sum == 0) cout << "-1\n"; else cout << sum / 5 << "\n";
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