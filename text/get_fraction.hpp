//
//  get_fraction.hpp
//  text
//
//  Created by admin on 16/2/3.
//  Copyright © 2016年 YooRarely. All rights reserved.
//

#ifndef get_fraction_hpp
#define get_fraction_hpp


#include <stdio.h>
#include<string>
#include<stack>
#include"fraction.hpp"

using namespace std;

class get_fraction{
    
private:
    string input;
    stack <char> oper;
    stack <int> important;
    stack <fraction> count;
    bool err;
    
    
public:
    get_fraction(string input);
    void tried(int important);
    void calculation();
    string answer();
    
};

#endif /* get_fraction_hpp */
