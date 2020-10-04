#include <bits/stdc++.h>
#define MOD 998244353
using namespace std; 

//accepted:)

long long gcd(long long a, long long b)
{
    if(b==0)
    {
        return a;
    }
    else
        return gcd(b, a%b);
}  
// Function for extended Euclidean Algorithm  
long long gcdExtended(long long a, long long b, long long *x, long long *y)  
{  
    // Base Case  
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  

    long long x1, y1; // To store results of recursive call  
    long long gcd = gcdExtended(b%a, a, &x1, &y1);  

    // Update x and y using results of  
    // recursive call  
    *x = y1 - (b/a) * x1;  
    *y = x1;  

    return gcd;  
}  

vector<vector< long long> > postfix(string s)
{

    long long bracket = 0;
    vector<long long > number;
    long long num;
    num = 748683265;
    for(long long i = 0; i < 4; i++)number.push_back(num);
    vector<vector<long long > > ans;
    vector<long long> R, And, Xr;
    R.push_back(1);And.push_back(2);Xr.push_back(3);
    stack<char> buf;
    for(long long n  = 0 ; n < s.size(); n++)
    {
        if(s[n] == '#')
        {
            ans.push_back(number);
            continue;
        }
        if(s[n] == ')')
        {
            while(buf.top() != '(')
            {
                if(buf.top() == '|')
                {
                    ans.push_back(R);
                }
                else if(buf.top() == '&')
                {
                    ans.push_back(And);
                }
                else if(buf.top() == '^')
                {
                    ans.push_back(Xr);
                }
                buf.pop();
            }
            buf.pop();
        }
        else if(s[n] == '(' || buf.empty() || buf.top() == '(')
        {
            buf.push(s[n]);
        }
        else 
        {
            if(buf.top() == '|')
            {
                ans.push_back(R);
            }
            else if(buf.top() == '&')
            {
                ans.push_back(And);
            }
            else if(buf.top() == '^')
            {
                ans.push_back(Xr);
            }
            buf.pop();
            buf.push(s[n]);
        }
    }
    while(!buf.empty())
    {
        if(buf.top() == '|')
            ans.push_back(R);
        else if(buf.top() == '&')
            ans.push_back(And);
        else if(buf.top() == '^')
            ans.push_back(Xr);
        buf.pop();
    }
    return ans;
}

long long Add(long long a, long long  b)
{
   return (a+b)%MOD;
}

long long mul(long long a, long long b)
{
   return (a*b)%MOD;
}

vector<long long> CalcOr(vector<long long > a, vector<long long > b)
{
    vector<long long > ans(4);
    long long buf;
    long long term1;
    ans[0] = (a[0]* b[0]) %MOD;
    term1 = b[0];
    for(long long n = 1; n < 4; n++)
    {
        term1 = Add(term1, b[n]);
    }
    term1 = mul(term1, a[1]);

    long long term2 = a[0];
    term2 = Add(term2, a[2]);
    term2 = Add(term2, a[3]);
    term2 = mul(term2, b[1]);

    long long term3 = mul(a[2], b[3]);

    long long term4 = mul(a[3], b[2]);

    buf = term1;
    buf = Add(term1, term2);
    buf = Add(buf, term3);
    buf = Add(buf, term4);

    ans[1] = buf;

    term1 = mul(a[0], b[2]);
    term2 = mul(a[2], b[0]);
    term3 = mul(a[2], b[2]);

    buf = term1;
    buf = Add(term1, term2);
    buf = Add(buf, term3);

    ans[2] =buf;

    term1 = mul(a[0], b[3]);
    term2 = mul(a[3], b[0]);
    term3 = mul(a[3], b[3]);

    buf = term1;
    buf = Add(term1, term2);
    buf = Add(buf, term3);

    ans[3] = buf;

    return ans;
}


vector<long long > CalcAnd(vector<long long > a, vector<long long > b)
{
    vector<long long > ans(4);
    long long buf;
    long long term1;
    ans[1] = mul(a[1], b[1]);

    term1 = b[0];
    for(long long n = 1; n < 4; n++)
    {
        term1 = Add(term1, b[n]);
    }
    term1 = mul(term1, a[0]);   

    long long term2;
    term2 = a[1];
    term2 = Add(term2, a[2]);
    term2 = Add(term2, a[3]);
    term2 = mul(term2, b[0]);

    long long term3;
    term3 = mul(a[2], b[3]);

    long long term4;
    term4 = mul(a[3], b[2]);

    buf = term1;
    buf = Add(term1, term2);
    buf = Add(buf, term3);
    buf = Add(buf, term4);

    ans[0] = buf;

    term1 = mul(a[1], b[2]);
    term2 = mul(a[2], b[1]);
    term3 = mul(a[2], b[2]);

    buf = term1;
    buf = Add(term1, term2);
    buf = Add(buf, term3);

    ans[2] = buf;

    term1 = mul(a[1], b[3]);
    term2 = mul(a[3], b[1]);
    term3 = mul(a[3], b[3]);

    buf = term1;
    buf = Add(term1, term2);
    buf = Add(buf, term3);

    ans[3] = buf;

    return ans;
}

vector<long long > CalcXor(vector<long long > a, vector<long long > b)
{
    long long buf;
    long long term1, term2, term3, term4;
    vector<long long > ans(4);

    term1 = mul(a[0], b[0]);
    term2 = mul(a[1], b[1]);
    term3 = mul(a[2], b[2]);
    term4 = mul(a[3], b[3]);
    buf = term1;
    buf = Add(buf, term2);
    buf = Add(buf, term3);
    buf = Add(buf, term4);

    ans[0] = buf;

    term1 = mul(a[0], b[1]);
    term2 = mul(a[1], b[0]);
    term3 = mul(a[2], b[3]);
    term4 = mul(a[3], b[2]);
    buf = term1;
    buf = Add(buf, term2);
    buf = Add(buf, term3);
    buf = Add(buf, term4);

    ans[1] = buf;


    term1 = mul(a[0], b[2]);
    term2 = mul(a[1], b[3]);
    term3 = mul(a[2], b[0]);
    term4 = mul(a[3], b[1]);
    buf = term1;
    buf = Add(buf, term2);
    buf = Add(buf, term3);
    buf = Add(buf, term4);

    ans[2] = buf;

    term1 = mul(a[0], b[3]);
    term2 = mul(a[1], b[2]);
    term3 = mul(a[2], b[1]);
    term4 = mul(a[3], b[0]);
    buf = term1;
    buf = Add(buf, term2);
    buf = Add(buf, term3);
    buf = Add(buf, term4);

    ans[3] = buf;

    return ans;
}


long long CalcInv(long long a)
{
    long long x, y;
    long long gcd = gcdExtended(a, MOD, &x, &y);
    while(x < 0) x += MOD;
    return x%MOD;
}

// Driver Code 
int main()  
{  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long long T;
    cin>>T;
    for(long long t = 0; t < T; t++)
    {
        string s;
        cin>>s;
        long long num = 0;
        vector<vector<long long > >  pfix = postfix(s);
        stack<vector<long long > > st;
        vector<long long > ele;
        for(long long n = 0; n < pfix.size(); n++)
        {
            ele = pfix[n];
            if(ele.size() == 4)
            {
                st.push(ele);
            }
            else if(ele.size() == 1)
            {
                vector<long long > a, b, c;
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                if(ele[0] == 1)
                    c = CalcOr(a, b);
                if(ele[0] == 2)
                    c = CalcAnd(a, b);
                if(ele[0] == 3)
                    c = CalcXor(a, b);
                st.push(c);
            }
        }
        ele = st.top();
        vector<long long> ans(4);
        for(long long i = 0; i < 4; i++)
        {
            ans[i] = ((ele[i]))%MOD;
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}   