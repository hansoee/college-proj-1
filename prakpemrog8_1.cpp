/**********RECURSIVE NUMBER REVERSE**********/
#include <iostream>
using namespace std;

int length(int a){          //int size consider -
    int len=0;              //initialized an empty container
    if(a>0){                //positive number only
        while(a>0){         //calculate the loop needed to divide the integer by 10 until it is 0
            a=a/10;         //ex: 1234/10 = 123 --> 123/10=12
            len++;
        }
        return len;
    }
    else return 0;
}

void reverse(int arr[], int n){     //array recursive reverse
    if(n > 1 ){
        int i=0, j=n-1;
        int temp;
        temp=arr[i];                    //swap the first element with the latest
        arr[i]=arr[j];
        arr[j]=temp;
        i++;                            //first element slide to right
        j--;                            //last element slide to left
        reverse(&arr[i], j);            //recursive
    }
    else return;
}

void intoarr(int x){                     //int to array
    int len=length(x), arr[len];
    int i;      
    for(i=len-1; i>=0; i--){        //ex: 1234%10=4 --> 1234/10=123 --> 123%=3
        arr[i]=x%10;
        x/=10;
    }
    reverse(arr, len);              //reverse the array
    for(int i=0; i<len; i++){
        cout<<arr[i];
    }
}

int main(){
    int x;
    cout<<"Enter the number: "; cin>>x;
    intoarr(x);
    cout<<"\n";
}
    
