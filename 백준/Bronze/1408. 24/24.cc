#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int cur_h, cur_m, cur_s;
	int start_h, start_m, start_s;
	char colon;
	
	int result_h, result_m, result_s;

	cin >> cur_h >> colon >> cur_m >> colon >> cur_s;
	cin >> start_h >> colon >> start_m >> colon >> start_s;

	result_h = start_h - cur_h;
	result_m = start_m - cur_m;
	result_s = start_s - cur_s;

	
	if (result_s < 0) {
		result_m--;
		result_s += 60;
	}
	if (result_m < 0) {
		result_h--; 
		result_m += 60; 
	}
	if (result_h < 0) 
		result_h += 24; 

	cout << setfill('0');
	cout << setw(2) << result_h << colon << setw(2) << result_m << colon << setw(2) << result_s << endl;

}