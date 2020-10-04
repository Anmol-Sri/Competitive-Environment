#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	if(n==k){
		cout<<s<<"\n";
		return;
	}
	stack<int> st;
	bool used[n]={false};
	int iter=0;
	for(int i=0;i<n;i++){
		if(iter==k){
			break;
		}
		if(s[i]=='('){
			st.push(i);
		}
		else{
			if(st.empty()){
				continue;
			}
			used[st.top()]=true;
			st.pop();
			used[i]=true;
			iter+=2;
		}
	}

	for(int i=0;i<n;i++){
		if(used[i]){
			cout<<s[i];
		}
	}
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}