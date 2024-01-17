 void heapify(int *arr, int size, int index){
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestIndex = index;

     if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]){
        largestIndex = leftIndex;
      }
      if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
        largestIndex = rightIndex;
      }

      if(index != largestIndex){
        swap(arr[largestIndex], arr[index]);
        index = largestIndex;
        heapify(arr,size,index);
      }
}
