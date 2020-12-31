#include <bits/stdc++.h>
using namespace std;
#define ll long int
void solve(){
	int n,q;
	cin>>n>>q;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	while(q--){
		char ch;
		int x,y;
		cin>>ch;
		cin>>x>>y;
		if(ch=='U'){
			arr[x-1]=y;
		}
		else{
			int l,r;
			x--;
			y--;
			l=x;
			r=y;
			for(int i=x-1;i>=0;i--){
				if(arr[i]>0){
					l=i;
				}
				else{
					break;
				}
			}
			for(int i=y+1;i<n;i++){
				if(arr[i]>0){
					r=i;
				}
				else{
					break;
				}
			}
			//cout<<l<<" "<<r<<endl;
			ll sum=0;
			for(int i=l;i<=r;i++){
				sum+=arr[i];
			}
			cout<<sum<<"\n";
		}
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