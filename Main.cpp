#include<iostream>
#include<stdio.h>

#define sizeOfArray 10

void InsertionSort(int *arr, int n)
{
	int j = 0, key = 0;

	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}

	std::cout << " After using Insertion Sort ..";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
};

void BubbleSort(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	std::cout << " After Sorting ..";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
}

void SelectionSort(int *arr, int n) 
{
	int min = 0;

	for (int i = 0; i < n; i++) 
	{
		min = arr[i];

		for (int j = i + 1; j < n ; j++)
		{
			if (min > arr[j] )
			{
				arr[i] = arr[j];
				arr[j] = min;
				min = arr[i];
			}
		}
	}

	std::cout << " After Sorting ..";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";

}              

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
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

void QuickSort(int *arr, int n)
{
	quickSort(arr, 0, n);
	std::cout << " After Sorting ..";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
}

void merge(int *arr,int l,int m, int r) 
{
	int left[sizeOfArray], right[sizeOfArray], i = 0, j = 0, k = 0;
	int size1 = m-l+1, size2 = r-m;
	
	memset(left, 0, sizeof(int)*sizeOfArray);
	memset(right, 0, sizeof(int)*sizeOfArray);


	for( i = 0; i < size1; i++)
	{
		left[i] = arr[l+i];
	}
	
	for( j = 0; j < size2; j++)
	{
		right[j] = arr[m+1+j];
	}

	i = 0, j = 0, k = l;
	while (i < size1 && j < size2)
	{
		if (left[i] < right[j]) 
		{
			arr[k] = left[i];
			k++;
			i++;
		}
		else
		{
			arr[k] = right[j];
			k++;
			j++;
		}
	}
	while (i < size1)
	{
		arr[k] = left[i];
		k++;
		i++;
	}
	while (j < size2)
	{
		arr[k] = right[j];
		k++;
		j++;
	}
}
 
void merge(int *arr, int l, int r)
{
	if (l < r) 
	{
		int mid = (l + r) / 2;
		merge(arr,l,mid);
		merge(arr, mid+1,r);
		merge(arr, l, mid, r);
	}
}

void MergeSort(int *arr, int n)
{
	merge(arr, 0, sizeOfArray - 1);
	std::cout << " After Sorting ..";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1};
	int n = 10;
	int choice = 0;

	std::cout <<" Before Sorting ..(";

	for (int i = 0; i < n; i++)
		std::cout <<arr[i] <<" ";

	std::cout <<")";
	std::cout << std::endl;

	std::cout << " 1.Insertion Sort \n 2.Bubble Sort \n 3.Merge Sort \n 4.Quick Sort \n 5.Selection  Sort \n Your Choice ";
	std::cin >> choice;

	switch (choice) 
	{
		case 1:
			std::cout << "\n1.Insertion Sort...\n";
			InsertionSort(arr, n);
			break;

		case 2:
			std::cout << "\n2.Loaded Bubble Sort...\n";
			BubbleSort(arr, n);
			break;

		case 3:
			std::cout << "\n4.Merge Sort...\n";
			MergeSort(arr, n);
			break;

		case 4:
			std::cout << "\n5.Quick Sort...\n";
			QuickSort(arr, n);
			break;

		case 5:
			std::cout << "\n3.Selection Sort...\n";
			SelectionSort(arr, n);
			break;
			
		default:
			std::cout << "By Default Bubble Sort...\n";
			BubbleSort(arr, n);
			break;
	}

	std::cout << std::endl;
}