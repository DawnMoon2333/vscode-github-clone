char* longestCommonPrefix(char** strs, int strsSize) {
    char str[200];
    char temp;
    int j = 0;
    for (int i = 0; i<strsSize; i++){
        temp = strs[i][0];
        j=0;
        while(j<200){
            if(strs[i][j]==temp) continue;
            
        }
        
    }
    return str;
}