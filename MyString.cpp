#include<iostream>
#include<string.h>

using namespace std;

class MyString {
private:
	char* data;
	int lenth;

public:
	// 通用构造函数
	MyString(char* str = NULL);
    // 复制构造函数
	MyString(const MyString& str);
    // 析构函数
	~MyString();
	// 获取长度
	int getlenth(){
	    return this->lenth;
	}
	// 获取数据
	const char* getdata() {
	    return this->data;
	}
	// 根据参数设置数据
	void setLandD(char* str) {
	    this->lenth = strlen(str);
	    data = new char[lenth+1];
		strcpy(data,str);
	}
    // 重载==算符
	bool operator==(MyString& str);
    // 重载=算符
	MyString& operator=(MyString& str);
	
	friend istream& operator>>(istream &is, MyString & str);
	friend ostream& operator<<(ostream &os, const MyString & str);

};

MyString::MyString(char*str) {
    if (str== NULL) {
	    lenth = 0;
		data = new char[1];
		data[0] = '\0';
	}
	else {
	    lenth = strlen(str);
    	data = new char[lenth+1];
	    strcpy(this->data,str);
	}
}

MyString::MyString(const MyString&str) {
    lenth = str.lenth;
	data = new char[lenth+1];
	strcpy(this->data, str.data);
}

MyString::~MyString() {
    lenth = 0;
	delete []data;
}

bool MyString::operator==(MyString& str) {
    if(str.lenth != lenth) return false;
	return (strcmp(str.data,this->data)==0 )?true:false;
}
MyString& MyString::operator=(MyString & str) {
    if (&str == this) return *this;

	delete []data;
	lenth = str.lenth;
    data = new char[lenth+1];
	strcpy(this->data, str.data);
	return *this;
}

istream& operator>>(istream &is, MyString& str) {
    char temp[1000];
	is>>temp;
	str.setLandD(temp);
	return is;
}

ostream& operator<<(ostream &os, const MyString& str) {
    os<<str.data;
	return os;
}
int main() {
	char a1[]="getyoudown";
	char b1[]="saylousaylou";
 //   MyString ms1("eheheh");
    MyString ms1;
	cin>>ms1;
	MyString ms2(a1),ms3(b1);
	cout<<ms1<<endl<<ms2<<endl<<ms3<<endl;
	if(ms2==ms3)
		cout<<"ms2 == ms3"<<endl;
	else
		cout<<"ms2 != ms3"<<endl;
	ms1 = ms2;
	cout<<ms1<<endl<<ms2<<endl<<ms3<<endl;
}
