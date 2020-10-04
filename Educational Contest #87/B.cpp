#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=2e5+1;
char s[mxN];
void solve(){
	string s;
	cin>>s;
	int q,w,e;
	q=-1;
	w=-1;
	e=-1;
	std::vector<pair<int,int>> v;
	int best=INT_MAX;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') q=i;
		if(s[i]=='2') w=i;
		if(s[i]=='3') e=i;

		if(q!=-1 && w!=-1 && e!=-1){
			best=min(best,1+max(q,max(w,e))-min(q,min(w,e)));
		}
	}

	if(best==INT_MAX){
		cout<<"0\n";
		return ;
	}
	//a=b=c=false;


	cout<<best<<"\n";
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