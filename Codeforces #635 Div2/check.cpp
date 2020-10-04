#include <bits/stdc++.h>
#define maxn 200005
std::vector<int>conj[maxn];
int n,k,u,v,depth[maxn]={0},size[maxn]={0},det[maxn];
long long ans=0;
int cmp(int a,int b){return a>b;}
int dfs(int u,int f){depth[u]=depth[f]+1;size[u]=1;
	for (int i=0;i<conj[u].size();++i){
		if ((v=conj[u][i])==f)continue;
		size[u]+=dfs(v,u);
	}det[u]=size[u]-depth[u];return size[u];
}
int main(){
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;++i){
		scanf("%d%d",&u,&v);conj[u].push_back(v);conj[v].push_back(u);
	}dfs(1,0);

	for(auto x=1;x<=n;x++){
	    std::cout<<x<<" - "<<depth[x]<<" - "<<size[x]<<"\n";
	}
	for(int i=1;i<=n;i++){
		std::cout<<det[i]<<" - ";
	}
	std::cout<<"\n";

	//std::nth_element(det+1,det+n-k,det+n+1,cmp);
	std::sort(det+1,det+n+1,cmp);

	for(int i=1;i<=n;i++){
		std::cout<<det[i]<<" - ";
	}
	std::cout<<"\n";

	for (int i=1;i<=n-k;++i)ans+=det[i];std::cout<<ans;
	return 0;
}