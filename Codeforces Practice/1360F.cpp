#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	string arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	string ans=arr[0];
	for(int j=0;j<m;j++){
		char save=ans[j];
		for(char d='a';d<='z';d++){
			ans[j]=d;
			bool flag=true;
			for(int z=0;z<n;z++){
				int cntErrors=0;
				for(int c=0;c<m;c++){
					if(arr[z][c]!=ans[c]){
						cntErrors++;
					}
				}
				if(cntErrors>1){
					flag=false;
					break;
				}
			}
			if(flag){
				cout<<ans<<"\n";
				return;
			}
		}
		ans[j]=save;
	}
	cout<<"-1\n";
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