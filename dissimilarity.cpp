#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cout << "Enter the size of matrix :";
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<double>> matrix(n,vector<double>(n,0));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j)
                continue;
            double sum = 0;
            for (int k = 0; k < m; k++){
                sum += pow(arr[i][k] - arr[j][k], 2);
            }
            matrix[i][j] = sqrt(sum);
        }
    }
    cout << "Through Euclidean distance" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> matrix2(n,vector<int>(n,0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j)
                continue;
            int sum = 0;
            for(int k = 0; k < m; k++){
                matrix2[i][j] += abs(arr[i][k] - arr[j][k]);
            }
        }
    }
    cout << "Through Manhattan distance" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
