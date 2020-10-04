#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#include<bits/stdc++.h>
using namespace std;
 
int n, m, G[1010][1010], ds[1010], dt[1010], s, t, len;
 
queue<int>q;
void bfs(int st,int *d){
	for (;!q.empty();) q.pop();
	d[st]=0;
	for (q.push(st);!q.empty();q.pop()){
	int x=q.front();
	for (int y=1;y<=n;++y)
		if (G[x][y]&&d[y]>d[x]+1){
			d[y]=d[x]+1;
			q.push(y);
		}
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
		
	cin>>n>>m>>s>>t;
	memset(ds,33,sizeof ds);
	memset(dt,33,sizeof dt);
	int x, y;
	for (int i=1;i<=m;++i){
		cin >> x >> y;
		G[x][y]=G[y][x]=1;
	}
	bfs(s,ds); bfs(t,dt);

	len=ds[t];
	int ans=0;
	for (int i=1;i<n;++i)
		for (int j=i+1;j<=n;++j)
			if (!G[i][j] && min(ds[i]+dt[j],dt[i]+ds[j])+1 >= len)
				++ans;
	cout<<ans<<endl;
}