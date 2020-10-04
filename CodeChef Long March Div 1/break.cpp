#include <bits/stdc++.h>
using namespace std;
#define ll long int 

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
		/*ll ch[n];
		ll fr[n];
		ll sumch=0,sumfr=0;
		for(int i=0;i<n;i++){
		    cin>>ch[i];
		    sumch+=ch[i];
		}
			
		for(int i=0;i<n;i++){
		    cin>>fr[i];
		    sumfr+=fr[i];
		}*/
		/*if(sumfr<sumch){
		    cout<<"NO\n";
		    continue;
		}	
		//sort(ch,ch+n);
		//sort(fr,fr+n);
		int i=0;
		for(;i<n;i++){
			if(ch[i]>=fr[i]){
			    if(s==1) cout<<"NO\n";
				else cout<<"YES\n";
				break;
			}			
		}
		if(i==n){
			if(s==1) cout<<"YES\n";
			else cout<<"NO\n";
		}*/
		std::vector<ll> at;
		std::vector<ll> def;
		ll temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			at.push_back(temp);
		}
		for(int i=0;i<n;i++){
			cin>>temp;
			def.push_back(temp);
		}
		//sort(def.begin(),def.end());
		//sort(at,begin(),at.end());
		bool flag=true;
		for(int i=0;i<n;i++){
			//temp=at[i];
			int min_index=-1;
			for(int j=0;j<def.size();j++){
				if(min_index==-1 && at[i]<def[j]){
					min_index=j;
				}
				else if(min_index!=-1 && def[min_index]>def[j] && def[j]>at[i]){
					min_index=j;
				}
			}
			if(min_index==-1){
				flag=false;
				break;
			}
			else{
				def.erase(def.begin()+min_index);
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
    return 0;
}