#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

const int MAXN = 100000 + 10, SIGMA_SIZE = 26, INF = 0x7fffffff;

struct Trie
{
	char stdc;
	int ch[MAXN][SIGMA_SIZE];
	int val[MAXN];
	int sz;

	void Init()
	{
		sz = 1;
		memset(ch, 0, sizeof(ch));
		memset(val, 0, sizeof(val));
	}

	Trie(char c) :stdc(c)
	{
		stdc = c;
		Init();
	}

	int idx(const char & c) const
	{
		return c - stdc;
	}

	void Insert(const string & s, const int & v = 1)
	{
		unsigned int u = 0, l = s.length();
		for (unsigned int i = 0; i < l; i++)
		{
			int c = idx(s[i]);
			if (!ch[u][c]) ch[u][c] = sz++;
			u = ch[u][c];
		}
		val[u] = v;
	}

	int Query(const string & s, const int & v = 1, const int & limit = INF)
	{
		int cost = 0;
		unsigned int u = 0, l = s.length();
		for (unsigned int i = 0; i < l; i++)
		{
			int c = idx(s[i]);
			if (!ch[u][c])
			{
				if (cost) return cost;
				else return -1;
			}
			cost += val[u];
			u = ch[u][c];
		}
		return cost;
	}
};

vector<string> v;
Trie trie = Trie('0');
//HDU1671
int main()
{
	int t, n;
	ios::sync_with_stdio(false);
	while (cin >> t)
	{
		v.clear();
		while (t--)
		{
			bool flag = true;
			string str;
			trie.Init();
			cin >> n;
			while (n--)
			{
				string str;
				cin >> str;
				v.push_back(str);
				trie.Insert(str);
			}
			for (unsigned int i = 0; i < v.size() && flag; i++)
			{
				if (trie.Query(v[i]) > 0) flag = false;
			}
			if (flag) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	system("pause");
	return 0;
}