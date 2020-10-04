#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxA=1e6+1;
const ll MOD=1e9+7;
int prime[mxA];
ll qwe;

void sieve_modified(){
	memset(prime,0,sizeof(prime));
	prime[0]=prime[1]=1;

	for(int i=2;i*i<mxA;i++){
		if(prime[i]==0){
			for(int j=i*2;j<mxA;j+=i){
				if(prime[j]==0){
					prime[j]=i;
				}
			}
		}
	}

	for(int i=2;i<mxA;i++){
		if(prime[i]==0){
			prime[i]=i;
		}
	}
}

void numberofDivisorofProduct(){
	
	for(int i=0;i<mxA;i++){
		int temp=i;
		unordered_map<int,int> prime_count;
		while(temp!=1){
			prime_count[prime[temp]]++;
			temp=temp/prime[temp];
		}
		for(auto it:prime_count){
			cout<<it.first<<" -> "<<it.second<<endl;
		}
	}
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	sieve_modified();
	/*for(int i=0;i<mxA;i++){
		cout<<prime[i]<<" ";
	}*/
	numberofDivisorofProduct();

    return 0;
}