#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	int a[n],b[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	sort(a,a+n);
	sort(b,b+m);

	int ans=0;
	int j=0;
	for(int i=0;j<m;){
		if(abs(a[i]-b[j])<=k){
			ans++;
			j++;
			i++;
		}
		else if(a[i]>(b[j]+k)) j++;
		else if(a[i]<(b[j]+k)) i++;
	}
	cout<<ans<<"\n";
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