#include<bits/stdc++.h>
using namespace std;
#define ll long int

void complement(string& s){
    for(char& c:s){
        if(c=='1')c='0';
        else if(c=='0')c='1';
    }
}
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);


    int t,n;
    cin>>t>>n;

    while(t--){

        int r=-1,c=-1;
        char q;

        string arr(n,'?');

        for(int i=1,j=0;j<n/2;i+=2)
        {
            if(i>10 && i%10==1)
            {
                if(c!=-1){
                    cout<<c+1<<endl;
                    cin>>q;
                    if(arr[c]!=q)
                        complement(arr);
                }
                else{
                    cout <<"1\n";
                    cin>>q;
                }
                if(r!=-1){
                    cout<<r+1<<endl;
                    cin>>q;
                    if(arr[r]!=q)
                    reverse(arr.begin(),arr.end());
                }
                else {
                    cout<<"1\n";
                    cin>>q;
                }
            }
            else{
                cout << j+1 << endl;
                cin >> arr[j];
                cout << n-j << endl;
                cin >> arr[n-1-j];
                if(arr[j]==arr[n-1-j])c=j;
                else if(arr[j]!=arr[n-1-j])r=j;
                ++j;
            }
        }
        char pro;
        cout<<arr<<endl;
        cin>>pro;
        if(pro=='N')return 0;
    }
}