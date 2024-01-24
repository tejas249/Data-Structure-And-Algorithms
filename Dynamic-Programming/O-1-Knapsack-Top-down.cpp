#include <iostream>
#include<vector>
using namespace std;

int knapsack( vector<int> wt,   vector<int> val, int w, int n){
   
    int t[n+1][w+1];
   
    //base condition
    for(int i=0; i<n+1; i++){
      for(int j=0; j<w+1; j++){
        if(i == 0 || j==0){
          t[i][j] = 0;
        }
      }
    }
    //choice diagram : agar uska wieght kam hai yani usko add karna hai to 
    for(int i=1; i<n+1; i++){
      for(int j=1; j<w+1; j++){
        if(wt[i-1] <= j){
          t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);
        }
        else{
          t[i][j] = t[i-1][j];
        }
      }
    }
    return t[n][w];    
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
