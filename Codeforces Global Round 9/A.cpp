#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	int  pos = 0;
	int neg = 0;
	for(int i =0; i < n; i++){
		cin >> arr[i];
		if(i > 0){
			if (arr[i] - arr[i - 1] > 0){
				pos ++;
			}
			else if(arr[i] - arr[i - 1] < 0){	
				neg++;
			}
			else{
				pos++;
				neg++;
			}
		}
	}
	for(int i =0; i < n; i++){
		if(i&1){
			cout<< abs(arr[i]) << " ";
		}
		else{
			cout << -1* abs(arr[i]) << " ";
		}
	}
	cout << "\n";
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