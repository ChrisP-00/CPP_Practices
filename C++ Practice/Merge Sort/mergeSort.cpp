#include <iostream>
#include <vector>

using namespace std; 

// divide arrays until they can no longer divided 
// merge arrays into sorted subarray 

vector <int> arrays; 
vector <int> sortedArrays;

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int sortedIndex = start;

    int startPoint = start; 
    int midPoint = mid + 1;

    while(startPoint <= mid && midPoint <= end) 
    {
        arrays[startPoint] <= arrays[midPoint] ? 
        sortedArrays[sortedIndex++] = arrays[startPoint++] :
        sortedArrays[sortedIndex++] = arrays[midPoint++];
    }

    // left subarray is remained 
    while (startPoint <= mid)
    {
        sortedArrays[sortedIndex++] = arrays[startPoint++];
    }

    while (midPoint <= end)
    {
        sortedArrays[sortedIndex++] = arrays[midPoint++];
    }

    startPoint = start; 

    std::copy(sortedArrays.begin() + start, sortedArrays.begin() + end + 1, arrays.begin() + start);
}


void mergeSort(int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, end);
    }
}

int main()
{
    int input = 0; 
    int idx = 0;
    int size = 0;
    
    cin >> size; 

    while(idx < size)
    {
        cin >> input;
        arrays[idx++] = input;
    }

    mergeSort(0, arrays.size() - 1);

    cout << "Merge Sort! : ";

    for(int idx = 0; idx < arrays.size(); idx++)
    {
        cout << arrays[idx] << ' ';
    }

    return 0;
}