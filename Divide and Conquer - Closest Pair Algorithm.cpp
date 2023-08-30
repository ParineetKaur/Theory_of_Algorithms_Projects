//Question: Find the closest pair of points in a given set of two-dimensional points using a divide-and-conquer approach.
//The following code recursively divides a problem into smaller subproblems, solve them separately, and then combine their solutions to obtain the final answer.
//The code utilized recursion to handle subsets of points. 
//There are also comments regarding the calculated time complexity of the algorithm. 

#include 
<iostream> 
#include <algorithm> 
using namespace std;

struct Point{ 
  int x, y;
};

bool compareX(Point p1, Point p2){ 
  return p1.x < p2.x;
}
bool compareY(Point p1, Point p2){ 
  return p1.y < p2.y;
}
double distance(Point p1, Point p2){ 
  int dx = p1.x - p2.x;
  int dy = p1.y - p2.y;
  return sqrt(dx*dx + dy*dy);
}
double bruteForce(Point P[], int n){ 
  double minDist = distance(P[0], P[1]); 
  for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
      double dist = distance(P[i], P[j]);
       if (dist < minDist) { 
          minDist = dist;
      } 
    }
  }
  return minDist; 
}
double stripClosest(Point strip[], int size, double d){ 
  double minDist = d;
  sort(strip, strip+size, compareY);
  for (int i = 0; i < size; i++){
    for (int j = i+1; j < size && (strip[j].y - strip[i].y) < minDist; j++){ 
      double dist = distance(strip[i], strip[j]);
      if (dist < minDist){
        minDist = dist; 
      }
    }
  }
  return minDist; 
}
double closestPair(Point Px[], Point Py[], int n){ 
  if (n <= 3){
    return bruteForce(Px, n); 
  }
  int mid = n/2;
  Point midPoint = Py[mid]; Point Pyl[mid+1];
  Point Pyr[n-mid-1];
  int li = 0, ri = 0;
  for (int i = 0; i < n; i++){
    if (Py[i].x <= midPoint.x){ 
      Pyl[li++] = Py[i];
    } 
    else{
      Pyr[ri++] = Py[i];
    } 
  }
  double dl = closestPair(Px, Pyl, mid);
  double dr = closestPair(Px + mid, Pyr, n - mid);

  double d = min(dl, dr); Point strip[n];
  int j = 0;
  for (int i = 0; i < n; i++){
    if (abs(Py[i].x - midPoint.x) < d){ 
      strip[j++] = Py[i];
    }
  }
  double stripDist = stripClosest(strip, j, d);
  return min(d, stripDist); 
}
//Using Master Theorem -> Time Complexity is O(n log n)
