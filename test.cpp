#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
using namespace std;
//float mytimer() ;
//float mytimer(){ 
//  struct tms hold;
    
 //  times(&hold);
    /*return  (float)(hold.tms_utime) / 60.0;*/
//    return  (float)(hold.tms_utime);
//}
void duplicate_array(int** A,int** B,int m,int n){
    for(int i = 0;i < m;i ++){
        for(int j = 0;j < n;j ++){
            B[i][j] = A[i][j];
        }
    }
}
void printout_arrary(int** A,int m,int n){
    for(int i = 0;i < m;i ++){
        for(int j = 0;j < n;j ++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
//---------------------------------------//
//---------------merge sort--------------//
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] >= R[j]) //
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}

//---------------------------------------------------------///
//-----------insertion sort----------//
void ins_sort(int arr[], int n) 
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 

       while (j >= 0 && arr[j] < key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
}
//---------------------------------------------------------///
//-----------main function to do heap sort----------//
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] < arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] < arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
void my_swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] >= pivot) 
        { 
            i++;    // increment index of smaller element 
            my_swap(&arr[i], &arr[j]); 
        } 
    } 
    my_swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}
//-------------------------------------------//
//------------------quicksort-----------------//
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}
//-----------------------------------//
//------------count sort----------------//
void countSort(int arr[],int n,int RANGE){
    int* count = new int [RANGE];
    for(int i = 0;i<RANGE;i++){
        count[i] = 0;
    }
    int i;
    int out[n]={0};
    for(int i = 0; i < n; i++) 
      ++count[arr[i]];
    for(int i = 1; i <=RANGE;i++) 
      count[i]+=count[i-1];
    for(int i = n-1; i >= 0; i--){
        out[n - 1 - (count[arr[i]]-1)]=arr[i];
        --count[arr[i]];
    }
    for(int i = 0; i < n; i++) 
      arr[i]=out[i];
}
//-----------------------------------------------------/
//----------------------radix_countsort---------------/
void radix_countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
//------------------------------------------// 
//----------------radixsort--------------------//
void radixSort(int arr[], int n) 
{ 
    // Find the maximum number to know number of digits 
    int out[n];
    int m = arr[0]; 
    for(int i = 0;i < n ;i ++){
        out[i] = arr[i];
    }
    for (int i = 1; i < n; i++){
        if (arr[i] > m){
            m = arr[i]; 
        }
    }
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m/exp > 0; exp *= 10){
        radix_countSort(out, n, exp); 
    }
    for(int i = 0;i < n ;i ++){
        arr[i] = out[n-1-i];
    }
} 
//--------------------------------------------------------/
//bucketsort//
void bucketSort(int array[], int n){
    int i, j;
    int *count = NULL;
    // find largest
    int mymax=array[0]+1;
    for (i=1; i<n; ++i)
    {
        if (mymax<(array[i])+1)
            mymax=array[i]+1;
    }
    // allocate and zero-fill a proper-sized array
    count=(int *)calloc(mymax, sizeof(*count));
    for(i=0; i < n; i++)
        (count[array[i]])++;
    for(i=0,j=n-1; i < mymax; i++)
    {
        for(;count[i]>0;(count[i])--)
            array[j--]= i;
    }
    free(count); 
} 
//-----//
//seed->random numbers//
double MyRand(int seed)
{
  if(seed!=0) 
    srand(seed);
  return(rand()/(double)RAND_MAX);
}
//-----//
//--calculate the time--//
clock_t mytimer()
{ 
	return clock();
}
//------//
//--test the result--//
int is_A_desc(int *A,int n){
	for(int i=0 ; i<n ; i++){
		for(int j=i+1 ; j<n ; j++){
			if (A[i]<A[j]){	
      cout<<"!!WRONGLY SORTED!!\n";
			return 0;
      }
		}
	}
	cout<< "order OK!\n";
	return 1;
}
//-----//
//---main--/////
int main(){
	bool is_p;
	int m = 1;
  int n ;
  int a_min, a_max , rs ;
	cout<<"Input [is_p,n,a_min,a_max,rs]=";
  cin>>is_p>>n>>a_min>>a_max>>rs;
  int **A = new int*[m];
  int **B = new int*[m];
  MyRand(rs);
  for(int i = 0;i < m;i ++){
      A[i] = new int [n];
      B[i] = new int [n];
    }
  for(int i = 0;i < n;i ++){
        // A[0][i] = i;
        double rn=MyRand(0);
        // cout << rn << " ";
        A[0][i] = round(rn*(a_max-a_min))+a_min;
    }
    //printout_arrary(A, 1, n);
    duplicate_array(A, B, 1, n);
    //printout_arrary(B, 1, n);

    clock_t t1, t2;
	cout << "after insertion sort\n";
	  t1 = mytimer();
    ins_sort(A[0], n);
    t2= mytimer();
    cout<<(double)(t2-t1)/CLOCKS_PER_SEC<<"ms"<<endl;
    //printout_arrary(A, 1, n);
    is_A_desc(A[0], n);
	duplicate_array(B, A, 1, n);
    

    cout << "after merge sort\n";
    //t1 = mytimer();
    t1 = mytimer();
    mergeSort(A[0], 0, n-1);
    //printout_arrary(A, 1, n);
    t2= mytimer();
cout<<(double)(t2-t1)/CLOCKS_PER_SEC<<"ms"<<endl;
    is_A_desc(A[0], n);
	duplicate_array(B, A, 1, n);
    
    
    cout << "after heap sort\n";
   t1 = mytimer();
    heapSort(A[0], n);
    //printout_arrary(A, 1, n);
    t2 = mytimer();
    cout<<(double)(t2-t1)/CLOCKS_PER_SEC<<"ms"<<endl;
    is_A_desc(A[0], n);
	duplicate_array(B, A, 1, n);
    

    cout << "after quick sort\n";
    t1 = mytimer();
    quickSort(A[0], 0, n-1);
    //printout_arrary(A, 1, n);
    t2 = mytimer();
    cout<<(double)(t2-t1)/CLOCKS_PER_SEC<<"ms"<<endl;
    is_A_desc(A[0], n);
	duplicate_array(B, A, 1, n);
    

      cout << "after counting sort\n";
      t1 = mytimer();
      countSort(A[0],n,a_max);
      //printout_arrary(A, 1, n);
      t2 = mytimer();
      cout<<(double)(t2-t1)/CLOCKS_PER_SEC<<"ms"<<endl;
      is_A_desc(A[0], n);
      duplicate_array(B, A, 1, n);
    

    cout << "after radix sort\n";
    t1 = mytimer();
    radixSort(A[0], n);
    //printout_arrary(A, 1, n);
    t2 = mytimer();
    cout<<(double)(t2-t1)/CLOCKS_PER_SEC<<"ms"<<endl;
    is_A_desc(A[0], n);
	duplicate_array(B, A, 1, n);
    

    cout << "after bucket sort\n";
    t1 = mytimer();
    bucketSort(A[0],n);
   // printout_arrary(A, 1, n);
    t2 = mytimer();
    cout<<(double)(t2-t1)/CLOCKS_PER_SEC<<"ms"<<endl;
    is_A_desc(A[0],n);
	duplicate_array(B, A, 1, n);
}; 
