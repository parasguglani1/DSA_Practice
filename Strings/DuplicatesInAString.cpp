#include<bits/stdc++.h>
using namespace std;

int main(){
    long int h=0, x=0;
    char a[]="dklfjffff";
    for(int i=0; a[i]!='\0'; i++){
        x=1;
        x=x<<a[i]-97;
        if((x&h)>0){
            cout<<a[i]<<" is duplicate.";
            break;
        }
        else
            h = x|h;
    }
    return 0;
}