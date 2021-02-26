#include <bits/stdc++.h>
#include <fstream>
#define ll long long
using namespace std;

class street //street class
{
public:
    long long length; //stores length of street
    string name;      //stores name of street
    ll begid;         //stores id of the intersection from where the street starts
    ll endid;         //stores id of the intersection from where the street ends
};

class intersection : public street //intersection class inherits street
{
public:
    vector<street> incoming; //stores objects of all the incoming streets
    vector<street> outgoing; //stores objects of all the outgoing streets
};

class cars : public street // cars class
{
public:
    long long noofstreets;     //stores the no of streets it passes through
    vector<street> points;     //stores the objects of all the streets it passes through
    vector<string> streetname; //stores names of all the streets it passes through
};

ll simtime, nointer, nostr, nocar, bp;
unordered_map<string, street> streetmap;         //map relates names of street to corresponding objects
unordered_map<ll, intersection> intersectionmap; //map relates ids of intersection to corresponding intersections
vector<cars> carsvec;                            //stores all the objects of cars

void readfile() // reads all the raw data and converts it into the objects
{
    string s;
    ifstream filena("a.txt"); //opens the file
    ll c = 0;                 //counter variable

    while (getline(filena, s)) // reads the file line by line
    {
        vector<string> ele; // the entire part splits the line acc to space and stores the tokens in ele
        string delimiter = " ";
        auto start = 0U;
        auto end = s.find(delimiter);
        while (end != string::npos)
        {
            ele.push_back(s.substr(start, end - start));
            start = end + delimiter.length();
            end = s.find(delimiter, start);
        }
        ele.push_back(s.substr(start, end)); // splitting complete
        if (c == 0)                          // this block runs only one time
        {
            simtime = stoi(ele[0]); // got the simulation time
            nointer = stoi(ele[1]); // got the no of intersections
            nostr = stoi(ele[2]);   // got the no of streets
            nocar = stoi(ele[3]);   // got the no of cars
            bp = stoi(ele[4]);      // got the value of bonus points
            c = 1;
        }
        else if (c <= nostr) // this block runs nostr times
        {
            street streetob;                // creating a street object
            streetob.begid = stoi(ele[1]);  // storing the id of the intersection from where the street starts
            streetob.endid = stoi(ele[0]);  // storing the id of the intersection from where the street ends
            streetob.name = ele[2];         //stores the street name
            streetob.length = stoi(ele[3]); //stores the street length
            c++;
            streetmap[streetob.name] = streetob; // mapping object to street name
        }
        else
        {
            cars carob;            // creating a car object
            ll nopath;             // stores the no of streets the car passes through
            nopath = stoi(ele[0]); // storing
            for (ll i = 0; i < nopath; i++)
            {
                carob.streetname.push_back(ele[i + 1]);        // storing the street names
                carob.points.push_back(streetmap[ele[i + 1]]); // storing the corresponding street object
            }
            carsvec.push_back(carob); // storing the car object in a vector
        }
    }
    filena.close(); // file read complete
}

void process_data() // here the intersections are created
{
    for (auto x : streetmap) // going through the street one by one
    {
        street ob = x.second;                                        //stores the object of the current street
        intersection obj;                                            // creating a new intersection object
        if (intersectionmap.find(ob.begid) != intersectionmap.end()) // checking if the intersection already exists
        {
            obj = intersectionmap[ob.begid]; //if yes the obj contains the found object
        }
        else
        {
            intersectionmap[ob.begid] = obj; // else mapping the newly created object
        }
        obj.incoming.push_back(x.second); // storing the incoming street object in the intersction
        intersection obje;                // same thing as above for outgoing street
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
void print_data()
{
    cout << intersectionmap.size() << "\n"; // printing the total no of intersections
    for (auto x : intersectionmap)          //going through the intersections one by one
    {
        cout << x.first << "\n";                  // printing the intersection id
        cout << x.second.incoming.size() << "\n"; // printing the no of incoming streets
        for (auto k : x.second.incoming)          // going through the incoming streets
        {
            cout << k.name << " 1"
                 << "\n"; // printing the incoming names and the schedule
        }
    }
}
int main()
{
    readfile();
    process_data();
    print_data();
}