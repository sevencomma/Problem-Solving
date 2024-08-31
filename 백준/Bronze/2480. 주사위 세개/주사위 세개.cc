#include <iostream>
using namespace std;

#define Change(x,y) ((x)^=(y), (y)^=(x), (x)^=(y));

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b)
		Change(a, b);
	if (a > c)
		Change(a, c);
	if (b > c)
		Change(b, c);

	int ans;
	if (a == b && b == c)
		ans = 10000 + a * 1000;
	else if (a == b)
		ans = 1000 + a * 100;
	else if (b == c)
		ans = 1000 + b * 100;
	else
		ans = c * 100;

	cout << ans;
}