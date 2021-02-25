#include <bits/stdc++.h>
using namespace std;
class street{
    public:
    street *start;
    street *end;
    long long length;
    string name;
};
class intersection{
    public:
    int l;
    vector<string> incoming;
    vector<string> outgoing;
};
class cars{
    public:

};