#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,s;
	cin>>t>>s;
	while(t--){
		int n;
		cin>>n;
		int at[n],def[n];
		for(int i=0;i<n;i++) cin>>at[i];
		for(int i=0;i<n;i++) cin>>def[i];

		sort(at,at+n);
		sort(def,def+n);
		int i;
		if(at[0]>=def[0]){
			cout<<"NO\n";
			continue;
		}
		for(i=1;i<n;i++){

			bool found=false;
			for(int j=0;j<i;j++){
				if(at[i]==at[j] || at[i]==def[j]){
					found=true;
					break;
				}
			}

			if(found){
				if(at[i]>=def[i]){
					cout<<"NO\n";
					break;
				}
			}
			else{
				cout<<"NO\n";
				break;
			}
		}
		if(i==n) cout<<"YES\n";
	}
	return 0;
}