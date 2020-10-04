#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	string s;
	cin>>s;
	int mx=1;
	for(int i=0;i<s.size();i++){
		int count=1;
		int j;
		for(j=i+1;j<s.size();j++){
			if(s[i]!=s[j]){
				break;
			}
			else{
				count++;
			}
		}
		i=j-1;
		mx=max(mx,count);
	}
	cout<<mx<<"\n";
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	*/	
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}