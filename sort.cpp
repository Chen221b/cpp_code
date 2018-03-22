#include <iostream>

using namespace std;

void swap(int a, int b, int* array){
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
	return;
}

void RadixSort(int* array){

}

void BucketSort(int* array){

}

void ShellSort(int* array){
	
}

void QuickSort(int left, int right, int* array){
	if(left >= right)
		return;
	int pole = left;
	int split = left + 1;
	for(int i = left + 1; i <= right; i++){
		if(array[pole] < array[i]){}
		else{
			swap(split, i, array);
			split++;
		}
	}
	swap(pole, split-1, array);
	QuickSort(left, split-1, array);
	QuickSort(split, right, array);
	return;
}

void MergeSort(int left, int right, int* array){
	int mid = left + (right - left) >> 1;
	if(left < mid)
		MergeSort(left, mid, array);
	if(mid + 1 < right)
		MergeSort(mid + 1, right, array);
	int leftside = left;
	int rightside = mid+1;
	int temparray[right-left+1];
	int counter = 0;
	while(leftside <= mid && rightside <= right){
		if(array[leftside] <= array[rightside]){
			temparray[counter] = array[leftside];
			leftside++;
		}else{
			temparray[counter] = array[rightside];
			rightside++;
		}
		counter++;
	}
	while(leftside <= mid)
		temparray[counter++] = array[leftside++];
	while(rightside <= right)
		temparray[counter++] = array[rightside++];
	for(int i = 0, j = left; j <= right;)
		array[j++] = temparray[i++];
	return;
}

void Display(int* array){
	for (int i = 0; i < sizeof(array); ++i)
	{
		cout << array[i] << " ";
	}
}

int main(int argc, char const *argv[])
{
	int array[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
	// QuickSort(0, sizeof(array)-1, array);
	MergeSort(0, 14, array);
	Display(array);
	return 0;
}