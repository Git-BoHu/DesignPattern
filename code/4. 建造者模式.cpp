#include <iostream>
#include <string>
#include <memory>

using namespace std;

/*
* С�����¿���һ�����г�����������ʹ�����г���������� frame �ͳ��� tires ��������װ���Ʋ�ͬ�����г�������ɽ�س��͹�·����
* ɽ�س�ʹ�õ���Aluminum Frame�����Ƴ��ܣ��� Knobby Tires����ץ����̥����
* ��·��ʹ�õ��� Carbon Frame ��̼���ܣ��� Slim Tries��
* �������յ���һ�ʶ�����Ҫ����һ�����г���
* ����ʹ�á�������ģʽ������С����ʶ�����Ҫʹ����Щ���г����ðɡ�
*/

// ��Ʒ �������� ���彨���� ָ����
// ���г���Ʒ
class Bike {
public:
    string frame;
    string tires;

    void setFrame(const std::string& frame) {
        // this ��һ��ָ��ǰ�����ָ�롣
        // this->frame �ǵ�ǰ����� frame ��Ա������
        this->frame = frame;
    }

    void setTires(const std::string& tires) {
        this->tires = tires;
    }

    // ��Ԫ���� 
    // �����Ԫ�����Ƕ��������ⲿ������Ȩ�����������˽�У�private����Ա�ͱ�����protected����Ա��
 //   friend ostream& operator<<(ostream& os, const Bike& bike) {
 //       os << bike.frame << " " << bike.tires;
 //       return os;
//    }
};

// ���г������߽ӿ�
class BikeBuilder {
public:
    virtual void buildFrame() = 0;
    virtual void buildTires() = 0;
    virtual Bike getResult() = 0;
    virtual ~BikeBuilder() = default; // ������������ȷ�����������������������
};

// ɽ�����г�������
class MountainBikeBuilder : public BikeBuilder {
private:
    Bike bike;

public:
    void buildFrame() override {
        bike.setFrame("Aluminum Frame");
    }

    void buildTires() override {
        bike.setTires("Knobby Tires");
    }

    Bike getResult() override {
        return bike;
    }
};

// ��·���г�������
class RoadBikeBuilder : public BikeBuilder {
private:
    Bike bike;

public:
    void buildFrame() override {
        bike.setFrame("Carbon Frame");
    }

    void buildTires() override {
        bike.setTires("Slim Tires");
    }

    Bike getResult() override {
        return bike;
    }
};

// ���г�Director�����𹹽����г�
class BikeDirector {
public:
    Bike construct(BikeBuilder& builder) {
        builder.buildFrame();
        builder.buildTires();
        return builder.getResult();
    }
};


int main() {
    int n; // ��������
    cin >> n;

    // ��C++�У�BikeDirector director; ����ջ�Ϸ���һ�� BikeDirector ����
    // ����ջ�Ϸ������ʱ������Ҫ�ֶ����� delete ���ͷ��ڴ棬��Ϊ���ö��󳬳�������ʱ��C++ ���Զ����ö�����������������ͷ���ö�����ص��ڴ档

    // ���֮�£��ڶ��Ϸ������ʱ������ͨ�� new �ؼ��֣���Ҫ�ֶ����� delete ���ͷ��ڴ棬�Ա����ڴ�й©��
    // ��Ҳ��ʹ������ָ�루�� std::unique_ptr �� std::shared_ptr����һ����Ҫԭ����Ϊ���ǻ��Զ������ڴ��ͷţ�
    // ��ֹ�ڴ�й©��
    BikeDirector director;

    while (n--) {
        string Type;
        cin >> Type;

        unique_ptr<BikeBuilder> builder;

        if (Type == "mountain") {
            builder = make_unique<MountainBikeBuilder>();
        }
        else if (Type == "road") {
            builder = make_unique<RoadBikeBuilder>();
        }
        else {
            cout << "Wrong Type!" << endl;
            return 0;
        }

        Bike bike = director.construct(*builder);
        cout << bike.frame << " " << bike.tires << endl;
    }

    return 0;
}