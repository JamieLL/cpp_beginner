#include<iostream>
using namespace std;

class BasePage {
public:
	void header() {
		cout << "首页、登录、注册..." << endl;
	}
	void footer() {
		cout << "帮助中心、交流合作..." << endl;
	}
	void left() {
		cout << "Java、Python、C++...（公共列表）" << endl;
	}
};

class Java : public BasePage {
public:
	void content() {
		cout << "Java学科视频" << endl;
	}
};

class Python : public BasePage {
public:
	void content() {
		cout << "Python学科视频" << endl;
	}
};

class CPP : public BasePage {
public:
	void content() {
		cout << "CPP学科视频" << endl;
	}
};

void test06_1() {
	Java j;
	Python p;
	CPP c;
	j.header();
	p.footer();
	c.left();
	c.content();
}

int main6() {
	test06_1();

	system("pause");
	return 0;
}