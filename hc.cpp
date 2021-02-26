#include <bits/stdc++.h>
#include <fstream>
#define ll long long
using namespace std;

class street
{
public:
    long long length;
    string name;
    ll begid;
    ll endid;
};

class intersection : public street
{
public:
    vector<street> incoming;
    vector<street> outgoing;
};

class cars : public street
{
public:
    long long noofstreets;
    vector<street> points;
    vector<string> streetname;
};

ll simtime, nointer, nostr, nocar, bp;
unordered_map<string, street> streetmap;
unordered_map<ll, intersection> intersectionmap;
vector<cars> carsvec;

void readfile()
{
    string s;
    ifstream filena("a.txt");
    ll c = 0;

    while (getline(filena, s))
    {
        vector<string> ele;
        string delimiter = " ";
        auto start = 0U;
        auto end = s.find(delimiter);
        while (end != std::string::npos)
        {
            ele.push_back(s.substr(start, end - start));
            start = end + delimiter.length();
            end = s.find(delimiter, start);
        }
        ele.push_back(s.substr(start, end));
        if (c == 0)
        {
            simtime = stoi(ele[0]);
            nointer = stoi(ele[1]);
            nostr = stoi(ele[2]);
            nocar = stoi(ele[3]);
            bp = stoi(ele[4]);
            c = 1;
        }
        else if (c <= nostr)
        {
            street streetob;
            streetob.begid = stoi(ele[0]);
            streetob.endid = stoi(ele[1]);
            streetob.name = ele[2];
            streetob.length = stoi(ele[3]);
            c++;
            streetmap[streetob.name] = streetob;
        }
        else
        {
            cars carob;
            ll nopath;
            nopath = stoi(ele[0]);
            for (ll i = 0; i < nopath; i++)
            {
                carob.streetname.push_back(ele[i + 1]);
                carob.points.push_back(streetmap[ele[i + 1]]);
            }
            carsvec.push_back(carob);
        }
    }
    filena.close();
}

void process_data()
{
    for (auto x : streetmap)
    {
        street ob = x.second;
        intersection obj;
        if (intersectionmap.find(ob.begid) != intersectionmap.end())
        {
            obj = intersectionmap[ob.begid];
        }
        else
        {
            intersectionmap[ob.begid] = obj;
        }
        obj.incoming.push_back(x.second);
        intersection obje;
        if (intersectionmap.find(ob.endid) != intersectionmap.end())
        {
            obje = intersectionmap[ob.endid];
        }
        else
        {
            intersectionmap[ob.endid] = obje;
        }
        obje.outgoing.push_back(x.second);
    }
}
void print_data(){
    cout<<intersectionmap.size()<<"\n";
    for(auto x:intersectionmap){
        cout<<x.first<<"\n";
        cout<<x.second.incoming.size()<<"\n";
        for(auto k:x.second.incoming){
            cout<<k.name<<" 1"<<"\n";
        }
    }
}
int main()
{
    readfile();
    process_data();
    print_data();
}