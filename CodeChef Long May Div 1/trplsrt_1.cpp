#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=2e5+10;
ll arr[mxN];
ll pos[mxN];
bool visited[mxN];

//Swap Code taken from GeeksForGeeks for swapping three numbers on an array
//https://www.geeksforgeeks.org/swap-three-variables-without-using-temporary-variable/
void update(ll x, ll y, ll z)
{
	//asserting to avoid un-wanted swapping
	assert(x!=y);
	assert(y!=z); 
	assert(x!=z);
	//temp variable
	int store = arr[z];
	arr[z] = arr[y];
	pos[arr[y]] = z; 
	arr[y] = arr[x]; 
	pos[arr[x]] = y;
	arr[x] = store;
	pos[store] = x;
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
		
	ll t;
	cin>>t;

	while(t--){

		ll n,k;
		cin>>n>>k;

		memset(arr,0,sizeof arr);
		memset(pos,0,sizeof pos);
		memset(visited,false,sizeof visited);

		ll i=1;
		while(i<=n){
			cin>>arr[i];
			i++;
		}

		i=1;
		while(i<=n){
			pos[arr[i]]=i;
			i++;
		}

		std::vector<std::vector<ll> > order;
		i=1;
		while(i<=n){
			if(pos[i] != i){
				ll x=pos[i];
				ll y=i;
				ll z=arr[i];
				if(x!=z){
					order.push_back({y,z,x});
					update(y,z,x);
				}
			}
			i++;
		}

		std::vector<pair<ll,ll> > swap_order;
		i=1;
		while(i<=n){
			if(i!=pos[i] and pos[i]==arr[i] and !visited[pos[i]]){
				swap_order.push_back(make_pair(i,pos[i]));
				visited[i]=true;
				visited[pos[i]]=true;
			}
			i++;
		}
		ll lim=(ll)swap_order.size();
		if(lim%2==1){
			cout<<"-1"<<"\n";
			continue;
		}

		i=0;
		while(i<lim){
			ll fir=swap_order[i].first;
			ll sec=swap_order[i].second;
			ll third=swap_order[i+1].first;
			ll fourth=swap_order[i+1].second;
			order.push_back({sec,third,fourth});
			update(sec,third,fourth);
			order.push_back({fir,sec,third});
			update(fir,sec,third);
			i+=2;
		}

		if((ll)order.size()>k){
			cout<<"-1"<<"\n";
			continue;
		}
		if(!is_sorted(arr+1,arr+n+1)){
			cout<<"-1"<<"\n";
			continue;
		}
		cout<<order.size()<<"\n";
		for(i=0;i<(ll)order.size();i++){
			cout<<order[i][0]<<" "<<order[i][1]<<" "<<order[i][2]<<"\n";
		}
	}
    return 0;
}