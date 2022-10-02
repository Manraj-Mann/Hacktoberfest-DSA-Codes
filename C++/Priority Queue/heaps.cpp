#include <iostream>
using namespace std;

struct heap
{
    int *arr; // to store the elements of the heap
    int count;  // to maintain the count that how many heap elements are filled
    int capacity; // ro check the capapcity of heap
    int heap_type; // additional to signify weather min heap or max haeap ( amx heap in our code)
};

heap *create(int cap, int type) // Create heap make an array of size cap and set type s
{

    heap *h = new heap;  // allocate a struct to pointer h 

    if (h == NULL)  // if we fail to allocate memory then return 
    {
        cout << "Memory error\n";
        return NULL;
    }

    h->heap_type = type;  // setting type 
    h->count = 0;       // setting count = 0 as no elements are there
    h->capacity = cap;   // setting capacity  = cap 
    h->arr = new int[h->capacity];   // making array of size cap

    if (h->arr == NULL)  // if we fail to allocate the array memory
    {
        cout << "Memory error\n";
        return NULL;
    }

    return h;  // retuening pointer h of struct heap type 
}

int parent(heap *h, int i)  // to find parent of element 
{

    if (i <= 0 || i >= h->count)  // if i is 0 the it cant have parent and also more then count means that elelmnts are not filled yet so the are invalid 
    {
        return -1;
    }

    return (i - 1) / 2; // parent of i = ( i-1 ) / 2
}

int leftchild(heap *h, int i)
{

    int left = 2 * i + 1; // calculating left

    if (left >= h->count) // if left is not allocated yet the we return -1
    {
        return -1;
    }
    return left;
}
int rightchild(heap *h, int i)
{

    int right = 2 * i + 2; //  calculating right

    if (right >= h->count) // if left is not allocated yet the we return -1
    {
        return -1;
    }

    return right;
}

int getmax(heap *h)   // returning top element 
{

    if (h->count == 0)
    {
        return -1;
    }

    return h->arr[0];
}

void percolatedown(heap *h, int i)   // this function will take element down to its correct position
{

    int l, r, max = i, temp;   // setting max = i which means we the assuming up the elemrnt which we want to step down as max and if we will find any of its child as
                             // greater then parent we will step make that child parent and make this eleemrent as child

    l = leftchild(h, i); 
    r = rightchild(h, i);

    if (l != -1)
    {

        if (h->arr[l] > h->arr[i]) // if left child exist and its greater then current element set max - left child
        {
            max = l;
        }
    }

    if (r != -1)
    {

        if (h->arr[r] > h->arr[max]) // if right child exist and its greater then current  max  which can either be left or i depending on previos i then we set max = r
        {
            max = r;
        }
    }

    if (max != i) /// if i is not max this implies that its position is wrong and we have to swap the element with its max child
    {
        temp = h->arr[i];              // swaping 
        h->arr[i] = h->arr[max];
        h->arr[max] = temp;
        percolatedown(h, max);         // checking that weather the new postion of our element of correct or not by again calling dtep down for it 
    }
}

int deletemax(heap *h)   // delete the maximum element or topmost element
{

    int data;
    if (h->count == 0)   // 
    {
        return -1;
    }

    data = h->arr[0];                   // recording the top element 
    h->arr[0] = h->arr[h->count - 1];  // making the last element as top element 
    h->count--;                       // decrementing the size as we removed one element 

    percolatedown(h, 0); // percolating the the new top to down to its correct but this will benefit beacause as we try to find the correct position of this top
                        // we will keep on pushing up the elements to their correct postions 

    return data;
}

void resizeheap(heap *h)   // resize the heap if the heap if already fully filled , implements the concept dynamic array
{

    int *arr_old = h->arr;   // storing old array in arr_old

    h->arr = new int[2 * h->capacity];  // allocating new array of 2 x previous capacity  

    if (h->arr == NULL)  // if we fail to allocate resources
    {
        cout << "Memory error\n";
        return;
    }

    for (int i = 0; i < h->capacity; i++)    // setting the elements of old array in new array 
    {
        h->arr[i] = arr_old[i];
    }

    h->capacity *= 2;    // setting up new capacity 

    delete[] arr_old;   // freeing the memory of old memory
}

int insert(heap *h, int data)   
{

    int i;

    if (h->count == h->capacity)  // if array is fully filled already resize the array to doubel of its size
    {
        resizeheap(h);
    }

    h->count++;  // incrementing coount 

    i = h->count - 1;  // index where element is to be inserted 

    while (i > 0 && data > h->arr[(i - 1) / 2])  // while we donot find the correct poisiton of the element we climb up as (i-1)/2 gives parent of i                                             
    {                                           // if the parent is less the parent should move down and new elemnent shoild climb up till this condition not fails
        h->arr[i] = h->arr[(i - 1) / 2];   // making parent to step down 
        i = (i - 1) / 2;                   // moving new element up using i = parent of i 

    }

    // after the complete execution of the whole loop i is the correct position of the new element so we can now set it in array 

    h->arr[i] = data;      
}

void destory_heap(heap *h)  // destry the heap
{

    if (h == NULL)
    {
        return;
    }
    delete[] h->arr; // free array memory 

    h = NULL;
}

void buildheap(heap *h, int a[], int n)
{

    if (h == NULL)  // if heap is not created yet
    {
        return;
    }

    while (n > h->capacity)  // if array size is more then heap capacity then increase heap size
    {
        resizeheap(h);   // resize 
    }

    for (int i = 0; i < n; i++)  // setting the array elemrnts from given array and incrementing count
    {
        h->arr[i] = a[i]; 
        h->count++;
    }

    for (int i = (n - 1) / 2; i >= 0; i--) // its known the it takes n-1/2 iteration of perlocate down to make a array into heap 
    {
        percolatedown(h, i);
    }
}

void printheap(heap *h)   // print heap
{

    for (int i = 0; i < h->count; i++)
    {
        cout << h->arr[i] << " ";
    }
    cout << "\n";
}

int main()
{

    heap *h = create(6, 1);

    insert(h, 3);
    insert(h, 6);
    insert(h, 7);
    insert(h, 1);
    insert(h, 2);
    insert(h, 4);

    printheap(h);

    cout << getmax(h) << "\n";

    deletemax(h);

    printheap(h);

    int arr[] = { 2, 5, 6,7 ,3, 9 , 1 };

    heap * h2;

    h2 = create(3 , 1);


    buildheap(h2 , arr , 7 );

    printheap(h2);

    return 0;
}