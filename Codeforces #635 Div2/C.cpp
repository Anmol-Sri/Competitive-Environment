#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=2e5+1;
vector<int> tree[mxN];
int depth[mxN];
int subtrees[mxN];
int ans[mxN];

void dfs(int v,int f){
    depth[v]=depth[f]+1;
    subtrees[v]=1;
    for(auto u:tree[v]){
        if(u!=f){
            dfs(u,v);
            subtrees[v]=subtrees[v]+subtrees[u];
        }
    }
    ans[v]=subtrees[v]-depth[v];
}

void addEdge(int x,int y){
    tree[x].push_back(y);
    tree[y].push_back(x);
}

void solve(){
    int n,k;   
    cin>>n>>k;

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        addEdge(x,y);
    }
    depth[0]=0;

    dfs(1,0);
    /*for(auto x=1;x<=n;x++){
        cout<<x<<" - "<<depth[x]<<" - "<<subtrees[x]<<"\n";
    }
    
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" - ";
    }
    cout<<endl;
*/
    sort(ans+1,ans+n+1,greater<int>());
/*
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" - ";
    }
    cout<<endl;
*/
    ll res=0;
    for(int i=1;i<=n-k;i++){
        res=res+ans[i];
    }
    cout<<res<<"\n";
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
    int t;
    //cin>>t;
    t=1;

    while(t--){
        solve();

    }
    return 0;
}