/* 
Files containing hamming in their name were written by me in class because I was bored.
They basically implement in code what I was learning on the board
hey that rhymes
 */
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
    int m  = data.length();
    reverse(data.begin(),data.end());

    int r = 1;
    while(true){
        if(power(2,r) >= m + r +1){
            break;
        }
        r++;
    }

    int i=0,t=1;
    while(i<m){
        if(round(log2(t)) == log2(t)){
            output.push_back('0');
            t++;
            continue;
        }
        output.push_back(data[i]);

        t++;
        i++;
    }

    int nl = output.length();

    for(int i = 0;i<r;i++){
        int x = power(2,i);
        bool flag = false;
        int count = 0;
        for(int j = x-1;j<nl;j++){
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
    reverse(output.begin(),output.end());
    
    int errorbit;
    cout<<"Choose a bit to add error to: "<<endl;
    cin>>errorbit;
    errorbit--;

    /* reverse(output.begin(),output.end());
    cout<<"Before Error: "<<output<<endl;
    reverse(output.begin(),output.end()); */
    if(output[errorbit]=='0') output[errorbit] = '1';
    else output[errorbit] = '0';
    reverse(output.begin(),output.end());
    cout<<"After Error:  "<< output<<endl;
    reverse(output.begin(),output.end());

    int pos = 0;
    for(int i = 0;i<r;i++){
        int x = power(2,i);
        bool flag = false;
        int count = 0;
        for(int j = x-1;j<nl;j++){
            if((j+1)%x == 0){
                flag = !flag;
            }
            if(flag && output[j] == '1'){
                count++;
            }
        }
        
        if(count%2){
            pos += x;
        }

    }

    cout<<"ERROR AT POSITION "<<pos<<endl;

    


}