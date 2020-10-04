#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool query(int r1,int c1,int r2,int c2){
	cout<<"? "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
	string s;
	cin>>s;
	if(s[0]=='Y') return true;
	return false;
}

void solve(){
	int n;
	cin>>n;
	//int row=1,col=1;
	string fir="";
	string sec="";
	int r,c;

	r=1,c=1;
	while(r+c<n+1){
		if(query(r+1,c,n,n)){
			r++;
			fir+='D';
		}
		else{
			c++;
			fir+='R';
		}
	}
	r=n,c=n;
	while(r+c>n+1){
		if(query(1,1,r,c-1)){
			sec+='R';
			c--;
		}
		else{
			sec+='D';
			r--;
		}
	}
	reverse(sec.begin(),sec.end());
	string ans=fir+sec;
	cout<<"! "<<ans<<endl;
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