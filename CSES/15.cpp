#include <bits/stdc++.h>
using namespace std;
#define ll long long int

char chess[8][8];
int ans=0;
int n;
bool diag1[16],diag2[16],row[8],col[8];
void search(int y){
	if(y==8){
		ans++;
	}

	for(int x=0;x<8;x++){
		if(col[x]||diag1[x+y]||diag2[x-y+n-1] || chess[y][x]=='*') continue;
		col[x]=diag2[x-y+n-1]=diag1[x+y]=true;
		search(y+1);
		col[x]=diag2[x-y+n-1]=diag1[x+y]=false;
	}
}

void solve(){
	n=8;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>chess[i][j];
		}
	}
	search(0);
	cout<<ans<<"\n";
	return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
/*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
*/		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}