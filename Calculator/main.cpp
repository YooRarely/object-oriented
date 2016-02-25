//
//  main.cpp
//  Calculator
//
//  Created by admin on 16/2/25.
//  Copyright © 2016年 YooRarely. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>

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
        // 初始化变量  a 为 返回值
        err=false;
        queue <string > a;
        int sum_kuohao = 0; // 括号数量
        
        // 当输入未出错时遍历输入字符串
        for (int i = 0; i < input.size() && ! err; i ++){
            
            string s; // 入队元素
            
            // 如果为 运算符 或 括号
            if ( isOper( input[i] ) || input[i] == '(' || input[i] == ')' ) {
                
                s = input[i];
                
                if (!a.empty()){    // 如果 前面 有东西
                string k=a.back();
                // 如果 当前为左括号 则 前一个不能为数字 或者 右括号
                if (input[i] == '(' && ( isCount( k[0] ) || k[0] == ')' ) ) err = true;
                // 如果 当前不为左括号 或负号 则 前一个不能为 运算符
                if ( isOper( k[0] ) && input[i] != '(' && input[i] != '-' ) err = true;
                }
                
                
                if (input[i] == '(') sum_kuohao ++; // 左括号 数量＋1
                if (input[i] == ')') sum_kuohao --; // 右括号 数量－1
                if ( sum_kuohao < 0 ) err = true;   // 若右括号多于左括号 错误
                
            }// 否则 如果为数字
            else if ( isCount( input[i] ) ){
                
                bool dian=false;    // 判断该数小数点是否已经存在
                
                // 未出错且未到字符串结尾时循环把整个数扣出来
                while ( ! err && i < input.size() ){
                    // 数字或小数点
                    if ( isCount( input[i] ) || input[i] == '.') s=s+input[i];
                    
                    if ( input[i] == '.' ) {
                        if ( dian ) err = true; // 如果小数点已经存在 错误
                        dian = true;    // 小数点设为存在
                    }
                    
                    // 如果下一个字符为 运算符 或 括号，说明整个数遍历结束
                    if ( isOper( input[i+1] ) || input[i+1] == '(' || input[i+1] == ')') break;
                    
                    i++;    // 下一个字符
                }
                
                //  如果这个数最后一位为小数点 错误
                if (dian && s[ s.size() - 1 ] == '.') err = true;
                
                // 如果这个数超过10位 错误
                if ( s.size() > 10 ) err = true;
                
            }
            
            // 入队
            a.push(s);
        }
        if ( sum_kuohao ) err = true;   // 若左括号多于右括号 错误
        // 如果没错 扣错
        if ( ! err && ! a.empty() ){
            string k = a.front();
            // 式子前面不能为运算符 除非 是负号
            if ( isOper( k[0] ) && k[0] != '-' ) err = true;
            k = a.back();
            //  式子末尾不能为运算符
            if ( isOper( k[0] ) ) err = true;
        }
        // 如果存在错误 把 a 队列清空 报告错误
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


int main(int argc, const char * argv[]) {
    string input;
    getline(cin,input);
    Scan scan;
    Print print;
    print.PrintStringQueue( scan.ToStringQueue(input) );
    
    return 0;
}
