#include <iostream>
#include "get_int.hpp"
#include "get_fraction.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    string input;
    getline(cin, input);
    
    
    
    get_int *m = new get_int(input);
    
    m->calculation();
    
    cout << m->answer() << endl;
    
    delete m;
    
    
    
    get_fraction *h = new get_fraction(input);
    
    h->calculation();
    
    cout << h->answer() << endl ;
    
    delete h;
    
    
    
    
}