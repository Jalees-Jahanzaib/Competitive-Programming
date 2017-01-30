#include<bits/stdc++.h>

using namespace std;

struct sw_list {
    deque<int> all[2];
    int size, id;

    sw_list() {
        size = 0; id = 0;
    }

    void make_add(int x) {
        all[id].push_back(x);
        ++size;
        if(size % 2 == 0) {
            int tmp = all[id].front();
            all[id].pop_front();
            all[id^1].push_back(tmp);
        }
    }

    void make_remove() {
        all[id].pop_back();
        --size;
        if(size&1) {
            int tmp = all[id^1].back();
            all[id^1].pop_back();
            all[id].push_front(tmp);
        }
    }

    void make_sort() {
        id = id^1;
        if(size&1) {
            int tmp = all[id^1].back();
            all[id^1].pop_back();
            all[id].push_front(tmp);
        }
    }

    void print() {
        printf("%d\n", size);
        bool first = true;
        while(!all[id^1].empty()) {
            if(!first) printf(" ");
            first = false;
            printf("%d", all[id^1].front());
            all[id^1].pop_front();
        }
        while(!all[id].empty()) {
            if(!first) printf(" ");
            first = false;
            printf("%d", all[id].front());
            all[id].pop_front();
        }
    }


};

int main() {
    freopen("kenobi.in", "r", stdin);
    freopen("kenobi.out", "w", stdout);

    int n; scanf("%d", &n);
    sw_list lista;
    char com[20]; int x;
    for(int i = 0; i < n; i++) {
        scanf("%s", com);
        if(com[0] == 'a') {
            scanf("%d", &x);
            lista.make_add(x);
        }
        if(com[0] == 't') {
            lista.make_remove();
        }
        if(com[0] == 'm') {
            lista.make_sort();
        }
    }

    lista.print();
}
