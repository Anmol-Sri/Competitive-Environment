#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll x,y,l,r;

ll right(ll r,int i){
	return (r>>i);
}

ll left(ll r,int i){
	return (r<<i);
}

ll prod(ll z){
	return (x&z)*(y&z);
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
		cin>>x>>y>>l>>r;
		ll ans=prod(r);
		ll z=r;
		for(int i=40; i>=0; i--){
			ll check= right(r,i)&1;
			if(check){
				ll c=(r>>(i+1)<<(i+1))+left(1LL,i)-1;
				for(int i=40; i>=0; i--){
					int temp1 = right(x,i)&1;
					int temp2 = right(y,i)&1;
					int temp3 = right(c,i)&1;

					if(!temp1 and !temp2 and temp3){
						if((c^left(1LL,i))>=l){
							c^=left(1LL,i);
						}
					}					
				}
				if(c<l){
					continue;
				}
				if(prod(c)>ans or (prod(c)==ans and c<z)){
					ans =prod(c);
					z=c;
				}
			}
		}
		if(!ans){
			z=l;
		}
		cout<<z<<"\n";
	}
    return 0;
}