#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

double distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

double distPointToSegment(Point P, Point A, Point B, Point &H) {
    double l2 = distSq(A, B);
    if (l2 == 0) {
        H = A;
        return sqrt(distSq(P, A));
    }
    double t =((P.x - A.x) * (B.x - A.x) + (P.y - A.y) * (B.y - A.y)) / l2;
    t = max(0.0, min(1.0, t));
    H = {A.x + t * (B.x - A.x), A.y + t * (B.y - A.y)};
    return sqrt(distSq(P, H));
}

int main() {
    ifstream fin("DTDTRON.INP");
    ofstream fout("DTDTRON.OUT");

    if (!fin) {
        return 0;
    }

    Point O, A, B;
    double R;
    fin >> O.x >> O.y >> R;
    fin >> A.x >> A.y >> B.x >> B.y;

    double R2 = R * R;
    double dOA2 = distSq(O, A);
    double dOB2 = distSq(O, B);

    if (dOA2 <= R2 && dOB2 <= R2) {
        fout << 3 << "\n";
        return 0;
    }

    Point H;
    double dist = distPointToSegment(O, A, B, H);
    double dOH2 = distSq(O, H);

    double area2 = abs((B.x - A.x) * (A.y - O.y) - (A.x - O.x) * (B.y - A.y));
    double lenAB = sqrt(distSq(A, B));
    double distLine = (lenAB == 0) ? sqrt(dOA2) : area2 / lenAB;

    const double EPS = 1e-9;

    int countInside = 0;
    if (dOA2 <= R2 + EPS) countInside++;
    if (dOB2 <= R2 + EPS) countInside++;

    if (countInside == 1) {
        fout << 1 << "\n";
    } 
    else if (countInside == 2) {
       
        fout << 3 << "\n";
    } 
    else {
        if (distLine > R - EPS) {
            if (abs(distLine - R) < EPS && dist <= R + EPS) {
                fout << 1 << "\n";
            } else {
                fout << 4 << "\n";
            }
        } else {
            double l2 = distSq(A, B);
            double t = ((H.x - A.x) * (B.x - A.x) + (H.y - A.y) * (B.y - A.y)) / l2;
            
            if (t >= 0.0 && t <= 1.0 && distLine < R - EPS) {
                fout << 2 << "\n"; 
            } else {
                fout << 4 << "\n";
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}
