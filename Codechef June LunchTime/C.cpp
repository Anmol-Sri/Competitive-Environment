#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin>>n;
	float a1=0.0,b1=0.0;
	for(int i=0;i<n;i++){
		int g,a,b;
		cin>>g>>a>>b;
		float part1=(g*b)/(a+b),part2=(g*a)/(a+b);
		a1+=part1;
		b1+=part2;
	}
	cout<<a1<<" "<<b1<<"\n";
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
	cout << fixed << setprecision(5);
	while(t--){
		solve();
	}

	return 0;
}