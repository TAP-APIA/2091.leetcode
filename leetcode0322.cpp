// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
int coinChange(int* coins, int coinsSize, int amount){
    int sy=amount,tt=0,n=coinsSize-1,count=0;
    int coins2[9999]={0};
    int temp=0;
    while (temp<coinsSize){
        coins2[temp]=coins[temp];
        temp++;
    }
     for(int i=0; i<coinsSize-1; i++){
        bool isSorted = true;
        for(int j=0; j<coinsSize-1-i; j++){
            if(coins2[j] > coins2[j+1]){
                isSorted = false;
                temp = coins2[j];
                coins2[j] = coins2[j+1];
                coins2[j+1]=temp;
            }  
        }
        if(isSorted) break;
    }
    while(n>=0){
        if(amount - tt >= coins2[n]){
            tt = tt + coins2[n];
            count++;
        }
        else n--;
    }
    if (tt==amount) return count;
    else return -1;
}

int main(int argc, char* argv[])
{
	int a[]={186,419,83,408};
	int b = sizeof(a)/sizeof(int);
	int c = 6249;
	printf("%d\n",b);
	printf("%d",coinChange(a,b,c));
}
