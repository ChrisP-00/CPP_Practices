#include <iostream>
#include <vector>

using namespace std; 

// divide myArray until they can no longer divided 
// merge myArray into sorted subarray 

vector <int> myArray; 
vector <int> tempArray;

void merge(int start, int mid, int end)
{
    int tempIndex = 0;
    int startPoint = start; 
    int midPoint = mid + 1;

    while(startPoint <= mid && midPoint <= end) 
    {
        myArray[startPoint] <= myArray[midPoint] ? 
        tempArray[tempIndex++] = myArray[startPoint++] :
        tempArray[tempIndex++] = myArray[midPoint++];
    }

    // left subarray is remained 
    while (startPoint <= mid)
    {
        tempArray[tempIndex++] = myArray[startPoint++];
    }

    while (midPoint <= end)
    {
        tempArray[tempIndex++] = myArray[midPoint++];
    }

    startPoint = start; 
    midPoint = mid + 1;
    tempIndex = 0;

    while(startPoint <= end)
    {
        myArray[startPoint++] = tempArray[tempIndex++];
    }

    cout << '\n';

    // std::copy(tempArray.begin() + start, tempArray.begin() + end + 1, myArray.begin() + start);
}


void mergeSort(int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
}

int main()
{
    int input = 0; 
    int idx = 0;
    int size = 0;
    
    cin >> size; 

    // Resize vectors to the specified size
    myArray.resize(size);
    tempArray.resize(size);

    while(idx < size)
    {
        cin >> input;
        myArray[idx++] = input;
    }

    mergeSort(0, myArray.size() - 1);

    cout << "Merge Sort! : ";

    for(int idx = 0; idx < myArray.size(); idx++)
    {
        cout << myArray[idx] << ' ';
    }

    return 0;
}