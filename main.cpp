#include <iostream>
#include "StringData.h"
using namespace std;

//linear search implementation
int linearSearch(vector<string> words, string word)
{
    //check every element
    for (int i = 0; i < words.size(); i++)
    {
        //found element
        if (words[i] == word)
        {
            //return index
            return i;
        }
    }
    //didn't find element, return -1
    return -1;
}

//binary search implementation
int binarySearch(vector<string> words, string word)
{
    //initialize pointers
    int left = 0;
    int right = words.size() - 1;

    //stop once left > right (we didn't find anything)
    while (left <= right)
    {
        //mid point of remaining dataset
        int mid = (left + right) / 2;

        //found it
        if (words[mid] == word)
        {
            return mid;
        }
        //element in lower half
        else if (word < words[mid])
        {
            right = mid - 1;
        }
        //element in upper half
        else if (word > words[mid])
        {
            left = mid + 1;
        }
    }
    //didn't find it
    return -1;
}

//check time for linear search
void testLinearSearch(vector<string> words, string word)
{
    chrono::time_point startTime = chrono::system_clock::now();
    int index = linearSearch(words, word);
    chrono::time_point endTime = chrono::system_clock::now();

    chrono::duration<double> elapsedTime = endTime - startTime;

    if (index >= 0)
    {
        cout << "Found \"" << word << "\" at index " << index << " in " << elapsedTime.count() << " seconds with Linear Search" << endl;
    }
    else
    {
        cout << "Failed to find \"" << word << "\" at index " << index << " in " << elapsedTime.count() << " seconds with Linear Search" << endl;
    }
}

//check time for binary search
void testBinarySearch(vector<string> words, string word)
{
    chrono::time_point startTime = chrono::system_clock::now();
    int index = binarySearch(words, word);
    chrono::time_point endTime = chrono::system_clock::now();

    chrono::duration<double> elapsedTime = endTime - startTime;

    if (index >= 0)
    {
        cout << "Found \"" << word << "\" at index " << index << " in " << elapsedTime.count() << " seconds with Binary Search" << endl;
    }
    else
    {
        cout << "Failed to find \"" << word << "\" at index " << index << " in " << elapsedTime.count() << " seconds with Binary Search" << endl;
    }
}

//helper method for comparing methods
void compareSearches(vector<string> words, string word)
{
    testLinearSearch(words, word);
    testBinarySearch(words, word);
}

int main()
{
    vector<string> dataset = getStringData();

    compareSearches(dataset, "not_here");
    cout << "" << endl;
    compareSearches(dataset, "mzzzz");
    cout << "" << endl;
    compareSearches(dataset, "aaaaa");
    cout << "" << endl;

    return 0;
}
