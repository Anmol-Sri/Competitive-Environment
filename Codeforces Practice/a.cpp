#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(int x){
	int n;
	cin>>n;
	string arr[n];
	char ans[10001];

	vector<string> middle;
	memset(ans,'@',sizeof(ans));
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	for(int i=0;i<n;i++){
		int start=0;
		int end=10000;
		bool flag=true;
		if(arr[i][0]=='*'){
			for(int j=arr[i].length()-1;j>=1;j--){
				char ch=arr[i][j];
				if(ch!='*'){
					if(ans[end]==ch){
						continue;
					}
					if(ans[end]!='@' || ans[end]!=ch){
						flag=false;
						break;
					}
					ans[end]=ch;
					end--;
				}
				else{
					middle.push_back(arr[i].substr(1,j));
					break;
				}
			}
		}
		else if(arr[i][arr[i].length()-1]=='*'){
			for(int j=0;j<arr[i].length()-1;j++){
				char ch=arr[i][j];
				if(ch!='*'){
					if(ans[start]!='@' || ans[start]!=ch){
						flag=false;
						break;
					}
					ans[start]=ch;
					start++;
				}
				else{
					middle.push_back(arr[i].substr(j+1,arr[i].length()-1-j-1));
					break;
				}
			}
		}
		else{
			/*int p1=-1;
			int p2=-1;
			for(int j=0;j<arr[i].length();j++){
				char ch=arr[i][j];
				if(ch=='*'){
					p1=j;
					break;
				}
				else{
					if(ans[start]!='@'){
						flag=false;
						break;
					}
					ans[start]=ch;
					start++;
				}
			}

			for(int j=arr[i].length()-1;j>=0;j--){
				char ch=arr[i][j];
				if(ch=='*'){
					p2=j;
					break;
				}
				else{
					if(ans[start]!='@'){
						flag=false;
						break;
					}
					ans[start]=ch;
					start++;
				}
			}
			if(flag==true){
				if(p1!=-1 && p2!=-1){
					middle.push_back()
				}
			}
			*/
			middle.push_back(arr[i]);
		}

		if(flag==false){
			cout<<"Case #"<<x<<": *\n";
			return;
		}
	}
	for(auto X:middle){
		cout<<x<<endl;
	}
	int start=-1;
	int end=-1;
	bool flag=true;
	for(int i=0;i<10001;i++){
		if(ans[i]=='@'){
			start=i;
			break;
		}
	}

	if(start==-1){
		if(middle.size()!=0){
			flag=false;
			cout<<"Case #"<<x<<": *\n";
			return;
		}
	}
	for(int i=0;i<middle.size();i++){
		string s=middle[i];
		for(int j=0;j<s.length();j++){
			if(s[j]!='*'){
				if(ans[start]!='@'){
					flag=false;
					cout<<"Case #"<<x<<": *\n";
					return;
				}
				ans[start]=s[j];
				start++;
			}
		}
	}

	if(flag){
		cout<<"Case #"<<x<<": ";
		for(int i=0;i<10001;i++){
			if(ans[i]!='@'){
				cout<<ans[i];
			}
		}
		return ;
	}
	else{
			cout<<"Case #"<<x<<": *\n";
			return;
		}
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

	for(int q=1;q<=t;q++){
		solve(q);
	}
    return 0;
}