#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k;
	cin>>n>>k;
	if(k<n){
		cout<<(k)<<"\n";
		return;
	}
	if(k==n){
		cout<<(n+1)<<"\n";
		return;
	}
	int fir=floor(k/n);
	int sec=floor(k+fir)/n;
	while(fir!=sec){
		fir=sec;
		sec=(k+fir)/n;
	}
	cout<<k+sec<<"\n";

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