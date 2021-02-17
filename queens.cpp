/*xep n quan hau vao ban co vua nXn */
#include<bits/stdc++.h>

using namespace std;

int n;
int x[10]; //mang chua gia tri cot cua quan hau thoa man
bool a[100], b[100], c[100]; //mang boolean cua chieu doc va 2 duong cheo TB-DN, DB-TN

void printResult() { //in ket qua

    for (int i = 1; i <= n - 1;++i) {
        cout << "(" << i << "," << x[i] << "), ";
    }
    cout <<"("<<n<<","<<x[n]<<")\n";
    return;
}

void trySolve(int i) {
    for (int j = 1; j <= n;++j) {
        if((a[j] == true) && (b[i+j] == true) && (c[i-j] == true)) {//kiem tra vi tri 
            x[i] = j;
                if(i==n) {
                    printResult();
                }
                else {
                    a[j] = false;
                    b[i + j] = false;
                    c[i - j] = false;
                    trySolve(i + 1);
                    a[j] = true;
                    b[i + j] = true;
                    c[i - j] = true;
                }
        } 
        
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n;++i) {
        a[i] = true;
    }
    for (int i = 2; i <= 2 * n; ++i) {
        b[i] = true;
    }
    for (int i = (1 - n); i <= (n - 1);++i) {
        c[i] = true;
    }
    cout<<"Cac cach xep"<<n<<" quan Hau la:\n";
    trySolve(1);

    return 0;
}
