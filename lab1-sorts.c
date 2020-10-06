// must include #include <stdbool.h> at start to use bools
//selection sort 
for (int i=0 ; i<size; i++){
	int copyValue= a[i];
	int currentSmallest= findMin(a[], size, i);
	a[i]=a[currentSmallest];
	a[currentSmallest]=copyValue;
	
}

//Insertion Sort
for(int i=0; i<size; i++({
	int copyValue=a[i];
	int j= i -1;
	while(j>=0 && a[j] > copyValue){
		a[j+1]=a[j];
		j--;
	}
	a[j+1]= copyValue;
}

//Bubble Sort
bool finished=false;
while(!finished){
	for (int i=0; i< size-1; i++){
		int copyValue=a[i];
		if(a[i] >a[i+1]){
			a[i]=a[i+1];
			a[i+1]=copy;
		}
	}
	int i=0;
	bool orderComplete=true;
	while(i<size-1 && orderComplete==true){
		if(a[i] < a[i+1]) i++:
		else orderComplete=false;
	}
	if(orderComplete==true) finished=true;
	else finished = false;
}

int main(){
}