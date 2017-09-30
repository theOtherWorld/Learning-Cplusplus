
#include "Chapter5/5.4-SmallTool.h"
#include "Chapter16/16.2-IntroductionOfClass.h"
#include "Chapter17/17.2-Constructor.h"
#include "Chapter17/17.3-InitializaOfObject.h"

using namespace st;
using namespace ioc;
using namespace cd;
using namespace ioo;


void f1(const vector<int>& v){
    int i = v[2];

    //v[3] = 4;
    cout<<i<<" "<<v[3];
}
int main() {

//    vector<int> vi{isi,iof};
//    for(auto& e:vi){
//        cout<<e<<" ";
//    }
//    forward_list<int> fli = {83,28,12,94,11,8,45};
//    vector<int> vi {1,0,34,2,67,43,32};
//    list<int> lst = {83,28,12,94,11,8,45};
//    sort(lst);
//    sort(vi);
//    for(auto p = fli.begin(); p != fli.end(); ++p){
//        cout<<*p<<" ";
//    }
//    cout<<endl;
//    for(auto p = lst.begin(); p != lst.end(); ++p){
//        cout<<*p<<" ";
//
//    }



//16.2
//    const Date_1 d = Date_1{};
//    string s = d.str_rep();
//    cout<<s;


//17.2
//    //cout<<sss.s.x;
//    cout<<xx;
//    Circle* c = new Circle();
//    use(c);




    return 0;
}