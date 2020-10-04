#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const ll mxN=19LL;

std::vector<std::vector<ll>> graph;
std::vector<ll> tree[mxN];

ll n;
ll m;

ll p[mxN];
ll positions[mxN];

ll x[mxN];
ll y[mxN];

ll store[mxN];
ll parent[mxN];
ll ans;



//GeeksForGeeks Code for union-disjoint set for find and union_parent by path compression method
ll find(ll x){
	if(x==parent[x]){
		return x;
	}
	return parent[x]=find(parent[x]);
}

void union_parent(ll x,ll y){
	x=find(x);
	y=find(y);
	if(x==y){
		return ;
	}
	parent[x]=y;
}

ll count_calc(){
	ll count = 0;
	ll i=1;
	while(i<=n){
		store[i] = p[i];
		i++;
	}
	i=1;
	while(i<=n){
		ll j=i;
		while(positions[store[j]] and positions[store[j]]!=j){
			count++;
			swap(store[j], store[positions[store[j]]]);
		}
		i++;
	}
	return count;
}

//calculate dfs by permutation CP-Algorithms Code
void dfs(ll x)
{
	if(x==(ll)graph.size()){
		ans=min(ans, count_calc());
		return;
	}

	std::vector<ll> index_pos(graph[x].size());
	
	ll number=0;

	for(auto &i:index_pos){
		i=number;
		number++;
	}

	do {
		for(ll i=0;i<(ll)graph[x].size();i++){
			positions[graph[x][i]] = graph[x][index_pos[i]];
		}
		dfs(x+1);
	}while(next_permutation(index_pos.begin(),index_pos.end()));
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
		
	ll t;
	cin>>t;

	while(t--){

		cin>>n>>m;
		ans=n-1;
		graph.clear();
		ll i=1;

		while(i<=n){
			cin>>p[i];
			i++;
		}

		i=1;
		while(i<=n){
			parent[i]=i;
			positions[i]=0;
			tree[i].clear();
			i++;
		}

		i=1;
		while(i<=m){
			cin>>x[i]>>y[i];
			union_parent(x[i],y[i]);
			i++;
		}

		ll maximum_ele=0;
		i=1;
		while(i<=n){
			ll r=find(i);
			tree[r].push_back(i);
			maximum_ele=max(maximum_ele, (ll)tree[r].size());
			i++;
		}
		
		bool check = 0;
		i=1;

		while(i<=n){

			if(parent[i]==i and (ll)tree[i].size()<maximum_ele){
				graph.push_back(tree[i]);
			}
			else if(parent[i]==i and (ll)tree[i].size()==maximum_ele)
			{
				if(!check)
					check=1;
				else
					graph.push_back(tree[i]);
			}
			i++;
		}
		dfs(0);
		cout<<ans<<"\n";
	}
    return 0;
}