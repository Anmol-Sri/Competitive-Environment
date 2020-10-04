#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	char s[n][m];
	bool vis[n][m];
	memset(vis,false,sizeof(vis));
	int white=0,black=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>s[i][j];
			if(s[i][j]=='.'){
				white++;
			}
		}
	}
	if(white==0){
		cout<<"0\n";
		return;
	}
	if(2*x<=y){
		cout<<white*x<<"\n";
		return ;
	}
	ll cost=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] && s[i][j]=='.'){
				vis[i][j]=true;
				if(j!=m-1 && s[i][j]==s[i][j+1] && s[i][j]=='.'){
					cost+=y;
					vis[i][j+1]=true;
				}
				else{
					cost+=x;
				}
			}
		}
	}
	cout<<cost<<"\n";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}