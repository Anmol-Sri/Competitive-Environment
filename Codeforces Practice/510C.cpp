#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=101;
string s[mxN];
string ans;
bool vis[26];
bool check[26];
std::vector<int> adj[26];

void dfs(int u){
	vis[u]=true;
	check[u]=true;

	for(int v:adj[u]){
		if(check[v]){
			cout<<"Impossible\n";
			exit(0);
		}
		if(!vis[v]){
			dfs(v);
		}
	}
	check[u]=false;
	ans+=u+'a';

}

void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(i){
			int j=0;
			while(j<s[i].size() and j<s[i-1].size() and s[i][j]==s[i-1][j]) j++;
			if(j==s[i].size()){
				cout<<"Impossible\n";
				exit(0);
			}
			if(j<s[i-1].size()){
				adj[s[i][j]-'a'].push_back(s[i-1][j]-'a');
			}
		}
	}

	for(int i=0;i<26;i++){
		if(!vis[i]) dfs(i);
	}
	cout<<ans<<"\n";
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
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}