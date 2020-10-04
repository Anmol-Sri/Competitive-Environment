#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN=196591;
bool vis[mxN]={false};
std::vector<ll> graph[mxN];
void solve(){
	ll a,b,mx=LLONG_MIN;
	while(cin>>a>>b){
		// mx=max(mx,max(a,b));
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	/*for(ll i=0;i<=mx;i+=2){
		cout<<i<<" ";
	}
	cout<<"\n";
	for(ll i=1;i<=mx;i+=2){
		cout<<i<<" ";
	}
	cout<<"\n";
	return;*/

	// cout<<mx<<"\n";
	for(auto x:graph){
		bool ok=false;
		for(auto q:x){
			if(!vis[q]){
				ok=true;
				vis[q]=true;
				cout<<q<<" ";
			}
		}
		if(ok)
			cout<<"\n";
	}
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("a1.in","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	int t=1;

	while(t--){
		solve();
	}

	return 0;
}