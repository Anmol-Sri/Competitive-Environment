#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1e5+10;
bool exclude[mxN]={false};
int arr[mxN];
int ans[mxN];

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	memset(ans,-1,sizeof(ans));

	for(int i=1;i<=n;i++){
		if(arr[i]!=arr[i-1]){
			ans[i]=arr[i-1];
			exclude[arr[i-1]]=true;
		}
	}
	exclude[arr[n]]=true;
	int small=0;

	for(int i=1;i<=n;i++){
		while(exclude[small]){
			small++;
		}
		if(ans[i]==-1){
			ans[i]=small;
			exclude[small]=true;
		}
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
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