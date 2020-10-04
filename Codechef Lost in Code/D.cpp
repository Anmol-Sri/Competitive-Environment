#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int mxN=1e5+3;


void solve(){
	int x1[mxN],x2[mxN],x3[mxN];
	int y1[mxN],y2[mxN],y3[mxN];
	int sum1[mxN],sum2[mxN],sum3[mxN],sum4[mxN];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>x3[i]>>y3[i];
		sum1[min(min(x1[i],x2[i]),x3[i])+1]++;
		sum2[min(min(y1[i],y2[i]),y3[i])+1]++;
		sum3[max(max(x1[i],x2[i]),x3[i])]++;
		sum4[max(max(y1[i],y2[i]),y3[i])]++;
	}
	for(int i=1;i<mxN;i++){
		sum1[i]+=sum1[i-1];
		sum2[i]+=sum2[i-1];
		sum3[i]+=sum3[i-1];
		sum4[i]+=sum4[i-1];
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		char c1,c2;
		int val;
		cin>>c1>>c2>>val;
		if(c1=='x'){
			cout<<abs(sum1[val]-sum3[val])<<"\n";
		}
		else{
			cout<<abs(sum2[val]-sum4[val])<<"\n";
		}
	}
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

	while(t--){
		solve();
	}
	return 0;
}