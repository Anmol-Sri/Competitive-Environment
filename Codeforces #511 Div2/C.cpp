#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 15e6 + 1;
int prime[mxN];
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < mxN; i++) prime[i] = i;
	for(int i = 2; i < mxN; i++){
		if(prime[i] == i){
			for(int j = 2 * i; j < mxN; j += i){
				if(prime[j] == j)
					prime[j] = i;
			}
		}
	}
	int arr[n];
	int mn = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		mn = gcd(arr[i], mn);
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