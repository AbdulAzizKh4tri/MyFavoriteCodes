#include<bits/stdc++.h>

using namespace std;

int power(int a,int b){
    int res = 1;
    for(int i =0;i<b;i++){
        res *= a;
    }
    return res;
}

int main(){

    string data,output;
    data;
    cout<<"Enter data (bitstring): "<<endl;
    cin>>data;
    int data_length  = data.length();
    reverse(data.begin(),data.end());

    int r = 1;
    while(true){
        if(power(2,r) >= data_length + r +1){
            break;
        }
        r++;
    }

    int i=0,t=1;
    while(i<data_length){
        if(round(log2(t)) == log2(t)){
            output.push_back('0');
            t++;
            continue;
        }
        output.push_back(data[i]);

        t++;
        i++;
    }

    int output_length = output.length();

    for(int i = 0;i<r;i++){
        int x = power(2,i);
        bool flag = false;
        int count = 0;
        for(int j = x-1;j<output_length;j++){
            if(j%x == 0){
                flag = !flag;
            }
            if(flag && output[j] == '1'){
                count++;
            }
        }
        
        if(count%2){
            output[x-1] = '1';
        }else{
            output[x-1] = '0';
        }

    }
    reverse(output.begin(),output.end());
    cout<<"After applying hamming code logic: "<<output<<endl;
}