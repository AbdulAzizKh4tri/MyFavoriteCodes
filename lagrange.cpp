/* 
This program extrapolates the output of a certain value given some data points
It uses the Lagrange Interpolation formula 
Another thing I learnt in class that I wanted to implement in code.
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    long double y,x = 20;
    vector<long double> xv = {1,2,3,4};
    vector<long double> yv = {2899,37696,93743,174072};

    if(xv.size() != yv.size()){
        cout<<"SIZES OF X AND Y MUST BE SAME"<<endl;
        return 0;
    }
    int n = xv.size();

    y = 0;
    for(int i = 0;i<n;i++){

        long double prod = 1;
        for(int j = 0;j<n;j++){
            if(i!=j){
                prod *= (x-xv[j]);
                //cout<<"Multipliying at :"<<i<<" "<<x-xv[j]<<endl;
            }
        }
        for(int j = 0;j<n;j++){
            if(i!=j){
                prod /= (xv[i]-xv[j]);
                //cout<<"dividing at :"<<i<<" "<<xv[i]-xv[j]<<endl;
            }
        }

        y+= yv[i] * prod;
        //cout<<"y at "<<i<<": "<<y<<endl;
    }

    cout<<"Result: "<<y<<endl;

    return 0;
}