//
//  make_problem.hpp
//  text
//
//  Created by admin on 16/2/3.
//  Copyright © 2016年 YooRarely. All rights reserved.
//

#ifndef make_problem_hpp
#define make_problem_hpp

#include <stdio.h>
#include<iostream>
#include <string>
using namespace std;

class make_problem{
    
private:
    int n,m,k;
    
public:
    make_problem(int n,int m,int k);
    int ran_int(int m);
    string get_info();
};

#endif /* make_problem_hpp */
