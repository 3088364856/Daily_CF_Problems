#include <bits/stdc++.h>
using namespace std; 
#define yes	cout << "YES" << '\n'
#define no	cout << "NO" << '\n'
int n, m, k, T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	remake:;
	while(T--){
		cin >> n >> k;
		vector<int> a(n);
		for(auto& x:a)	cin >> x;
		vector<int> v[n];
		for(int i = 1; i < n; ++i){
			int x, y;
			cin >> x >>y;
			--x,--y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		vector<int> val(n,0);
		function<int(int,int)> init = [&](int x, int f){
			val[x] = a[x];
			for(auto t:v[x]){
				if(t == f)	continue;
				val[x] ^= init(t,x);
			}
			return val[x];
		};
		init(0,-1);
		if(val[0] == 0){
			yes;
			goto remake;
		}
		if(k == 2)	{
			no;
			goto remake;
		}
		int cnt = 0;
		function<int(int,int)> dfs = [&](int x, int f){
			int res = a[x];
			for(auto t:v[x]){
				if(t == f)	continue;
				res ^= dfs(t,x);
			}
			if(res == val[0]){
				++cnt;
				return 0;
			}
			return res;
		};
		dfs(0,-1);
		cnt > 1 ? yes : no;
	}
}
