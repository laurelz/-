#include<iostream>
#include<string.h>

using namespace std;

char* my_strcpy(char* dest,const char* src) {
    if (src == NULL|| dest == NULL) {
        return dest;
    }
    if (src == dest)
        return dest;

    int lenth = strlen(src)+1;
    // 判断是否存在src和dest内存重叠的可能
    // 若dest位于src之前，或者dest位于整个src字符串之后
    // 此时不需要考虑复制中的覆盖
    if (dest < src || dest >= src+lenth) {
        const char*ps = src;
        char * pd = dest;
        while (lenth>0) {
            *pd++ = *ps++;
            lenth--;
        }
    }
    // 否则，说明可能存在复制中的内存覆盖
    // 需要从后往前复制
    else {
        // 使指针指向字符串的末尾字符
        const char* ps = src;
        char* pd = dest+lenth-1;
        ps += lenth-1;
        while (lenth-- > 0) {
            *pd-- = *ps--;
        }
    }
    return dest;
}
int main() {
    char * src  = new char();
    strcpy(src,"laurelfighting!");
	  cout<<src<<endl;
    char* dest = src+16;
    char* baddest = src+6;
    my_strcpy(dest,src);
    //my_strcpy(baddest,src);
	  cout<<dest<<endl;
    //cout<<baddest<<endl;
 	return 0;
}
