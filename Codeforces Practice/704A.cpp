#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=3e5+10;
std::vector<int> arr[mxN];
bool vis[mxN];

int t;
int cur;
void solve(){
	int n,q;
	cin>>n>>q;
	int count=0;
	while(q--){
		int a,b;
		cin>>a>>b;
		if(a==1){
			arr[b].push_back(++t);
			count++;
		}
		else if(a==2){
			int temp=arr[b].size();
			for(int i=0;i<temp;i++){
				if(!vis[arr[b][i]]){
					vis[arr[b][i]]=true;
					count--;
				}
			}
			arr[b].clear();
		}
		else{
			for(int i=cur+1;i<=b;i++){
				if(!vis[i]){
					vis[i]=true;
					count--;
				}
			}
			cur=max(cur,b);
		}
		cout<<count<<"\n";
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
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}