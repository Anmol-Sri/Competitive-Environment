#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int INF=1e9+1;

void solve(){
	string s;
	cin>>s;
	int m;
	cin>>m;
	vector<int> arr(m);
	for(int &i:arr) cin>>i;

	std::vector<int> count(26);
	for(char c:s) count[c-'a']++;

	string ans(m,'?');
	
	while(*min_element(arr.begin(), arr.end())!=INF){

		std::vector<int> zeros;
		for(int i=0;i<m;i++){
			if(arr[i]==0){
				zeros.push_back(i);
			}
		}

		while(count.back()<zeros.size()) count.pop_back();

		int c=(int)count.size()-1;
		for(int i:zeros){
			ans[i]=c+'a';
		}

		for(int i:zeros){
			for(int j=0;j<m;j++){
				if(arr[j]!=INF && arr[j]>0){
					arr[j]=arr[j]-abs(i-j);
				}
			}
		}
		count.pop_back();
		for(int i:zeros) arr[i]=INF;
	}
	cout<<ans<<"\n";
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