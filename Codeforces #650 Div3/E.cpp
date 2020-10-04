#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	std::vector<int> cnt(26,0);
	for(char c:s){
		cnt[c-'a']++;
	}
	int ans=0;
	for(int len=n;len>=1;len--){
		std::vector<bool> used(len);
		std::vector<int> cycles;

		for(int i=0;i<len;i++){
			if(used[i]) continue;
			int j=(i+k)%len;
			used[i]=true;
			cycles.push_back(0);
			cycles.back()++;
			while(!used[j]){
				cycles.back()++;
				used[j]=true;
				j=(j+k)%len;
			}
		}

		std::vector<int> cur_cnt(cnt);

		sort(cycles.begin(), cycles.end());
		sort(cur_cnt.begin(), cur_cnt.end());

		bool ok=true;
		while(!cycles.empty()){
			if(cur_cnt.back()<cycles.back()){
				ok=false;
				break;
			}
			else{
				cur_cnt.back()-=cycles.back();
				cycles.pop_back();
				sort(cur_cnt.begin(), cur_cnt.end());
			}
		}
		if(ok){
			cout<<len<<"\n";
			return ;
		}
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