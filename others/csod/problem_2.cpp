#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
#define foreq(i, a, b) for (int i = a; i <= b; i++)

#define printA(A, n) \
    foreq(p, 0, n - 1) { cout << p << ": " << A[p] << endl; }
#define print(s) cout << s << endl

#define sq(a) (a) * (a)

// ios::sync_with_stdio(0);
// cin.tie(0);

string leftToRight(vector<vector<string>> grid, int start, int end,
                   pair<int, int> pos) {
    string out = "";
    foreq(i, start, end) { out += grid[pos.first][pos.second + i + 1]; }

    return out;
}

string rightToleft(vector<vector<string>> grid, int start, int end,
                   pair<int, int> pos) {
    string out = "";
    foreq(i, start, end) { out += grid[pos.first][pos.second - i - 1]; }

    return out;
}

string downToUp(vector<vector<string>> grid, int start, int end,
                pair<int, int> pos) {
    string out = "";
    foreq(i, start, end) { out += grid[pos.first - i - 1][pos.second]; }

    return out;
}
string upToDown(vector<vector<string>> grid, int start, int end,
                pair<int, int> pos) {
    string out = "";
    foreq(i, start, end) { out += grid[pos.first + i + 1][pos.second]; }

    return out;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<string>> grid;
    string temp;
    foreq(i, 0, n - 1) {
        grid.push_back(vector<string>());
        foreq(j, 0, m - 1) {
            cin >> temp;
            grid[i].push_back(temp);
        }
    }

    pair<int, int> curr(0, 0);
    string result = grid[curr.first][curr.second];

    foreq(i, 0, (grid.size() - 1) / 2) {
        curr.first = 2 * i;
        curr.second = 0;
        result += leftToRight(grid, 0, n - 1, curr);
        curr.first = 2 * i + 1;
        curr.second = n - 1;
        if (grid.size() % 2 == 1) {
            result += rightToleft(grid, n - 1, 0, curr);
        }
    }

    print(result);

    return 0;
}