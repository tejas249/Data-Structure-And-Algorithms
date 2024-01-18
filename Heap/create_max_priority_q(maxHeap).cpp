#include <iostream>
#include<queue>
using namespace std;

int main() {
  //create max priority queue
  priority_queue<int> maxPQ;
  //insertion 
  maxPQ.push(10);
  maxPQ.push(20);
  maxPQ.push(30);
  maxPQ.push(40);
  maxPQ.push(50);


  cout<<"top element is: "<<maxPQ.top()<<endl;
  maxPQ.pop();
  cout<<"top element is: "<<maxPQ.top()<<endl;



  cout<<"size of the max heap: " << maxPQ.size()<<endl;

  cout<<"max empty is empty or not:  "<< maxPQ.empty()<<endl;


  return 0;
}
