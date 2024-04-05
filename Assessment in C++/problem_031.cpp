#include <iostream>
#include <vector>
using namespace std;

bool isCollinear(const vector<int>& P1, const vector<int>& P2, const vector<int>& P3) {
    int X1 = P1[0], Y1 = P1[1];
    int X2 = P2[0], Y2 = P2[1];
    int X3 = P3[0], Y3 = P3[1];

    return (X1 * (Y2 - Y3) + X2 * (Y3 - Y1) + X3 * (Y1 - Y2)) == 0;
}

bool arePointsCollinear(const vector<vector<int>>& points) {
    int N = points.size();
    if (N <= 2) {
        return true; // Two points are always collinear
    }

    for (int i = 0; i <= N - 3; ++i) {
        if (!isCollinear(points[i], points[i + 1], points[i + 2])) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cout << "Enter the number of points: ";
    cin >> N;

    vector<vector<int>> points(N, vector<int>(2));
    cout << "Enter the points (x y): ";
    for (int i = 0; i < N; ++i) {
        cin >> points[i][0] >> points[i][1];
    }

    if (arePointsCollinear(points)) {
        cout << "Points are collinear." << endl;
    } else {
        cout << "Points are not collinear." << endl;
    }

    return 0;
}

