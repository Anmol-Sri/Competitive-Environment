#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 2e5 + 1;
int n, arr[mxN], mxi = -1, cnt;
vector < int > zero;

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] < 0){
			++cnt;
			if(mxi == -1 || arr[mxi] < arr[i]) mxi = i;
		}
		else if(arr[i] == 0) zero.push_back(i);
	}
	if(cnt & 1){
		zero.push_back(mxi);
	}
	if(zero.size()){
		for(int i = 0; i < zero.size() - 1; i++){
			cout << "1 " << zero[i] + 1 << " " << zero[i + 1] + 1 << "\n";
		}
		if(zero.size() < n){
			cout << "2 " << zero.back() + 1 << "\n";
		}
	}
	int prev = -1;
	for(int i = 0; i < n; i++){
		if(arr[i] == 0 || (i == mxi && cnt & 1)) continue;
		if(prev != -1) cout << "1 " << prev << " " << i + 1 << "\n";
		prev = i + 1;
	}
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