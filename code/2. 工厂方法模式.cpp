#include <iostream>
#include <vector>
#include <memory> // ��������ָ���ڴ������ع���

using namespace std;

// �����ľ�ӿ�
class Block {
public:
    virtual void produce() = 0; // ���麯��, ����ӿ�
    virtual ~Block() = default; // ������������
};

// Բ�λ�ľʵ��
class CircleBlock : public Block {
public:
    void produce() override {
        cout << "Circle Block" << endl;
    }
};

// ���λ�ľʵ��
class SquareBlock : public Block {
public:
    void produce() override {
        cout << "Square Block" << endl;
    }
};

// �����ľ�����ӿ�
class BlockFactory {
public:
    virtual unique_ptr<Block> createBlock() = 0;
    virtual ~BlockFactory() = default;
};

// Բ�λ�ľ����ʵ��
class CircleBlockFactory : public BlockFactory {
public:
    unique_ptr<Block> createBlock() override {
        /* make_unique ����ģ�壺
        * std::make_unique ��һ������ģ�壬���ڴ���һ������Ϊ T �Ķ��󣬲�����һ��ָ��ö���� std::unique_ptr��
        * �����Խ��ܹ��캯���Ĳ�����������Щ����ת��������Ĺ��캯����

        * <CircleBlock>��
        * ����� CircleBlock ��ģ���������ʾ����Ҫ�����Ķ��������� CircleBlock��

        * ()��
        * ������ű�ʾû�д��ݸ� CircleBlock ���캯���Ĳ�������ʹ��Ĭ�Ϲ��캯�������� CircleBlock ����
        */
        return make_unique<CircleBlock>();
    }
};

// ���λ�ľ����ʵ��
class SquareBlockFactory : public BlockFactory {
public:
    unique_ptr<Block> createBlock() override{
        return make_unique<SquareBlock>();
    }
};

// ��ľ����ϵͳ
class BlockFactorySystem {
private:
    vector<unique_ptr<Block>> blocks;

public:
    void produceBlocks(BlockFactory& factory, int nums) {
        for (int i = 0; i < nums; ++i) {
            unique_ptr<Block> block = factory.createBlock(); // ������ BlockFactory �� createBlock ������ͨ������ģʽ������һ���µ� Block ���󣬲������װ�� std::unique_ptr �С�
            block->produce(); // ������ Block ����� produce ������
            blocks.push_back(move(block));
        }
    }

    const vector<unique_ptr<Block>>& getBlocks() const {
        return blocks;
    }
};

int main() {
    int n; // ���������Ĵ���
    string blockName;
    int blockNum;
    cin >> n;

    // ������ľ����ϵͳ
    BlockFactorySystem factorySystem;

    // �������幤������
    CircleBlockFactory circleFactory;
    SquareBlockFactory squareFactory;

    while (n--) {
        cin >> blockName >> blockNum;

        if (blockName == "Circle") {
            factorySystem.produceBlocks(circleFactory, blockNum);
        }
        else if (blockName == "Square") {
            factorySystem.produceBlocks(squareFactory, blockNum);
        }
    }

    return 0;
}