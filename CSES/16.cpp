#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string s;
int grid[7][7];
int count=0;
int r[]={-1,0,1,0};
int c[]={0,-1,0,1};

int recur(int y,int x,int i,char m){
	if(i==48) return 1;
	if(grid[6][0]) return 0;
	if(m=='L' && (x==0 || grid[y][x-1]) && y>0 && y<6 && !grid[y-1][x] && !grid[y+1][x]) return 0;
	if(m=='R' && (x==6 || grid[y][x+1]) && y>0 && y<6 && !grid[y-1][x] && !grid[y+1][x]) return 0;
	if(m=='U' && (y==0 || grid[y-1][x]) && x>0 && x<6 && !grid[y][x-1] && !grid[y][x+1]) return 0;
	if(m=='D' && (y==6 || grid[y+1][x]) && x>0 && x<6 && !grid[y][x-1] && !grid[y][x+1]) return 0;
	if(s[i]=='?'){
		int k=0;
		for(int j=0;j<4;j++){
			int yy=y+r[j];
			int xx=x+c[j];
			if(yy<0 || yy>6) continue;
			if(xx<0 || xx>6) continue;
			if(grid[yy][xx]) continue;
			grid[yy][xx]=true;
			k+=recur(yy,xx,i+1,"ULDR"[j]);
			grid[yy][xx]=false;
		}
		return k;
	}
	if(s[i]=='L') x--;
	else if(s[i]=='R') x++;
	else if(s[i]=='U') y--;
	else if(s[i]=='D') y++;
	if(x<0||x>6) return 0;
	if(y<0||y>6) return 0;
	if(grid[y][x]) return 0;
	grid[y][x]=true;
	int k=recur(y,x,i+1,s[i]);
	grid[y][x]=false;
	return k;
}

void solve(){
	cin>>s;
	grid[0][0]=true;
	cout<<recur(0,0,0,0)<<"\n";
	return ;
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