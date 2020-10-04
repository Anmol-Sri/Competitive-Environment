#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	//int n,m;
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	int fre[70][2];
	memset(fre,0,sizeof(fre));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]==0){
				fre[i+j][0]++;
			}
			else{
				fre[i+j][1]++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=(n+m-2)/2;i++){
		if(i!=(n+m-2)/2 || (m+n&1))
			ans+=min(fre[i][0]+fre[n+m-2-i][0],fre[i][1]+fre[n+m-2-i][1]);
	}
	cout<<ans<<"\n";
	return ;
	/*cin>>n>>m;
	ans=0;
	int arr[n][m];
	int one=0,zero=0;
	int a[n+m]={0},b[n+m]={0};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]==1) {one++;b[i+j]++;}
			else {zero++;a[i+j]++;}
		}
	}

	int mid=(m+n-2)/2;
	for(int i=0;i<=mid;i++){
		if(i!=mid || (m+n)&1){
			ans+=min(b[i]+b[n+m-i-2],a[i]+a[n+m-i-2]);
		}
	}
	cout<<ans<<"\n";
	return ;*/
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