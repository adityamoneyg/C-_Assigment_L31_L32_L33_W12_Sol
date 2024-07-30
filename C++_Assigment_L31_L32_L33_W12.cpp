#include<iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] > R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main(){
    int arr[] = {5, 3, 4, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

//                                     2 Solution

#include <vector>
#include <iostream>

int mergeSortAndCount(std::vector<int>& nums, int left, int right);
int mergeAndCount(std::vector<int>& nums, int left, int mid, int right);

int reversePairs(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    return mergeSortAndCount(nums, 0, nums.size() - 1);
}

int mergeSortAndCount(std::vector<int>& nums, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    int count = mergeSortAndCount(nums, left, mid) + mergeSortAndCount(nums, mid + 1, right);
    count += mergeAndCount(nums, left, mid, right);
    return count;
}
int mergeAndCount(std::vector<int>& nums, int left, int mid, int right) {
    int count = 0;
    int j = mid + 1;

    for (int i = left; i <= mid; ++i) {
        while (j <= right && nums[i] > 2LL * nums[j]) {
            ++j;
        }
        count += j - (mid + 1);
    }
    std::vector<int> sorted(right - left + 1);
    int i = left, k = mid + 1, pos = 0;
    while (i <= mid && k <= right) {
        if (nums[i] <= nums[k]) {
            sorted[pos++] = nums[i++];
        } else {
            sorted[pos++] = nums[k++];
        }
    }
    while (i <= mid) {
        sorted[pos++] = nums[i++];
    }
    while (k <= right) {
        sorted[pos++] = nums[k++];
    }
    for (int i = 0; i < sorted.size(); ++i) {
        nums[left + i] = sorted[i];
    }
    return count;
}

int main() {
    std::vector<int> nums = {1, 3, 2, 3, 1};
    std::cout << "Number of reverse pairs: " << reversePairs(nums) << std::endl;
    return 0;
}


//                                   Assignment :- 2

//        1 Solution :-  (c) option correct

//        2 Solution :-  (b) option correct

//        3 Solution :-

#include <iostream>
#include <vector>

void sortSwappedElements(std::vector<int>& arr) {
    int n = arr.size();
    int first = -1, second = -1;

    // Find the first misplaced element
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            first = i;
            break;
        }
    }

    // Find the second misplaced element
    for (int i = n - 1; i > 0; --i) {
        if (arr[i] < arr[i - 1]) {
            second = i;
            break;
        }
    }

    // Swap the two elements
    if (first != -1 && second != -1) {
        std::swap(arr[first], arr[second]);
    }
}

int main() {
    std::vector<int> arr = {3, 8, 6, 7, 5, 9, 10};
    sortSwappedElements(arr);
    
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}


//                                      Assignment :- 3

//            1 Solution :-  (d) is correct option

//            2 Solution

#include <iostream>
#include <vector>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    int duplicate = -1, missing = -1;
    // Step 1: Identify the duplicate number
    for (int i = 0; i < n; ++i) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) {
            duplicate = abs(nums[i]);
        } else {
            nums[index] = -nums[index];
        }
    }
    // Step 2: Identify the missing number
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            missing = i + 1;
        }
    }
    return {duplicate, missing};
}
int main() {
    vector<int> nums = {1, 2, 2, 4};
    vector<int> result = findErrorNums(nums);
    cout << "Duplicate: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}


//                                 3 Solution

#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) {
            result.push_back(abs(nums[i]));
        } else {
            nums[index] = -nums[index];
        }
    }
    return result;
}
int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> duplicates = findDuplicates(nums);
    cout << "Duplicates: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
