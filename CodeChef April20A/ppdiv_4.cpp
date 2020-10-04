#include <bits/stdc++.h> 
using namespace std;
#define N 1000005 
#define MAX 1e18 
#define ll long int
const ll MOD=1e9+7;
// Code Taken From Geeks for Geeks
//vector<long int> powers; 
set<long int> squares; 
set<long int> s; 
set<ll> universal;

ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

ll modInverse(ll b, ll m) 
{ 
    ll x, y; // used in extended GCD algorithm 
    ll g = gcdExtended(b, m, &x, &y); 
    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 
    // m is added to handle negative x 
    return (x%m + m) % m; 
} 
// Function to compute a/b under modlo m 
void modDivide(ll a, ll b, ll m) 
{ 
    a = a % m; 
    ll inv = modInverse(b, m); 
    if (inv == -1) 
       cout << "Division not defined"; 
    else
       cout << "Result of division is " << (inv * a) % m; 
} 
void testing(){
	ll n=1e18;

	for(ll i=1e6;i<=1e7;i++){
		ll p=i*i;
		cout<<i<<" - "<<floor(n/p)<<" - "<<modInverse(p,MOD)<<"\n";
	}
}
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
	ll i=0;
	/*
	for(auto x:squares){
		cout<<i+2<<" - "<<x<<"\n";
		i++;
	}*/
	
	
	/*for (auto x : s) 
		powers.push_back(x); 
	ll dup=0;
	for(auto x:squares){
		if(find(powers.begin(),powers.end(),x)!=powers.end()){
			cout<<"Duplicate Value : "<<x<<"\n";
			dup++;
		}
	}*/
	/*
	std::set<int> odd = { 1, 3, 5 };
	std::set<int> even = { 2, 4, 6 };

	std::set<int> s;
	std::set_union(odd.begin(), odd.end(),
				even.begin(), even.end(),
				std::inserter(s, s.begin()));

	for (auto const &e: s) {
		std::cout << e << ' ';
	}*/
	std::set_union(s.begin(), s.end(),squares.begin(),squares.end(),std::inserter(universal,universal.begin()));

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
	/*for(ll i=0;;i++){
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
	}*/

	for(auto q:universal){
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
	return;
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
	//powersPrecomputation(); 
	testing();
	int t;
	cin>>t;

	while(t--){
		//solve();
		//cout<<"-------------\n";
	}
	return 0;	
} 
