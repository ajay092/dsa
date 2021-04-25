/* This is a code to get the pair of points with shortest distance apart from a given set of points in a 2D domain. This uses a divide and conquer approach
 * in which the set of points is divided into two halves each of which is recursively called. 
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#define INF 1e10

using namespace std;
using namespace std::chrono;

struct point{
    long x;
    long y;
};

// main functions
double closestPairDistance(vector<point> P); 
double bruteForce_CPD(vector<point> P);
double recursive_CPD(vector<point> Px, vector<point> Py);
double minStrip(vector<point> strip, double d);

// utility functions
double dist(point p1, point p2);
double min(double a, double b);
bool compareX(point p1, point p2);
bool compareY(point p1, point p2);

int main(){
    long x, y;
    ifstream f_read_N;
//     vector<point> P = {{2,33}, {1,42}, {5,21}, {4,29}, {3,8}, {77,7}, {9,1}, {9,2}};
//     vector<point> P = {{2, 3}, {12, 30}, {40, 50}, {12,100}, {5, 1}, {12, 10}, {3, 4}};
//     vector<point> P = {{2,3}, {1,4}, {5,2}};
    
    for (long N = 10;N<=100000;N*=10){
    vector<point> P{};
    f_read_N.open("N_100000.dat");
    
    for(long i=0;i<N;i++){
        f_read_N >> x >> y;
        P.push_back({x, y});
    }
    f_read_N.close();    
    
    auto start = high_resolution_clock::now();
    cout <<N<<"\t\t"<<bruteForce_CPD(P);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout <<"\t\t"<<duration.count(); 
    
    start = high_resolution_clock::now();
    cout<<"\t\t"<<closestPairDistance(P);
    stop = high_resolution_clock::now(); 
    duration = duration_cast<milliseconds>(stop - start);
    cout << "\t\t"<< duration.count()<< endl; 
        
    }
    
   /* ifstream f_read_N;
    f_read_N.open("N_100000.dat");
    
    for(long i=0;i<10;i++){
        f_read_N >> x >> y;
        P.push_back({x, y});
    }
    f_read_N.close();    
    
    cout <<"BF = "<<bruteForce_CPD(P)<<endl;
    
    cout<<"DC = "<<closestPairDistance(P)<<endl;
    */
    
    return 0;
}

bool compareX(point p1, point p2) { 
    return (p1.x == p2.x)?(p1.y < p2.y):(p1.x < p2.x); 
}

double min(double a, double b){
    return (a<=b)?a:b ;
}

double dist(point p1, point p2){
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

bool compareY(point p1, point p2) { 
    return (p1.y < p2.y); 
}

double closestPairDistance(vector<point> P){
    vector<point> Px = P;
    vector<point> Py = P;
    sort(Px.begin(), Px.end(), compareX);
    sort(Py.begin(), Py.end(), compareY);

    return recursive_CPD(Px, Py);
}

double recursive_CPD(vector<point> Px, vector<point> Py){
    long n = Px.size();
    if(n<=3)
        return bruteForce_CPD(Px);

    long mid = (n-1)/2;
    long midx = Px[mid].x;
    long midy = Px[mid].y;

    vector<point> Pyl{};
    vector<point> Pyr{};
    
    vector<point> Pxl{};
    vector<point> Pxr{};
    
    vector<point> strip{};
    for(long i=0;i<n;i++){
        if(Py[i].x < midx )
            Pyl.push_back(Py[i]);
        else if(Py[i].x > midx)
            Pyr.push_back(Py[i]);
        else {
            if(Py[i].y <= midy)
                Pyl.push_back(Py[i]);
            else if(Py[i].y > midy)
                Pyr.push_back(Py[i]);
        }
        
        if(i<=mid)
            Pxl.push_back(Px[i]);
        else
            Pxr.push_back(Px[i]);
    }
    double d1 = min(recursive_CPD(Pxl, Pyl) , recursive_CPD(Pxr, Pyr));
        
    for (long i = 0; i < n; i++){ 
        if (fabs(Py[i].x - midx) < d1) 
            strip.push_back(Py[i]);
    }
  
    double d2 = minStrip(strip, d1);

    return min(d2, d1);
}

double minStrip(vector<point> strip, double d){
    float min = d;  // Initialize the minimum distance as d 
    double distance = INF;
    long n = strip.size();
        for (long i = 0; i < n; ++i){ 
            for (long j = i+1; j < n && (strip[j].y - strip[i].y) < min; ++j){ 
                distance = dist(strip[i],strip[j]) ;
                if (distance < min) 
                    min = distance; 
            }
        }
    return min; 
}

double bruteForce_CPD(vector<point> P){
    double minDist = INF;
    long n = P.size();
    for(long i=0; i<n; i++){
        for(long j=i+1; j<n; j++){
            double distance = dist(P[i], P[j]);
            if(distance < minDist)
                minDist = distance;
        }
    }
    return minDist;
}
