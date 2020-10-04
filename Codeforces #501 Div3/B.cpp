#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	string s,t;
	cin>>s;
	cin>>t;
	if(s==t){
		cout<<"0\n";
		return;
	}
	if(s.size()!=t.size()){
		cout<<"-1\n";
		return;
	}
	bool flag=true;
	/*
	for(int i=0;i<s.size();i++){
		char ch=s[i];
		bool temp=false;
		for(int j=0;j<t.size();j++){
			if(ch==t[j]){
				temp=true;
				break;
			}
		}
		if(temp==false){
			flag=false;
			break;
		}
	}*/

	
	std::vector<int> ans;
	for(int i=0;i<n;i++){
		char ch=s[i];
		if(s[i]==t[i]) continue;
		int pos=-1;
		for(int j=i+1;j<n;j++){
			if(s[j]==t[i]){
				pos=j;
				break;
			}
		}
		if(pos==-1){
			flag=false;
			break;
		}
		for(int j=pos-1;j>=i;j--){
			ans.push_back(j);
			swap(s[j],s[j+1]);
		}
		//cout<<i<<" - "<<s<<"\n";
	}

	if(flag==false || ans.size()>10000){
		cout<<"-1\n";
		return;
	}
	else{
		cout<<ans.size()<<"\n";
		for(auto x:ans){
			cout<<x+1<<" ";
		}
		cout<<"\n";
		return;
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