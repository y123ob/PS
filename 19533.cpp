#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

typedef long long int ll;

int type[1010101][3];

ll get_10_exp_mod(int a, int mod)
{
    if (a == 0) return 1;
    if (a == 1) return 10 % mod;
    ll ret = (ll)get_10_exp_mod(a / 2, mod);
    ret = ret * ret * (a % 2 ? 10 : 1) % mod;
    return ret;
}

ll get_mod(int a, int b, int len)
{
    ll ret = 0;
    ret -= (ll)a * get_10_exp_mod(b, len + 1) % (len + 1);
    ret += get_10_exp_mod(len, len + 1);
    ret += (len + 1);
    ret = ret % (len + 1);
    if (ret == 0) ret = len + 1;
    return ret;
}

void check_type_start() {
    type[2][0] = -2;
    type[2][1] = -1;
    type[2][2] = -3;

    for (int i = 3; i < 1000100; i++) {
        int shift = (9 * get_10_exp_mod(i - 1, i + 1) - 1) % (i + 1);
        for (int j = 0; j < 3; j++) {
            type[i][j] = type[i - 1][j] - shift - 1;
            if (type[i][j] < -i - 1) type[i][j] += (i + 1);
        }
    }
    return;
}

int get_type(int a, int b, int len_ab)
{
    int mod_get = -int(get_mod(a, b, len_ab));
    int case_;
    if (type[len_ab][0] <= mod_get && mod_get < type[len_ab][1]) case_ = 8;
    else if (type[len_ab][1] <= mod_get && mod_get < type[len_ab][2]) case_ = 9;
    else if (type[len_ab][2] <= mod_get && mod_get < type[len_ab][0]) case_ = 10;
    else {
        if (type[len_ab][0] < type[len_ab][2]) case_ = 10;
        else if (type[len_ab][1] < type[len_ab][0]) case_ = 8;
        else if (type[len_ab][2] < type[len_ab][1]) case_ = 9;
    }
    return case_;
}

int main() {

    int a, b;

    check_type_start();
    int tc = 0;
    scanf("%d", &tc);
    for (int t = 0; t < tc; t++) {
        scanf("%d %d", &a, &b);
        int len_a = int(log10(a)) + 1;
        int len_ab = len_a + b;
        int case_ = 0;
        if (len_ab <= 2) {
            int ab = a;
            if (b == 1) ab *= 10;
            if (ab == 1) printf("1\n");
            else if (ab == 2) printf("-2\n");
            else if (ab == 3) printf("1-3\n");
            else if (ab == 4) printf("-2-4\n");
            else if (ab == 5) printf("1-3-5\n");
            else if (ab == 6) printf("-2-4-6\n");
            else if (ab == 7) printf("1-3-5-7\n");
            else if (ab == 8) printf("-2-4-6-8\n");
            else if (ab == 9) printf("1-3-5-7-9\n");
            else if (ab == 10) printf("1-3-5-7-10\n");
            else if (ab == 11) printf("-2-4-6-8-11\n");
            else if (ab == 12) printf("1-3-5-7-9-12\n");
            else if (ab == 13) printf("1-3-5-7-10-13\n");
            else if (ab == 14) printf("-2-4-6-8-11-14\n");
            else if (ab == 15) printf("1-3-5-7-9-12-15\n");
            else if (ab == 16) printf("1-3-5-7-10-13-16\n");
            else if (ab == 17) printf("-2-4-6-8-11-14-17\n");
            else if (ab == 18) printf("1-3-5-7-9-12-15-18\n");
            else if (ab == 19) printf("1-3-5-7-10-13-16-19\n");
            else if (ab == 20) printf("-2-4-6-8-11-14-17-20\n");
            else {
                if (ab % 3 == 0) case_ = 9;
                if (ab % 3 == 1) case_ = 10;
                if (ab % 3 == 2) case_ = 8;
            }
        }
        else {
            case_ = get_type(a, b, len_ab);
        }
        if (case_ == 8) printf("-2-4-6-8-11-14-17...\n");
        else if (case_ == 9) printf("1-3-5-7-9-12-15-1...\n");
        else if (case_ == 10) printf("1-3-5-7-10-13-16-...\n");
    }
    return 0;
}