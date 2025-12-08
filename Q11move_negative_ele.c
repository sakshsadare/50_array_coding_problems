#include<stdio.h>
void segregateElements(int arr[], int n)
{
   int temp[n];
    int index = 0;
// copy all postive elements in temp array
  for(int i=0;i<n;i++){
    if(arr[i]>=0)
{
  temp[index++] = arr[i];
}
}
for(int i=0;i<n;i++){
  if(arr[i]<0);{
temp[index++] = arr[i];
}
}
for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {1, -1, 3, 2, -7, -5, 11, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    segregateElements(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

