#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
bool visited[51][51];

bool check(int a,int b){
	return (a>=1 && a<=n && b<=m && b>=1);
}

void solve(){
	memset(visited,false,sizeof(visited));
	cin>>n>>m;

	char arr[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
		}
	}	

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j]=='B'){
				for(int k=0;k<4;k++){
					int x=i+dir[k][0];
					int y=j+dir[k][1];
					if(check(x,y) && arr[x][y]=='.'){
						arr[x][y]='#';
					}
				}
			}
		}
	}

	queue<pair<int,int>> qu;

	if(arr[n][m]=='.'){
		qu.push({n,m});
		visited[n][m]=true;
	}

	while(!qu.empty()){
		int a=qu.front().first;
		int b=qu.front().second;
		qu.pop();

		for(int k=0;k<4;k++){
			int x=a+dir[k][0];
			int y=b+dir[k][1];

			if(check(x,y) && !visited[x][y] && arr[x][y]!='#'){
				qu.push({x,y});
				visited[x][y]=true;
			}
		}
	}

	bool ok=true;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((arr[i][j]=='G' && !visited[i][j]) || (arr[i][j]=='B' && visited[i][j])){
				ok=false;
				break;
			}
		}
	}

	if(ok){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
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