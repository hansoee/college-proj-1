//mencari data terkecil setiap iterasi trs ditukar
#include <iostream>
using namespace std;

int seleksi(int data[], int pod, int limit_atas){
    int min=pod;      
    for(int i=pod; i<limit_atas; i++){
        if(data[i]<data[min]) min=i;
    }
    return min;
}

void tukar_data(int &data1, int &data2){

}

int main(){
    int arr[]={1,4,2,5,7,9};
    int podium=0;
    int token_terpilih=seleksi(arr[],podium; );
    //tukar data di podium dgn data di token
}