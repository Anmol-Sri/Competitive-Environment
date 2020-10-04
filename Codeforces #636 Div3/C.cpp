#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	ll sum=0;
	bool pos=false;

	for(int i=0;i<n;i++){
		cin>> arr[i];
	}

	if(arr[0]>0){
		pos=true;
	}
	else{
		pos=false;
	}
	for(int i=0;i<n;i++){

		if(pos){
			int qwe=-1;
			for(;i<n;i++){
				if(arr[i]>0){
					qwe=max(qwe,arr[i]);
				}
				else{
					break;
				}
			}
			i--;
			sum+=qwe;
			pos=false;
		}
		else{
			int qwe=INT_MIN;
			for(;i<n;i++){
				if(arr[i]<0){
					qwe=max(qwe,arr[i]);
				}
				else{
					break;
				}
			}
			i--;
			sum+=qwe;
			pos=true;
		}

	}

	cout<<sum<<"\n";
	return;

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