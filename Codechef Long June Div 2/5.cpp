#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n][n];
	if(n&1){
		int count=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				arr[i][j]=count;
				count++;
			}
		}
	}
	else{
		int count=1;
		for(int i=0;i<n;i++){
			if(i&1){
				for(int j=n-1;j>=0;j--){
					arr[i][j]=count;
					count++;
				}
			}
			else{
				for(int j=0;j<n;j++){
					arr[i][j]=count;
					count++;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
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