#include <bits/stdc++.h>
using namespace std;

int power(int a,int b){
    int res = 1;
    for(int i =0;i<b;i++){
        res *= a;
    }
    return res;
}


int main(){
    string incoming_data;
    cin>>incoming_data;

    int data_length = incoming_data.length();
    int r = floor(log2(data_length))+1;
    reverse(incoming_data.begin(),incoming_data.end());
    int pos = 0;
    for(int i = 0;i<r;i++){
        int x = power(2,i);
        bool flag = false;
        int count = 0;
        for(int j = x-1;j<data_length;j++){
            if((j+1)%x == 0){
                flag = !flag;
            }
            if(flag && incoming_data[j] == '1'){
                count++;
            }
        }
        
        if(count%2){
            pos += x;
        }
    }

    cout<<"ERROR AT POSITION "<<pos<<endl;

}