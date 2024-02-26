#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// FIRST METHOD USING ARRAYS
int main() {
    int n, q, size;
    cin >> n >> q;
    int **array_ = new int*[n];
    for (int a = 0; a < n; a++) {
        cin >> size;
        array_[a] = new int[size];
        for (int iter = 0; iter < size; iter++) {
            cin >> array_[a][iter];
        }
    }
    int arrno[q], elem[q];
    for (int q2 = 0; q2 < q; q2++) {
        cin >> arrno[q2] >> elem[q2];
    }
    for(int ans = 0; ans < q; ans++) {
        cout << array_[arrno[ans]][elem[ans]] << endl;
    }
    for(int i=0; i<n; i++) {
        delete [] array_[i];
    }
    delete [] array_;
    
    return 0;
}

// SECOND METHOD USING VECTORS


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, q;
    cin >> n >> q;
    vector<vector<int>> data;
    vector<int> row_data;
    int input;
    for(int counter = 0; counter < n; counter++){
        int i;
        cin >> i; 
        row_data.clear();
        for(int counter2 = 0; counter2 < i; counter2++){
            cin >> input;
            row_data.push_back(input);
        }
        data.push_back(row_data);
    }
    
    int row, column;
    for(int counter = 0; counter < q; counter++){
        cin >> row >> column;
        cout << data[row][column] << "\n";
    }
    
    return 0;
}