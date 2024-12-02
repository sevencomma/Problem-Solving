#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	double a, b, c, d, A, B;
	cin >> a >> b >> c >> d;
	A = a / b;
	B = pow(c, 2) * M_PI / d;
	if (A > B)
		cout << "Slice of pizza";
	else
		cout << "Whole pizza";
}