#include <iostream>

using namespace std;

double res[2010];
double a[1010];
int main(){
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int e;
        cin>>e;
        cin>>a[e];
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int e;
        cin>>e;
        double c;
        cin>>c;
        for(int i=1000;i>=0;i--){
            if(a[i]!=0.0){
                res[i+e]+=c*a[i];
            }
        }
    }
    int cnt=0;
    for(int i=2000;i>=0;i--){
        if(res[i]!=0.0)cnt++;
    }
    cout<<cnt;
    for(int i=2000;i>=0;i--){
        if(res[i]!=0.0){
            cout<<" "<<i<<" ";
            printf("%.1f",res[i]);
        }
    }

}
