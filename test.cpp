//
// Created by xl on 2017/9/8.
//

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main() {
//
//    using uli = unsigned long int;
//    uli n;
//    double max = 0.00000000;
//    cin >> n;
//    if(n < 2) return 0;
//
//    vector<double> vd(n);
//    double dist = 0;
//    cin >> vd[0];
//    for (uli i = 1; i < n; ++i) {
//        cin >> vd[i];
//        dist = vd[i] - vd[0];
//        if(dist > 180) dist = 360 - dist;
//        if(dist > max) max = dist;
//    }
//
//
//    cout.precision(8);
//    cout.setf(ios::fixed);
//    cout<< max<<endl;
//    return  0;
//}