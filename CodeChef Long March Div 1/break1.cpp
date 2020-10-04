#include <bits/stdc++.h>
using namespace std;
#define ll long int 
int deflen;
int card(ll def[],ll val){
	int min_index=-1;
	for(int j=0;j<deflen;j++){
		if(min_index==-1 && val<def[j] && def[j]!=-1){
			min_index=j;
		}
		else if(min_index!=-1 && def[min_index]>def[j] && def[j]>val && def[j]!=-1){
			min_index=j;
		}
	}
	return min_index;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,s;
	cin>>t>>s;
	while(t--){
		int n;
		cin>>n;
		ll ch[n];
		ll def[n];
		ll temp;
		deflen=n;
		for(int i=0;i<n;i++){
		    cin>>ch[i];
		}
		for(int i=0;i<n;i++){
		    cin>>def[i];
		}	

		sort(ch,ch+n);
		sort(def,def+n);
		//sort(fr,fr+n);
		/*if(ch[0]>fr[0]){
		    cout<<"NO\n";
		    continue;
		}*/
		int i;
		std::vector<ll> ranks;
		temp=card(def,ch[0]);
		if(temp==-1){
			cout<<"NO\n";
			continue;
		}
		else{
			ranks.push_back(ch[0]);
			ranks.push_back(def[temp]);
			//def.erase(def.begin()+temp);
			def[temp]=-1;
		}
		for(i=1;i<n;i++){
			bool found=false;
			for(int j=0;j<ranks.size();j++){
				if(ch[i]==ranks[j]){
					found=true;
					break;
				}
			}
			if(found){
				temp=card(def,ch[i]);
				if(temp==-1){
					cout<<"NO\n";
					break;
				}
				else{
					ranks.push_back(ch[i]);
					ranks.push_back(def[temp]);
					//def.erase(def.begin()+temp);
					def[temp]=-1;
				}		
			}
			else{
				cout<<"NO\n";
				break;
			}
		}
		if(i==n)
			cout<<"YES\n";
		}
	
    return 0;
}