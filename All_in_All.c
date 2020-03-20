/*
 * All in All
 * PB17000005 赵作竑
 * 2020年3月20日
 * http://bailian.openjudge.cn/practice/2976/
 */

#include <stdio.h>
#include <string.h>

#define STR_LEN 100100

char g_acStrS[STR_LEN];
char g_acStrT[STR_LEN];

int main() {
    while (scanf("%s%s", g_acStrS, g_acStrT) == 2) {
        int i = 0, j = 0;
        int iSLen = (int) strlen(g_acStrS);
        int iTLen = (int) strlen(g_acStrT);
        while (i < iSLen && j < iTLen) {
            // 如果找到了和S串对应的字符，则接着寻找下一个字符
            if (g_acStrS[i] == g_acStrT[j]) {
                ++i;
            }
            ++j;
        }
        // 判断是否找到了S串里的全部字符
        if (i == iSLen) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
