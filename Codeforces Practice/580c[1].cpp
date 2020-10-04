#include <bits/stdc++.h>
using namespace std;
#define ll long int
const int mxN=100005;
int n,m;
int cats[mxN];
vector<int> graph[mxN];
bool visited[mxN];
int ans;
void dfs(int u,int pr,int c){
	if(cats[u]) c++;
	else c=0;
	if(c==m+1) return;
	bool leaf=true;

	for(auto node: graph[u]){
		if(node != pr){
			leaf=false;
			dfs(node,u,c);
		}
	}
	ans+=leaf;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>cats[i];
	}
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	/*for(int i=0;i<n;i++){
		cout<<i+1<<" --> ";
		for(auto q:graph[i]){
			cout<<q+1<<" ";
		}
		cout<<endl;
	}*/
	dfs(0,-1,0);
	cout<<ans<<endl;
    return 0;
}