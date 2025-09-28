program: 
#include <iostream>
using namespace std;

void findMinCoins(int amount)
{
    int denominations[] = {2000,500,200,100,50,20,10,5,2,1};
    int n = sizeof(denominations)/sizeof(denominations[0]);
    cout<<"Amount: "<<amount;
    int count[n] = {0};
    
    for(int i=0;i<n;i++)
    {
        while(amount>=denominations[i])
        {
            amount-=denominations[i];
            count[i]++;
        }
    }
    
    int totalNotes = 0, totalCoins = 0;
    for(int i=0;i<7;i++)
    {
        if(count[i]>0)
        {
            cout<<denominations[i]<<" X "<<count[i]<<endl;
            totalNotes += count[i];
        }
    }
    
    cout<<"Total notes used: "<<totalNotes<<endl;
    
    for(int i=7;i<n;i++)
    {
        if(count[i]>0)
        {
            cout<<denominations[i]<<" X "<<count[i]<<endl;
            totalCoins +=count[i];
        }
    }
    
    cout<<"Total coins used; "<<totalCoins<<endl;
    
    cout<<"Total notes/coins used: "<<totalNotes+totalCoins;
}

int main()
{
    int amount;
    cout<<"Enter the amount; ";
    cin>>amount;
    
    findMinCoins(amount);
    return 0;
}

output: 
Enter the amount; 2808
Amount: 28082000 X 1
500 X 1
200 X 1
100 X 1
Total notes used: 4
5 X 1
2 X 1
1 X 1
Total coins used; 3
Total notes/coins used: 7

=== Code Execution Successful ===