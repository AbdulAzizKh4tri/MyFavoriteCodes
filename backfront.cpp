/* 

www.codechef.com/problems/BACKFRONT
My solution for this problem statement. I sadly couldn't solve it in the contest itself, but I felt like the solution was
withing my reach and I just had to put in some time, and sure enough, time did the trick. 

I started off using vectors to store the indices to determine the order, but I realised I could just reverse the loop and keep track of things that way. Overall, took longer than it should have (hindsight privilege), but it was fun and I'm still proud for having solved it.

*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int T;
    cin>>T;

    while(T--){
        int len;
        cin>>len;
        string s;
        cin>>s;
        int slen = len;
        int k = 0, ck = 0, ack = 0, back = 0;
        int f = 0, fr = 0, fro = 0, fron = 0, front = 0;

        for(int i = slen-1; i >= 0; i--){
            if(s[i] == 'k'){
                k++;
            }else if(s[i] == 'c' && k > 0){
                k--;
                ck++;
            }else if(s[i] == 'a' && ck > 0){
                ck--;
                ack++;
            }else if(s[i] == 'b' && ack > 0){
                ack--;
                back++;
                len -= 4;
            }

        }

        int added_length = 0;
        while(back > 0){
            back--;
            if(ack > 0){
                len -= 3;
                ack--;
                back++;
            }else if(ck > 0){
                ck--;
                ack++;
                added_length++;
            }else if(k > 0){
                k--;
                ck++;
                added_length++;
            }else{
                k++;
                added_length++;
            }
        }

        len += added_length;

        added_length = 0;
        for(int i = 0 ; i < slen; i++){
            if(s[i] == 'f'){
                f++;
            }else if(s[i] == 'r' && f > 0){
                fr++;
                f--;
            }else if(s[i] == 'o' && fr > 0){
                fro++;
                fr--;
            }else if(s[i] == 'n' && fro > 0){
                fron++;
                fro--;
            }else if(s[i] == 't' && fron > 0){
                front++;
                fron--;
                len -= 5;
            }
        }

        while(front > 0){
            front--;
            if(fron > 0){
                len -= 4;
                fron--;
                front++;
            }else if(fro > 0){
                fron++;
                fro--;
                added_length++;
            }else if(fr > 0){
                fro++;
                fr--;
                added_length++;
            }else if(f > 0){
                f--;
                fr++;
                added_length++;
            }else{
                f++;
                added_length++;
            }
        }

        len += added_length;
        cout<<len<<endl;
    }
}