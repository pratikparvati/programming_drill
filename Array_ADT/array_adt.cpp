#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>
#include <string>

struct array
{
    int arr[20];
    int size;
    int length;
};

void append(struct array* ar, int x)
{
    if(ar->length < ar->size)
    {
        ar->arr[ar->length++] = x;
    }
}

void insert(struct array* ar, int idx, int x)
{
    if(ar->length >= ar->size)
    {
        return;
    }
    for(int i = ar->length; i > idx; i--)
    {
        ar->arr[i] = ar->arr[i-1];
    }
    ar->arr[idx] = x;
    ar->length++;
}

void delete_ele(struct array* ar, int idx)
{
    if(idx < 0 && idx > ar->size)
    {
        return;
    }
    for(int i = idx; i < ar->length; i++)
    {
        ar->arr[i] = ar->arr[i+1];
    }
    ar->length--;
}

int linear_search(struct array* ar, int x) // O(n)
{
    for(int i = 0; i < ar->length; i++)
    {
        if(x == ar->arr[i])
            return i;
    }
    return -1;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *b = *a;
    *b = temp;
}

/**
 * linear search by transposition (optimize linear search)
 * if the element is searched frequently, it is left shifted by one position
 */
int linear_search_trans(struct array* ar, int x)
{
    for(int i = 0; i < ar->length; i++)
    {
        if(x == ar->arr[i])
        {
            swap(&ar->arr[i], &ar->arr[i-1]);
            return i-1;
        }
    }
    return -1;
}


/**
 * formula for binary search
 * m = (l+h)/2
 * l = m + 1;
 * h = m - 1;
 * if(l > h) no ele found
 * if(array[m] == key) ele found
 */
int binary_search(struct array* ar, int x) // O(log n)
{
    int l = 0;
    int h = ar->length - 1;
    int m = (l+h)/2;
    while(l <= h)
    {
        if(ar->arr[m] == x)
        {
            return m;
        }
        else if(ar->arr[m] > x)
        {
            h = m - 1;
        }
        else if(ar->arr[m] < x)
        {
            l = m + 1;
        }
        m = (l+h)/2;
    }
    return -1;
}

int recursive_binary_search(int a[], int l, int h, int x)
{
    int m;
    if(l<=h)
    {
        m = (l+h)/2;
        if(a[m] == x)
        {
            return m;
        }
        else if(a[m] > x)
        {
            return recursive_binary_search(a, l, m-1, x);
        }
        else if(a[m] < x)
        {
            return recursive_binary_search(a, m+1, h, x);
        }
    }
    return -1;
}

int get(struct array* ar, int idx)
{
    if(idx <= 0 && idx >= ar->length) return -1;
    return ar->arr[idx];
}

int set(struct array* ar, int idx, int x)
{
    if(idx <= 0 && idx >= ar->length) return -1;
    ar->arr[idx] = x;
    return 1;
}

int max(struct array* ar)
{
    int m = ar->arr[0];
    for(int i = 0; i < ar->length; i++)
    {
        if(ar->arr[i] > m)
            m = ar->arr[i];
    }
    return m;
}

int min(struct array* ar)
{
    int m = ar->arr[0];
    for(int i = 0; i < ar->length; i++)
    {
        if(ar->arr[i] < m)
            m = ar->arr[i];
    }
    return m;
}

int sum(struct array* ar)
{
    int s = 0;
    for(int i = 0; i < ar->length; i++)
    {
        s+= ar->arr[i];
    }
    return s;
}

float avg(struct array* ar)
{
    int s = 0;
    for(int i = 0; i < ar->length; i++)
    {
        s+= ar->arr[i];
    }
    return (float)s/ar->length;
}

void reverse(struct array *ar)
{
     for(int i = 0, j = ar->length - 1; i<j; i++, j-- )
     {
         int temp = ar->arr[i];
         ar->arr[i] = ar->arr[j];
         ar->arr[j] = temp;
     }
}

void left_shift(struct array *ar)
{
    for(int i = 0; i < ar->length; i++)
    {
        ar->arr[i] = ar->arr[i+1];
    }
    ar->arr[ar->length - 1] = 0;
}

void right_shift(struct array *ar)
{
    for(int i = ar->length -1; i >= 0; i--)
    {
        ar->arr[i] = ar->arr[i-1];
    }
    ar->arr[0] = 0;
}

void left_rotate(struct array *ar)
{
    int temp = ar->arr[0];
    for(int i = 0; i < ar->length; i++)
    {
        ar->arr[i] = ar->arr[i+1];
    }
    ar->arr[ar->length - 1] = temp;
}

void right_rotate(struct array *ar)
{
    int temp = ar->arr[ar->length - 1];
    for(int i = ar->length -1; i >= 0; i--)
    {
        ar->arr[i] = ar->arr[i-1];
    }
    ar->arr[0] = temp;
}

bool is_sorted(struct array* ar)
{
    for(int i = 0; i < ar->length - 1; i++)
    {
        if(ar->arr[i] > ar->arr[i+1])
            return false;
    }
    return true;
}

// insert the element maintaining the sorted array
void insertSort(struct array* ar, int x)
{
    if(ar->length == ar->size) return;
    for(int i = 0; i < ar->length; i++)
    {
        if(ar->arr[i] < x)
        {
            continue;
        }
        else
        {
            insert(ar, i, x);
            break;
        }
    }
}

struct array merge_array(struct array* ar1, struct array* ar2)
{
    struct array t_arr;
    int i,j,k;
    i=j=k=0;
    while((i < ar1->length) && (j < ar2->length))
    {
        if(ar1->arr[i] < ar2->arr[j])
        {
            t_arr.arr[k++] = ar1->arr[i++];
        }
        else
        {
            t_arr.arr[k++] = ar2->arr[j++];
        }
    }
    for(;i < ar1->length; i++)
       t_arr.arr[k++] =  ar1->arr[i];
    for(;j < ar2->length; j++)
       t_arr.arr[k++] =  ar2->arr[j];
    
    t_arr.length = ar1->length + ar2->length;
    t_arr.size = 20;
    return t_arr;
}

// set operations
struct array union_array(struct array* ar1, struct array* ar2)
{
    struct array t_arr;
    int i,j,k;
    i=j=k=0;
    while((i < ar1->length) && (j < ar2->length))
    {
        if(ar1->arr[i] < ar2->arr[j])
        {
            t_arr.arr[k++] = ar1->arr[i++];
        }
        else if(ar1->arr[i] == ar2->arr[j])
        {
            t_arr.arr[k++] = ar2->arr[j++];
            i++;
        }
        else
        {
            t_arr.arr[k++] = ar2->arr[j++];
        }
    }
    for(;i < ar1->length; i++)
       t_arr.arr[k++] =  ar1->arr[i];
    for(;j < ar2->length; j++)
       t_arr.arr[k++] =  ar2->arr[j];
    
    t_arr.length = k;
    t_arr.size = 20;
    return t_arr;
}

struct array intersection_array(struct array* ar1, struct array* ar2)
{
    struct array t_arr;
    int i,j,k;
    i=j=k=0;
    while((i < ar1->length) && (j < ar2->length))
    {
        if(ar1->arr[i] < ar2->arr[j])
        {
            i++;
        }
        else if(ar1->arr[i] > ar2->arr[j])
        {
            j++;
        }
        else
        {
            t_arr.arr[k++] = ar1->arr[i++];
        }
    }
    t_arr.length = k;
    t_arr.size = 20;
    return t_arr;
}

// elements in ar1 but not in ar2
struct array difference_array(struct array* ar1, struct array* ar2)
{
    struct array t_arr;
    int i,j,k;
    i=j=k=0;
    while((i < ar1->length) && (j < ar2->length))
    {
        if(ar1->arr[i] < ar2->arr[j])
        {
            t_arr.arr[k++] = ar1->arr[i++];
        }
        else if(ar1->arr[i] > ar2->arr[j])
        {
            j++;
        }
        else if(ar1->arr[i] == ar2->arr[j])
        {
            i++;j++;
        }
    }
    for(;i < ar1->length; i++)
       t_arr.arr[k++] =  ar1->arr[i];
    
    t_arr.length = k;
    t_arr.size = 20;
    return t_arr;
}

void display(struct array* ar)
{
    for(int i = 0; i < ar->length; i++)
        std::cout << ar->arr[i] << ' ';
    std::cout << '\n';
}

int main()
{
    struct array a = {{1,2,3,4,5,6,6}, 20, 7};

    std::cout << "array:"; display(&a);
    append(&a, 7); std::cout << "append: "; display(&a);
    insert(&a, 5, 8); std::cout << "insert: "; display(&a);
    delete_ele(&a, 2); std::cout << "delete: "; display(&a);
    // Linear search
    if(linear_search(&a, 7) != -1) 
        std::cout << "linear: 7 found\n"; 
    else 
        std::cout << "linear: 7 not found\n";
    if(linear_search(&a, 10) != -1)
         std::cout << "linear: 10 found\n";
    else 
        std::cout << "linear: 10  not found\n";

    // binary search
    if(recursive_binary_search(a.arr, 0, a.length - 1, 7) != -1) 
        std::cout << "binary: 7 found\n"; 
    else 
        std::cout << "binary:7 not found\n";
    if(recursive_binary_search(a.arr, 0, a.length - 1, 10) != -1)
         std::cout << "binary: 10 found\n";
    else 
        std::cout << "binary: 10 not found\n";

    std::cout << "get: " << get(&a, 3) << '\n';
    std::cout << "set: "; set(&a, 3, 9); display(&a);
    std::cout << "max: " << max(&a) << '\n';
    std::cout << "min: " << min(&a) << '\n';
    std::cout << "sum: " << sum(&a) << '\n';
    std::cout << "avg: " << avg(&a) << '\n';
    std::cout << "reverse: "; reverse(&a); display(&a);
    std::cout << "left shift: "; left_shift(&a); display(&a);
    std::cout << "right shift: "; right_shift(&a); display(&a);
    set(&a, 0, 5); std::cout << "set idx 0: "; display(&a);
    std::cout << "left rotate: "; left_rotate(&a); display(&a);
    std::cout << "right rotate: "; right_rotate(&a); display(&a);
    std::cout << "is sorted: " << (is_sorted(&a)? "yes\n": "no\n");
    std::cout << "sorting the array:"; std::sort(a.arr, a.arr + a.length); display(&a);
    std::cout << "is sorted: " << (is_sorted(&a)? "yes\n": "no\n");
    std::cout << "insert sort: "; insertSort(&a, 7); display(&a);
    struct array a1 = {{4,7,9,10,14,23}, 20, 6}; std::cout << "array a1: "; display(&a1);
    struct array res = merge_array(&a,  &a1); std::cout << "merge a and a1: "; display(&res);
    res = union_array(&a,  &a1); std::cout << "union a and a1: "; display(&res);
    res = intersection_array(&a,  &a1); std::cout << "intersection a and a1: "; display(&res);
    res = difference_array(&a,  &a1); std::cout << "difference a and a1: "; display(&res);
}


