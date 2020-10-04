#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int mxN=2e5+7;
std::vector<int> graph[mxN];
void solve(){
	int n,m;
	cin>>n>>m;
	int x[m],y[m];
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int s[n+1]={0};
	for(int i=0;i<m;i++){
		cin>>x[i]>>y[i];
		graph[x[i]].push_back(i);
		graph[y[i]].push_back(i);
		s[x[i]]++;
		s[y[i]]++;
	}
	int fri[n+1];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for(int i=1;i<=n;i++){
		if(s[i]){
			pq.push({max(0,s[i]-w[i]),i});
		}
		else{
			fri[i]=1;
		}
	}
	while(!pq.empty()){
		auto q=pq.top();
		pq.pop();
		if(q.first!=max(0,s[q.second]-w[q.second])) continue;
		if(q.first>0){
			cout<<"DEAD\n";
			return ;
		}
		int id=q.second;
		std::vector<int> wt;
		for(auto u:graph[id]){
			if(fri[u]) continue;
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
		clock_t tStart = clock();
	#endif
		
	int t=1;

	while(t--){
		solve();
	}
	#ifndef ONLINE_JUDGE
		cerr<<fixed<<setprecision(10)<<"Time Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
	#endif

	return 0;
}