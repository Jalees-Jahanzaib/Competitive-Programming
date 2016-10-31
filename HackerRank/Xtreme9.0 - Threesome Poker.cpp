#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX/2;
const int MAX = 256;
const int DX[] = {0, 0, -1, 1};
const int DY[] = {-1, 1, 0, 0};

int best_depth = 13;
vector<iii> best_path, cur_path;
vector<ii> cur_beats, best_beats;

void go(int a, int b, int c, int winner, int looser, int depth, bool finish) {
    cur_path.push_back(iii(a, ii(b, c)));
    cur_beats.push_back(ii(winner, looser));

    if(finish) {
        if(best_beats.empty()) best_beats = cur_beats;
        if(best_depth > depth || (best_depth == depth && cur_beats < best_beats)) {
            best_depth = depth;
            best_path = cur_path;
            best_beats = cur_beats;
        }
        cur_path.pop_back();
        cur_beats.pop_back();
        return;
    }

    if(depth < best_depth) {
        if( c - a >= 0 ) go(a*2, b, c-a, 1, 3, depth + 1, c == a);
        if( b - a >= 0 ) go(a*2, b-a, c, 1, 2, depth + 1, b == a);
        if( c - b >= 0 ) go(a, b*2, c-b, 2, 3, depth + 1, c == b);
        if( a - b >= 0 ) go(a-b, b*2, c, 2, 1, depth + 1, a == b);
        if( a - c >= 0 ) go(a-c, b, c*2, 3, 1, depth + 1, a == c);
        if( b - c >= 0 ) go(a, b-c, c*2, 3, 2, depth + 1, b == c);
    }

    cur_path.pop_back();
    cur_beats.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    go(a, b, c, -1, -1, 1, 0);
    if(best_depth > 12) {
        cout << "Ok\n";
    }
    else {
        for(int i = 0; i < best_path.size(); i++) {
            cout << best_path[i].first << " " << best_path[i].second.first << " " << best_path[i].second.second << "\n";
        }
    }


}

