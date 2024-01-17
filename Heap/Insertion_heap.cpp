#include <iostream>
using namespace std;


class Heap{
  public:
  int *arr;
  int capacity;
  int size;

  Heap(int capacity){
    this->arr = new int[capacity];
    this->capacity = capacity;

    this->size = 0;
  }

  void insertion(int val){
    if(size == capacity){
      cout<<"Heap Overflow"<<endl;
      return;
    }
    size++;
    int index = size;
    arr[index] = val;

    while(index > 1){
      int parentIndex = index/2;
      if(arr[index] > arr[parentIndex]){
        swap(arr[index] , arr[parentIndex]);
        index = parentIndex;
      }
      else{
        break;
      }
    }
  }
  void printheap(){
    for(int i=1; i<=size; i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;

  }

};

int main() {
  int capacity = 5;
  Heap h(capacity);

  h.insertion(10);
  h.insertion(20);
  h.insertion(5);
  h.insertion(11);
  h.insertion(6);
  cout<<"printing heap"<<endl;
  h.printheap();
  
  return 0;
}
