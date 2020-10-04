#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	ll x,k;
	cin>>x>>k;
	if(k>30){
		cout<<"0\n";
		return;
	}
	if(x<2){
		if(x==1 && k==0) cout<<"1\n";
		else cout<<"0\n";
		return;
	}
	if(x==2){
		if(k==1){
			cout<<"1\n";
		}
		else{
			cout<<"0\n";
		}
		return;
	}
	if(x<=k){
		cout<<"0\n";
		return;
	}
	ll min=(ll)pow(2,k);
	if(x<min){
		cout<<"0\n";
		return;
	}
	
	std::vector<int > P;
	ll n=x;
	while(n%2==0){
		P.push_back(2);
		n/=2;
	}
	for(int i=3;i*i<=n;i=i+2){
		while(n%i==0){
			n=n/i;
			P.push_back(i);
		}
	}
	if(n>2){
		P.push_back(n);
	}
	if(P.size()<k){
		cout<<"0\n";
		return;
	}
	ll pro=1;
	for(int i=k-1;i<P.size();i++){
		pro=pro*P[i];
	}
	P.push_back(pro);
	std::vector<int>::iterator it;
	it=std::find(P.begin(), P.end(),1);
	if(it==P.end()){
		cout<<"1\n";
		return;
	}
	cout<<"0\n";
	return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}