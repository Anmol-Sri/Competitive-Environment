#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mxN=500005;

int parent[mxN];
int find(int x){
	if(parent[x]==x){
		return x;
	}
	else parent[x]=find(parent[x]);
}

void solve(){
	int n.m.k;
	cin>>n>>k>>m;
	for(int i=0;i<=n;i++){
		parnet[i]=i;
	}

	for(int i=1;i<=k;i++){
		cin>>me[i]
	}
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