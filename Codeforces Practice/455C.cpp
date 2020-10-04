#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=3e5+1;
int n,m,q;
std::vector<int> graph[mxN];
bool visited[mxN];
int diameter[mxN];
int maxi,maxV;
int parent[mxN];
int size[mxN];

int max(int a ,int b ,int c){
	return max(a,max(b,c));
}
void dfs(int u,int f,int depth){
	if(depth>maxi){
		maxi=depth;
		maxV=u;
	}
	for(auto x:graph[u]){
		if(x!=f){
			dfs(x,u,depth+1);
		}
	}
}

int findLongestWay(int v){
	
	maxi=-1;
	dfs(v,-1,0);
	maxi=-1;
	dfs(maxV,-1,0);
	return maxi;

}

int getSet(int v){
	if(parent[v]==v) return v;
	return parent[v]=getSet(parent[v]);
}

void unionSets1(int x,int y){
	x=getSet(x);
	y=getSet(y);

	if(size[x]>size[y]){
		swap(x,y);
	}
	size[y]+=size[x];
	parent[x]=y;
}

int radius(int x){
	return (diameter[x]+1)/2;
}

void unionSets2(int x,int y){

	x=getSet(x);
	y=getSet(y);
	if(x==y){
		return;
	}
	if(size[x]>size[y]){
		swap(x,y);
	}

	size[y]+=size[x];
	parent[x]=y;
	diameter[y]=max(radius(x)+radius(y)+1,diameter[x],diameter[y]);

}

int query(int x){
	return diameter[getSet(x)];
}

void solve(){
	cin>>n>>m>>q;

	for(int i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
		diameter[i]=0;
	}

	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
		unionSets1(x,y);
	}

	for(int i=1;i<=n;i++){
		int pp=getSet(i);
		if(!visited[pp]){
			visited[pp]=true;
			diameter[pp]=findLongestWay(i);
		}
	}

	while(q--){

		int t,x,y;
		cin>>t;
		if(t==2){
			cin>>x>>y;
			unionSets2(x,y);
		}
		else{
			cin>>x;
			cout<<query(x);
		}
	}

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
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}