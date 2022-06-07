#include<iostream>
using namespace std;

void array_traverse(int *arr, int size)
{
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void array_insert(int *arr, int size , int position, int element){
    size++;
    for(int i=size;i>=position-1;i--){
        swap(arr[i],arr[i+1]);
    }

    arr[position-1]=element;
    //printing after insertion
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void array_delete(int *arr, int size , int position){
    for(int i=position-1;i<=size;i++){
        swap(arr[i+1],arr[i]);
    }
    position--;

    //printing after insertion
    for(int i=0;i<size-1;i++){
        cout<<arr[i]<<" ";
    }
}
void array_search(int *arr,int size, int element){

    bool isFound=false;
    int index;
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            isFound=true;
            index=i+1;
        }
    }
    cout<<endl;
    isFound?cout<<"Value at found at postion: "<<index:cout<<"Value not Found";
}

int main(){
    int arr[100]={1,2,3,4,5,6,7,8};
    array_traverse(arr,8);
    array_insert(arr,8,3,100);
    array_delete(arr,8,7);
    array_search(arr,8,7);
}

