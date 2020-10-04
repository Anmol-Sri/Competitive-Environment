#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n;
int min_ele(int arr[],int start){
	if(start==n){
		return -1;
	}
	for(int i=start+1;i<n;i++){
		if(arr[start]>=arr[i]){
			start=i;
		}
		else{
			return start;
		}
	}
	return start;
}

int max_ele(int arr[],int start){
	if(start==n){
		return -1;
	}

	for(int i=start+1;i<n;i++){
		if(arr[i]>=arr[start]){
			start=i;
		}
		else{
			return start;
		}
	}
	return start;
}

void solve(){
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans=0;
	std::vector<int> a1;
	for(int i=0;i<n;i++){
		i=min_ele(arr,i);
		if(i==-1){
			break;
		}
		a1.push_back(arr[i]);
		i=max_ele(arr,i+1);
		if(i==-1){
			break;
		}
		a1.push_back(arr[i]);
	}
	//cout<<ans<<"\n";
	int ans2=0;
	std::vector<int> a2;
	for(int i=0;i<n;i++){
		i=max_ele(arr,i);
		if(i==-1){
			break;
		}
		a2.push_back(arr[i]);
		i=min_ele(arr,i+1);
		if(i==-1){
			break;
		}
		a2.push_back(arr[i]);
	}
	int s1=0,s2=0;
	for(int i=1;i<a1.size();i++){
		s1+=abs(a1[i]-a1[i-1]);
	}
	for(int i=1;i<a2.size();i++){
		s2+=abs(a2[i]-a2[i-1]);
	}
	if(s1>s2){
		cout<<a1.size()<<"\n";
		for(int i:a1){
			cout<<i<<" ";
		}
		cout<<"\n";
	}
	else if(s2>s1){
		cout<<a2.size()<<"\n";
		for(int i:a2){
			cout<<i<<" ";
		}
		cout<<"\n";
	}
	else{
		if(a1.size()<a2.size()){
			cout<<a1.size()<<"\n";
			for(int i:a1){
				cout<<i<<" ";
			}
			cout<<"\n";
		}
		else{
			cout<<a2.size()<<"\n";
			for(int i:a2){
				cout<<i<<" ";
			}
			cout<<"\n";
		}
	}
	return ;
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}