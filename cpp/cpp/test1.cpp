#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int counter;
	int countera;
	int counterb;
	int maxsum;
	int sum;

	cin >> countera;
	int * res = new int[countera];

	for(counter = 1;counter <= countera; counter++){
		maxsum = -pow(10,9);
		cin >> counterb;
		int *array = new int[counterb];
		for(int i = 0;i<counterb;i++){
			cin >> array[i];
			if(array[i] > maxsum){
				maxsum = array[i];
			}
		}

		int i;
		for(i=0;i< counterb;i++){
			if(array[i] < 0){
				continue;
			}
			
			sum = 0;
			for(int j = i;j<counterb;j++){
				sum += array[j];
				if(sum > maxsum){
					maxsum = sum;	
				}

				if(sum <0) break;
			}
		}
		
		res[counter] = maxsum;
	}
	
	for(counter = 1;counter <= countera;counter++){
		cout<<res[counter]<<endl;
	}

	return 0;
}
