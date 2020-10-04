#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll summation(int x){
	return (ll)x*((ll)x+1LL)/2LL;
}

void solve(){
	int n,x;
	cin>>n>>x;
	int d[n];
	int maxi=-1,maxv=INT_MIN;
	for(int i=0;i<n;i++){
		cin>>d[i];
		if(maxv<d[i]){
			maxv=d[i];
			maxi=i;
		}
	}
	ll sum=0;
	if(x<maxv){
		ll tot=(maxv*(maxv+1))/2;
		ll rem=(maxv-x);
		ll rem_tot=(rem*(rem+1))/2;
		ll ans=tot-rem_tot;
		cout<<ans<<"\n";
		return ;
	}
	int one=maxi,two=maxi;
	if(one==two){
		sum+=summation(d[one]);
		x-=d[one];
		one--;
		two++;
	}
	//cout<<sum<<"\n";
	while(x>0){
		if(one==-1){
			one=n-1;
		}
		if(two==n){
			two=0;
		}
		if(x<d[one]){
			ll tot=(d[one]*(d[one]+1))/2;
			ll rem=(d[one]-x);
			ll rem_tot=(rem*(rem+1))/2;
			ll ans=tot-rem_tot;
			sum+=ans;
			break;
		}
		if(x<d[two]){
			sum+=summation(x);
			break;
		}
		if(d[one]>d[two]){
			sum+=summation(d[one]);
			x-=d[one];
			one--;
		}
		else{
			sum+=summation(d[two]);
			x-=d[two];
			two++;
		}

	}
	cout<<sum<<"\n";
	return;
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