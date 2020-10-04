#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int s=0,t=0,count=0;
	int dp[n][n]={0};
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			dp[i][j]=arr[j]+dp[i][j-1];
			int s=dp[i][j];
			int t=sqrt(s);
			if(t*t==s){
				count++;
			}
		}
		//s=0;
	}
	cout<<count<<"\n";
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
	int i=1;
	while(t--){
		cout<<"Case #"<<i<<": ";
		solve();
		i++;
	}
    return 0;
}