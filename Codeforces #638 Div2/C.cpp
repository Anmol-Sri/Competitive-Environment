#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	std::vector<string> s1(k);
	std::vector<string> s2(k);

	for(int i=0;i<k;i++){
		s1[i]="";
		s2[i]="";
	}
	sort(s.begin(),s.end());
	if(k==1){
		cout<<s;
		cout<<"\n";
		return;
	}
	if(k==n){
		cout<<s[n-1];
		cout<<"\n";
		return;
	}

	for(int i=0;i<k;i++){
		s1[i]+=s[i];
		s2[i]+=s[i];
	}

	for(int i=k;i<n;i++){
		s1[0]+=s[i];
		s2[i%k]+=s[i];
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	cout<<min(s1[k-1],s2[k-1]);
	cout<<"\n";
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