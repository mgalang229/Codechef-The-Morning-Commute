#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int time = 0;
		for (int i = 0; i < n; i++) {
			int x, l, f;
			cin >> x >> l >> f;
			if (i == 0) {
				// on the 1st station simply get the sum of the operating 
				// (departure) time and the travel time between current and next station
				time = x + l;
			} else {
				// otherwise, check if Chef arrived early than the operating (departure) time or not
				if (time <= x) {
					// if Chef arrived earlier than the operating (departure) time, then do
					// do the same thing as done in the 1st station
					time = x + l;
				} else {
					// otherwise, we need to wait for the next train that arrives every 'f' minutes
					while (time > x) {
						x += f;
					}
					// once the train arrived, add the travel time between current and next station
					time = x + l;
				}
			}
		}
		cout << time << '\n';
	}
	return 0;
}
