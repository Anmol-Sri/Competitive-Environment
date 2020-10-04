#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,x;
	cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);

	int start=0,end=n-1;
	int mn=0;
	while(start<=end){
		if(arr[start]>x){
			break;
		}
		if(arr[start]+arr[end]<=x){
			mn++;
			start++;
			end--;
		}
		else if(arr[end]<=x){
			mn++;
			end--;
		}
	}
	cout<<mn<<"\n";
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
/*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
*/		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}