#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char ch;
int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int arr1[]={5,10,3,2,18,12,9,7,16,19,1,4,11,14,6,15,8,20,13,17,20};
int arr2[]={5,10,3,2,18,12,9,7,16,19,1,4,11,14,6,15,8,20,13,17,20};
int arr3[]={5,10,3,2,18,12,9,7,16,19,1,4,11,14,6,15,8,20,13,17,20};
int arr4[]={1,3,2,3,4,1,6,4,3,9};
int arr5[]={1,11,2,5,6,3,4,10,15,7,8,12,13,14,9,16};
int arr6[] = { 64, 34, 25, 12, 22, 11, 90 };
int array[] = {24,2,45,-1,0,53,12};
int size = sizeof(array) / sizeof(array[0]);
int arr7[]={5,10,3,2,18,12,9,7,16,19,1,4,11,14,6,15,8,10,13,17,20};
int arr8[]={11,36,82,39,78,15,64,47,80,97};
int arr9[]={5,10,3,2,18,12,9,7,16,19,1,4,11,14,6,15,8,20,13,17,20};

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void binary_search(int list[], int n, int lo, int hi, int key)
{
    int mid;

    if (lo > hi)
    {
        printf("Key not found\n");
        return;
    }
    mid = (lo + hi) / 2;
    bargraph(list,n,mid);
    if (list[mid] == key)
    {
        printf("Key found\n");
        delay(5);
        system("cls");
        menu();
    }
    else if (list[mid] > key)
    {
        delay(5);
        system("cls");
        binary_search(list, n, lo, mid - 1, key);
    }
    else if (list[mid] < key)
    {
        delay(5);
        system("cls");
        binary_search(list, n, mid + 1, hi, key);
    }
}

void linear_search(int arr1[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++){
        bargraph(arr1,20,i);
        if (arr1[i] == x){
            printf("key found");
            delay(5);
            system("cls");
            goto label;
        }
        delay(2);
        system("cls");
    }
    printf("key not found");
    delay(5);
    system("cls");
    label:
    menu();
}


void bargraph(int arr[],int n, int index)
{
    printf("\n");
    int largest=arr[0];
    for(int i=0;i<n;i++){
        largest=max(largest,arr[i]);
    }
    int num=2*largest+2;
    while(num!=-2){
        int count=-1;
        for (int i=0;i<n;i++){
            count++;
            if (num==arr[i]*2+2){
                printf("%d",arr[i]);
            }
            else{
                int temp=arr[i];
                while(temp>=10){
                    printf(" ");
                    temp=temp/10;
                }
                printf(" ");
            }
            if (num<=arr[i]*2){
                if (count==index){
                    SetColor(7);
                    printf("***");
                    SetColor(6);
                }
                else{
                    printf("***");
                }
            }
            else{
                printf("   ");
            }

            printf("   ");
        }
        num=num-2;
        printf("\n");
    }
}

void bargraph1(int arr[],int n, int index1, int index2)
{
    printf("\n");
    int largest=arr[0];
    for(int i=0;i<n;i++){
        largest=max(largest,arr[i]);
    }
    int num=2*largest+2;
    while(num!=-2){
        int count1=-1;
        int count2=-1;
        for (int i=0;i<n;i++){
            count1++;
            count2++;
            if (num==arr[i]*2+2){
                printf("%d",arr[i]);
            }
            else{
                int temp=arr[i];
                while(temp>=10){
                    printf(" ");
                    temp=temp/10;
                }
                printf(" ");
            }
            if (num<=arr[i]*2){
                if (count1==index1){
                    SetColor(7);
                    printf("***");
                    SetColor(6);
                }
                else if (count2==index2){
                    SetColor(4);
                    printf("***");
                    SetColor(6);
                }
                else{
                    printf("***");
                }
            }
            else{
                printf("   ");
            }

            printf("   ");
        }
        num=num-2;
        printf("\n");
    }
}

void printArray(int arr[], int n, int k, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (i == m)
            SetColor(4);
        else if (i < k)
            SetColor(14);
        printf("%d  ",arr[i]);
        SetColor(3);
    }
}

void InsertionSort(int arr[],int n)
{
    SetColor(3);
    int i,j,temp;
    for (i=1; i<n; i++)
    {
        temp=arr[i];
        //printf("\n\n\n");
        printArray(arr, n, i, -1);
        printf("    key = %d\n\n\n",temp);
        //delay(1);
        printArray(arr, n, i, -1);
        printf("    key = %d\n",temp);
        //delay(1);
        for (j=i-1; j>=0; j--)
        {
            if (arr[j]>temp){
                arr[j+1]=arr[j];
                arr[j]=0;
                printArray(arr, n, i, j+1);
                printf("    key = %d\n",temp);
                //delay(1);
            }
            else
                break;
        }
        arr[j+1]=temp;
    }
    printArray(arr, n, i, -1);
    char a = getch();
    system("cls");
    menu();
}

void Swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void WaveSort(int arr[],int n)
{
	bargraph1(arr, n, -1, -1);
	delay(3);
	system("cls");
	int i;
	for(i=1;i<n;i=i+2)
	{
		bargraph1(arr, n, i, i-1);
        delay(3);
        system("cls");
		if(i>0&&arr[i]>arr[i-1])
		{
			Swap(&arr[i],&arr[i-1]);
			bargraph1(arr, n, i, i-1);
			delay(3);
			system("cls");

		}
		bargraph1(arr, n, i, i+1);
        delay(3);
        system("cls");
		if(i<n-1&&arr[i]>arr[i+1])
		{
			Swap(&arr[i],&arr[i+1]);
			bargraph1(arr, n, i, i+1);
			delay(3);
			system("cls");
		}
	}
	bargraph1(arr, n, -1, -1);
	delay(15);
	system("cls");
	menu();
}

void print_ArrayWithIndex(int arr[], int n, int pointer)
{
    for (int i = 0; i < n; i++)
    {
        printf("| %d ", arr[i]);
    }
    printf("|\n");
    for (int i = 0; i < n; i++)
    {
        printf("|___");
    }
    printf("|\n");
    for (int i = 0; i < n; i++)
    {
        printf("  %d ", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (i == pointer)
            printf("  ^ ");
        else
            printf("    ");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (i == pointer)
            printf("  | ");
        else
            printf("    ");
    }
    printf("\n");
}

void countingSort(int array[], int size) {
  printf("Original array\n");
  print_ArrayWithIndex(array,10,-1);
  printf("\n\n");
  int output[10];
  for (int i = 0; i < 10; i++)
    output[i]=0;

  // Find the largest element of the array
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // The size of count must be at least (max+1) but
  // we cannot declare it as int count(max+1) in C as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int count[10];

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }
  printf("Frequency array\n");
  print_ArrayWithIndex(count,10,-1);
  printf("\n\n");

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  printf(" Cummulative Frequency array\n");
  print_ArrayWithIndex(count,10,-1);
  printf("\n\n");

  delay(10);
  system("cls");

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {

    printf("Original array\n");
    print_ArrayWithIndex(array, size, i);
    printf("\n\nCummulative Frequency array\n");
    print_ArrayWithIndex(count, 10, array[i]);
    printf("\n\nOutput array\n");
    print_ArrayWithIndex(output, 10, count[array[i]]-1);
    delay(4);
    system("cls");

    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;

    printf("Original array\n");
    print_ArrayWithIndex(array, size, i);
    printf("\n\nCummulative Frequency array\n");
    print_ArrayWithIndex(count, 10, array[i]);
    printf("\n\nOutput array\n");
    print_ArrayWithIndex(output, 10, count[array[i]]);
    delay(4);
    system("cls");
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
  menu();
}

void merge_sort(int arr[],int low,int high)
{
  int mid;
  if(low<high)
  {
    mid=(low+high)/2;
   // Divide and Conquer
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
   // Combine
    merge(arr,low,mid,high);
  }
}

void merge(int arr[],int l,int m,int h)
{
  int arr1[10],arr2[10];  // Two temporary arrays to
                             //hold the two arrays to be merged
  int n1,n2,i,j,k;
  n1=m-l+1;
  n2=h-m;

  for(i=0;i<n1;i++)
    arr1[i]=arr[l+i];
  for(j=0;j<n2;j++)
    arr2[j]=arr[m+j+1];

  arr1[i]=9999;  // To mark the end of each temporary array
  arr2[j]=9999;

  i=0;j=0;
  for(k=l;k<=h;k++)  //process of combining two sorted arrays
  {
    if(arr1[i]<=arr2[j])
      arr[k]=arr1[i++];
    else
      arr[k]=arr2[j++];
  }
}

void merge_sort_visual(int arr[], int n)
{
    SetColor(3);
    printf("[ ");
    for (int i = 0; i < n; i++){
        if (arr[i] < 9998)
            printf("%d ",arr[i]);
    }
    printf("]\n");
    int count = n;
    for (int i = 0; i < log2(n); i++){
        printf("[ ");
        int temp = 0;
        for (int k = 0; k < n; k++){
            if (arr[k] < 9998)
                printf("%d",arr[k]);
            if (temp == (count-1)/2 && k != n-1){
                printf(" ] [ ");
                temp = 0;
                continue;
            }
            else
                printf(" ");
            temp++;
        }
        printf("]\n");
        count /= 2;
    }
    printf("\n");
    //================================
    SetColor(10);
    int flag, temp = 0, temp1 = 0;
    for (int i = 0; i < log2(n); i++){
        flag = pow(2,temp+1);
        temp++;
        for (int j = 0; j < n; j = j + flag){
            merge_sort(arr, j, j + flag - 1);
        }
        flag = pow(2,temp1+1);
        temp1++;
        int a = 1;
        printf("[ ");
        for (int j = 0; j < n; j++){
            if (arr[j] < 9998)
                printf("%d",arr[j]);
            if (a == flag && j != n-1){
                printf(" ] [ ");
                a = 1;
                continue;
            }
            else
                printf(" ");
            a++;
        }

        printf("]\n");
    }

    getchar();
    system("cls");
    SetColor(14);
    menu();
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void printSwapArray(int arr[], int size,int m)
{
	int i;
	printf("After swapping:\n");
	for (i = 0; i < size; i++){
            if(i==m||i==m+1){
                    //red();
                    SetColor(1);
                    printf("%d ", arr[i]);
            }
           else{
                   SetColor(14);
                   printf("%d ", arr[i]);
           }
	}

	printf("\n\n");
}
void printNotSwapArray(int arr[], int size,int m)
{
	int i;
	printf("Not swapped:\n");
	for (i = 0; i < size; i++){
            if(i==m||i==m+1){
                    //red();
                    SetColor(2);
                    printf("%d ", arr[i]);
            }
           else{
                   SetColor(14);
                   printf("%d ", arr[i]);
           }
	}

	printf("\n\n");
}

void printBeforeSwapArray(int arr[], int size,int m)
{
	int i;
	printf("Before swapping:\n");
	for (i = 0; i < size; i++){
            if(i==m||i==m+1){
                    //red();
                    SetColor(4);
                    printf("%d ", arr[i]);
            }
           else{
                   SetColor(14);
                   printf("%d ", arr[i]);
           }
	}

	printf("\n\n");
}
void printAfterIterationArray(int arr[], int size,int num)
{
	int i;
	printf("After %d Iteration:\n",num);
	for (i = 0; i < size; i++){
            if(i>=size-1-num){
                    //red();
                    SetColor(5);
                    printf("%d ", arr[i]);
            }
           else{
                   SetColor(14);
                   printf("%d ", arr[i]);
           }
	}

	printf("\n\n");
}
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{   //bool temp = true;
	int i, j;
	for (i = 0; i < n - 1; i++){

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++){
                printBeforeSwapArray(arr,n,j);
			if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                printSwapArray(arr,n,j);
               // temp = false;
			}
			else
			//if(temp == true)
			    printNotSwapArray(arr,n,j);
		}
    printAfterIterationArray(arr,n,i);
   }
}

/* Function to print an array */
void printArray1(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void exchange(int i, int j)
 {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
 }

void printArray2(int lower_bound, int upper_bound)
{
	int i;
	for (i = 0; i < size; i++){
      if (i == lower_bound)
        SetColor(3);
      printf("%d ",array[i]);
      if (i == upper_bound)
        SetColor(14);
	}
	printf("\n");
}

void sort(int lowerIndex, int heigherIndex)
 {
    SetColor(14);
    int i= lowerIndex;
    int j= heigherIndex;
    int piviot = array[(lowerIndex + ((heigherIndex-lowerIndex)/2))];
    printf("Pivot selected %d in array from %d to %d:\n",piviot,i,j);
    while (i<=j)
    {
        while (array[i]<piviot)
            i++;

        while (array[j]>piviot)
            j--;

        if(i<=j)
        {
            exchange(i,j);
            i++;
            j--;
        }
    }
    printArray2(lowerIndex,heigherIndex);
    if (lowerIndex<j)
        sort(lowerIndex,j);
    if (heigherIndex>i)
        sort(i,heigherIndex);
 }

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
        bargraph1(array,20,step,i);
        delay(1);
        system("cls");

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}

int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void print_ArrayWithIndex1(int arr[], int n, int pointer)
{
    for (int i = 0; i < n; i++)
    {
        printf("| %d ", arr[i]);
    }
    printf("|\n");
    for (int i = 0; i < n; i++)
    {
        printf("|____");
    }
    printf("|\n");
    for (int i = 0; i < n; i++)
    {
        printf("  %d  ", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (i == pointer)
            printf("  ^ ");
        else
            printf("    ");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (i == pointer)
            printf("  | ");
        else
            printf("    ");
    }
    printf("\n");
}




// Using counting sort to sort the elements in the basis of significant places
void countingSort1(int array[], int size, int place) {
    printf("Original array\n");
    print_ArrayWithIndex1(array,size,-1);
    //printArray(array,size);
    printf("\n\n");
    int output[size];
      for (int i = 0; i < size; i++){
        output[i]=0;
      }
    // int max = (array[0] / place) % 10;

    // for (int i = 1; i < size; i++) {
    //     if (((array[i] / place) % 10) > max) max = array[i];
    // }
    int count[10];

    for (int i = 0; i < 10; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;


    printf("Frequency array\n");
     print_ArrayWithIndex(count,10,-1);
    // printArray(count,10);
    printf("\n\n");

    // Calculate cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];


    printf(" Cummulative Frequency array\n");
    print_ArrayWithIndex(count,10,-1);
    //printArray(count,10);
    printf("\n\n");

    delay(10);
    system("cls");

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--) {
        printf("Original array\n");
        print_ArrayWithIndex1(array, size, i);
        //printArray(array,size);
        printf("\n\nCummulative Frequency array\n");
        print_ArrayWithIndex(count, 10, array[i]);
        //printArray(count,10);
        printf("\n\nOutput array\n");
        print_ArrayWithIndex1(output, 10, count[array[i]]-1);
        delay(4);
        system("cls");

        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
        printf("Original array\n");
         print_ArrayWithIndex1(array, size, i);
       // printArray(array,size);
        printf("\n\nCummulative Frequency array\n");
        print_ArrayWithIndex(count, 10, array[i]);
        //printArray(count,10);
        printf("\n\nOutput array\n");
        print_ArrayWithIndex1(output, 10, count[array[i]]-1);
        delay(4);
        system("cls");
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort1(array, size, place);


    getchar();
    menu();


}

void tree_from_array(int arr[], int n)
{
    int index = 0, num = 100;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < num; j++){
            printf(" ");
        }
        if (index >= n){
            break;
        }
        for (int k = 0; k < pow(2,i); k++){
            if (index >= n)
                break;
            printf("%d",arr[index]);
            index++;
            for (int l = 0; l < 2*num; l++){
                printf(" ");
            }
        }
        printf("\n");
        //---------------
        for (int j = 0; j < num/2; j++){
            printf(" ");
        }
        if (index >= n){
            break;
        }
        for (int k = 0; k < pow(2,i+1); k++){
            if (index >= n)
                break;
            printf(" ");
            //index++;
            for (int l = 0; l < num; l++){
                if (k%2 == 0){
                    if (l == num/2)
                        printf("|");
                    else
                        printf("_");
                }
                else
                    printf(" ");
            }
        }
        //---------------
        printf("\n");
        //---------------
        for (int j = 0; j < num/2; j++){
            printf(" ");
        }
        if (index >= n){
            break;
        }
        for (int k = 0; k < pow(2,i+1); k++){
            if (index >= n)
                break;
            printf("|");
            //index++;
            for (int l = 0; l < num; l++){
                printf(" ");
            }
        }
        //---------------
        num /= 2;
        printf("\n");
    }
}

void heapify(int arr[], int N, int i)
{
    // Find largest among root, left child and right child

    // Initialize largest as root
    int largest = i;


    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])

        largest = right;

    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{

    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--){
            tree_from_array(arr,N);
            delay(1);
            system("cls");
            //goto label;
        heapify(arr, N, i);
    }



    // Heap sort
    for (int i = N - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at
        // root again
            tree_from_array(arr,N);
            delay(1);
            system("cls");
           // goto label;
        heapify(arr, i, 0);
    }
}

void menu()
{
     char a[6]={'a','b','c'};
  int i,j,z,k,l;

  for(z=0;z>=0;z++)
  {
  if (kbhit())
    break;
  for(i=0;i<150;i=i+10)
  {
  if (kbhit())
  {
      i=150;
      break;
  }

  for(l=0;l<13;l++)
  {
        SetColor(13);
        if(a[l]=='a')
        {
        k=(l*10)+7;
        gotoxy(i,k);
        printf("  $$         $$  $$$$$$$$$$  $$         $$$$$$     $$$$$$    $$         $$  $$$$$$$$$$\n");
        gotoxy(i,k+1);
        printf("  $$   $$    $$  $$          $$       $$     $$  $$      $$  $$$$     $$$$  $$        \n");
        gotoxy(i,k+2);
        printf("  $$  $$ $$  $$  $$$$$$$$$$  $$       $$         $$      $$  $$  $$  $$ $$  $$$$$$$$$$\n");
        gotoxy(i,k+3);
        printf("  $$$$     $$$$  $$          $$       $$     $$  $$      $$  $$    $$   $$  $$        \n");
        gotoxy(i,k+4);
        printf("  $$         $$  $$$$$$$$$$  $$$$$$$$   $$$$$$     $$$$$$    $$         $$  $$$$$$$$$$\n");
        }


  }
  SetColor(10);
  printf("\n\n(1) Linear Search\n(2) Binary Search\n(3) Insertion Sort\n(4) Wave Sort\n(5) Count Sort\n(6) Merge Sort\n(7) Bubble Sort\n(8) Quick Sort\n(9) Selection Sort\n(*) Radix Sort\n(+) Heap Sort\n(0) Exit");
  SetColor(6);
  delay(1);
  system("CLS");

  }

  }

}

void thankyou()
{

  SetColor(76);
  char a[6]={'a','b','c'};
  int i,j,z,k,l;

  for(z=0;z>=0;z++)
  {
  if (kbhit())
    break;
  for(i=0;i<150;i=i+10)
  {
  if (kbhit())
  {
      i=150;
      break;
  }

  for(l=0;l<13;l++)
  {

        if(a[l]=='a')
        {
        k=(l*10)+7;
        gotoxy(i,k);
        printf("@@@@@@@@@@  @@     @@        @@       @@         @@   @@        @@\n");
        gotoxy(i,k+1);
        printf("@@@@@@@@@@  @@     @@      @@  @@     @@@@       @@   @@      @@\n");
        gotoxy(i,k+2);
        printf("    @@      @@     @@     @@    @@    @@ @@      @@   @@    @@\n");
        gotoxy(i,k+3);
        printf("    @@      @@     @@    @@      @@   @@  @@     @@   @@  @@\n");
        gotoxy(i,k+4);
        printf("    @@      @@@@@@@@@    @@@@@@@@@@   @@   @@    @@   @@@@\n");
        gotoxy(i,k+5);
        printf("    @@      @@@@@@@@@    @@      @@   @@    @@   @@   @@  @@\n");
        gotoxy(i,k+6);
        printf("    @@      @@     @@    @@      @@   @@      @@ @@   @@    @@\n");
        gotoxy(i,k+7);
        printf("    @@      @@     @@    @@      @@   @@       @@@@   @@      @@\n");
        gotoxy(i,k+8);
        printf("    @@      @@     @@    @@      @@   @@         @@   @@        @@\n");
        }


        if(a[l]=='b')

        {
          k=(l*10)+7;
          gotoxy(i,k);
          printf("        @@            @@    @@@@@@@@@    @@         @@\n");
          gotoxy(i,k+1);
          printf("          @@        @@     @@@@@@@@@@@   @@         @@\n");
          gotoxy(i,k+2);
          printf("           @@      @@     @@         @@  @@         @@\n");
          gotoxy(i,k+3);
          printf("            @@    @@      @@         @@  @@         @@\n");
          gotoxy(i,k+4);
          printf("             @@  @@       @@         @@  @@         @@\n");
          gotoxy(i,k+5);
          printf("               @@         @@         @@  @@         @@\n");
          gotoxy(i,k+6);
          printf("               @@         @@         @@  @@         @@\n");
          gotoxy(i,k+7);
          printf("               @@          @@@@@@@@@@@    @@@@@@@@@@@ \n");
          gotoxy(i,k+8);
          printf("               @@           @@@@@@@@@      @@@@@@@@@  \n");
        }

        if(a[l]=='c')

        {
          printf("\n\n\n\n\n\n\n\n\n\n                                                                                          PRESS ENTER TO CONTINUE\n");
        }


  }
  delay(1);
  system("CLS");

  }

}
}

void choice()
{
    switch(ch)
    {
    case '1':
        linear_search(arr1,20,8);
        break;
    case '2':
        binary_search(arr,20,0,19,18);
        break;
    case '3':
        InsertionSort(arr2,20);
        break;
    case '4':
        WaveSort(arr3, 20);
        break;
    case '5':
        countingSort(arr4, 10);
        break;
    case '6':
        merge_sort_visual(arr5,16);
        break;
    case '7':
        bubbleSort(arr6, 7);
        printf("Sorted array: \n");
        printArray1(arr6, 7);
        getchar();
        system("cls");
        menu();
        break;
    case '8':
        printArray2(-1,-1);
        sort(0, size - 1);
        printf("Sorted array: \n") ;
        printArray2(-1,-1);
        getchar();
        system("cls");
        menu();
        break;
    case '9':
        SetColor(6);
        selectionSort(arr1,20);
        bargraph1(arr1,20,0,19);
        SetColor(14);
        getchar();
        system("cls");
        menu();
        break;
    case '*':
        radixsort(arr8, 10);
        break;
    case '+':
        SetColor(6);
        heapSort(arr9,20);
        tree_from_array(arr9,20);
        SetColor(14);
        getchar();
        system("cls");
        menu();
        break;
    case '0':
        break;
    default:
        printf("Wrong Choice!");
        break;
    }
}


int main()
{
    SetColor(6);
    menu();
    while(ch!='0'){
        ch = getch();
        choice();
    }
    thankyou();
    return 0;
}
