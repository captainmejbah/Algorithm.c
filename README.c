
#include <stdio.h> 
void linearSearch(int array[], int length, int searchItem){ 
 int i; 
 for (i = 0; i < length; i++){ 
 if (array[i] == searchItem){ 
 printf("%d is found %d.\n", searchItem, i); 
 break; 
 } 
 } 
 if (i == length) 
 printf("%d isn't found \n", searchItem); 
} 
void binarySearch(int array[], int length, int searchItem) { 
 int low = 0, high = length - 1; 
 int mid = low + (high - low) / 2; 
 while (low <= high){ 
 if (array[mid] < searchItem) 
 low = mid + 1; 
 else if (array[mid] == searchItem){ 
 printf("%d is found\n", searchItem, mid); 
 break; 
 } 
 else 
 high = mid - 1; 
 mid = (low + high) / 2; 
 } 
 if(low > high) 
 printf("%d isn't found\n", searchItem); 
}
void bubbleSort(int array[], int length){ 
 int i, j, swap; 
 for (i = 0; i < length - 1; i++){ 
 for (j = 0; j < length - i - 1; j++) 
 { 
 if (array[j] > array[j + 1]) /* For decreasing order use '<' instead of '>' */ 
 { 
 swap = array[j]; 
 array[j] = array[j + 1]; 
 array[j + 1] = swap; 
 } 
 } 
 } 
 printf("ascending order: "); 
 for (i = 0; i < length; i++) 
 printf("%d ", array[i]); 
 printf("\n"); 
} 
void insertionSort(int array[], int length){ 
 int i, j, temp; 
 for (i = 1; i < length; i++) 
 { 
 temp = array[i]; 
 j = i - 1; 
 while ((temp < array[j]) && (j >= 0)) 
 { 
 array[j + 1] = array[j]; 
 j = j - 1; 
 } 
 array[j + 1] = temp; 
 }
 printf("ascending order: "); 
 for(i = 0; i < length; i++) 
 printf("%d ",array[i]); 
 printf("\n"); 
} 
void selectionSort(int array[], int length){ 
 int i, j, temp; 
 for (i = 0; i < length; i++) 
 { 
 for (j = i + 1; j < length; j++) 
 { 
 if (array[i] > array[j]) 
 { 
 temp = array[i]; 
 array[i] = array[j]; 
 array[j] = temp; 
 } 
 } 
 } 
 printf("ascending order: "); 
 for(i = 0; i < length; i++) 
 printf("%d ",array[i]); 
 printf("\n"); 
} 
void quicksort(int array[],int first, int last){ 
 int i, j, pivot, temp; 
 if(first<last){ 
 pivot=first; 
 i=first;
 j=last; 
 while(i<j){ 
 while(array[i]<=array[pivot]&&i<last) 
 i++; 
 while(array[j]>array[pivot]) 
 j--; 
 if(i<j){ 
 temp=array[i]; 
 array[i]=array[j]; 
 array[j]=temp; 
 } 
 } 
 temp=array[pivot]; 
 array[pivot]=array[j]; 
 array[j]=temp; 
 quicksort(array,first,j-1); 
 quicksort(array,j+1,last); 
 } 
} 
void countingSort(int a[],int n,int max){ 
 int count[50]={0},i,j; 
 for(i=0;i<n;++i) 
 count[a[i]]=count[a[i]]+1; 
 printf("ascending order: "); 
 for(i=0;i<=max;++i) 
 for(j=1;j<=count[i];++j) 
 printf("%d ",i); 
 printf("\n");
} 
void radixSort (int a[], int n){ 
 int bucket[10][10], bucket_cnt[10]; 
 int i, j, k, r, NOP = 0, divisor = 1, lar, pass, max = a[0]; 
 for (int i = 1; i < n; i++) 
 if (a[i] > max) 
 max = a[i]; 
 lar = max; 
 while (lar > 0){ 
 NOP++; 
 lar /= 10; 
 } 
 for (pass = 0; pass < NOP; pass++){ 
 for (i = 0; i < 10; i++){ 
 bucket_cnt[i] = 0; 
 } 
 for (i = 0; i < n; i++){ 
 r = (a[i] / divisor) % 10; 
 bucket[r][bucket_cnt[r]] = a[i]; 
 bucket_cnt[r] += 1; 
 } 
 i = 0; 
 for (k = 0; k < 10; k++){ 
 for (j = 0; j < bucket_cnt[k]; j++){ 
 a[i] = bucket[k][j]; 
 i++; 
 } 
 } 
 divisor *= 10; 
 } 
}
int main(){ 
 int test; 
 printf("(1) Searching\n (2) Sorting\n"); 
 printf("Enter Your number: "); 
 scanf("%d", &test); 
 if(test == 1){ 
 int searching, length, item, i; 
 printf(" 1 Linear Search.\n 2 Binary Search.\n"); 
 printf("Enter your number: "); 
 scanf("%d", &searching); 
 printf("How many numbers for add: "); 
 scanf("%d", &length); 
 int array[length]; 
 printf("Enter %d your numbers: ", length); 
 for (i = 0; i < length; i++) 
 { 
 scanf("%d", &array[i]); 
 } 
 printf("Enter your search no: "); 
 scanf("%d", &item); 
 switch (searching) 
 { 
 case 1: 
 linearSearch(array, length, item); 
 break; 
 case 2: 
 binarySearch(array, length, item); 
 break; 
 default: 
 printf("not found.\n"); 
 } 
 } 
 else if(test == 2){
 int sorting, length, i, max = 0; 
 printf("1. Selection Sort.\n 2. Counting Sort.\n 3. Bubble Sort.\n 4. Radix Sort.\n5. Insertion Sort.\n 6. Quick Sort.\n"); 
 printf("Enter yournumber: "); 
 scanf("%d", &sorting); 
 printf("How many numbers for add: "); 
 scanf("%d", &length); 
 int array[length]; 
 printf("Enter %d your elements: ", length); 
 for (i = 0; i < length; i++){ 
 scanf("%d", &array[i]); 
 if(array[i] > max) 
 max = array[i]; 
 } 
 switch (sorting) 
 { 
 case 1: 
 selectionSort(array, length); 
 break; 
 case 2: 
 countingSort(array, length, max); 
 break; 
 case 3: 
 bubbleSort(array, length); 
 break; 
 case 4: 
 radixSort(array, length); 
 printf ("ascending order: "); 
 for (i = 0; i < length; i++) 
 printf ("%d ", array[i]); 
 printf ("\n"); 
 break; 
 case 5:
 insertionSort(array, length); 
 break; 
 case 6: 
 quicksort(array, 0, length - 1); 
 printf("ascending order: "); 
 for(i = 0;i < length; i++) 
 printf("%d ", array[i]); 
 printf("\n"); 
 break; 
 default: 
 printf("not found.\n"); 
 } 
 } 
 else{ 
 printf("not found."); 
 } 
 return 0; 
} 
