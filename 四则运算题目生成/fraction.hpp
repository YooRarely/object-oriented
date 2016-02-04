//
//  fraction.hpp
//  text
//
//  Created by admin on 16/2/3.
//  Copyright © 2016年 YooRarely. All rights reserved.
//

#ifndef fraction_hpp
#define fraction_hpp

#include <stdio.h>
#include <string>
using namespace std;


class fraction{
    
private:
    int x;
    int y;
public:
    void operator+=(fraction k);
    void operator-=(fraction k);
    void operator*=(fraction k);
    void operator/=(fraction k);
    bool operator==(int k);
    fraction change(int k);
    string get_info();
    
    
    
    
    int gcd(int a,int b) { return (b>0)?gcd(b,a%b):a; }
    int abs(int a){ return a<0? -a:a;}
};


#endif /* fraction_hpp */
