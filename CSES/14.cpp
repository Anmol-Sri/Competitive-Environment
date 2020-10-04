#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll recur(int arr[],int i,ll sumCalc,ll tot){
	if(i==0) return abs((tot-sumCalc)-sumCalc);
	return min(recur(arr,i-1,sumCalc+arr[i-1],tot),recur(arr,i-1,sumCalc,tot));
}
void solve(){
	int n;
	cin>>n;
	int arr[n];
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	cout<<recur(arr,n,0,sum)<<"\n";
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