//
//  main.cpp
//  CECS 328 Project2
//
//  Created by So Young Sarah Lee on 11/22/19.
//  Copyright © 2019 wonsuk seo. All rights reserved.
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Operator{
    protected :
    int value;
    string symbol;
    string op;
    int p ;
     vector <Operator*> v;
public:
    Operator(){
    }
    Operator(int prioity){
        p = prioity;
    }
    int getP(){
        return p;
    }
    string getOp(){
        return symbol;
    }
    string getType(){

        return op;
    }
    int getValue(){
        return value;
    }
};

class Plus : public Operator{
public:
    Plus(){
        p = 1;
        symbol = "+";
        op = "op";

    }

};
class Minus : public Operator{
public:
    Minus(){
        p = 1;
        symbol = "-";
        op = "op";
        
    }
       };
class Divide : public Operator{
public:
    Divide(){
        p = 2;
        symbol = "/";
        op = "op";
    }
   
};

class Multiplcation : public Operator{
public:
    Multiplcation(){
        p = 2;
        symbol = "*";
        op = "op";
        
    }
 
};

class Power : public Operator{
public:
    Power(){
        p = 3;
        symbol = "^";
        op = "op";
    }
    
};

class integer : public Operator{
public:
    integer(int a){
        value = a;
        op = "num";
    }
    int getValue(){
        return value;
    }
};

int main() {
    
    int c;
    string e;
    string num = "";
    stack <Operator*> stack;
    vector <Operator*> array;
    while(true){
        
        cout << "1.Run the program" << endl;
        cout << "2.Quit" << endl;
        
        cin >> c;
        switch(c){
            case 1:
            cout << "Put expression" << endl;
            cin >> e;
        for( int i = 0; i <= e.length(); i++){
               if(e[i] == '+'){
                 array.push_back(new integer(stoi(num)));
                   num = "";
                array.push_back(new Plus());
                
               }
                    
                else if(e[i] == '-'){
                    array.push_back(new integer(stoi(num)));
                    num = "";
                    array.push_back(new Minus());
                    
                }
                    
                else if(e[i] == '*'){
                array.push_back(new integer(stoi(num)));
                num = "";
                array.push_back(new Multiplcation());
                                 
                }
                    
                else if(e[i] == '/'){
                array.push_back(new integer(stoi(num)));
                num = "";
                                 
                array.push_back(new Divide());
                                 
                }
                else if(e[i] == '^'){
                array.push_back(new integer(stoi(num)));
                num = "";
                array.push_back(new Power());
                
                }
                else{
                  
                    num += e[i];
                }
           
                  
                }
                
                array.push_back(new integer(stoi(num)));
                
            /*
                for (int i=0; i < array.size(); i++){
                    cout << array[i] -> getValue() << endl;
                    cout << array[i] -> getType() << endl;
                    
                }
               */
                
vector <Operator*> postFix;
                
 for(int j=0; j <array.size(); j++){
     
    if(array[j]->getType() == "num"){
        postFix.push_back(array[j]);
    
    }
     
    else{
        if(stack.empty()){
                stack.push(array[j]);
    }
    else{
        
        if(stack.top()->getP() < array[j]->getP()){
        stack.push(array[j]);
        }
    else{
                        
       while(!stack.empty() && stack.top()->getP() == array[j] ->getP()){
            postFix.push_back(stack.top());
            stack.pop();
}
          
        stack.push(array[j]);
        
         }
         }
        }
    
                         
}
    while(!stack.empty()){
    postFix.push_back(stack.top());
        stack.pop();
     
    }
          
               
                //while
    cout << "Postfix expression: " ;
    for(int a = 0; a< postFix.size(); a++){
        if(postFix[a]->getType() == "num"){
            cout<<postFix[a]->getValue();
                          }
        else if(postFix[a] ->getType() == "op"){
            cout<<postFix[a]->getOp();
                              
                          }
                
            }//for
        cout << endl;
                        
                
  
        }    //switch
    
    }//while
                     
    return 0;
    
}
