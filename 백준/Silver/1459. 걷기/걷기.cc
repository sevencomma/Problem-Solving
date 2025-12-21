#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, y, w, s;

int main(void) {
	cin >> x >> y >> w >> s;

	ll res = (x + y) * w;
	res = min(res, (min(x, y) * s + w * (max(x, y) - min(x, y))));
	
	if (w > s) {
		ll tmp = min(x, y) * s;
		ll k = (max(x, y) - min(x, y));
		tmp += (k / 2) * 2 * s + (k % 2) * w;
		res = min(res, tmp);
	}

	cout << res;
}