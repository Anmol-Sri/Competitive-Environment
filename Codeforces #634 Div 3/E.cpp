#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	int n;
	cin>>n;
	int x,y;
	int high=0,sec=0;
	int arr[n];
	unordered_map<int,int> fre;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		fre[arr[i]]++;
		if(fre[arr[i]]>high){
			x=arr[i];
			high=fre[arr[i]];
		}
		else if(high>fre[arr[i]] && fre[arr[i]]<sec){
			y=arr[i];
			sec=fre[arr[i]];
		}
	}
	int ans=0,i;
	for(i=0;i<n;i++){
		if(arr[i]==x){
			
		}
	}


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}