#include<bits\stdc++.h>
using namespace std;
class heap{
    public:
    int a[100];
    int size;
    heap(){
        a[0]=-1;
        size=0;
    }
void insrt(int val){
    size=size+1;
    int index=size;
    a[index]=val;
    while(index>1){
        int parent=index/2;
        if(a[parent]<a[index]){
            swap(a[parent],a[index]);
            index=parent;
        }
        else{
            return;
        }
    }
}
void del(){
    if(size==0){
        cout<<"nthg to delete"<<endl;
    }
    a[1]=a[size];
    size--;
    int i=1;
    while(i<size){
        int leftchild=2*i;
        int rightchild=2*i+1;
        if(a[leftchild]>a[i]&&leftchild<size){
            swap(a[leftchild],a[i]);
            i=leftchild;
        }
        else if(a[rightchild]>a[i]&&rightchild<size){
            swap(a[rightchild],a[i]);
            i=rightchild;
        }
        else{
            return;
        }
    }
}

void print(){
    for(int i=1;i<=size;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}

          
};
void heapify(int arr[],int n ,int i){
    int largest =i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n&& arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n&& arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}
int main(){
    heap h;
    h.insrt(50);
    h.insrt(55);
    h.insrt(53);
    h.insrt(52);
    h.insrt(54);
    h.del();
    h.print();
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
   for(int i= n/2;i>0;i--){
     heapify(arr,n,i);
}
cout<<"heapify ";
for(int i=1;i<= n;i++){
    cout<<arr[i]<<" ";
}cout<<endl;

heapsort(arr,n);
cout<<"heapsort ";
for(int i=1;i<= n;i++){
    cout<<arr[i]<<" ";
}cout<<endl;
    return 0;
}