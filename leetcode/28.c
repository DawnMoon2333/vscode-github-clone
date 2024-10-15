void BuildLPS(const char* pattern, int length, int* lps) {
    int fixlength = 0; // 最长前后缀长度
    lps[0] = 0; // lps数组的首个元素不使用，初始化为0

    int i = 1; // 从lps的第二个元素开始遍历
    while (i < length) {
        if (pattern[i] == pattern[fixlength]) { // 首尾元素相同
            fixlength++;
            lps[i] = fixlength;
            i++;
        }
        else { //首尾元素不同
            if (fixlength != 0) { // 之前有部分匹配
                fixlength = lps[fixlength - 1];
                //将length更新为lps中length-1处的值以检查更短的前缀
            }
            else { // 没有匹配前后缀
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP(const char* text, const char* pattern) {
    int len_text = strlen(text);
    int len_pattern = strlen(pattern);

    // 求LPS数组
    int* lps = (int*)malloc(len_pattern * sizeof(int));
    BuildLPS(pattern, len_pattern, lps);

    // 进行串的模式匹配
    // 两个索引指向文本串和模式串的起始位置
    int index_text = 0, index_pattern = 0;
    while (index_text < len_text) { // 遍历整个字符串
        if (pattern[index_pattern] == text[index_text]) { // 若第一个元素匹配成功，两个索引就都自增
            index_text++;
            index_pattern++;
        }
        if (index_pattern == len_pattern) { // 当pattern的索引和长度相同时就匹配成功
            free(lps);
            return index_text - index_pattern;
        }
        else if (index_text < len_text && pattern[index_pattern] != text[index_text]) { // text索引小于长度且索引处字符不匹配
            if (index_pattern != 0) { // pattern索引不为零说明已有部分字符匹配
                index_pattern = lps[index_pattern - 1]; // 从lps数组中获取跳过字符的数量
            }
            else { // pattern索引为零，无匹配部分
                index_text++; // 仅将text索引+1，继续向后比较
            }
        }
    }

    // 没有在循环内return说明匹配失败
    free(lps);
    return -1;
}

int strStr(char* haystack, char* needle) {
    return KMP(haystack, needle);
}
