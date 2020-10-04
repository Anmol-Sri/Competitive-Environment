#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
        ll sum = 1,n;
        ll sum1 = 0, sum2 = 0;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
            cin>>arr[i];
        for (ll i=0;i<n;i++){
            if (arr[i]%2!=0||arr[i]%4==0)
                sum1++;
            for (ll j=i+1;j<n;j++){
                sum=sum*arr[i]*arr[j];
                //cout<<sum<<endl;
                if (sum%2!=0||sum%4==0)
                    sum2++;
            }
            sum=1;
        }
        cout<<sum1+sum2<<endl;
    return ;
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