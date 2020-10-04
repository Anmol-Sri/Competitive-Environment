#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=5e5+13;
std::vector<int> graph[mxN];
bool vis[mxN];
unordered_set<int> s[mxN];
int topic[mxN];
bool ok;
int parent[mxN];
std::vector<pair<int,int>> store;

void make_set(int v){
	parent[v]=v;
}

int find_set(int v){
	if(v==parent[v]) return v;
	return find_set(parent[v]);
}

void union_set(int a,int b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b)
		parent[b]=a;
}

void dfs(int u){
	vis[u]=true;
	for(int v:graph[u]){
		if(topic[v]==topic[u]){
			ok=false;
			return ;
		}
		else{
			if(!vis[v])
				dfs(v);
		}
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x-1].push_back(y-1);
		graph[y-1].push_back(x-1);
	}
	for(int i=0;i<n;i++){
		cin>>topic[i];
		//s[topic[i]].insert(i);
	}
	int i=0;
 	while(i<n){
        for(int x:graph[i]){
            s[i].insert(topic[x]-1);
        }
        i++;
    }
    i=0;
    while(i<n){
        store.push_back(make_pair(topic[i]-1,i));
        i++;
    }

    sort(store.begin(),store.end());

    for(auto i : store){
        int ci = i.second;
        int ct = i.first;
        for(int j = 0; j < ct; ++j){
            if(s[ci].count(j) == 0){
                cout << -1;
                return ;
            }
        }
        if (s[ci].count(ct) != 0){
            cout << -1;
            return ;
        }
    }

    for(int qwe=0;qwe<store.size();++qwe){
        cout << store[qwe].second+1<< " ";
    }
    /*
	ok=true;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	if(!ok){
		cout<<"-1\n";
		return ;
	}
	memset(vis,false,sizeof(vis));
	int ans[n];
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			for(int x:s[i]){
				cout<<x<<" ";
			}
		}
	}
	cout<<"\n";*/
	return ;
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
	while(t--){
		solve();
	}
    return 0;
}