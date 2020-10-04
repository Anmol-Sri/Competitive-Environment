#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	int ans[n];
	map<int,int> freq;
	std::vector<int> unique;
	std::vector<int> neg;
	std::vector<int> dup;
	std::vector<int> zero;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		freq[arr[i]]++;
	}
	
	map<int,int>::iterator x;
	for(x=freq.begin();x!=freq.end();x++){
		int val=x->first;
		int fre=x->second;
		if(fre>1){
			int run=(fre/2)*2;
			for(int j=0;j<run;j++){
				dup.push_back(val);
			}
			if(val<=0)
			{	for(int j=0;j<fre-run;j++){
					neg.push_back(val);
				}
			}
			else{
				for(int j=0;j<fre-run;j++){
					unique.push_back(val);
				}
			}
		}
		else if(val==0){
			zero.push_back(val);
		}
		else if(val<=0){
			neg.push_back(val);
		}
		else{
			unique.push_back(val);
		}
	}

	sort(dup.begin(), dup.end(),greater<int>());
	sort(unique.begin(), unique.end());
	sort(neg.begin(), neg.end(),greater<int>());
	int i=0;
	for(;i<dup.size();i++){
		ans[i]=dup[i];
	}
	int iu=0,in=0;
	int lenu=unique.size();
	int lenneg=neg.size();
	int lenzero=zero.size();
	int count=0;
	if(unique.size()==0){
		for(int j=0;j<neg.size();j++,i++){
			ans[i]=neg[j];
		}
	}
	else if(neg.size()==0){
		for(int j=0;j<unique.size();j++,i++){
			ans[i]=unique[j];
		}
	}
	else if(neg.size()==1){
		for(int j=0;j<unique.size();j++,i++){
			ans[i]=unique[j];
		}
		ans[i]=neg[0];	
	}
	else if(unique.size()==1){
		for(int j=0;j<neg.size();j++,i++){
			ans[i]=unique[j];
		}
		ans[i]=unique[0];	
	}
	else if(unique.size()>=neg.size()){
		count=0;
		std::vector<int> vec(neg);
		vec.insert(neg.end(),zero.begin(), zero.end());
		sort(vec.begin(), vec.end());	
		for(int j=n-1;j>=i;j--){
			if(count%2==0 && in!=vec.size()){
				ans[j]=vec[vec.size()-in-1];
				in++;
			}
			else{
				ans[j]=unique[unique.size()-iu-1];
				iu++;
			}
			count++;
		}

	}
	else{
		count=0;
		std::vector<int> vec(unique);
		vec.insert(unique.end(),zero.begin(), zero.end());
		for(int j=n-1;j>=i;j--){
			if(count%2==0 && iu!=vec.size()){
				ans[j]=vec[vec.size()-iu-1];
				iu++;
			}
			else{
				ans[j]=neg[neg.size()-in-1];
				in++;
			}
			count++;
		}
	}
	for(auto x:ans){
		cout<<x<<" ";
	}
	cout<<"\n";
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