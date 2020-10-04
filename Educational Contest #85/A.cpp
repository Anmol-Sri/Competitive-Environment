#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int p[n],c[n];
	for(int i=0;i<n;i++){
		cin>>p[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		if(p[i]<c[i]){
			cout<<"NO\n";
			return ;
		}
	}
	for(int i=1;i<n;i++){
		int t1=p[i]-p[i-1];
		int t2=c[i]-c[i-1];
		if(t1<0 || t2<0 || t2>t1){
			cout<<"NO\n";
			return ;
		}
	}

	cout<<"YES\n";
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