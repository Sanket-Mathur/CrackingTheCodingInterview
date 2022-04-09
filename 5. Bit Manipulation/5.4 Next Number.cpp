#include <iostream>
#include <cmath>
using namespace std;

int nextLargest(int n) {
    int check1 = 1, check2 = 2;

	while (true) {
	    if ((n & check1) && !(n & check2)) {
	        n ^= check1;
	        n ^= check2;
	        return n;
	    }
	    check1 <<= 1;
	    check2 <<= 1;
	}
}

int nextSmallest(int n) {
    int cnt0 = 0, cnt1 = 0;
    int i = 1;

	while (i < n) {
		if ((n & i) == 0) {
			cnt0++;
		} else if (cnt0 > 0) {
			n ^= i;
			n ^= (i >> 1);
			n |= ((1 << (cnt0 + cnt1 - 1)) - 1);
			n &= (~0) << (cnt0 - 1);

			return n;
		} else {
			cnt1++;
		}

		i <<= 1;
	}

	return -1;
}

int main() {
    int n;
    cin >> n;

    cout << nextSmallest(n) << endl << nextLargest(n) << endl;

    return 0;
}