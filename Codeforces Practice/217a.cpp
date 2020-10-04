#include <bits/stdc++.h>
using namespace std;
#define ll long int

const int mxN=110;
int x[mxN],y[mxN];
bool visited[mxN];
int n;
void dfs(int v){
	visited[v]=true;

	for(int i=0;i<n;i++){
		if(visited[i]) continue;
		if(x[i]==x[v] || y[i]==y[v]) dfs(i);
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(i);
			++ans;
		}
	}
	cout<<(ans-1)<<"\n";

    return 0;
}