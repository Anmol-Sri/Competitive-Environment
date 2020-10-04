#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int INF = 2e9;

int solve(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int start = 1;
	int end = 4;
	int ans = 0;
	for(int i = 1; i < n; i++){
		if(arr[i] > arr[i - 1]) start++, end = 4;
		else if(arr[i] == arr[i - 1]) continue;
		else start = 1, end--;
		if(start > end) ans++, start = 1, end = 4;
	}
	return ans;
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
		cout << "Case #" << i << ": " << solve() << "\n";
	}

	return 0;
}