// 4 5 6
#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int sum=0;
    int floor=0;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(tmp>floor){
            sum+=6*(tmp-floor);
            floor=tmp;
            sum+=5;
        }

        if(tmp<floor){
            sum+=4*(floor-tmp);
            floor=tmp;
            sum+=5;
        }
    }
    cout <<sum;

}
