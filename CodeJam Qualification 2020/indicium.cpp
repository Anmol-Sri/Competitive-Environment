#include <bits/stdc++.h>
using namespace std;
#define ll long int

int arr[60][60];
int n,k,q;
bool rs[60][60],cs[60][60];
bool flag;

void recur(int r,int c,int m){
	if(!flag && r==n && c==n+1 && m==k){
		flag=true;
		cout<<"Case #"<<q<<": "<<"POSSIBLE\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}
		return;
	}
	else if(r>n){
		return;
	}
	else if(c>n){
		recur(r+1,1,m);
	}
	for(int i=1;!flag && i<=n;i++){
		if(!rs[r][i] && !cs[c][i]){
			rs[r][i]=cs[c][i]=true;
			if(r==c){
				m=m+i;
			}
			arr[r][c]=i;
			recur(r,c+1,m);
			rs[r][i]=cs[c][i]=false;
			if(r==c){
				m=m-i;
			}
			arr[r][c]=0;
		}
	}
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

	for( q=1;q<=t;q++){
		cin>>n>>k;
		recur(1,1,0);
		if(!flag){
			cout<<"Case #"<<q<<": "<<"IMPOSSIBLE\n";
		}
		flag=false;
	}
    return 0;
}