#include <iostream>
#include<vector>
using namespace std;


int knapsack( vector<int> wt,   vector<int> val, int w, int n){
    //base condition
    if(n == 0){
      return 0;
    }

    //choice diagram : agar uska wieght kam hai yani usko add karna hai to 
    else if(wt[n-1] <= w){
      return max(val[n-1]+ knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt, val, w, n-1));
    }

    //agar uska weight jyada ho or usko add nahi kar sakte 
    else if(wt[n-1] > w){
      return knapsack(wt,val, w, n-1);
    }
}

int main() {
  vector<int> wt = {1,3,4,5};
  vector<int> val = {1,4,5,7};
  int w = 7;
  int n = wt.size()-1;
  cout<<knapsack(wt, val, w, n-1)<<endl;


  return 0;
   
   return 0;
}
