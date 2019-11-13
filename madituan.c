#include <stdio.h>

#define MAXM 5
#define MAXN 5

int map[MAXM][MAXN];
FILE *fout;

void init_map() { // khởi tạo tất cả giá trị của map bằng 0
    for(int m = 0; m < MAXM; m++) {
        for(int n = 0; n < MAXN; n++) {
            map[m][n] = 0;
        }
    }
}

void print_map() {
    for(int m = 0; m < MAXM; m++) {
        for(int n = 0; n < MAXN; n++) {
            fprintf(fout, "%2d ", map[m][n]);
        }
        fprintf(fout, "\n");
    }
    fprintf(fout, "\n");
}

void init_way_variables(int m, int n, int list_m[8], int list_n[8]) {
    list_m[0] = m-2;
    list_n[0] = n-1;

    list_m[1] = m-2;
    list_n[1] = n+1;

    list_m[2] = m-1;
    list_n[2] = n+2;

    list_m[3] = m+1;
    list_n[3] = n+2;

    list_m[4] = m+2;
    list_n[4] = n+1;

    list_m[5] = m+2;
    list_n[5] = n-1;

    list_m[6] = m+1;
    list_n[6] = n-2;

    list_m[7] = m-1;
    list_n[7] = n-2;
}

int in_map(int m, int n) {
    if (m >= 0 && m < MAXM && n >= 0 && n < MAXN) return 1;
    return 0;
}

void quaylui(int k, int m, int n) {
    int list_m[8];
    int list_n[8];
    init_way_variables(m, n, list_m, list_n);
    for (int i = 0; i < 8; i++) {
        if (in_map(list_m[i], list_n[i]) && map[list_m[i]][list_n[i]] == 0) {
            map[list_m[i]][list_n[i]] = k;
            //printf("%d\n", k);
            if (k == MAXM * MAXN) {
                print_map();
                printf(".\n");
            }
            else {
                quaylui(k+1, list_m[i], list_n[i]);
            }
            map[list_m[i]][list_n[i]] = 0;
        }
    }
    
}

int main() {
    fout = fopen("output.txt", "w");
    init_map();
    map[0][0] = 1;
    quaylui(2, 0, 0);
    print_map();
}