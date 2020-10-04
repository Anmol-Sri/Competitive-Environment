#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1e6+1;
int fre[mxN];
void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		fre[arr[i]]++;
	}
	int count=0;
	for(int i=0;i<n;i++){
		bool ok=true;
		for(int j=0;j<n;j++){
			if(i==j){
				continue;
			}
			if(arr[i]%arr[j]==0){
				ok=false;
				break;
			}
		}
		if(ok){
			count++;
		}
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
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}