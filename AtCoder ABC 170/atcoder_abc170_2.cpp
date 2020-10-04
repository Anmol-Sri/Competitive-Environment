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
		//cout<<"asd";
		int x=arr[i];
		if(fre[x]>1){
			continue;
		}
		bool ok=true;
		for(int j=1;j<=sqrt(x);j++){
			if(x%j==0){
				if(fre[j]>0){
					//cout<<arr[i]<<"\n";
					//cout<<j<<"\n";
					ok=false;
					break;
				}
				if(x/j!=x){
					//cout<<x/j<<"\n";
					if(fre[x/j]>0){
						ok=false;
						break;
					}
				}
				else{
					if(fre[x/j]>1){
						ok=false;
						break;
					}
				}
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