#include <bits/stdc++.h>
using namespace std;
#define ll long long int


ll check(ll a,ll b){
	if(a==0) return 0;
	if(b==0) return INT_MIN;
	if(a%b==0){
		return a/b;
	}
	return INT_MIN;
}

void solve(){

	ll p,q,r;
	ll a,b,c;
	cin>>p>>q>>r;
	cin>>a>>b>>c;	

	//cout<<p<<" "<<q<<" "<<r<<"\n"<<a<<" "<<b<<" "<<c<<"\n--------------\n";

	if(a==p && b==q && c==r){
			cout<<"0\n";
			return ;
	}
	if(a==0 && b==0 && c==0){
		cout<<"1\n";
		return ;
	}
	if(a==p && b==q){
		cout<<"1\n";
		return ;
	}
	if(a==p && c==r){
		cout<<"1\n";
		return ;
	}
	if(c==r && b==q){
		cout<<"1\n";
		return ;
	}
	if(a==p){
		if(b==0 && c==0){
			cout<<"1\n";
			return ;
		}
	}
	if(b==q){
		if(a==0 && c==0){
			cout<<"1\n";
			return ;
		}
	}
	if(c==r){
		if(b==0 && a==0){
			cout<<"1\n";
			return ;
		}
	}
	ll c1=check(a,p);
	ll c2=check(b,q);
	ll c3=check(c,r);
	ll d1=a-p;
	ll d2=b-q;
	ll d3=c-r;
	//cout<<c1<<" "<<c2<<" "<<c3<<"\n"<<d1<<" "<<d2<<" "<<d3<<"\n-------------------------\n";
	if(c1==c2 && c2==c3 && c1!=INT_MIN){
		cout<<"1\n";
		return ;
	}
	if(d1==d2 && d2==d3){
		cout<<"1\n";
		return ;
	}
	if(a==p){
		if(d2==d3){
			cout<<"1\n";
		}
		else if(c2==c3 && c2!=INT_MIN){
			cout<<"1\n";
		}
		else cout<<"2\n";
		return;
	}
	if(b==q){
		if(d1==d3){
			cout<<"1\n";
		}
		else if(c1==c3 && c1!=INT_MIN){
			cout<<"1\n";
		}
		else cout<<"2\n";
		return;
	}
	if(c==r){
		if(d1==d2){
			cout<<"1\n";
		}
		else if(c1==c2 && c2!=INT_MIN){
			cout<<"1\n";
		}
		else cout<<"2\n";
		return;
	}
	if(d1==d2){
		if(c==r) cout<<"1\n";
		else cout<<"2\n";
		return ;
	}
	if(c1==c2 && c1!=INT_MIN){
		if(c==r) cout<<"1\n";
		else cout<<"2\n";
		return ;
	}
	if(d2==d3){
		if(a==p) cout<<"1\n";
		else cout<<"2\n";
		return ;
	}
	if(c2==c3 && c2!=INT_MIN){
		if(a==p) cout<<"1\n";
		else cout<<"2\n";
		return ;
	}
	if(d1==d3){
		if(b==q) cout<<"1\n";
		else cout<<"2\n";
		return ;
	}
	if(c1==c3 && c1!=INT_MIN){
		if(b==q) cout<<"1\n";
		else cout<<"2\n";
		return ;
	}

	if(a==b && b==c){
		cout<<"2\n";
		return;
	}
//multiply + same add on two
//add something to two numbers so that multiplying by any number will result to the answer
/*	if(c1!=0 && c1!=INT_MIN){
		//add something to b && c so that by multiplying by c1 results the answer
		if((b-(q*(b/c1)))==(c-(r*(c/c1)))){
			cout<<"2\n";
			return;
		}
	}
	if(c2!=0 && c2!=INT_MIN){
		//add something to a && c so that by multiplying by c2 results the answer
		if((a-(p*(a/c2)))==(c-(r*(c/c2)))){
			cout<<"2\n";
			return;
		}
	}
	if(c3!=0 && c3!=INT_MIN){
		//add something to b && a so that by multiplying by c3 results the answer
		if((b-(q*(b/c3)))==(a-(r*(a/c3)))){
			cout<<"2\n";
			return;
		}
	}
*/
	// if any of a b c is zero

	if(a==0 or b==0 or c==0){
		if((a==0 && b==0)||(b==0 && c==0)||(c==0 && a==0)){
			cout<<"2\n";
			return ;
		}
		if(a==0){
			if(b==c){
				cout<<"2\n";
				return ;
			}
			if(q-p==b && r-p==c){
				cout<<"1\n";
				return ;
			}
			if(b%(q-p)==0 && c%(r-p)==0 && b/(q-p)==c/(r-p)){
				cout<<"2\n";
				return ;
			}
			cout<<"3\n";
		}
		if(b==0){
			if(a==c){
				cout<<"2\n";
				return ;
			}
			if(p-q==a && r-q==c){
				cout<<"1\n";
				return ;
			}
			if(a%(p-q)==0 && c%(r-q)==0 && a/(p-q)==c/(r-q)){
				cout<<"2\n";
				return ;
			}
			cout<<"3\n";
		}
		if(c==0){
			if(b==a){
				cout<<"2\n";
				return ;
			}
			if(q-r==b && p-r==a){
				cout<<"1\n";
				return ;
			}
			if(b%(q-r)==0 && a%(p-r)==0 && b/(q-r)==a/(p-r)){
				cout<<"2\n";
				return ;
			}
			cout<<"3\n";
		}
	}

	if(p==0 or q==0 or r==0){
		if(p==0 && q==0)
	}
//multiply + same add on two
//add something to two numbers so that multiplying by any number will result to the answer

	if(c1!=0 && c1!=INT_MIN){
		//add something to b && c so that by multiplying by c1 results the answer
		if((b-(q*(c1)))==(c-(r*(c1)))){
			cout<<"2\n";
			return;
		}
	}
	if(c2!=0 && c2!=INT_MIN){
		//add something to a && c so that by multiplying by c2 results the answer
		if((a-(p*(c2)))==(c-(r*(c2)))){
			cout<<"2\n";
			return;
		}
	}
	if(c3!=0 && c3!=INT_MIN){
		//add something to b && a so that by multiplying by c3 results the answer
		if((b-(q*(c3)))==(a-(r*(c3)))){
			cout<<"2\n";
			return;
		}
	}

//add something to all three numbers so that multiplying remaining two by any number will result to the answer

//add + same multiply on two

	if(q+d1!=0 && b%(q+d1)==0 && r+d1!=0 && c%(r+d1)==0 && b/(q+d1)==c/(r+d1)){
		cout<<"2\n";
		return;
	}
	if(p+d2!=0 && r+d2!=0 && a%(p+d2)==0 && c%(r+d2)==0 && a/(p+d2)==c/(r+d2)){
		cout<<"2\n";
		return;
	}
	if(p+d3!=0 && q+d3!=0 && a%(p+d3)==0 && b%(q+d3)==0 && a/(p+d3)==b/(q+d3)){
		cout<<"2\n";
		return;
	}
//add + same multiply on three

	ll g=__gcd(d1,__gcd(d2,d3));
	if(g!=1){
		ll a1=p+g;
		ll b1=q+g;
		ll c1=r+g;
		if(a1!=0 && a%a1==0 && b1!=0 && b%b1==0 && c1!=0 && c%c1==0){
			if(a/a1==b/b1 && b/b1==c/c1){
				cout<<"2\n";
				return;
			}
		}
	}

// multiply + same add on three

	if(p!=0){
		ll qwe=a/p;
		ll a1=qwe*p;
		ll b1=qwe*q;
		ll c1=qwe*r;
		if(a-a1==b-b1 && b-b1==c-c1){
			cout<<"2\n";
			return ;
		}
	}

	if(q!=0){
		ll qwe=b/q;
		ll a1=qwe*p;
		ll b1=qwe*q;
		ll c1=qwe*r;
		if(a-a1==b-b1 && b-b1==c-c1){
			cout<<"2\n";
			return ;
		}
	}

	if(r!=0){
		ll qwe=c/r;
		ll a1=qwe*p;
		ll b1=qwe*q;
		ll c1=qwe*r;
		if(a-a1==b-b1 && b-b1==c-c1){
			cout<<"2\n";
			return ;
		}
	}
	cout<<"3\n";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}