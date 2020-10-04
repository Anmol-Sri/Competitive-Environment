#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
	int n;
	cin >> n;
	vector <string> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int pos1 = -1;
	int pos2 = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i][0] != '*')
		{
			int count = 0;
			for (auto t1 : arr[i])
			{
				if (t1 == '*')
					break;
				count++;
			}
			if (count > pos1)
			{
				pos1 = count;
				pos2 = i;
			}
		}
	}
	if (pos2 != -1)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i][0] != '*')
			{
				int j = 0;
				for (auto t1 : arr[i])
				{
					if (t1 == '*')
						break;
					if (t1 != arr[pos2][j])
					{
						cout << "*";
						return;
					}
					j++;
				}
			}
		}
	}
	string temp = "";
	if (pos2 != -1)
	{
		for (auto t1 : arr[pos2])
		{
			if (t1 == '*')
				break;
			temp += t1;
		}
	}
	int pos3 = -1;
	int pos4 = -1;
	for (int i = 0; i < n; i++)
	{
		int m = arr[i].size();
		if (arr[i][m - 1] != '*')
		{
		int count = 0;
		for (int j = m - 1; j >= 0 && arr[i][j] != '*'; j--)
			count++;
		if (count > pos3)
		{
			pos3 = count;
			pos4 = i;
		}
		}
	}
	if (pos4 != -1)
	{
		int suf_size = arr[pos4].size();
		for (int i = 0; i < n; i++)
		{
			int m = arr[i].size();
			if (arr[i][m - 1] != '*')
			{
				int j = suf_size - 1;
				for (int jj = m - 1; jj >= 0 && arr[i][jj] != '*'; jj--)
				{
					if (arr[i][jj] != arr[pos4][j])
					{
						cout << "*";
						return;
					}
					j--;
				}
			}
		}
	}
	string suf = "";
	if (pos4 != -1)
	{
		int m = arr[pos4].size();
		int st = m - pos3;
		for (int j = st; j < m; j++)
			suf += arr[pos4][j];
	}
	string ans = temp;
	for (int i = 0; i < n; i++)
	{
		int m = arr[i].size();
		int l = 0, r = m - 1;
		for (; l < m && arr[i][l] != '*'; l++);
		for (; r >= 0 && arr[i][r] != '*'; r--);
		if (l == r)
		continue;
		l++;
		r--;
		for (int j = l; j <= r; j++)
		{
		if (arr[i][j] != '*')
		ans += arr[i][j];
		}
	}
	ans += suf;
	cout << ans;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	for (int i = 1; i <= t; i++)
	{
	cout << "Case #" << i << ": ";
	solve();
	cout << endl;
	}
    return 0;
}