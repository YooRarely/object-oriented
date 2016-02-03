#include <iostream>
#include <string>
#include <strstream>
using namespace std;
class add{
private:
    int c;

public:
    add(int a,int b){
        this->c=a+b;
    };
    string answer(){
        strstream an;
        string ans,s;
        if (c<0) {ans+="-"; c=-c;}
        an<<this->c;
        an>>s;

        int t=s.length()%3;
        for (int i=0; i<s.length(); i++){
            ans+=s[i];
            if (!t) t=2;else t--;
            if (!t && i!=s.length()-1) ans+=",";
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    int a,b;
    cin>>a>>b;
    add *p=new add(a,b);
    cout<<p->answer();
    delete p;
    return 0;
}