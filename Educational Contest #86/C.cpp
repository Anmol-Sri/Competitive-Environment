#include <bits/stdc++.h>
using namespace std;
#define ll long long int
std::vector<ll> calculated(160000);
std::vector<ll> arr;
ll calc(ll i,ll a,ll b,ll l,ll r){
	if(l>r){
		return 0;
	}

	if(a==l and b==r){
		return calculated[i];
	}
	ll mid=(a+b)/2;
	return calc(i*2,a,mid,l,min(r,mid))+calc(i*2+1,mid+1,b,max(l,mid+1),r);
}


//GeeksForGeeks Code
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

ll lcm(ll a,ll b){
	return (a*b)/gcd(a,b);
}


void precalc(ll i, ll a,ll b){
	if(a==b){
		calculated[i]=arr[a];
	}
	else{
		ll mid=(a+b)/2;
		precalc(i*2,a,mid);
		precalc(i*2+1,mid+1,b);
		calculated[i]=calculated[2*i]+calculated[2*i+1];
	}
}

void solve(){
	ll a,b,q;
	cin>>a>>b>>q;

	if(a>b){
		swap(a,b);
	}

	ll LCM=lcm(a,b);
	arr.assign(LCM,0);

	for(ll i=0;i<LCM;i++){
		if(((i%a)%b)!=((i%b)%a)){
				arr[i]++;
		}
	}

	precalc(1,0,LCM-1);

	while(q--){
		ll l,r;
		cin>>l>>r;
		ll t1=l%LCM;
		ll t2=r%LCM;
		ll ans=calc(1,0,LCM-1,t1,LCM-1)+calc(1,0,LCM-1,0,t2);
		ll t3=LCM-t1;
		ll t4=t2+1;
		ll path=r-l-t4-t3+1;
		ans=ans+(path/LCM)*calc(1,0,LCM-1,0,LCM-1);
		cout<<ans<<" ";
	}
	cout<<endl;
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