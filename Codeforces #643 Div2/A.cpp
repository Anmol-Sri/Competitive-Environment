#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n,k;
	cin>>n>>k;
	while(k>1){
		ll temp=n;
		int max_dig=0;
		int min_dig=9;
		while(temp>0){
			int qwe=temp%10;
			max_dig=max(max_dig,qwe);
			min_dig=min(min_dig,qwe);
			temp/=10;
		}
		if(min_dig==0){
			break;
		}
		n+=min_dig*max_dig;
		k--;
	}
	cout<<n<<"\n";
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