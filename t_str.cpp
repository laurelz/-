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

// 字符串反转函数，反转时不使用中间变量
char * reverse_str(char* src) {
    if (src == NULL) return src;
	int len = strlen(src);
	char * start = src;
	char * end = src + len -1;
	while (start < end) {
	    *start = *end + *start;
		*end = *start - *end;
		*start = *start -*end;
		++start;
		--end;
	}
	return src;
}

int my_atoi(const char* src) {
    if (src == NULL) return 0;
	int len = strlen(src);
	const char *tmp = src;
	// tmp指向src的最后一个有效字符
	tmp += len-1;
	int res = 0;
	int times = 1;
	while (len--) {
		if (len == 0 && *tmp == '-') {
		    // 此时字符串的第一个字符为'-'
			res = -res;
			break;
		}
	    if ((*tmp - '0') >= 0 && (*tmp - '0') <= 9) {
		    res += (*tmp-- - '0')*times;
			times *= 10;
		}
		else{
		    cout<<"invalid input"<<endl;
			return INVALID_INPUT;
		}
	}
		return res;
}

int my_strlen(const char* src) {
    if (src == NULL) return -1;
	const char* ps = src;
	int res = 0;
	while(*ps++ != '\0')
		++res;
	return res;
}

int main() {
    char * src  = new char();
    strcpy(src,"laurelfighting!");
    char * src_res = new char();
    strcpy(src_res,"-1234");
    cout<<src<<endl;
    char* dest = src+16;
    char* baddest = src+6;
    //my_strcpy(dest,src);
    //my_strcpy(baddest,src);
    dest = reverse_str(src);
	  cout<<dest<<endl;
    int res = my_atoi(src_res);
    cout<<res<<endl;
    //cout<<baddest<<endl;
 	return 0;
}
