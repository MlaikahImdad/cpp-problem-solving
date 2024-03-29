#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = {10, 20, 20, 10, 10, 30, 50, 10, 20};
    int count = 0;

    sort(vec.begin(), vec.end()); // Sort the vector to group identical numbers together

    for (auto i = vec.begin(); i != vec.end(); ) {
        auto j = upper_bound(i, vec.end(), *i); // Find the upper bound of current element
        int freq = j - i; // Calculate frequency of current element
        count += freq / 2; // Add half of frequency to count (since each pair requires two elements)
        i = j; // Move iterator to the next distinct element
    }

    cout << "Number of pairs: " << count << endl;

    return 0; 
}
