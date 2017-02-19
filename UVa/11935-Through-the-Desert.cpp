#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-4;

struct event {
    double time, c;
    string type;
    event(double time, string type, double c) : time(time), type(type), c(c) {}
    event() {}

    bool operator < (const event &x) const {
        if(time != x.time) return time < x.time;
        if(type == "Leak") return true;
        return false;
    }
};

bool addevent(vector<event> &events, string& line) {
    istringstream ss(line);
    double time; ss >> time;
    string type; ss >> type;
    if(type != "Fuel") {
        events.push_back(event(time, type, -1));
        return type == "Goal";
    }
    string p; ss >> p;
    double c; ss >> c;
    events.push_back(event(time, type, c));
    return false;
}

bool can(vector<event> &events, double cap) {
    double cur_cap = cap, consuption = events[0].c/100.0;
    double time = 0;
    int holes = 0;
    for(int i = 1; i < events.size(); i++) {
        double trans = events[i].time - time;
        cur_cap -= trans*consuption + holes*trans;
        if(cur_cap < 0.0) return false;
        if(events[i].type == "Leak") {
            holes++;
        }
        if(events[i].type == "Gas") {
            cur_cap = cap;
        }
        if(events[i].type == "Fuel") {
            consuption = events[i].c/100.0;
        }
        if(events[i].type == "Mechanic") {
            holes = 0;
        }
        time = events[i].time;
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout.setf(ios_base::fixed);
    cout.precision(3);

    string line;
    while (getline(cin, line)) {
        vector<event> events;
        addevent(events, line);
        if(events.back().c == 0) break;
        while (getline(cin, line)) {
            if(addevent(events, line)) break;
        }

        double low = 0, high = 1e15;
        while((high-low) > EPS) {
            double mid = (low+high)/2.0;
            if(can(events, mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        double ans = (low+high)/2.0;
        cout << ans << "\n";
    }
}
