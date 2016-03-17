//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void fastInOut();

//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
// 12032 - The Monkey and the Oiled Bamboo
	int t, n, x, k, res, r = 1, temp;
	vector<int> v;
	cin >> t;
	while (t--) {
		cin >> n;
		v.clear();
		v.push_back(0);
		while (n--) {
			cin >> x;
			v.push_back(x);
		}
		sort(all(v));
		k = temp = 0;
		int past = -1e9;
		for (int i = 0; i < v.size() - 1; i++) {
			res = v[i + 1] - v[i];
			if (res > temp && res > k) {
				if (res == past) {
					k = res + 1;
					temp = k - 1;
				} else {
					k = res;
					temp = k - 1;
				}
			} else if (res == temp)
				temp--;
			past = res;
		}
		// easier loop
		// for(int i=0;i<v.size()-1;i++)
		//	 if(v[i+1]-v[i]>k)
		//		 k=v[i+1]-v[i];
		temp = k;
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i + 1] - v[i] == temp)
				temp--;
			else if (v[i + 1] - v[i] > temp) {
				k++;
				break;
			}
		}
		cout << "Case " << r++ << ": " << k << endl;
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
