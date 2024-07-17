#include <iostream>
#include <string>
#include <vector>

/* 
* ԭ��ģʽ��
* ����ԭ�ͽӿ�prototype: ����һ����¡����ķ���clone
* ����ԭ����ConcretePrototype: ʵ��clone���������Ƶ�ǰ���󲢷���һ���¶���
*/ 

// ����ԭ����
// ����һ��������࣬�����������麯�� clone �� getDetails
class Prototype {
public:
	virtual Prototype* clone() const = 0;
	virtual std::string getDetails() const = 0;
	virtual ~Prototype() {} // ������һ����������������ȷ����ɾ�����������ʱ����ȷ��������������
};

// ����ԭ����
// RectanglePrototype �̳��� Prototype��ʵ���� clone �� getDetails ������
class RectanglePrototype : public Prototype {
private:
	std::string color;
	int width;
	int height;
public :

	RectanglePrototype(std::string color, int width, int height) : 
		color(color), width(width), height(height) {}

	/* 
	* clone ��������һ���µ� RectanglePrototype ����Ŀ�����
	* �÷����ķ��������� Prototype*����ʾ����һ��ָ�� Prototype �����ָ�롣
	* ���ָ��ʵ���ϻ�ָ��һ���µ� RectanglePrototype ������Ϊ RectanglePrototype �� Prototype �����ࡣ
	* *this �ǵ�ǰ��������ã�����ζ���¶�����ͨ�����Ƶ�ǰ������������ݳ�Ա����ʼ���ġ�
	*/ 
	Prototype* clone() const override {
		return new RectanglePrototype(*this);
	}

	// getDetails �������ؾ��ε���ϸ��Ϣ��
	std::string getDetails() const override {
		return "Color: " + color + ", Width: " + std::to_string(width) + ", Height: " + std::to_string(height);
	}
};

// �ͻ��˳���
int main() {
	std::string color;
	int width, height;
	std::cin >> color >> width >> height;

	// ���� ԭ�� ����
	/*
	* ʹ�� Prototype* orginRectangle = new RectanglePrototype(color, width, height); ���ַ�ʽ��������֮���Կ��У�
	* ����Ϊ C++ �����ڴ�������ʱʹ�û���ָ��ָ�����������
	* ���ֻ��Ƴ�Ϊ��̬�ԣ�Polymorphism��������������̵���Ҫ����֮һ��
	*/
	Prototype* orginRectangle = new RectanglePrototype(color, width, height);

	int N;
	std::cin >> N;

	std::vector<Prototype*> rectangles;
	for (int i = 0; i < N; ++i) {
		// ��¡ԭ�Ͷ���
		Prototype* clonedRectangle = orginRectangle->clone();
		rectangles.push_back(clonedRectangle);
	}

	// �����ϸ��Ϣ
	for (const auto& rectangle : rectangles) {
		std::cout << rectangle->getDetails() << std::endl;
	}

	// �ͷſ�¡������ڴ�
	for (const auto& rectangle : rectangles) {
		delete rectangle;
	}

	// �ͷ�ԭ�Ͷ�����ڴ�
	delete orginRectangle;

	return 0;
}