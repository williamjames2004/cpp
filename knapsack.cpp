program: 
#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n)
{
    if(n==0||W==0) return 0;
    if(wt[n-1]>W) return knapsack(W,wt,val,n-1);
    return max(val[n-1]+knapsack(W-wt[n-1], wt, val, n-1),
        knapsack(W,wt,val,n-1));
}

int main()
{
    int W,n;
    cout<<"Enter the number of items: ";
    cin>>n;
    int wt[n], val[n];
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++) cin>>val[i];
    cout<<"Enter the weights: ";
    for(int i=0;i<n;i++) cin>>wt[i];
    cout<<"Enter the maximum capacity of knapsack: ";
    cin>>W;
    cout<<"The maximum knapsack value: "<<knapsack(W,wt,val,n);
    
    return 0;
}

output: 
Enter the number of items: 3
Enter the values: 60 100 120
Enter the weights: 10 20 30
Enter the maximum capacity of knapsack: 50
The maximum knapsack value: 220

=== Code Execution Successful ===
