#include<iostream>
#include<string.h>
#include<cmath>

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

string big_num_plus(string p1, string p2) {
	string t1 = p1;
	string t2 = p2;
	int index1 = 0,index2= 0;
	while (t1[index1] == ' ' || t1[index1] == '0') index1++;
	while (t2[index2] == ' ' || t2[index2] == '0') index2++;
	// 获取字符串的有效长度
	int len1 = t1.size() - index1;
	int len2 = t2.size() - index2;

	// 指向末尾元素
	int end1 = t1.size() - 1, end2 = t2.size() - 1;

	int flag = 0;
	int temp_val;
	string res;
	char temp_char;
	int len = abs(len1 - len2);
	if (len1 > len2) {
	    while (len2-- && isdigit(t1[end1]) && isdigit(t2[end2])) {
		    temp_val = (t1[end1--] - '0') + (t2[end2--] - '0') + flag;
			// 若temp_val >= 10，则flag有进位
			if (temp_val >= 10) {
			    temp_val -= 10;
				flag = 1;
			}
			else
				flag = 0;
			// 将该位数字int 转换为char
			temp_char = temp_val + '0';
			// 将字符插入res的最前端
			res.insert(res.begin(),temp_char);
		}
		// 说明while异常结束
		if (len2 >= 0) {
		    res = "";
			return res;
		}
		while (len-- && isdigit(t1[end1])) {
		    temp_val = (t1[end1--] - '0') + flag;		
			if (temp_val >= 10) {
			    temp_val -= 10;
				flag = 1;
			}
			else
			    flag = 0;
			temp_char = temp_val + '0';
			res.insert(res.begin(),temp_char);
		}
		if (len >= 0) {
		    res = "";
			return res;
		}
		if (flag) {
			temp_char = flag + '0';
			res.insert(res.begin(),temp_char);
		}
	}
	else {
	    while (len1-- && isdigit(t1[end1]) && isdigit(t2[end2])) {
		    temp_val = (t1[end1--] - '0') + (t2[end2--] - '0') + flag;
			// 若temp_val >= 10，则flag有进位
			if (temp_val >= 10) {
			    temp_val -= 10;
				flag = 1;
			}
			else
				flag = 0;
			// 将该位数字int 转换为char
			temp_char = temp_val + '0';
			// 将字符插入res的最前端
			res.insert(res.begin(),temp_char);
		}
		// 说明while异常结束
		if (len1 >= 0) {
		    res = "";
			return res;
		}
		while (len-- && isdigit(t2[end2])) {
		    temp_val = (t2[end2--] - '0') + flag;		
			if (temp_val >= 10) {
			    temp_val -= 10;
				flag = 1;
			}
			else
			    flag = 0;
			temp_char = temp_val + '0';
			res.insert(res.begin(),temp_char);
		}
		if (len >= 0) {
		    res = "";
			return res;
		}
		if (flag) {
			temp_char = flag + '0';
			res.insert(res.begin(),temp_char);
		}
	}
	return res;
}

string big_num_minus(string p1, string p2) {
    int index1= 0,index2= 0;
	string t1=p1,t2=p2;
	while (t1[index1] == ' ' || t1[index1] == '0') index1++;
	while (p2[index2] == ' ' || p2[index2] == '0') index2++;
    t1.erase(0,index1);
	t2.erase(0,index2);
	// 获取字符串的有效长度
	int len1 = p1.size() - index1;
	int len2 = p2.size() - index2;

	cout<<t1<<endl<<t2<<endl;

	string res;
	// 相等直接返回
	if (len1 == len2 && t1 == t2)
		return "0";

	// 获取字符串的末尾位置
	int e1 = t1.size()-1;
	int e2 = t2.size()-1;

	int temp_val;
	char temp_char;
	int flag = 0;
	// 长度差
	int len = abs(len1- len2);
    // 若len1 < len2 说明 t1 < t2
	// 若二者长度相等，且t1<t2，用t2-t1
	if (len1 < len2 || (len1 == len2 && t1 < t2)) {
		// 在短字符没被比较完的情况下，做字符串减法
	    while (len1-- && isdigit(t1[e1]) && isdigit(t2[e2])) {
		    temp_val = (t2[e2]-'0') - flag - (t1[e1] - '0');
			if ( temp_val < 0 ) {
				// 此时需要借位
				// temp_val 值为被减数+10-减数
				temp_val = (t2[e2]-'0')+10-flag-(t1[e1]-'0');
			    flag = 1;
			}
			else 
				flag = 0;
			temp_char = '0' + temp_val;
			res.insert(res.begin(),temp_char);
			e1--;
			e2--;
		}
		if (len1 >= 0 ) {
		    res = "";
			cout<<"invalid input"<<endl;
			return res;
		}
		while (len-- && isdigit(t2[e2])) {
		    temp_val = (t2[e2]-'0') - flag;
			if (temp_val < 0) {
			    temp_val = t2[e2] - '0' + 10 - flag;
			 	flag = 1;
			}
			else
			    flag = 0;
			if (len == 0 && temp_val == 0)
				return res;
			temp_char = temp_val + '0';
			res.insert(res.begin(),temp_char);
			e2--;
		}
		if (len >= 0) {
		    res = "";
			cout<<"invalid input"<<endl;
			return res;
		}
		return res;
	}
	// 否则用 t1-t2
	else {
	    while (len2-- && isdigit(t1[e1]) && isdigit(t2[e2])) {
		    temp_val = (t1[e1]-'0') - flag - (t2[e2] - '0');
			if ( temp_val < 0 ) {
				// 此时需要借位
				// temp_val 值为被减数+10-减数
				temp_val = (t1[e1]-'0')+10-flag-(t2[e2]-'0');
			    flag = 1;
			}
			else 
				flag = 0;
			temp_char = '0' + temp_val;
			res.insert(res.begin(),temp_char);
			e1--;
			e2--;
		}
		if (len2 >= 0 ) {
		    res = "";
			cout<<"invalid input"<<endl;
			return res;
		}
		while (len-- && isdigit(t1[e1])) {
		    temp_val = (t1[e1]-'0') - flag;
			if (temp_val < 0) {
				temp_val = t1[e1] - '0' + 10 - flag;
			    flag = 1;
			}
			else
			    flag = 0;
			if (len == 0 && temp_val == 0 )
				return res;
			temp_char = temp_val + '0';
			res.insert(res.begin(),temp_char);
			--e1;
		}
		if (len >= 0) {
		    res = "";
			cout<<"invalid input"<<endl;
			return res;
		}
		return res;
	}
}


// 在str1中查找str2，成功则返回str2第一次出现的位置
// 失败则返回NULL
// 回溯法
char* my_strstr(const char* str1, char* str2) {
    if (str1 == NULL || str2 == NULL)
		return NULL;
	if (*str2 == '\0')
	    return const_cast<char*>(str1);
	const char* s1 = str1;
	char* s2 = str2;
	while(*s1 != '\0') {
	    if(*s1 == *s2) {
		    // 如果当前字符相等，记录s1的当前位置
     		const char* tmp = s1;
	    	++s1;
		    ++s2;
     		while(*s2 != '\0' && *s1 != '\0') {
     		    if (*s1 != *s2) {
					// 若出现不相等字符，则将s2和s1恢复原状
		    	    s2 = str2;
			    	s1 = tmp+1;
				    break;
     	 		}
		    	else {
			        s1++;
				    s2++;
     			}
	        }
		    if (*s2 == '\0')
	            return const_cast<char*>(tmp);
    	}
		else
			s1++;
	}
	return NULL;
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
    string a("0123456");
    string b(" 099999999");
    string c = big_num_plus(a,b);
    cout<<c<<endl;
 	return 0;
}
