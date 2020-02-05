#include <iostream>
#include <vector>
using namespace std;

int nums[10];
int main()
{
	int len=0;
	for(int i=0;i<10;i++){
		cin>>nums[i];
		len+=nums[i];
	}
	vector<int> num;
	for(int i=1;i<10;i++){
		if(nums[i]>0){
			num.push_back(i);
			nums[i]--;
			break;
		}
	}

	for(int i=1;i<len;i++){
		for(int i=0;i<10;i++){
			if(nums[i]>0){
				num.push_back(i);
				nums[i]--;
				break;
			}
		}	
	}
	for(auto x:num)
		cout<<x;	
	return 0;
}
