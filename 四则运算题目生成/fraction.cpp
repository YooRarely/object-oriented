//
//  fraction.cpp
//  text
//
//  Created by admin on 16/2/3.
//  Copyright © 2016年 YooRarely. All rights reserved.
//

#include "fraction.hpp"



void fraction::operator+=(fraction k){
    if (y<0) x=-x,y=-y;
    int l=gcd(y,k.y);
    x=x*k.y/l+k.x*y/l;
    y=y*k.y/l;
    l=gcd(abs(x),y);
    x/=l; y/=l;
};

void fraction::operator*=(fraction k){
    if (y<0) x=-x,y=-y;
    x*=k.x;
    y*=k.y;
    int l=gcd(abs(x),y);
    x/=l; y/=l;
}

void fraction:: operator/=(fraction k)
{

    x*=k.y;
    y*=k.x;
    if (y<0) x=-x,y=-y;
    int l=gcd(abs(x),y);
    x/=l; y/=l;
}
void fraction::operator-=(fraction k){
    if (y<0) x=-x,y=-y;
    int l=gcd(y,k.y);
    x=x*k.y/l-k.x*y/l;
    y=y*k.y/l;
    l=gcd(abs(x),y);
    x/=l; y/=l;
}
bool fraction::operator==(int k){
    return x==k;
}
fraction fraction:: change(int k){
    fraction x;
    x.x=k; x.y=1;
    return x;
}
string fraction:: get_info(){
    char t[250];
    string ans;
    if (y==1) { sprintf(t, "%d",x); ans=t; return ans; }
    if (x==y) { return "1"; }
    if (x>y) {
        sprintf(t, "%d'%d/%d",x/y,x%y,y); ans=t;
    }
    if (x<y){
        sprintf(t, "%d/%d",x,y); ans=t;
    }
    return ans;
};


