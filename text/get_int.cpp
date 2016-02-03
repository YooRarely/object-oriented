//
//  get_int.cpp
//  text
//
//  Created by admin on 16/2/3.
//  Copyright © 2016年 YooRarely. All rights reserved.
//

#include "get_int.hpp"


get_int:: get_int(string input){
    this->input=input;
    err=false;
}

void get_int::tried(int important){
    while (!this->important.empty() && important<=this->important.top()){
        int amazing=this->count.top();
        this->count.pop();
        switch (oper.top()) {
            case '+':
                this->count.top()+=amazing;
                break;
            case '-':
                this->count.top()-=amazing;
                break;
            case '*':
                this->count.top()*=amazing;
                break;
            case '/':
                if (amazing==0) { this->err=true; return ;}
                this->count.top()/=amazing;
                break;
            default:
                break;
        }
        this->oper.pop();
        this->important.pop();
    }
}

void get_int::calculation()
{
    int k=0;
    int count=0;
    for (int i=0; i<this->input.length(); i++){
        if (this->oper.size()>this->count.size() || this->err) {
            this->err=true;
            return;
        }
        switch (this->input[i]) {
            case '(':
                k+=2;
                break;
            case ')':
                k-=2;
                break;
            case '+':
                tried(k),oper.push('+'),important.push(k),count=0;
                break;
            case '-':
                tried(k),oper.push('-'),important.push(k),count=0;
                break;
            case '*':
                tried(k+1),oper.push('*'),important.push(k+1),count=0;
                break;
            case '/':
                tried(k+1),oper.push('/'),important.push(k+1),count=0;
                break;
            default:
                break;
        }
        if (this->input[i]>='0' && this->input[i]<='9') {
            if (!this->count.empty() && this->count.size()>oper.size())
                this->count.pop();
            count=count*10+input[i]-48;
            this->count.push(count);
        }
    }
    if (!this->oper.empty()) tried(-1);
}

string get_int ::answer(){
    if (this->err) return "error input";
    char t[256];
    sprintf(t, "%d" ,this->count.top());
    string ans=t;
    return ans;
}

