int my_strlen(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int my_strncmp(char* str1, char* str2, int n) {
    for (int i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return 0; // 不相同
        }
        if (str1[i] == '\0' || str2[i] == '\0') {
            return 1; // 到达字符串末尾，认为相同
        }
    }
    return 1; // 相同
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];
    
    // 检查是否有空字符串
    for (int i = 0; i < strsSize; i++) {
        if (strs[i][0] == '\0') return "";
    }

    // 假设第一个字符串是最长公共前缀
    char* prefix = strs[0];

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        // 比较当前字符串与prefix
        while (my_strncmp(prefix, strs[i], j + 1)) {
            j++;
            if (j >= my_strlen(prefix) || j >= my_strlen(strs[i])) {
                break; // 达到任一字符串的末尾
            }
        }
        // 如果没有公共前缀，返回空字符串
        if (j == 0) return "";

        // 截断prefix
        prefix[j] = '\0';
    }
    
    return prefix;
}