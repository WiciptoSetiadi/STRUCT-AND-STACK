#include <stdio.h>

int twoStacks(int maxSum, int a[], int n, int b[], int m) {
    int maxScore = 0, score = 0;
    int i = 0, j = 0;
    // Hitung berapa banyak elemen dari stack a yang dapat diambil tanpa melampaui maxSum
    while (i < n && score + a[i] <= maxSum) {
        score += a[i];
        i++;
    }
    maxScore = i;
    // Iterasi melalui stack b dan tambahkan elemen ke skor sambil memeriksa batasan maxSum
    while (j < m && i >= 0) {
        score += b[j];
        j++;
        // Kurangi elemen dari stack a jika diperlukan agar tidak melampaui maxSum
        while (score > maxSum && i > 0) {
            i--;
            score -= a[i];
        }
        // Perbarui maxScore jika diperlukan
        if (score <= maxSum && i + j > maxScore) {
            maxScore = i + j;
        }
    }
    return maxScore;
}

int main() {
    int g;
    scanf("%d", &g);
    while (g--) {
        int n, m, maxSum;
        scanf("%d %d %d", &n, &m, &maxSum);
        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        int result = twoStacks(maxSum, a, n, b, m);
        printf("%d\n", result);
    }
    return 0;
}
