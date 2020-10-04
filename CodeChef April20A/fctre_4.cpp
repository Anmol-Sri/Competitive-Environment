#include <bits/stdc++.h>
using namespace std;
#define ll long int

const int mxA=1e6+1;
const ll MOD=1e9+7;
int prime[mxA];
unordered_map<int,int>prc[mxA];
ll qwe;
int ptr=0;

void sieve_modified(){
	memset(prime,0,sizeof(prime));
	prime[0]=prime[1]=1;

	for(int i=2;i*i<mxA;i++){
		if(prime[i]==0){
			for(int j=i*2;j<mxA;j+=i){
				if(prime[j]==0){
					prime[j]=i;
				}
			}
		}
	}
	for(int i=2;i<mxA;i++){
		if(prime[i]==0){
			prime[i]=i;
		}
	}
}

void numberofDivisorofProduct(){
	/*unordered_map<int,int> prime_count;
	int n=vec.size();
	for(int i=0;i<n;i++){
		int temp=vec[i];
		while(temp!=1){
			prime_count[prime[temp]]++;
			temp=temp/prime[temp];
		}
	}
	ll ans=1;
	for(auto it:prime_count){
		ans=(ans*(it.second+1))%MOD;
	}
	return ans%MOD;
	*/
	for(int i=1;i<mxA;i++){
		int temp=i;
		while(temp!=1){
			prc[i][prime[temp]]++;
			temp=temp/prime[temp];
		}
	}
} 

void addEdge(vector<int> v[],int x,int y){
	v[x].push_back(y);
	v[y].push_back(x);
}

void calc(unordered_map<int,int> mp){
	ll ans=1;
	for(auto it:mp){
		ans=(ans*(it.second+1))%MOD;
	}
	qwe=ans%MOD;
	return;
}

void DFS(vector<int> v[],bool vis[],int x,int y,vector<int> stack,int cost[],unordered_map<int,int> mp){
	stack.push_back(x);
	//cout<<"Entered - "<<x<<endl;
	/*<<"Prime factors are:-\n";
	for(auto x:prc[cost[x-1]]){
		cout<<x.first<<" - "<<x.second<<"\n";
	}
	cout<<"------------\n";
	*/
	/*cout<<"Map mp is :- \n";
	for(auto x:mp){
		cout<<x.first<<" - "<<x.second<<"\n";
	}*/
	unordered_map<int,int> val=prc[cost[x-1]];
	for(auto it:val){
		if(mp.find(it.first)!=mp.end()){
			mp[it.first]+=it.second;
		}
		else{
			mp[it.first]=it.second;
		}
	}

	if(x==y){
		calc(mp);
		return ;
	}
	vis[x]=true;

	int flag=0;
	if(!v[x].empty()){
		for(int j=0;j<v[x].size();j++){
			if(vis[v[x][j]]==false){
				DFS(v,vis,v[x][j],y,stack,cost,mp);
			}
		}
	}
}

ll DFScallUtil(int x,int y,vector<int> v[],int n,vector<int> stack,int cost[]){
	bool visited[n+1];
	memset(visited,false,sizeof(visited));
	unordered_map<int,int> mp;
	qwe=1;
	DFS(v,visited,x,y,stack,cost,mp);
	return qwe;
}

void dfs_for_euler(std::vector<int> vec[],int *FAI,int *level,std::vector<int> euler,int cur,int prev,int dep){
	if(FAI[cur]==-1){
		FAI[cur]=ptr;
	}
	level[cur]=dep;
	euler.push_back(cur);
	ptr++;

	for(auto x:vec[cur]){
		if(x!=prev){
			dfs_for_euler(vec,FAI,level,euler,x,cur,dep+1);
			euler.push_back(cur);
			ptr++;
		}
	}
}

void solve(){
	int n;
	cin>>n;
	vector<int> vec[n+1],stack;
	std::vector<int > euler;
	std::vector<int > depthArr;
	int FAI[n+1];
	memset(FAI,-1,sizeof(FAI));
	int level[n+1];
	int x,y;
	for(int i=1;i<=n-1;i++){
		cin>>x>>y;
		addEdge(vec,x,y);
	}
	int cost[n];
	for(int i=0;i<n;i++){
		cin>>cost[i];
	}

	ptr=0;
	dfs_for_euler(1,1,0);
	makeArr();

	int q;
	cin>>q;
	/*
	cout<<"Before :-\n";
	for(int i=0;i<n;i++){
		cout<<"prc for "<<cost[i]<<"\n";
		for(auto x:prc[cost[i]]){
			cout<<x.first<<" - "<<x.second<<"\n";
		}
	}
	*/
	
	for(int i=0;i<q;i++){
		ll ans123;
		cin>>x>>y;
		/*if(x==y){
			cout<<cost[i];
			continue;
		}*/
		ans123=DFScallUtil(x,y,vec,n+1,stack,cost);
		cout<<ans123%MOD<<"\n";
	}
	/*
	cout<<"After :-\n";
	for(int i=0;i<n;i++){
		cout<<"prc for "<<cost[i]<<"\n";
		for(auto x:prc[cost[i]]){
			cout<<x.first<<" - "<<x.second<<"\n";
		}
	}*/
	return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;
	sieve_modified();
	numberofDivisorofProduct();
	while(t--){
		solve();
	}
    return 0;
}