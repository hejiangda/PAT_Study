#include <iostream>

using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    string c=to_string(a+b);
    for(int i=0;i<c.size();i++){
        printf("%c",c[i]);
        if(c[i]=='-')
            continue;
        if((i+1)%3==c.size()%3  && i!=c.size()-1)
            printf(",");
    }
    return 0;
}
