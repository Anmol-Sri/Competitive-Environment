#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,m;
	cin>>n>>m;
	int lar=0;
	bool fre[m];
	int small=0;
	memset(fre,false,sizeof(fre));
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x>m) lar++;
		if(x<m) fre[x]=true,small++;
	}
	for(int i=1;i<m;i++){
		if(!fre[i]){
			cout<<"-1\n";
			return ;
		}
	}
	cout<<lar+small<<"\n";
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