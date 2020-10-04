#include <bits/stdc++.h> 
using namespace std;
#define N 1000005 
#define MAX 1e18 
#define ll long int
const ll MOD=1e9+7;
// Code Taken From Geeks for Geeks
vector<long int> powers; 
set<long int> squares; 
set<long int> s; 
void powersPrecomputation() 
{ 
	for (long int i = 2; i < N; i++) 
	{ 
		squares.insert(i * i); 
		if (squares.find(i) != squares.end()) 
				continue; 
		long int temp = i; 
		while (i * i <= MAX / temp) 
		{ 
			temp *= (i * i); 
			s.insert(temp); 
		} 
	} 
	for (auto x : s) 
		powers.push_back(x); 
	ll dup=0;
	for(auto x:squares){
		if(find(powers.begin(),powers.end(),x)!=powers.end()){
			cout<<"Duplicate Value : "<<x<<"\n";
			dup++;
		}
	}
} 

void solve(){
	ll n;
	cin>>n;
	if(n==1){
		cout<<"1\n";
		return;
	}
	else if(n==2){
		cout<<"2\n";
		return;
	}
	else if(n==3){
		cout<<"3\n";
		return;
	}
	else if(n==4){
		cout<<"8\n";
		return;
	}
	ll ans=0;
	for(ll i=0;;i++){
		if(powers[i]==0){
			break;
		}
		ll x=(ll)(floor(n/powers[i]));
		//cout<<i<<" - "<<powers[i]<<" - "<<x<<endl;
		if(x<1){
			break;
		}
		ans=(ans+((powers[i]%MOD)*x)%MOD)%MOD;
	}
	ans=ans%MOD;
	for(auto q:squares){
		if(q==0){
			break;
		}
		ll x=(ll)(floor(n/q));
		//cout<<q<<" - "<<x<<endl;
		if(x<1){
			break;
		}
		ans=(ans+((q%MOD)*x)%MOD)%MOD;
	}
	ans=ans%MOD;
	ans=(ans+(n%MOD))%MOD;
	cout<<ans<<"\n";
}

// Driver Code 
int main() 
{ 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	// precompute the powers 
	powersPrecomputation(); 
	int t;
	cin>>t;

	while(t--){
		solve();
		//cout<<"-------------\n";
	}
	
} 
