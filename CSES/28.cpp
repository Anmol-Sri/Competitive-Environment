#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int x,n;
	cin>>x>>n;
	multiset<int> m;
	set<int>s;
	s.insert(0);
	s.insert(x);
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		auto l=s.lower_bound(arr[i]);
		auto r=--s.upper_bound(arr[i]);
		if(*l>arr[i]) --l;
		if(*r<arr[i]) ++r;
		auto f=m.find(*r-*l);
		if(f!=m.end()) m.erase(f);
		m.insert(arr[i]-*l);
		m.insert(*r-arr[i]);
		s.insert(arr[i]);
		cout<<*--m.end()<<" ";
	}
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
/*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
*/		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}