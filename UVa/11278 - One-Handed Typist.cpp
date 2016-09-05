#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 200010
#define INF 0x3fffffff
#define ll long long
#define MOD 1000000007

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    map<char, char> id;
    id['1'] = '1';
    id['2'] = '2';
    id['3'] = '3';
    id['4'] = 'q';
    id['5'] = 'j';
    id['6'] = 'l';
    id['7'] = 'm';
    id['8'] = 'f';
    id['9'] = 'p';
    id['0'] = '/';
    id['q'] = '4';
    id['w'] = '5';
    id['e'] = '6';
    id['r'] = '.';
    id['t'] = 'o';
    id['y'] = 'r';
    id['u'] = 's';
    id['i'] = 'u';
    id['o'] = 'y';
    id['p'] = 'b';
    id['a'] = '7';
    id['s'] = '8';
    id['d'] = '9';
    id['f'] = 'a';
    id['g'] = 'e';
    id['h'] = 'h';
    id['j'] = 't';
    id['k'] = 'd';
    id['l'] = 'c';
    id['z'] = '0';
    id['x'] = 'z';
    id['c'] = 'x';
    id['v'] = ',';
    id['b'] = 'i';
    id['n'] = 'n';
    id['m'] = 'w';
    id['Q'] = '$';
    id['W'] = '%';
    id['E'] = '^';
    id['R'] = '>';
    id['T'] = 'O';
    id['Y'] = 'R';
    id['U'] = 'S';
    id['I'] = 'U';
    id['O'] = 'Y';
    id['P'] = 'B';
    id['A'] = '&';
    id['S'] = '*';
    id['D'] = '(';
    id['F'] = 'A';
    id['G'] = 'E';
    id['H'] = 'H';
    id['J'] = 'T';
    id['K'] = 'D';
    id['L'] = 'C';
    id['Z'] = ')';
    id['X'] = 'Z';
    id['C'] = 'X';
    id['V'] = '<';
    id['B'] = 'I';
    id['N'] = 'N';
    id['M'] = 'W';
    id['`'] = '`';
    id['-'] = '[';
    id['='] = ']';
    id['['] = ';';
    id[']'] = '=';
    id['\\'] = '\\';
    id[';'] = 'k';
    id['\''] = '-';
    id[','] = 'v';
    id['.'] = 'g';
    id['/'] = '\'';
    id['$'] = 'Q';
    id['^'] = 'L';
    id['&'] = 'M';
    id['*'] = 'F';
    id['('] = 'P';
    id[')'] = '?';
    id['_'] = '{';
    id['+'] = '}';
    id['{'] = ':';
    id['}'] = '+';
    id[':'] = 'K';
    id['"'] = '_';
    id['<'] = 'V';
    id['>'] = 'G';
    id['?'] = '"';
    id['%'] = 'J';
    string line;
    while(getline(cin, line)) {
        for(int i = 0; i < line.size(); i++) {
            if(id.count(line[i])) cout << id[ line[i] ];
            else cout << line[i];
        }
        cout << "\n";
    }



}
