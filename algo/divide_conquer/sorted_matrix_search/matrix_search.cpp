/*C++ program to perform linear search on a Matrix in log(n) time.
 * 
 */
#include <bits/stdc++.h>

using namespace std;

pair<int, int> matrixSearch(int M[4][4], int key);

int main(){
    int M[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50}};
    int key = 48;
    pair<int, int> location = matrixSearch(M, key);
    
    if(location.first == -1 || location.second == -1)
        cout<<"Number not found\n";
    else
        cout<<key<<" is present at index ("<<location.first<<","<<location.second<<")\n";
}

pair<int, int> matrixSearch(int M[4][4], int key){
    if(key < M[0][0] || key > M[3][3])  // if the key is out of matrix element range, return not found 
        return make_pair(-1,-1);
    int i=0, j=3;
    
    while(i<4 && i>-1 && j<4 && j>-1){ // search within the valid range inside matrix
        if(M[i][j] == key)
            return make_pair(i,j);
        else if(key > M[i][j])      // if key is greater than the current element search in the next row
            i++;
        else if(key < M[i][j])      // if key is smaller than the current element search in the previous column
            j--;
    }
    return make_pair(-1,-1);
}