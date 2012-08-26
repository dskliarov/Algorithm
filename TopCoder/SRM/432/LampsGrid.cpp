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

class LampsGrid {
public:
    int mostLit(vector <string> initial, int K) {
        sort(initial.begin(), initial.end());
        vector<pair<int, int> > mm;
        string last = initial[0];
        int cnt = 0;
        REP(i,initial.size()) {
            if (initial[i] == last) ++cnt;
            else {
                int needed = 0;
                REP(j,last.length()) {
                    if (last[j] == '0') ++needed;
                }
                mm.push_back(make_pair(cnt, needed));
                cnt = 1;
                last = initial[i];
            }
        }
        int needed = 0;
        REP(j,last.length()) {
            if (last[j] == '0') ++needed;
        }
        mm.push_back(make_pair(cnt, needed));

        sort(mm.begin(), mm.end());
        RFOR(i,mm.size()-1,0) {
            int m = mm[i].first;
            int d = mm[i].second;
            if (d > K) continue;
            if ((K - d) & 1) continue;
            return m;
        }
        return 0;
    }
};
// BEGIN CUT HERE
int main() {
    {
        string initialARRAY[] = {"01",
            "10",
            "10"};
        vector <string> initial( initialARRAY, initialARRAY+ARRSIZE(initialARRAY) );
        LampsGrid theObject;
        eq(0, theObject.mostLit(initial, 1),2);
    }
    {
        string initialARRAY[] = {"101010"};
        vector <string> initial( initialARRAY, initialARRAY+ARRSIZE(initialARRAY) );
        LampsGrid theObject;
        eq(1, theObject.mostLit(initial, 2),0);
    }
    {
        string initialARRAY[] = {"00", "11"};
        vector <string> initial( initialARRAY, initialARRAY+ARRSIZE(initialARRAY) );
        LampsGrid theObject;
        eq(2, theObject.mostLit(initial, 999),0);
    }
    {
        string initialARRAY[] = {"0", "1", "0", "1", "0"}
           ;
        vector <string> initial( initialARRAY, initialARRAY+ARRSIZE(initialARRAY) );
        LampsGrid theObject;
        eq(3, theObject.mostLit(initial, 1000),2);
    }
    {
        string initialARRAY[] = {"001", "101", "001", "000", "111", "001", "101", "111", "110", "000", "111", "010", "110", "001"};
        vector <string> initial( initialARRAY, initialARRAY+ARRSIZE(initialARRAY) );
        LampsGrid theObject;
        eq(4, theObject.mostLit(initial, 6),4);
    }
    {
        string initialARRAY[] = {"01", "10", "01", "01", "10"};
        vector <string> initial( initialARRAY, initialARRAY+ARRSIZE(initialARRAY) );
        LampsGrid theObject;
        eq(5, theObject.mostLit(initial, 1),3);
    }
    return 0;
}
// END CUT HERE
