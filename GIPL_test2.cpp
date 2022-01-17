/*By filing the blanks with +, -, *, / and following the operator precedence, you can get different results.
Please write a function to enumerate all valid results created by filling blanks in this formula: 
4 _ 3 _ 2 _ 1  
And 
1 _ 2 _ 3 _ 4*/ 
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int Precedence(char op)
{
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    return 0;
}
 
/* Function to perform arithmetic operations.*/
int applyOperator(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
 
/* Function that returns value of expression */
int Evaluate(string tokens)
{
    int i;
     
    /*stack to store integer values.*/
    stack <int> values;
     
    /* stack to store operators.*/
    stack <char> ops;
     
    for(i = 0; i < tokens.length(); i++){
         
 
        if(isdigit(tokens[i]))
        {
            int val = 0;
             
            /* There may be more than one digits in number.*/
            while(i < tokens.length() && isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
             
            values.push(val);
       
              i--;
        }
        else
        {
           
            while(!ops.empty() && Precedence(ops.top())>= Precedence(tokens[i]))
            {
                int val2 = values.top();
                values.pop();
                 
                int val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOperator(val1, val2, op));
            }
            /* Push current token to 'ops'.*/
            ops.push(tokens[i]);
        }
    }
     
    /* applying remaining ops to remaining values.*/
    while(!ops.empty()){
        int val2 = values.top();
        values.pop();
                 
        int val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();
                 
        values.push(applyOperator(val1, val2, op));
    }
     
    /* Top of 'values' contains result, return it.*/
    return values.top();
}
int main()
{
    int a,b,c,d;
    char arr[]={'/','*','+','-'};
    cout<<"enter 4 numbers: \n"<<endl;
    cin>>a>>b>>c>>d;
    int jCount=0;
    for(int i=0;i<4;i++)
    {
        
        for(int j=0;j<4;j++)
        {
             
             for(int k=0;k<4;k++)
            {
               string  sExpression = to_string(a)+arr[i]+to_string(b)+arr[j]+to_string(c)+arr[k]+to_string(d); /*expression*/
               cout<<to_string(a)<<arr[i]<<to_string(b)<<arr[j]<<to_string(c)<<arr[k]<<to_string(d)<<" = "<<Evaluate(sExpression)<<endl;
               jCount++;    
            }
        }
    }
    cout<<"Total number of possibile outcomes: "<<jCount; /*prints the total number of possibilities*/
    return 0;
}