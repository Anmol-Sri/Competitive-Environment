#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,b,m;
	cin>>n>>b>>m;
	int ans=0;
	int prev_start=-1,prev_end=-1;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		int set=x/b;
		if(prev_start==-1 && prev_end==-1){
			prev_start=set*b;
			prev_end=(set+1)*b-1;
			ans++;
		}
		else if(prev_start<=x && x<=prev_end){
			continue;
		}
		else{
			prev_start=set*b;
			prev_end=(set+1)*b-1;
			ans++;
		}
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
		clock_t tStart = clock();
	#endif
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
	#ifndef ONLINE_JUDGE
		cerr<<fixed<<setprecision(10)<<"Time Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
	#endif

	return 0;
}