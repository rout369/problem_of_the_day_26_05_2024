class Solution {
public:
    int M = 1E9 + 7;
    // int memo(int n , int ab , int con_late){
    //     //pruning case ;
    //     if(con_late >= 3 || ab >= 2){
    //         return 0;
    //     }

    //     // base case ..

    //     if(n == 0){
    //         return 1;
    //     }

    //     // all the possible

    //     if(t[n][ab][con_late] != -1){
    //         return t[n][ab][con_late];
    //     }

    //     int A = memo(n-1 , ab + 1 , 0) % M;
    //     int L = memo(n-1 , ab , con_late + 1) % M;
    //     int P = memo(n-1 , ab , 0) % M;

    //     return t[n][ab][con_late] = (((A + L) % M) + P) % M;
    // }

    int checkRecord(int n) {
        // memset(t , -1 , sizeof(t));
        // return memo(n , 0 , 0);
        int t[100001][2][3];
        // base case check
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 2; j++) {
                t[0][i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    long result = t[i - 1][j][0]; // P (Present)

                    if (k + 1 <= 2) {
                        result += t[i - 1][j][k + 1]; // L (Late)
                    }

                    if (j + 1 <= 1) {
                        result += t[i - 1][j + 1][0]; // A (Absent)
                    }

                    t[i][j][k] = result % M;
                }
            }
        }

        return t[n][0][0];
    }
};

// space complexity (in both memo and bottom): O(N);
// time complexity (in both memo and bottom ) : O(N);
