#include <bits/stdc++.h>
using namespace std;
#define ll long int
void solve(){
	int n;
	cin>>n;
	int arr[n];
	int max1=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>arr[max1]) max1=i;
	}
	
	int max2=-1;
	for(int i=max1+1;i<n;i++){
		if(arr[i]==arr[max1]){
			max2=i;
		}
	}
	//cout<<max1<<max2<<endl;
	if(max2==-1){
		if(max1>(n/2-1)) cout<<n-max1-1<<endl;
		else cout<<n/2<<endl;
		return;
	}
	else if((n-max2-1)<=(n/2-max1-1)){
	    cout<<"0\n";
	    return;
	}
	else{
		/*int ans=n-max2-1;
		cout<<ans<<"\n";*/
		/*int mins=max2-max1+1;
		int av=n-max2-1;
		if(mins>av)cout<<"0\n";
		else{
			max1+=n/2;
			max1--;
			max2+=n/2;
			max2--;
			cout<<n-max2-1<<endl;
		}*/

		if(max1>(n/2-1)){
			cout<<n-max2-1<<endl;
			return;
		}
		else{
			max1=max1+n/2;
			if(max1>=n){
				cout<<"0\n";
				return;
			}
			max2=max2+n/2;
			//cout<<max1<<max2<<endl;
			if(max2>=n){
				cout<<"0\n";
				return;
			}
			else{
				//cout<<max1<<" "<<max2<<endl;
				cout<<n-max2<<endl;
				return;
			}
		}
		//if(mins==av)
	}
	
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
    return 0;
}