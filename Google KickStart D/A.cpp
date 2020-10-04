#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = 0;
	if(n == 1){
		cout << 1 ;
		return ;
	}
	int mx = 0;
	for(int i = 0; i < n; i++){
		if(i == 0 && arr[i] > arr[i + 1]){
			ans++;
			mx = max(arr[i], mx);
		}
		else if(i == n -1 && mx < arr[i]){
			ans++;
		}
		else if(mx < arr[i] && arr[i] > arr[i + 1]){
			mx = max(arr[i], mx);
			ans++;
		}
		mx = max(arr[i], mx);
	}
	cout << ans ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
		
	int t;
	cin>>t;

	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
	}

	return 0;
}