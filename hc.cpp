#include <bits/stdc++.h>
#include <fstream>
#define ll long long
using namespace std;
/*class street
{
public:
    intersection *start;
    intersection *end;
    long long length;
    string name;
};
class intersection
{
public:
    vector<street> incoming;
    vector<street> outgoing;
};
class cars
{
public:
    long long noofstreets;
    vector<intersection> points;
};*/
ll simtime, nointer, nostr, nocar, bp;
void readfile()
{
    string s;
    ifstream filena("a.txt");
    ll c = 0;

    while (getline(filena, s))
    {
        vector<string> ele;
        auto start = 0U;
        auto end = s.find(" ");
        while (end != string::npos)
        {
            ele.push_back(s.substr(start, end - start));
            start = end + 1;
            end = s.find(" ", start);
        }
        if (c == 0)
        {
            simtime = stoi(ele[0]);
            nointer = stoi(ele[1]);
            nostr = stoi(ele[2]);
            nocar = stoi(ele[3]);
            bp = stoi(ele[4]);
            c = 1;
        }
        else if (c <= nostr + 1)
        {

        }
        cout << s << "\n";
    }
    filena.close();
}
int main()
{
    readfile();
}