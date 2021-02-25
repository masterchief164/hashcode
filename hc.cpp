#include <bits/stdc++.h>
using namespace std;
class street{
    public:
    intersection *start;
    intersection *end;
    long long length;
    string name;
};
class intersection{
    public:
    vector<street> incoming;
    vector<street> outgoing;
};
class cars{
    public:
    long long noofstreets;
    vector<intersection> points;

};
