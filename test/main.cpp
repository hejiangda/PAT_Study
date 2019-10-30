#include <iostream>
#include <iomanip>
using namespace std;

double poly[10010]={0};

int main(){
    int k,n;
    double a;
    for(int j=0;j<2;j++){
        cin>>k;
        for(int i=0;i<k;i++){
            cin >> n>>a;
            poly[n]+=a;
        }
    }
    int cnt=0;
    for(int i=1000;i>=0;i--)
        if(poly[i]!=0)
            cnt++;
    cout<<cnt;
    for(int i=1000;i>=0;i--)
    {
        if(poly[i]!=0){
            cout<<" "<<i<<" "<<setprecision(1);
            cout.setf(ios::fixed,ios::floatfield);
            cout<<poly[i];
        }
    }
    return 0;
}
