// #include<stdio.h>
// int main(){
//     int a, b;
//     for(a = 1, b = 1; a <= 100; a++){
//         if(b >= 20)
//             break;
//         if(b % 3 == 1){
//             b = b + 3;
//             continue;
//         }
//         b = b - 5;
//     }
//     printf("%d\n" ,a);
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> res(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            res[i][j] = mat[j][i];
        }
    }

    cout << n << " " << m << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}