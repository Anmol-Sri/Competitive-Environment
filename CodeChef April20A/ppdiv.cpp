#include <bits/stdc++.h>
using namespace std;
#define ll long int

const ll MOD=1e9+7;
map<ll,ll>perfect_power;

void precalc(){
	perfect_power[1]=1;
	perfect_power[2]=1;
	perfect_power[3]=1;
	perfect_power[4]=5;
}

void solve(){

	ll n;
	cin>>n;
	
	ll mxN=10e6,i=1,calc_fact=0,count_till_i=0;

	for(ll j=1;j<n+1;j++){
		if(perfect_power[j]!=0){
			calc_fact=calc_fact+perfect_power[j];
		}
		else{
			set<ll> store;
			i=2;
			count_till_i=1;
			while(i<=sqrt(j)){
				ll k=i*i;
				while(k<=j){
					if(j%k==0){
						store.insert(k);
					}
					k=k*i;
				}
				i++;
			}
			for(auto x:store){
				count_till_i=count_till_i+x;
			}
			calc_fact=calc_fact+count_till_i;
			if(calc_fact>MOD){
				calc_fact=calc_fact%MOD;
			}
			perfect_power[j]=count_till_i;
		}
		i++;
		if(calc_fact>MOD){
			calc_fact=calc_fact%MOD;
		}
	}

	if(calc_fact>MOD){
		calc_fact=calc_fact%MOD;
	}

	cout<<calc_fact<<"\n";

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
	precalc();

	while(t--){
		solve();
	}
    return 0;
}