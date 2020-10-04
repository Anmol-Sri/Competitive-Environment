#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,m;
	cin>>n>>m;
	unordered_map<int,int> mp;
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			mp[arr[i][j]]++;
		}
	}
	int single=0;
	//bool ok=false;
	std::vector<int> si;
	std::vector<int> ele;
	for(auto x:mp){
		if(x.second&1){
			single++;
			si.push_back(x.first);
			if(single>n){
				cout<<"-1\n";
				return;
			}
			mp[x.first]--;
		}
		for(int i=1;i<=mp[x.first];i++){
			ele.push_back(x.first);
		}
	}
	if(m%2==0 && single>0){
		cout<<"-1\n";
		return ;
	}
	int qwe[n][m];
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m/2;j++){
			qwe[i][j]=qwe[i][m-1-j]=ele[count];
			count+=2;
		}
	}
	int asd=0;
	if(m&1){
		for(int i=0;i<n;i++){
			if(count<ele.size())
				qwe[i][(int)m/2]=ele[count++];
			else{
				qwe[i][(int)m/2]=si[asd++];
			}
		}
	}
	

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<qwe[i][j]<<" ";
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