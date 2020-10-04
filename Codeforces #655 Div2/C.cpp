#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	int ans = 0, inv = 0;
	bool ok = false;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] == i + 1){
			if(inv > 0){
				ans++;
				inv = 0;
			}
		}
		else{
			inv++;
		}
	}
	if(inv > 0){
		ans++;
	}
	if(ans <= 1){
		cout << ans << "\n";
		return ;
	}
	cout << "2\n";
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