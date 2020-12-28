#include<iostream>
using namespace std;

class Animal {
public:
	//如果不加virtual就是地址早绑定，会用父类的；加了virtual后就是地址晚绑定，用子类的
	virtual void speak() {
		cout << "Animal is speaking." << endl;
	}
};

class Cat :public Animal {
public:
	void speak() {
		cout << "Cat is speaking." << endl;
	}
};

void doSpeak(Animal& animal) {
	animal.speak();
}

void test07_01() {
	Cat cat;
	doSpeak(cat);
}


//普通写法实现计算器
class Calculator {
public:
	int getResult(string oper) {
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		//如果想扩展新的功能，需要修改源码；
		//在真实开发中，提倡开闭原则：对扩展进行开放，对修改进行关闭
	}
	int m_Num1;
	int m_Num2;

};

void test07_02() {
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << "普通实现Calculator：" << endl;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}

//多态实现计算器
class AbstractCalculator {
public:
	//virtual int getResult() {
	//	return 0; 
	//}
	virtual int getResult() = 0;//纯虚函数
	int m_Num1;
	int m_Num2;
};

class AddCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 + m_Num2;
	}
};

class SubCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 - m_Num2;
	}
};

class MulCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 * m_Num2;
	}
};

void test07_03() {
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << "多态实现Calculator：" << endl;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	//用完后记得销毁
	delete abc;
	//销毁只是释放堆区数据，指针类型没变
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
}


//多态案例：制作饮品
//烧水-冲泡-倒入杯中-加辅料
class AbstractDrink {
public:
	virtual void Boil() = 0;
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void PutSomething() = 0;
	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

class Coffee :public AbstractDrink {
public:
	void Boil() {
		cout << "Boil water for coffee." << endl;
	}
	void Brew() {
		cout << "Brew coffee bean." << endl;
	}
	void PourInCup() {
		cout << "Pour coffee into cup." << endl;
	}
	void PutSomething() {
		cout << "Add sugar and milk." << endl;
	}
};

class Tea :public AbstractDrink {
public:
	void Boil() {
		cout << "Boil water for tea." << endl;
	}
	void Brew() {
		cout << "Brew tea." << endl;
	}
	void PourInCup() {
		cout << "Pour tea into cup." << endl;
	}
	void PutSomething() {
		cout << "Add lemon" << endl;
	}
};

void doWork(AbstractDrink* abs) {
	abs->makeDrink();
	delete abs;
}

void test07_04() {
	doWork(new Coffee);
	cout << "---------" << endl;
	doWork(new Tea);
}


//案例：电脑组装、
//CPU、显卡、内存条
//抽象出每个零件的类，构造电脑类传入三个零件并提供每个零件工作的接口，具体零件厂商
class CPU {
public:
	virtual void calculate() = 0;
};

class VideoCard {
public:
	virtual void display() = 0;
};

class Memory {
public:
	virtual void storage() = 0;
};

class Computer {
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* memo) {
		m_cpu = cpu;
		m_vc = vc;
		m_memo = memo;
	}
	void work() {
		m_cpu->calculate();
		m_vc->display();
		m_memo->storage();
	}
	~Computer() {
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		if (m_memo != NULL) {
			delete m_memo;
			m_memo = NULL;
		}
	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_memo;
};

class IntelCPU :public CPU {
	void calculate() {
		cout << "Intel's CPU starts calculating." << endl;
	}
};
class IntelVideoCard :public VideoCard {
	void display() {
		cout << "Intel's VideoCard starts displaying." << endl;
	}
};
class IntelMemory :public Memory {
	void storage() {
		cout << "Intel's Memory starts to storage." << endl;
	}
};

class LenovoCPU :public CPU {
	void calculate() {
		cout << "Lenovo's CPU starts calculating." << endl;
	}
};
class LenovoVideoCard :public VideoCard {
	void display() {
		cout << "Lenovo's VideoCard starts displaying." << endl;
	}
};
class LenovoMemory :public Memory {
	void storage() {
		cout << "Lenovo's Memory starts to storage." << endl;
	}
};

void test07_05() {
	// 1st Com
	CPU* intelCPU = new IntelCPU;
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMemory = new IntelMemory;
	cout << "computer1: " << endl;
	Computer* computer1 = new Computer(intelCPU, intelCard, intelMemory);
	computer1->work();
	delete computer1;
	cout << "----------" << endl;
	cout << "computer2: " << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;
	cout << "----------" << endl;
	cout << "computer3: " << endl;
	Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
}


int main7() {
	test07_01();
	test07_02();
	test07_03();
	test07_04();
	test07_05();

	system("pause");
	return 0;
}