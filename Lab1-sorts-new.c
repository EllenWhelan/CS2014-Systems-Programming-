// must include #include <stdbool.h> at start to use bools
/* find smallest element between start and end of array */
int findMin(int a[], int size, int start) {
  int min = a[start];
  int result = start;
  int i;

  for ( i = start; i < size; i++ ) {
    if ( a[i] < min ) {
      min = a[i];
      result = i;
    }
  }
  return result;
}

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