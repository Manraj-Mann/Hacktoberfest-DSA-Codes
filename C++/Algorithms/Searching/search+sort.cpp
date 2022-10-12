#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

// Function for operations
void linear_search(int *arr, int n);              // Linear Search
int binary_search(int *arr, int l, int r, int x); // Binary Search
void merge_sort(int arr[], int l, int r);         // Merge Sort
void insertion_sort(int *arr, int n);             // Insertion Sort
void bubble_sort(int *arr, int n);                // Bubble Sort
void selection_sort(int *arr, int n);             // Selection Sort
void heap_sort(int *arr, int n);                  // Heap Sort
void radix_sort(int *arr, int n);                 // Radix sort

// Function
void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    return mx;
}

// Function
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] =
            arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// Function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function
void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[q + 1 + j];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Main Function
int main()
{
    int n = 0;
    int c = 0;
    cout << "Number of elements in the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements of array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
start:
    system("cls");
    cout << "Array : ";
    print_array(arr, n);

    cout << "\n\n\n      Main Menu        " << endl;
    cout << "1 => Linear search in the array" << endl;
    cout << "2 => Binary search in the array" << endl;
    cout << "3 => Merge sort in the array" << endl;
    cout << "4 => Insertion sort in the array" << endl;
    cout << "5 => Bubble sort in the array" << endl;
    cout << "6 => Selection sort in the array" << endl;
    cout << "7 => Heap sort in the array" << endl;
    cout << "8 => Radix sort in the array" << endl;
    cout << "9 => Exit" << endl
         << endl;
    cout << "Enter choice : ";
    cin >> c;

    if (c == 1)
    {
        system("cls");
        cout << "Array : ";
        print_array(arr, n);
        cout << "\n\n\n      Linear Search       " << endl;
        linear_search(arr, n);
        cout << "Press any key to continue... " << endl;
        getch();
        goto start;
    }
    if (c == 2)
    {
        system("cls");
        cout << "Array : ";
        print_array(arr, n);
        cout << "\n\n\n      Binary Search       " << endl;
        int x;
        cout << "Element to be searched : ";
        cin >> x;
        int res = binary_search(arr, 0, n - 1, x);
        if (res == 1)
        {
            cout << "Element Found" << endl;
        }
        else if (res == -1)
        {
            cout << "Element Not Found" << endl;
        }
        cout << "Press any key to continue... " << endl;
        getch();
        goto start;
    }
    if (c == 3)
    {
        system("cls");
        cout << "Array : ";
        print_array(arr, n);
        cout << "\n\n\n      Merge Sort       " << endl;
        cout << "Before Sorting : ";
        print_array(arr, n);
        cout << "\nAfter Sorting : ";
        merge_sort(arr, 0, n - 1);
        print_array(arr, n);
        cout << "Press any key to continue... " << endl;
        getch();
        goto start;
    }
    if (c == 4)
    {
        system("cls");
        cout << "Array : ";
        print_array(arr, n);
        cout << "\n\n\n      Insertion Sort       " << endl;
        cout << "Before Sorting : ";
        print_array(arr, n);
        cout << "\nAfter Sorting : ";
        insertion_sort(arr, n);
        print_array(arr, n);
        cout << "Press any key to continue... " << endl;
        getch();
        goto start;
    }
    if (c == 5)
    {
        system("cls");
        cout << "Array : ";
        print_array(arr, n);
        cout << "\n\n\n      Bubble Sort       " << endl;
        cout << "Before Sorting : ";
        print_array(arr, n);
        cout << "\nAfter Sorting : ";
        bubble_sort(arr, n);
        print_array(arr, n);
        cout << "Press any key to continue... " << endl;
        getch();
        goto start;
    }
    if (c == 6)
    {
        system("cls");
        cout << "Array : ";
        print_array(arr, n);
        cout << "\n\n\n      Selection Sort       " << endl;
        cout << "Before Sorting : ";
        print_array(arr, n);
        cout << "\nAfter Sorting : ";
        selection_sort(arr, n);
        print_array(arr, n);
        cout << "Press any key to continue... " << endl;
        getch();
        goto start;
    }
    if (c == 7)
    {
        system("cls");
        cout << "Array : ";
        print_array(arr, n);
        cout << "\n\n\n      Heap Sort       " << endl;
        cout << "Before Sorting : ";
        print_array(arr, n);
        cout << "\nAfter Sorting : ";
        heap_sort(arr, n);
        print_array(arr, n);
        cout << "Press any key to continue... " << endl;
        getch();
        goto start;
    }
    if (c == 8)
    {
        system("cls");
        cout << "Array : ";
        print_array(arr, n);
        cout << "\n\n\n      Radix Sort       " << endl;
        cout << "Before Sorting : ";
        print_array(arr, n);
        cout << "\nAfter Sorting : ";
        radix_sort(arr, n);
        print_array(arr, n);
        cout << "Press any key to continue... " << endl;
        getch();
        goto start;
    }
    if (c == 9)
    {
        system("cls");
        cout << "Closing Application................" << endl;
        getch();
        exit(0);
    }
    return 0;
}

// Linear Search
void linear_search(int *arr, int n)
{
    int t;
    int m;
    cout << "Enter the element to be searched : ";
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == m)
        {
            // cout<<"Found at "<<i<<endl;
            t = 1;
            break;
        }
        else
        {
            // cout<<"Not Found";
            t = 0;
        }
    }
    if (t == 1)
    {
        cout << "Element Found\n";
    }
    else
    {
        cout << "Not Found";
    }
}

// Binary Search
int binary_search(int *arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return binary_search(arr, l, mid - 1, x);
        }
        return binary_search(arr, mid + 1, r, x);
    }
    return -1;
}

// Merge Sort
void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Insertion Sort
void insertion_sort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort
void bubble_sort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selection_sort(int *arr, int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Heap Sort
void heap_sort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Radix sort
void radix_sort(int *arr, int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}
// End of Program