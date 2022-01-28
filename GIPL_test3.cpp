#include<bits/stdc++.h>
using namespace std;

class Squares
{
    public :
    static int counter;
    private:
    /*Function that prints all combinations*/
    void combination(vector<int> table,int j_num,int token, vector<int> perfectSquares)
    {
        /*If sum of perfect squares exceeds j_num*/
        if(j_num<0||token==table.size()){
            return;
        }
        /*Sum of perfect squares equals to j_num and combination is found*/
        if(j_num==0){
            for(int i:perfectSquares){
                
                cout<<sqrt(i)<<" ";
            }
    counter++;
            cout<<endl;
            return;
        }
        combination(table,j_num,token+1,perfectSquares); /*Does not include current number*/

        perfectSquares.push_back(table[token]); /*Includes number at current position*/

        combination(table,j_num-table[token],token,perfectSquares);

        perfectSquares.pop_back(); /*removes current number*/
    }

    public:
    /*function to check all perfect squares*/
    void sumofSquares(int j_num){
        vector<int> table; /*Initialize an array list to store all squares less than j_num*/
        int sqroot_of_jnum=(int)(sqrt(j_num));

        for(int i=2;i<=sqroot_of_jnum;i++){
            table.push_back(i*i); /*Adding all squares to the table*/
        }

        vector<int> perfectSquares;
        combination(table,j_num,0,perfectSquares);
    }
};
int Squares::counter = 0;
int main(){
    Squares sq1;
    int j_num;
    cout<<"Enter a number to find sum of squares: "<<endl;
    cin>>j_num;

    sq1.sumofSquares(j_num);
    cout<<"Total number of possible outcomes: "<<sq1.counter<<endl;
    return 0;
}