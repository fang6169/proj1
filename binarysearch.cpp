#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void Binary_Search(const vector<int> &numbers, int value);
void mergeSort(int arr[], int l, int r) ;
void merge(int arr[], int l, int m, int r) ;
void BiTree_Search(int arr[], int sizo, int myKey);
void DoSort(int arr[], int nsize);
void QuickSort(int arr[], int start, int end);
int Partition(int arr[], int begin, int end);

int main() 
{
vector <string>my_char;
my_char.push_back("dd");
my_char.push_back("3rd");
//my_char.push_back('h');
//my_char.push_back("7");
   
vector <int>my_numbers;
  
for (int i=0; i<=999; i++) 
{
	if(i <= 100)
		my_numbers.push_back(i);
	else if(i > 100 && i < 300)
		my_numbers.push_back(i+6);
	else if(i>=300 && i<900)
       my_numbers.push_back(i*2);
	else
		my_numbers.push_back(1800 +7);

}
/*
    my_numbers.push_back(265);
	my_numbers.push_back(10);
	my_numbers.push_back(72);
	my_numbers.push_back(920);
	my_numbers.push_back(510);
	my_numbers.push_back(275);
	my_numbers.push_back(19);
	my_numbers.push_back(68);
	my_numbers.push_back(129);
	my_numbers.push_back(55);
	my_numbers.push_back(489);
	my_numbers.push_back(310);
	my_numbers.push_back(26);
	my_numbers.push_back(554);
	my_numbers.push_back(209);
	my_numbers.push_back(8);
	*/


cout << "Size of vector my_nymbers :" << my_numbers.size() << endl; 
//	Binary_Search(my_numbers, 2);
//	Binary_Search(my_numbers, 23);
//	Binary_Search(my_numbers, 234);
//	Binary_Search(my_numbers, 333);
//	Binary_Search(my_numbers, 561);
//	Binary_Search(my_numbers, 559);
//	Binary_Search(my_numbers, 378);
//	Binary_Search(my_numbers, 375);
	Binary_Search(my_numbers, 99);
//	Binary_Search(my_numbers, 80);

	//merge sorting example below
	/*
    vector <int> arr;
	arr.push_back(12);
	arr.push_back(11);
	arr.push_back(15);
	arr.push_back(1);
	arr.push_back(32);
	arr.push_back(22);
	arr.push_back(39);
	arr.push_back(56);
	arr.push_back(19);
	arr.push_back(42);
	arr.push_back(12);
	arr.push_back(10);
	int arr_size = arr.size();
	*/


	int arr[] = {6, 11, 13, 5, 6, 7, 19, 32, 2, 43, 10, 22, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 

	//mergeSort(arr, 0, arr_size - 1);
	//DoSort(arr, arr_size);//good
	//return 0;
	QuickSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n"); 
   // printArray(arr, arr_size);
	for(int xx =0; xx < arr_size; xx++)
	{
		cout <<arr[xx]<<"\n";
		//cout <<"-";
	}
    BiTree_Search(arr, arr_size, 19);

	

    return 0;
}

void Binary_Search(const vector< int> &my_numbers, int key) 
{
	int iteration = 0, left = 0, right = my_numbers.size()-1, mid;

	while (left <= right) 
	{
		iteration++;
		mid = (int) ((left + right) / 2);
		if (key == my_numbers[mid]) 
		{
		cout << "Binary search found " << my_numbers[mid] << " after " << iteration << " iterations.\n";
		iteration++;
		return;
		}
		else if (key > my_numbers[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout << "Binary search did not found " << my_numbers[mid] << " after " << iteration << " iterations.\n";

	return;

}

void BiTree_Search(int arr[], int itsSize, int Key)
{
	int nSize = itsSize;
	int mid = nSize*0.5;
	int left =0, right = nSize;

	while(left <= right)
	{
  //    if(right == left + 1)
			//mid = right;
	//  else
		//mid =(left + right)/2;
        mid =(left + right)/2;
		if(arr[mid] == Key)
		{
			cout <<Key<<"is Key found = @ "<< mid<<"\n";
			return;
		}
		else if(arr[mid] > Key)
		{
			int mm = arr[mid];
			right = mid -1;
		}
		else if(arr[mid] < Key)
		{
			int kk = arr[mid];
            left = mid + 1;
		}
		else
			;
	}
	cout <<"not found"<<"\n";
}

void mergeSort(int arr[], int l, int r) //const vector< int> &my_numbers
{ 
	int test1, test2, test3;
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 

		test1 = l;
		test2 = m;
		test3 =r;
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
		test1 = l;
		test2 = m;
		test3 =r;
        mergeSort(arr, m+1, r); 
		test1 = l;
		test2 = m;
		test3 =r;
  
        merge(arr, l, m, r); 
    }
	
	else
	{
       int aa =0;
	}
} 

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
	int *L , *R;
	L = new int[n1];
	R = new int[n2];
	//float *p = 10;
		//*R;
	
   // int L[n1]; 
	//int R[n2]; 
  
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
        if (L[i] <= R[j]) 
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

	if(R !=NULL)
	{
		delete R;
		R = NULL;
	}
	if(L !=NULL) 
	{
		delete L;
		L = NULL;
	}
} 

void DoSort(int arr[], int nsize)
{
	int temp;
	//int *rank;
	//rank = new int[nsize-1];
	vector<int> datalist;
	temp = arr[0];
	int zz =0;// xx=0, yy=0;
	int pos=0;
	
	/* work grate
	for(int i=0;i<nsize;i++)
	{
		for(int j= i+1;j<nsize;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}	
	}
	*/
	 /*  冒泡排序 -BubbleSort
	  for(int i = 0; i < nsize;i++)  
        for(int j = i+1;j < nsize;j++)
		{  
            if(arr[j] > arr[j + 1])  
                swap(arr[j],arr[j + 1]);  
        }  
		*/

       
	/* //选择排序 -SelectionSort -good
		for(int i = 0;i < nsize;i++)  
			for(int j = i + 1;j < nsize;j++)
		{  
            if(arr[i] > arr[j])  
                swap(arr[i],arr[j]);  
        }  
		*/

	   
	

#if 0
	for(int ii =0; ii <nsize; ii++)
	{
      datalist.push_back(arr[ii]);
	//  arr[ii]=0;
	}
	for(int ii=0; ii <nsize; ii++)
	{
		for(int jj=ii+1; jj <nsize; jj++)
		{
			if(datalist[ii]>datalist[jj])
			{
				temp = datalist[ii];
				datalist[ii] = datalist[jj];
				datalist[jj]= temp;
			}
		}
	}

	
	for(int vv=0; vv< datalist.size(); vv++)
	{
		cout<<datalist[vv]<<"\n";
	}
#endif

/*
	sort(datalist.begin(), datalist.end());

	for(int vv=0; vv< datalist.size(); vv++)
	{
		cout<<datalist[vv]<<"\n";
	}
*/
}

void QuickSort(int arr[],int start,int end)
{  
    if(start < end)
	{  
        int q = Partition(arr,start,end); //分割成两部分  
        QuickSort(arr,start,q - 1);  
        QuickSort(arr,q + 1,end);  //
    }  
}  

int Partition(int arr[],int start,int end)
{  
    int x = arr[start];  
    int i = start;  
    for(int j = start + 1;j <= end;j++)
	{  
        if(arr[j] <= x)
		{  
            i++;  
            swap(arr[i],arr[j]);  //after out of loop, j-th item is the smallest
        }  
    }  
    swap(arr[i],arr[start]); //把基准的值放在中间，则左边都小于他，右边都大于他  
    return i;  //there are i of array value smaller than arr[start]
}  
