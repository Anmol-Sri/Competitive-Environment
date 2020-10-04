#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	std::vector<array<int,3>> v;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v.push_back({a,0,i});
		v.push_back({b,1,i});
	}
	sort(v.begin(), v.end());
	/*for(auto x:v){
		cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
	}*/
	int c=0;
	int ans[n];
	std::vector<int> room;
	for(auto x:v){
		if(x[1]==0){
			c++;
			if(room.empty()) ans[x[2]]=c;
			else{
				ans[x[2]]=room.back();
				room.pop_back();
			}
		}
		else{
			c--;
			room.push_back(ans[x[2]]);
		}
	}
	cout<<*max_element(ans,ans+n)<<"\n";
	for(int z:ans){
		cout<<z<<" ";
	}
	cout<<"\n";
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    /*#ifndef ONLINE_JUDGE
    	freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		clock_t tStart = clock();
	#endif*/

	int t=1;

	while(t--){
		solve();
	}

    return 0;
}