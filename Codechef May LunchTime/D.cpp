#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	if(a==b){
		cout<<"0\n";
		return ;
	}

	std::vector<std::vector<int>> ans;

	for(int i=0;i<n;i++){
		if(a[i]<b[i]){
			cout<<"-1\n";
			return ;
		}			
	}

	for(char c='z';c>='a';c--){
		vector<int> pos;
		bool ok=false;
		for(int i=0;i<n;i++){
			if(b[i]==c and a[i]!=c){
				pos.push_back(i);
			}
		}

		if(!ok && !pos.empty()){
			for(int i=0;i<n;i++){
				if(a[i]==c){
					ok =true;
					pos.push_back(i);
				}
			}
		}
		if(ok==false and !pos.empty()){
			cout<<"-1\n";
			return ;
		}
		if(!pos.empty()){
			ans.push_back(pos);
		}
		for(int i:pos){
			a[i]=c;
		}
	}
	cout<<ans.size()<<"\n";
	for(auto x:ans){
		cout<<x.size()<<" ";
		for(int q:x){
			cout<<q<<" ";
		}
		cout<<"\n";
	}
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