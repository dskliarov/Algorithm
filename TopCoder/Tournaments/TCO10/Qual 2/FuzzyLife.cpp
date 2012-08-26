// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

// BEGIN CUT HERE
vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}
// END CUT HERE

// BEGIN CUT HERE
int s2i(string s) {
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}
// END CUT HERE
int vv[60][60];
int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

vector<string> grid;
int row, col;

int cal(int r, int c) {
    int ret = 0;
    REP(i,8) {
        int tr = r + dir[i][0], tc = c + dir[i][1];
        if (tr < 0 || tc < 0 || tr >= row || tc >= col) {
            continue;
        }
        if (grid[tr][tc] == '1') ++ret;
    }
    return ret;
}

class FuzzyLife {
public:
    int survivingCells(vector <string> _grid) {
        grid = _grid;
        vector<pair<int, int> > marks;
        row = grid.size(), col = grid[0].length();
        memset(vv, 0, sizeof(vv));
        REP(i,row) {
            REP(j,col) {
                if (grid[i][j] == '?') {
                    marks.push_back(make_pair(i, j));
                    vv[i][j] = 1;
                }
            }
        }
        int res = 0;
        REP(i,marks.size()) {
            int mm = 0;

            {
                // 1
                int sum = 0;
                int cnt = cal(marks[i].first, marks[i].second);
                if (cnt == 2 || cnt == 3) ++sum;

                REP(d,8) {
                    int tr = marks[i].first + dir[d][0];
                    int tc = marks[i].second + dir[d][1];
                    char state;
                    if (!(tr < 0 || tc < 0 || tr >= row || tc >= col)) {
                        vv[tr][tc] = 1;
                        state = grid[tr][tc];
                    } else {
                        state = '0';
                    }
                    cnt = cal(tr, tc);
                    ++cnt;
                    if (state == '1' && (cnt == 2 || cnt == 3)) ++sum;
                    if (state == '0' && cnt == 3) ++sum;
                }

                mm = max(mm, sum);
            }
            {
                // 0
                int sum = 0;
                int cnt = cal(marks[i].first, marks[i].second);
                if (cnt == 3) ++sum;

                REP(d,8) {
                    int tr = marks[i].first + dir[d][0];
                    int tc = marks[i].second + dir[d][1];
                    char state;
                    if (!(tr < 0 || tc < 0 || tr >= row || tc >= col)) {
                        vv[tr][tc] = 1;
                        state = grid[tr][tc];
                    } else {
                        state = '0';
                    }
                    cnt = cal(tr, tc);
                    if (state == '1' && (cnt == 2 || cnt == 3)) ++sum;
                    if (state == '0' && cnt == 3) ++sum;
                }

                mm = max(mm, sum);
            }

            res += mm;
        }
        FOR(i,-1,row) {
            FOR(j,-1,col) {
                char state;
                if (i < 0 || j < 0 || i == row || j == col) {
                    state = '0';
                    int rel = 0;
                    REP(ii,marks.size()) {
                        REP(d,8) {
                            int ti = marks[ii].first + dir[d][0];
                            int tj = marks[ii].second + dir[d][1];
                            if (ti == i && tj == j) {
                                rel = 1;
                                break;
                            }
                        }
                        if (rel == 1) break;
                    }
                    if (rel == 1) continue;
                } else {
                    state = grid[i][j];
                    if (vv[i][j] == 1) continue;
                }
                int cnt = cal(i, j);
                if (state == '1' && (cnt == 2 || cnt == 3)) ++res;
                if (state == '0' && cnt == 3) ++res;
            }
        }
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        string gridARRAY[] = {"011",
            "0?1",
            "100"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        FuzzyLife theObject;
        eq(0, theObject.survivingCells(grid),5);
    }
    {
        string gridARRAY[] = {"101",
            "0?0",
            "101"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        FuzzyLife theObject;
        eq(1, theObject.survivingCells(grid),4);
    }
    {
        string gridARRAY[] = {"11",
            "11"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        FuzzyLife theObject;
        eq(2, theObject.survivingCells(grid),4);
    }
    {
        string gridARRAY[] = {"111",
            "1?1",
            "111"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        FuzzyLife theObject;
        eq(3, theObject.survivingCells(grid),8);
    }
    {
        string gridARRAY[] = {"?11?",
            "0110",
            "1001",
            "?11?"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        FuzzyLife theObject;
        eq(4, theObject.survivingCells(grid),12);
    }
    {
        string gridARRAY[] = {"00100",
            "01010",
            "10?01",
            "01010",
            "00100"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        FuzzyLife theObject;
        eq(5, theObject.survivingCells(grid),12);
    }
    return 0;
}
// END CUT HERE
