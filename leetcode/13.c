void replace(char* s, char* target, char c) {
    for (int i = 0; s[i] != '\0';i++){
        if (s[i] != target[0] || s[i+1] != target[1]) continue;
        s[i]=c;
        for (int j = i + 1; s[j] != '\0'; j++){
            s[j] = s[j+1];
        }
    }
}

int romanToInt(char* s) {
    char target[6][2] = {{'I','V'},{'I','X'},{'X','L'},{'X','C'},{'C','D'},{'C','M'}};
    char c[6] = { 'a', 'b', 'c', 'd', 'e', 'f'};
    for(int i = 0; i<6; i++){
        replace(s, target[i], c[i]);
    }
    char temp;
    int sum=0;
    for(int i = 0; s[i]!='\0';i++){
        temp = s[i];
        switch (temp){
            case 'a': sum+=4;break;
            case 'b': sum+=9;break;
            case 'c': sum+=40;break;
            case 'd': sum+=90;break;
            case 'e': sum+=400;break;
            case 'f': sum+=900;break;
            case 'I': sum+=1;break;
            case 'V': sum+=5;break;
            case 'X': sum+=10;break;
            case 'L': sum+=50;break;
            case 'C': sum+=100;break;
            case 'D': sum+=500;break;
            case 'M': sum+=1000;break; 
        }
    }
    return sum;
}