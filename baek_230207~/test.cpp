#include <iostream>

using namespace std;


int main(){
	int arr[4][2] ={0,1,0,1,0,1,0,1};
	int cnt =0;


	for(int i =0; i < 4;i++){
		for(int j =0; j < 2;j++){
			if(arr[i][j] == 1)
			{
				break;
			}
			cout<<"1"<<"\n";
		}
	}
}
