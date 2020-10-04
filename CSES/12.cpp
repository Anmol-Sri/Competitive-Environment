#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	string s;
	cin>>s;

	int fre[26]={0};
	int mx=0;
	for(char c:s) fre[c-'A']++,mx=max(mx,fre[c-'A']);
	if(mx==s.size()){
		cout<<s<<"\n";
		return ;
	}

	int not_even=0;
	for(int i=0;i<26;i++){
		if(fre[i]%2!=0){
			not_even++;
		}
	}

	if(s.size()%2==0 && not_even!=0){
		cout<<"NO SOLUTION\n";
		return ;
	}
	if(s.size()%2!=0 && not_even!=1){
		cout<<"NO SOLUTION\n";
		return ;
	}
	string half="";
	string mid="";
	for(int i=0;i<26;i++){
		if(fre[i]==0) continue;
		if(fre[i]%2==0){
			string add="";
			for(int j=0;j<fre[i]/2;j++) add+=char(i+'A');
			half+=add;
		}
		else{
			mid+=char(i+'A');
			string add="";
			for(int j=0;j<fre[i]/2;j++) add+=char(i+'A');
			half+=add;
		}
	}
	string rest=half;
	half+=mid;
	reverse(rest.begin(), rest.end());
	half+=rest;
	cout<<half<<"\n";
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