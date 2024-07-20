/* This was my submission on codeforces for a problem called vlad and a sum of sum of digits.
Looking at the problem, it is quite evident that it is a memoization problem.
However, I didn't like that approach, There just had to be some other way, I tried different ways of thinking about the problem,
but what led me to this was noticing that the sum of sum of digits of certain numbers followed a pattern.
And here we have the GeniusFunction, named after how I was feeling after coming up with it.
 */ 

#include<bits/stdc++.h>
using namespace std;

int power10(int b){

    int res = 1;
    for(int i=0; i<b; i++){
        res *= 10;
    }
    return res;

}

int count9s(string s){
    int count= 0;
    for(auto c: s){
        if(c=='9'){
            count++;
        }
    }
    return count;

}

int geniusfunction(int x){
    if(x<10){
        return (x*(x+1))/2;
    }
    string s = to_string(x);
    int n = s.length();
    int tens = power10(n-1);
    int m = x/(tens);
    if(count9s(s) == n){
        return 4.5 * (n * tens * 10);
    }else{
        int t =m*tens;
        return geniusfunction(t-1) + geniusfunction(x-t) + (m * (x-t+1));
    }
}

int main() {
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;

        cout<<geniusfunction(n)<<endl;
    }
   
}
