#include <bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define mod 1000000007
long long int dx[]={0,0,-1,1,-1,-1,1,1};
long long int dy[]={1,-1,0,0,1,-1,-1,1};
long long int power(long long int a,long long int b)
    {
    long long int value;
    if(b==0)
        {
        return 1;
    }
    else if(b%2==0)
        {
        value=power(a,b/2)%mod;
        return(value*value)%mod;
    }
    else
        {
        value=power(a,b/2)%mod;
        return ((a*value)%mod*(value))%mod;
    }
}
string f(long long int n) {
    std::vector<long long int> v;
    long long int i;
    if(n==0) {
        return "00";
    }
    string s="0";
    while(n) {
        v.push_back(n%10);
        n/=10;
    }
    reverse(v.begin(), v.end());
    rep(i,0,v.size()) {
        s+=(v[i]+'0');
    }
    return s;
}
long long int a[100005],pref[100005],suf[100005];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
    /*long long int files=10;
    while(files--) {
    #ifndef ONLINE_JUDGE
        string input="in"+f(files)+".txt";
        string output="out"+f(files)+".txt";
        freopen(input.c_str(),"r",stdin);
        freopen(output.c_str(),"w",stdout);
        #endif*/
        ios_base::sync_with_stdio(0);
        long long int t;
        cin>>t;
        while(t--) {
            long long int n,m,k;
            cin>>n>>m>>k;
            long long int ans=0,i,sum=0;
            rep(i,1,1+n) {
                cin>>a[i];
                pref[i]=a[i];
                suf[i]=a[i];
                sum+=a[i];
            }
            sum*=m;
            if(sum<=k) {
                long long int temp=(n*m)%mod;
                ans=(temp*(temp+1))%mod;
                ans=(ans*power(2,mod-2))%mod;
                cout<<ans<<endl;
                continue;
            }
            sum/=m;
            rep(i,2,1+n) {
                pref[i]+=pref[i-1];
            }
            repr(i,n-1,0) {
                suf[i]+=suf[i+1];
            }
            rep(i,1,1+n) {
                if(suf[i]>=k) {
                    long long int temp=-1,l=i,r=n;
                    while(l<=r) {
                        long long int mid=(l+r)/2;
                        if((pref[mid]-pref[i-1])<=k) {
                            temp=mid;
                            l=mid+1;
                        } else {
                            r=mid-1;
                        }
                    }
                    if(temp!=-1) {
                        ans=(ans+(m*(temp-i+1)))%mod;
                    }
                    continue;
                }
                if((suf[i]+(m-1)*sum)<=k) {
                    long long int temp=(m*(2*(n-i+1)+(m-1)*n));
                    temp/=2;
                    ans=(ans+temp)%mod;
                    continue;
                }
                long long int cnt=(k-suf[i])/sum;
                cnt++;
                long long int temp=(cnt*(2*(n-i+1)+(cnt-1)*n));
                temp/=2;
                temp%=mod;
                ans=(ans+temp)%mod;
                cnt--;
                long long int val=(k-suf[i]-cnt*sum);
                long long int l=1,r=n,idx=0;
                while(l<=r) {
                    long long int mid=(l+r)/2;
                    if(pref[mid]<=val) {
                        idx=mid;
                        l=mid+1;
                    } else {
                        r=mid-1;
                    }
                }
                long long int no=(n-i+1)+(cnt*n)+idx;
                no%=mod;
                ans=(ans+(no*(m-cnt-1)))%mod;
            }
            cout<<ans<<endl;
        }
    //}
}