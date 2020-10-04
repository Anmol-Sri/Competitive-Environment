#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	//string s[n];
	string arr[n];
	unordered_map<string,int> mp;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		//arr[i]=stoi(s[i]);
		mp[arr[i]]++;
	}
	int ans=0;
	string qwe[n];
	for(int i=0;i<n;i++){
		if(mp[arr[i]]==1){
			qwe[i]=arr[i];
			mp[arr[i]]--;
		}
		else{
			ans++;
			//mp[arr[i]]--;
			for(int j=0;j<=9;j++){
				string asd=arr[i].substr(0,arr[i].size()-1)+to_string(j);
				//cout<<asd<<"\n";
				if(mp.find(asd)==mp.end()){
					//cout<<"at i = "<<i<<"taken asd = "<<asd<<"\n";
					qwe[i]=asd;
					mp[asd]++;
					break;
				}
			}
			mp[arr[i]]--;
		}
	}
	cout<<ans<<"\n";
	for(int i=0;i<n;i++){
		cout<<qwe[i]<<"\n";
	}
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