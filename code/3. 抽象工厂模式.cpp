#include <iostream>
#include <string>

using namespace std;

/* С�����¿��������������������Ҿߣ�һ�������ִ�����ɳ�������ӣ�
 * һ�������ŵ����ɳ�������ӣ�
 * ���ڹ����յ���һ�ʶ���������������һ��ϵͳ������������Ҫ�����Ҿߵ���Ϣ��
*/

// �����Ʒ��: ɳ�� �� ����
class Chair {
public:
    virtual void showInfo() = 0;
};

class Sofa {
public:
    virtual void displayInfo() = 0;
};

// �����Ʒ��: ����ɳ��������
class ModernChair : public Chair {
public:
    void showInfo() override {
        std::cout << "modern chair" << std::endl;
    }
};

class ClassicalChair : public Chair {
public:
    void showInfo() override {
        std::cout << "classical chair" << std::endl;
    }
};

class ModernSofa : public Sofa {
public:
    void displayInfo() override {
        std::cout << "modern sofa" << std::endl;
    }
};

class ClassicalSofa : public Sofa {
public:
    void displayInfo() override {
        std::cout << "classical sofa" << std::endl;
    }
};

// ����Ҿӹ����ӿ�
class FurnitureFactory {
public:
    virtual Chair* createChair() = 0;
    virtual Sofa* createSofa() = 0;
};

// �����ִ����Ҿӹ���
class ModernFurnitureFactory : public FurnitureFactory {
public:
    Chair* createChair() override {
        return new ModernChair();
    }

    Sofa* createSofa() override {
        return new ModernSofa();
    }
};

// ����ŵ���Ҿӹ���
class ClassicalFurnitureFactory : public FurnitureFactory {
public:
    Chair* createChair() override {
        return new ClassicalChair();
    }

    Sofa* createSofa() override {
        return new ClassicalSofa();
    }
};

int main() {
    int n; //��������
    cin >> n;

    while (n--) {
        string Type;
        cin >> Type;

        FurnitureFactory* factory = nullptr;

        if (Type == "modern") {
            factory = new ModernFurnitureFactory();
        }
        else if (Type == "classical") {
            factory = new ClassicalFurnitureFactory();
        }
        else {
            cout << "Wrong Type!" << endl;
            return 0;
        }

        Chair* chair = factory->createChair();
        Sofa* sofa = factory->createSofa();

        chair->showInfo();
        sofa->displayInfo();
    }
    return 0;
}