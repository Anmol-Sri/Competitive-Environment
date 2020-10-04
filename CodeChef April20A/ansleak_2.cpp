#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,m,k;
	cin>>n>>m>>k;

	for(int i=0;i<n;i++){
		int fre[m];
		int ansk[k];
		for(int j=0;j<k;j++){
			cin>>ansk[j];
			fre[ansk[j]-1]++;
		}
		for(int j=0;j<m;j++){
			
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