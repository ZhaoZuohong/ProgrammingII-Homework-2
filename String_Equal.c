/*
 * 字符串判等
 * PB17000005 赵作竑
 * 2020年3月20日
 * http://bailian.openjudge.cn/practice/2743/
 */

#include <stdio.h>

#define STR_LEN 500
#define DIFF_A_a 'A' - 'a'

int main() {
    char acStrA[STR_LEN];
    char acStrB[STR_LEN];
    fgets(acStrA, STR_LEN, stdin);
    fgets(acStrB, STR_LEN, stdin);

    char *pcA = acStrA;
    char *pcB = acStrB;

    int iIsEqual = 0;

    while (1) {
        // 把小写字母全部转化成大写字母
        if (*pcA >= 'a' && *pcA <= 'z') {
            *pcA += DIFF_A_a;
        }
        if (*pcB >= 'a' && *pcB <= 'z') {
            *pcB += DIFF_A_a;
        }

        // 跳过空格
        if (*pcA == ' ') {
            ++pcA;
            continue;
        }
        if (*pcB == ' ') {
            ++pcB;
            continue;
        }

        // 到此为止，只有大写字母，*pcA与*pcB中不会有空格
        // 因为没有空格，所以如果*pcA是换行符且*pcB不是换行符，*pcB就是大写字母，不相等
        // 否则，两者都是换行符，相等
        if (*pcA == '\n') {
            if (*pcB == '\n') {
                iIsEqual = 1;
            } else {
                iIsEqual = 0;
            }
            break;
        } else {
            // 同样，这里*pcA不是换行符，如果*pcB是，则不相等，否则两者都不是换行符
            if (*pcB == '\n') {
                iIsEqual = 0;
                break;
            }
        }

        // 以下只有大写字母的情况
        // 如果相等，继续判断
        if (*pcA == *pcB) {
            ++pcA;
            ++pcB;
        } else {
            // 如果不相等，结束判断
            iIsEqual = 0;
            break;
        }
    }

    // 根据判断结果输出信息
    if (iIsEqual == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
