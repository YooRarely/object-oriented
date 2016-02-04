//
//  main.cpp
//  text
//
//  Created by admin on 16/2/3.
//  Copyright © 2016年 YooRarely. All rights reserved.
//


#include <iostream>
#include "get_int.hpp"
#include "get_fraction.hpp"
#include "make_problem.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
    string input;
    
//    getline(cin, input);
//    
//    
//    
//    get_fraction *m = new get_fraction(input);
//    
//    m->calculation();
//    
//    cout << m->answer() << endl;
//    
//    delete m;
    
    srand((unsigned)time(NULL));
    
    for (int i=0; i<10000; i++){
    
        make_problem *p =new make_problem( 5, 10, 1);
        
        input=p->get_info();
        
        cout<<input;
        
        get_fraction *h = new get_fraction(input);
    
        h->calculation();
        
        cout << h->answer() << endl ;
    
        delete h;
    
    }
    
}