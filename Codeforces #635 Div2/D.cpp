#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int mxN=1e5+1;
ll ans;

ll sq(int x){
	return 1ll*x*x;
}

void solve(std::vector<int> a,std::vector<int> b,std::vector<int> c){

	for(auto x:a){
		auto y=lower_bound(b.begin(),b.end(),x);
		auto z=upper_bound(c.begin(),c.end(),x);

		if(y==b.end() || z==c.begin())
			continue;

		z--;
		ll temp=sq(x-*y)+sq(*y-*z)+sq(*z-x);
		ans=min(ans,temp);
		//cout<<temp<<endl;
	}
}

void calc(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> r(n);
	vector<int > g(m);
	vector<int > b(k);

	for(auto &x:r){
		cin>>x;
	}

	for(auto &x:g){
		cin>>x;
	}

	for(auto &x:b){
		cin>>x;
	}

	sort(r.begin(),r.end());
	sort(b.begin(),b.end());
	sort(g.begin(),g.end());

	ans=9e18;

	solve(r,b,g);
	solve(r,g,b);
	solve(g,b,r);
	solve(g,r,b);
	solve(b,g,r);
	solve(b,r,g);

	cout<<ans<<"\n";
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
		calc();
	}
    return 0;
}