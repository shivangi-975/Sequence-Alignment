/*Shivangi Parashar*/
#include<bits/stdc++.h>
//Import libraries
using namespace std;
#define debug(x) cout << #x << " " << x <<endl;
#define ff first
#define ss second
#define INF 1e18

typedef long long ll;
// nested pair for storing result
pair<pair<char, char>, ll> find_ans(ll x, ll y, int index1, int index2, int n, int m, string &a, string &b, pair<pair<char, char>, ll> **dp) {

	if (index1 == n && index2 == m)
	{
		return {{'\0', '\0'}, 0};  // end of both strings .Hence,return 0
	}

	if (dp[index1][index2].ff.ff != '?')
	{
		return dp[index1][index2]; // already evaluated dp state
	}

	if (index2 == m)
	{
		dp[index1][index2] = {{a[index1], '_'}, x + find_ans(x, y, index1 + 1, index2, n, m, a, b, dp).ss}; // end of string2
		return dp[index1][index2];
	}

	if (index1 == n)
	{
		dp[index1][index2] = {{'_', b[index2]}, x + find_ans(x, y, index1, index2 + 1, n, m, a, b, dp).ss}; // end of string1
		return dp[index1][index2];
	}

        //initialisation of nested ans pair
	pair<pair<char, char>, ll> ans = {{'?', '?'}, INF};  //having infinity as answer as we haven't done anything yet


	//case 3 add '_' in string2 and continue with index1+1 and index2
	//doing this first to find lexicographically smallest query
	ll value3 = find_ans(x, y, index1 + 1, index2, n, m, a, b, dp).ss + x;
	if (ans.ss > value3)
		ans = {{a[index1], '_'}, value3};


	//case 1 continue with index1+1 and index2+1
	ll value1 = find_ans(x, y, index1 + 1, index2 + 1, n, m, a, b, dp).ss + (a[index1] != b[index2] ? y : 0);
	if (ans.ss > value1)
		ans = {{a[index1], b[index2]}, value1};

	//case 2 add '_' in string1 and continue with index1 and index2+1
	ll value2 = find_ans(x, y, index1, index2 + 1, n, m, a, b, dp).ss + x;
	if (ans.ss > value2)
		ans = {{'_', b[index2]}, value2};

        //assigning ans  to dp
	dp[index1][index2] = ans;
	return dp[index1][index2];

}

int main() {
	int n, m;
	cin >> n >> m;
	ll x, y;
	cin >> x >> y;
	string a, b;
	cin >> a >> b;
	pair<pair<char, char>, ll> **dp = new pair<pair<char, char>, ll>*[n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = new pair<pair<char, char>, ll>[m + 1];
		for (int j = 0; j <= m; j++) {
			dp[i][j] = {{'?', '?'}, -1}; //unevaluated dp state hence initialise it with -1
		}
	}
	find_ans(x, y, 0, 0, n, m, a, b, dp);
	//dp[0][0].ss will store the optimal alignment cost
	cout << dp[0][0].ss << "\n";
	string ans_a = "", ans_b = "";
	int index1 = 0, index2 = 0;
	//index1 and index2 to specify the indices of first and second string respectively
	while (index2 < m || index1 < n) {
		int increment1 = 0;
		int increment2 = 0;
		ans_a += dp[index1][index2].ff.ff;
		ans_b += dp[index1][index2].ff.ss;
		//no gap is present in first string
		if (dp[index1][index2].ff.ff != '_')
			increment1++;
		//no gap is present in second string
		if (dp[index1][index2].ff.ss != '_')
			increment2++;
		index1 += increment1;
		index2 += increment2;
	}
	//return results in console
	cout << ans_a << "\n";
	cout << ans_b;
	return 0;
}
