//
//  main.cpp
//  Calculator
//
//  Created by admin on 16/2/25.
//  Copyright © 2016年 YooRarely. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

class Scan{
    
private:
    bool err; // 输入是否出错
    
public:
    // 字符是否为运算符
    bool isOper(char c){
        
        if ( c == '+' || c == '-' || c == '*' || c == '/' ) return true;
        return false;
    }
    // 字符是否为数字
    bool isCount(char c){
        
        if (c>='0' && c<='9') return true;
        return false;
    }
    
    queue <string> ToStringQueue(string input){
        err=false;
        queue <string > a;
        int sum_kuohao = 0;
        
        // 当输入未出错时遍历输入字符串
        for (int i = 0; i < input.size() && ! err; i ++){
            
            string s;
            
            // 如果为 运算符 或 括号
            if ( isOper( input[i] ) || input[i] == '(' || input[i] == ')' ) {
                
                s = input[i];
                
                if (!a.empty()){
                    
                string k=a.back();
                    
                if (input[i] == '(' && ( isCount( k[0] ) || k[0] == ')' ) ) err = true;
                if ( isOper( k[0] ) && input[i] != '(' && input[i] != '-' ) err = true;
                    
                }
                
                
                if (input[i] == '(') sum_kuohao ++;
                if (input[i] == ')') sum_kuohao --;
                if ( sum_kuohao < 0 ) err = true;
                
            }// 否则 如果为数字
            else if ( isCount( input[i] ) ){
                
                bool dian=false;
                
                while ( ! err && i < input.size() ){
                    if ( isCount( input[i] ) || input[i] == '.') s=s+input[i];
                    if ( input[i] == '.' ) {
                        
                        if ( dian ) err = true;
                        dian = true;
                        
                    }
                    
                    if ( isOper( input[i+1] ) || input[i+1] == '(' || input[i+1] == ')') break;
                    i++;
                }
                
                if (dian && s[ s.size() - 1 ] == '.') err = true;
                if ( s.size() > 10 ) err = true;
                
            }
            // 入队
            a.push(s);
            s="";
        }
        if ( sum_kuohao ) err = true;
        
        if ( ! err && ! a.empty() ){
            
            string k = a.front();
            if ( isOper( k[0] ) && k[0] != '-' ) err = true;
            k = a.back();
            if ( isOper( k[0] ) ) err = true;
            
        }
        if ( err ) {
            
            while ( ! a.empty() ) a.pop();
            a.push("Error Input !");
            
        }
        return a;
    }
};

class Print{
public:
    void PrintStringQueue(queue<string> a){
        
        while ( ! a.empty() ) {
            
            cout << a.front() << endl;
            a.pop();
        }
    }
};






class Calculate{
private:
    bool print;
    int tried (stack <char> &oper,stack <int> &important,stack <double> &count, int k){
        
        while ( ! important.empty() && k <= important.top()){
            
            double amazing = count.top();
            count.pop();
            
            
            
            switch (oper.top()) {
                case '+':
                    if (print) cout<<count.top()<<"+"<<amazing;
                    count.top() += amazing;
                    if (print) cout<<"="<<count.top()<<endl;
                    break;
                case '-':
                    if (print) cout<<count.top()<<"-"<<amazing;
                    count.top() -= amazing;
                    if (print) cout<<"="<<count.top()<<endl;
                    break;
                case '*':
                    if (print) cout<<count.top()<<"*"<<amazing;
                    count.top() *= amazing;
                    if (print) cout<<"="<<count.top()<<endl;
                    break;
                case '/':
                    if (amazing == 0) { return -1;}
                    if (print) cout<<count.top()<<"/"<<amazing;
                    count.top() /= amazing;
                    if (print) cout<<"="<<count.top()<<endl;
                    break;
            }
            
            oper.pop();
            important.pop();
        }
        return 0;
    }
    
    
    
    
    
public:
    // 字符是否为运算符
    bool isOper(char c){
        if ( c == '+' || c == '-' || c == '*' || c == '/' ) return true;
        return false;
    }
    // 字符是否为数字
    bool isCount(char c){
        if (c>='0' && c<='9') return true;
        return false;
    }
    
    double getAns(queue<string> a,bool p){
        
        stack <char> oper;
        stack <int> important;
        stack <double> count;
        int k=0;
        print=p;
        
        while ( ! a.empty() ){
            
            if (a.front()[0] == '(') k += 2;
            if (a.front()[0] == ')') k -= 2;
            
            if (isOper( a.front()[0] )){
                
                if ( oper.size() == count.size() ){
                    
                    count.push(0);
                    important.push(10000);
                    
                }
                else if ( a.front()[0] == '*' || a.front()[0] == '/'){
                    
                    if ( tried(oper, important, count, k+1) == -1 ) return 0.000000;
                    important.push(k+1);
                    
                }
                else{
                    
                    if ( tried(oper, important, count, k) == -1 ) return 0.000000;
                    important.push(k);
                    
                }
                oper.push( a.front()[0] );
            }
            if (isCount( a.front()[0] )){
                
                count.push( atof( a.front().c_str() ) );
                
            }
            
            a.pop();
        }
        
        if ( ! oper.empty() )
            if ( tried(oper, important, count, -1) == -1 ) return 0.000000;
        return count.top();
    }
    
    
};



int main(int argc, const char * argv[]) {
    string input;
    bool p,a;
    double ans;
    int i;
    Scan scan;
    Print print;
    Calculate Calculate;
    
    p=false;
    a=false;
    i=1;
    
//    getline(cin,input);
    
    if (argc<2) return 0;
    
    input=argv[i];
    
    while (1){
        
        if (input=="-a") {
            input=argv[++i];
            a=true;
            continue;
        }
        
        if (input=="-p"){
            input=argv[++i];
            p=true;
            continue;
        }
        
        break;
    }
    

// print.PrintStringQueue( scan.ToStringQueue(input) );
    
    
    ans=Calculate.getAns( scan.ToStringQueue(input) , p);
    
    if (a) cout<<input<<"=";
    cout<<ans<<endl;
    return 0;
}
