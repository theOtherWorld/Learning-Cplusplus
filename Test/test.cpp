//
// Created by xl on 2017/8/22.
//

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main(){
//
//
//    string from, to;
//    cin >> from >> to;
////    char* s = new char[MAX_PATH];
////    GetFullPathName("f1.txt", MAX_PATH, s, NULL);
////    cout << s <<endl;
//    from = "D:\\xl\\c++\\C++ Programming Language\\Test\\" + from;
//    to = "D:\\xl\\c++\\C++ Programming Language\\Test\\" + to;
//
//    ifstream is{from};
//    ofstream os(to);
//
//    set<string> ss{istream_iterator<string>{is}, istream_iterator<string>{}};
//    for(auto p = ss.begin(); p!= ss.end(); ++p){
//        cout<<*p<<" ";
//    }
//    copy(ss.begin(), ss.end(), ostream_iterator<string>{os,"\n"});// unique_copy() 在#include<algorithm> 中 copy()在std中
//
//    return !is.eof() || !os;
//}