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
	int idx = n - 1;
	if(is_sorted(arr, arr + n)){
		cout << "0\n";
		return ;
	}
	for(int i = n - 2; i >= 0; i--){
		if(arr[i] >= arr[i + 1]){
			idx = i;
		}
		else{
			break;
		}
	}
	if(idx == 0){
		cout << "0\n";
		return ;
	}
	for(int i = idx - 1; i >= 0; i--){
		if(arr[i] <= arr[i + 1]){
			idx = i;
		}
		else{
			break;
		}
	}
	if(idx == 0){
		cout << "0\n";
		return ;
	}
	cout << idx << "\n";
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