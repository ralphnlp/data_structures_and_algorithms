#include <iostream>
using namespace std;

void selection_sort(int n, float arr[]){
    for(int i = 0; i < n-1; i++){
        float min = arr[i];
        int index_min = i;

        for(int j = i+1; j < n; j++)
            if (arr[j] < min){
                min = arr[j];
                index_min = j;
            }
        swap(arr[i], arr[index_min]);
    }
}

void insertion_sort(int n, float arr[]){
    for(int i = 1; i < n; i++){
        float flag = arr[i];
        for(int j = i-1; 0 <= j; j--)
            if(arr[j] > flag)
                arr[j+1] = arr[j];
            else{
                arr[j+1] = flag;
                break;
            }        
    }
}



int main(){
    
    int n = 5;
    float arr[100] = {3, 6, 8, 12, 5};
    
    for(int i = 0; i < n; i++)
        cout << arr[i] << '\t';
    cout << '\n';

    insertion_sort(n, arr);
    for(int i = 0; i < n; i++)
        cout << arr[i] << '\t';
    cout << '\n';

    return 0;
}