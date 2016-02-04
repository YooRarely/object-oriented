//
//  make_problem.cpp
//  text
//
//  Created by admin on 16/2/3.
//  Copyright © 2016年 YooRarely. All rights reserved.
//

#include "make_problem.hpp"


make_problem::make_problem(int n,int m,int k){
    this->n=n;
    this->m=m;
    this->k=k;
}



string make_problem::get_info(){
    char t[10];
    string ans;
    int k=0;
    for (int i=0,j=0; i<n;)
    {
        if (i==j)
        {
            if (rand()%2==0 || k == this->k)
                sprintf(t,"%d ",rand()%m),ans+=t,i++;
            else ans+="( ",k++;
        }
        else
        {
            int o=rand()%5;
            if (o==0 && k>0) ans+=") ",k--;
            else
                    switch (o) {
                        case 1:
                            ans+="+ "; j++;
                            break;
                        case 2:
                            ans+="- "; j++;
                            break;
                        case 3:
                            ans+="* ";  j++;
                            break;
                        case 4:
                            ans+="/ ";  j++;
                            break;
                        default:
                            break;
                
            }
            
        }
    }
    while (k) ans+=") ",k--;
    
    return ans+"= ";
}