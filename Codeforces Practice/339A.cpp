#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mxN=1e2+5;
char s[mxN];
void solve(){
	string st;
	cin>>st;
	if(st.size()==1){
		cout<<st<<"\n";
		return ; 
	}
	int i=0;
	for(char c:st){
		if(c=='+'){
			continue;
		}
		s[i++]=c;
	}
	sort(s,s+i);
	for(int j=0;j<i;j++){
		if(j==i-1) cout<<s[j]<<"\n";
		else  cout<<s[j]<<'+';
	}
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}