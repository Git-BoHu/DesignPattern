#include <iostream>
#include <map>
#include <vector>

using namespace std;

class ShoppingCartManager {
public:

    /* ���÷��� : getInstance() �������ض� instance �����á�
    *  �������ö����Ƕ���ĸ�����������Ҫ�ģ���Ϊ�Ᵽ֤������ͨ�� getInstance() ��ȡ�� ShoppingCartManager ���ö�ָ��ͬһ��ʵ���������ǵ���ģʽ��Ҫȷ���ġ�
    */
    static ShoppingCartManager& getInstance() {
        /* �ֲ���̬����: �����е� instance ������Ϊ��̬�ֲ�������
        * ��C++�У��ֲ���̬�����ڵ�һ��ִ�е��ñ���������λ��ʱ����ʼ����
        * ֮�󼴱㺯�����ý���������ֵҲ���ᱻ���٣����Ǳ�����״ֱ̬���´ε��á�
        */
        static ShoppingCartManager instance;
        return instance;
    }

    void addCart(const string& itemName, int num) {
        if (myCart.find(itemName) == myCart.end()) {
            order.push_back(itemName);
        }
        myCart[itemName] += num;
    }

    void showCart() const {
        for (const auto& item : order) { // &ʹ�����ã����ⲻ��Ҫ�Ŀ��������Ч��
            cout << item << ' ' << myCart.at(item) << endl;
        }
        return;
    }
private:
    ShoppingCartManager() {} // ˽�й��캯����ȷ��һ�������һ��ʵ�������ṩһ��ȫ�ַ��ʵ㵽��ʵ����
    map<string, int> myCart; // map �ײ�ʵ��Ϊ�����
    vector<string> order; // ���ڱ��ֲ���˳��
};

int main() {
    string name;
    int num;
    while (cin >> name >> num) {
        ShoppingCartManager& cart = ShoppingCartManager::getInstance();
        cart.addCart(name, num);
    }
    const ShoppingCartManager& cart = ShoppingCartManager::getInstance();
    cart.showCart();

    return 0;
}