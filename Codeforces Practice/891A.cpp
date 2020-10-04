#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve(){
	int n;
	cin>>n;
	int arr[n];
	int count1=0;
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		if(arr[i]==1)count1++;
	}

	if(count1>0){
		cout<<(n-count1)<<"\n";
		return ;
	}
	int best=INT_MAX;
	for(int i=0;i<n;i++){
		int g=arr[i];
		for(int j=i+1;j<n;j++){
			g=gcd(g,arr[j]);
			if(g==1){
				best=min(best,j-i+n-1);
			}
		}
	}
	if(best==INT_MAX){
		cout<<"-1\n";
		return ;
	}
	cout<<best<<"\n";
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}