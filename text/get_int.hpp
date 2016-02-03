//
//  get_int.hpp
//  text
//
//  Created by admin on 16/2/3.
//  Copyright © 2016年 YooRarely. All rights reserved.
//

#ifndef get_int_hpp
#define get_int_hpp

#include <stdio.h>
#include<string>
#include<stack>

using namespace std;

class get_int{
    
private:
    string input;
    stack <char> oper;
    stack <int> important;
    stack <int> count;
    bool err;
    
    
public:
    get_int(string input);
    void tried(int important);
    void calculation();
    string answer();

};


#endif /* get_int_hpp */
