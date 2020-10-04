#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e5 + 10;
int arr[mxN];

void solve(){
	int n;
	cin >> n;
	bool ok = true;
	n++;
	int arr[n + 1];
	arr[n] = 0;
	for(int i  = 0; i < n; i++){
		cin >> arr[i];
	}
	int idx = -1;
	for(int i = 0; i <  n; i++){
		if(arr[i] > 1 && arr[i + 1] > 1) {idx = i; ok = false; break;}
	}
	if(ok){
		cout << "perfect\n";
		return ;
	}
	cout << "ambiguous\n";
	int cur  = 0;
	for(int i = 0; i < n; i++){
		for(int  j = 0; j < arr[i]; j++){
			cout << cur << " ";
		}
		cur += arr[i];
	}
	cout << endl;
	cur = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < arr[i]; j++){
			if(j == 0  && i == idx + 1) cout << cur - 1 << " "; else cout << cur << " ";
		}
		cur += arr[i];
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
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}