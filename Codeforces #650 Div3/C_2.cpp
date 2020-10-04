#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int count=0;
	//bool ok=false;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			bool ok=true;
			for(int j=max(i-k,0);j<=min(i+k,n-1);j++){
				if(s[j]=='1'){
					ok=false;
					break;
				}
			}
			
			if(ok){
				count++;
				s[i]='1';
			}
			i=min(i+k,n-1);
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}