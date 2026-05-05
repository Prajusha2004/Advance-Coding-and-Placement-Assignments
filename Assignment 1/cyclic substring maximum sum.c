#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    char s[200005];
    scanf("%s", s);

    int n = strlen(s);

    char temp[400010];
    strcpy(temp, s);
    strcat(temp, s); // cyclic handling

    int visited[26] = {0};
    int left = 0, sum = 0, ans = 0;

    for (int right = 0; right < 2*n; right++) {

        int idx = temp[right] - 'a';

        while (visited[idx] == 1) {
            int lidx = temp[left] - 'a';
            visited[lidx] = 0;
            sum -= (lidx + 1);
            left++;
        }

        visited[idx] = 1;
        sum += (idx + 1);

        // window size should not exceed n
        if (right - left + 1 > n) {
            int lidx = temp[left] - 'a';
            visited[lidx] = 0;
            sum -= (lidx + 1);
            left++;
        }

        ans = max(ans, sum);
    }

    printf("%d\n", ans);
    return 0;
}