#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<int, int> visited;
int dfs(int f, int s, int g, int u, int d, int cnt) {
	visited[s]++;

	if (s == g)
		return cnt;
	else if (g > s) {
		if (!visited[s + u] && s + u >= 1)
			if (s + u <= f)
				return dfs(f, s + u, g, u, d, cnt + 1);
			else
				if (!visited[s - d] && s - d >= 1)
					return dfs(f, s - d, g, u, d, cnt + 1);
	}
	else {
		if (!visited[s - d] && s - d <= f)
			if (s - d >= 1)
				return dfs(f, s - d, g, u, d, cnt + 1);
			else
				if (!visited[s + u] && s + u <= f)
					return dfs(f, s + u, g, u, d, cnt + 1);
	}
	return 0;
}

int main(void) {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	
	if (s == g) {
		cout << 0;
		return 0;
	}

	if (s + u > f && s - d < 1) {
		cout << "use the stairs";
		return 0;
	}

	int ans = 0;
	if (g > s) {
		if (u == 0) {
			cout << "use the stairs";
			return 0;
		}
		while ((g - s) > u) {
			ans++;
			s += u;
		}
		if (s > f) {
			cout << "use the stairs";
			return 0;
		}
		ans += dfs(f, s, g, u, d, 0);
	}
	else if (g < s) {
		if (d == 0) {
			cout << "use the stairs";
			return 0;
		}
		while ((s - g) > d) {
			ans++;
			s -= d;
		}
		if (s < 1) {
			cout << "use the stairs";
			return 0;
		}
		ans += dfs(f, s, g, u, d, 0);
	}

	if (visited[g])
		cout << ans;
	else
		cout << "use the stairs";
}