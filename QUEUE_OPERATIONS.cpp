#include <iostream>
#include<queue> q;

using namespace std;



int main() {

  // creating the queue 
   queue<int> q;
  //inserting the elements in the queue 
   q.push(10);
   q.push(20);
   q.push(30);
  cout<<"Front element of the queue: "<<q.front()<<endl;
  cout<<"back element of the queue:" <<q.back()<<endl;



   //checking the size of the q

   //checking if the queue is empty or not 
   if(q.empty() == true){
    cout<<"Q is empty"<<endl;
   }
   else{
    cout<<"Q is not empty"<<endl;
   }

   // poping the element 
   q.pop();

   //size
   q.size();

   ////front element 
   cout<<"Front element of the queue: "<<q.front()<<endl;

   //back element
   cout<<"back element of the queue:" <<q.back()<<endl;


  return 0;
}