// LeetCode max-points-on-a-line
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
using namespace std;

#define LEN1 1005
#define LEN2 1005
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int dp[LEN1][LEN2];

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point> &points) {
		int len = points.size();
		if (len <= 2)
			return len;
		vector<pair<Point, int>> mark;
		sort(points.begin(), points.end(), xcompare);
		int last = -1;
		for (int i = 0; i < len; ++i) {
			if (last >= 0 && same(points[last], points[i]))
				mark.back().second += 1;
			else {
				mark.push_back(pair<Point, int>(points[i], 1));
				last = i;
			}
		}
		len = mark.size();
		if (len == 1)
			return mark[0].second;
		else if (len == 2)
			return mark[0].second + mark[1].second;
		
		int result = 1;
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < len; ++j) {
				if (i == j)
					continue;
				int count = mark[i].second + mark[j].second;
				for (int k = 0; k < len; ++k) {
					if (k == j || k == i)
						continue;
					if (online(mark[i].first, mark[j].first, mark[k].first))
						count += mark[k].second;
				}
				//cout << mark[i].first.x << ", " << mark[i].first.y << " " << mark[j].first.x << ", " << mark[j].first.y << "\t\t" << count << endl;
				result = max(result, count);
			}
		}
		return result;
	}

	bool online(Point & a, Point & b, Point & c) {
		return (a.y - b.y) * (a.x - c.x) == (a.x - b.x) * (a.y - c.y);
	}

	bool same(Point & a, Point & b) {
		return (a.x == b.x) && (a.y == b.y);
	}

	static bool xcompare(Point & a, Point & b) {
		if (a.x == b.x)
			return a.y < b.y;
		else
			return a.x < b.x;
	}
};

int main() {
	freopen("in.txt", "r", stdin);
	Solution solution;
	vector<Point> v;
	//v.push_back(Point(84, 250));
	//v.push_back(Point(0, 0));
	//v.push_back(Point(1, 0));
	//v.push_back(Point(0, -70));
	//v.push_back(Point(0, -70));
	//v.push_back(Point(1, -1));
	//v.push_back(Point(21, 10));
	//v.push_back(Point(42, 90));
	//v.push_back(Point(-42, -230));
	v.push_back(Point(40, -23)); v.push_back(Point(9, 138)); v.push_back(Point(429, 115)); v.push_back(Point(50, -17)); v.push_back(Point(-3, 80)); v.push_back(Point(-10, 33)); v.push_back(Point(5, -21)); v.push_back(Point(-3, 80)); v.push_back(Point(-6, -65)); v.push_back(Point(-18, 26)); v.push_back(Point(-6, -65)); v.push_back(Point(5, 72)); v.push_back(Point(0, 77)); v.push_back(Point(-9, 86)); v.push_back(Point(10, -2)); v.push_back(Point(-8, 85)); v.push_back(Point(21, 130)); v.push_back(Point(18, -6)); v.push_back(Point(-18, 26)); v.push_back(Point(-1, -15)); v.push_back(Point(10, -2)); v.push_back(Point(8, 69)); v.push_back(Point(-4, 63)); v.push_back(Point(0, 3)); v.push_back(Point(-4, 40)); v.push_back(Point(-7, 84)); v.push_back(Point(-8, 7)); v.push_back(Point(30, 154)); v.push_back(Point(16, -5)); v.push_back(Point(6, 90)); v.push_back(Point(18, -6)); v.push_back(Point(5, 77)); v.push_back(Point(-4, 77)); v.push_back(Point(7, -13)); v.push_back(Point(-1, -45)); v.push_back(Point(16, -5)); v.push_back(Point(-9, 86)); v.push_back(Point(-16, 11)); v.push_back(Point(-7, 84)); v.push_back(Point(1, 76)); v.push_back(Point(3, 77)); v.push_back(Point(10, 67)); v.push_back(Point(1, -37)); v.push_back(Point(-10, -81)); v.push_back(Point(4, -11)); v.push_back(Point(-20, 13)); v.push_back(Point(-10, 77)); v.push_back(Point(6, -17)); v.push_back(Point(-27, 2)); v.push_back(Point(-10, -81)); v.push_back(Point(10, -1)); v.push_back(Point(-9, 1)); v.push_back(Point(-8, 43)); v.push_back(Point(2, 2)); v.push_back(Point(2, -21)); v.push_back(Point(3, 82)); v.push_back(Point(8, -1)); v.push_back(Point(10, -1)); v.push_back(Point(-9, 1)); v.push_back(Point(-12, 42)); v.push_back(Point(16, -5)); v.push_back(Point(-5, -61)); v.push_back(Point(20, -7)); v.push_back(Point(9, -35)); v.push_back(Point(10, 6)); v.push_back(Point(12, 106)); v.push_back(Point(5, -21)); v.push_back(Point(-5, 82)); v.push_back(Point(6, 71)); v.push_back(Point(-15, 34)); v.push_back(Point(-10, 87)); v.push_back(Point(-14, -12)); v.push_back(Point(12, 106)); v.push_back(Point(-5, 82)); v.push_back(Point(-46, -45)); v.push_back(Point(-4, 63)); v.push_back(Point(16, -5)); v.push_back(Point(4, 1)); v.push_back(Point(-3, -53)); v.push_back(Point(0, -17)); v.push_back(Point(9, 98)); v.push_back(Point(-18, 26)); v.push_back(Point(-9, 86)); v.push_back(Point(2, 77)); v.push_back(Point(-2, -49)); v.push_back(Point(1, 76)); v.push_back(Point(-3, -38)); v.push_back(Point(-8, 7)); v.push_back(Point(-17, -37)); v.push_back(Point(5, 72)); v.push_back(Point(10, -37)); v.push_back(Point(-4, -57)); v.push_back(Point(-3, -53)); v.push_back(Point(3, 74)); v.push_back(Point(-3, -11)); v.push_back(Point(-8, 7)); v.push_back(Point(1, 88)); v.push_back(Point(-12, 42)); v.push_back(Point(1, -37)); v.push_back(Point(2, 77)); v.push_back(Point(-6, 77)); v.push_back(Point(5, 72)); v.push_back(Point(-4, -57)); v.push_back(Point(-18, -33)); v.push_back(Point(-12, 42)); v.push_back(Point(-9, 86)); v.push_back(Point(2, 77)); v.push_back(Point(-8, 77)); v.push_back(Point(-3, 77)); v.push_back(Point(9, -42)); v.push_back(Point(16, 41)); v.push_back(Point(-29, -37)); v.push_back(Point(0, -41)); v.push_back(Point(-21, 18)); v.push_back(Point(-27, -34)); v.push_back(Point(0, 77)); v.push_back(Point(3, 74)); v.push_back(Point(-7, -69)); v.push_back(Point(-21, 18)); v.push_back(Point(27, 146)); v.push_back(Point(-20, 13)); v.push_back(Point(21, 130)); v.push_back(Point(-6, -65)); v.push_back(Point(14, -4)); v.push_back(Point(0, 3)); v.push_back(Point(9, -5)); v.push_back(Point(6, -29)); v.push_back(Point(-2, 73)); v.push_back(Point(-1, -15)); v.push_back(Point(1, 76)); v.push_back(Point(-4, 77)); v.push_back(Point(6, -29));
	cout << solution.maxPoints(v) << endl;
	return 0;
}