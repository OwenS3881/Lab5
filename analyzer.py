#import needed modules
from stringdata import get_data
import time

#linear search implementation
def linear_search(container, element):
    #check every element in order
    for i in range(len(container)):
        #if element is the one we want..
        if element == container[i]:
            #return its index
            return i
    #didn't find element
    return -1

#implemnetation of binary search for sorted datasets
def binary_search(container, element):
    #initialize pointers
    left = 0
    right = len(container) - 1
    #stop once left > right (we didn't find anything)
    while left <= right:
        #mid point of remaining dataset
        mid = (left + right) // 2
        #found it
        if element == container[mid]:
            return mid
        #element in lower half
        elif element < container[mid]:
            right = mid - 1
        #element in upper half
        elif element > container[mid]:
            left = mid + 1
   #didnt find it
    return -1


#determine the time it takes for linear search
def test_linear_search(container, element):
    start_time = time.time()
    index = linear_search(container, element)
    end_time = time.time()

    diff = end_time - start_time

    if index >= 0:
        print(f"Found \"{element}\" at index {index} in {diff:.10f} seconds with Linear Search")
    else:
        print(f"Failed to find \"{element}\" at index {index} in {diff:.10f} seconds with Linear Search")

#determine the time it takes for binary search
def test_binary_search(container, element):
    start_time = time.time()
    index = binary_search(container, element)
    end_time = time.time()

    diff = end_time - start_time

    if index >= 0:
        print(f"Found \"{element}\" at index {index} in {diff:.10f} seconds with Binary Search")
    else:
        print(f"Failed to find \"{element}\" at index {index} in {diff:.10f} seconds with Binary Search")

#helper method to run both comparisons
def compare_searches(container, element):
    test_linear_search(container, element)
    test_binary_search(container, element)

def main():
    dataset = get_data()

    compare_searches(dataset, "not_here")
    print()
    compare_searches(dataset, "mzzzz")
    print()
    compare_searches(dataset, "aaaaa")
    print()


if __name__ == '__main__':
    main()



