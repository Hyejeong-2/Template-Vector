#include <iostream>
using namespace std;

template <typename T>
class SimpleVector {
private:
    T* arr;            // ���� �迭
    int currentSize;   // ���� ���� ����
    int maxCapacity;   // �迭�� �ִ� ũ��

public:
    // ���� ������ (�⺻ ���� ���)
    SimpleVector(int capacity = 10) : currentSize(0), maxCapacity(capacity) {
        arr = new T[maxCapacity];
    }

    // �Ҹ��� (���� �޸� ����)
    ~SimpleVector() {
        delete[] arr;
    }

    // push_back: �迭�� �� �ڿ� ���� �߰�
    void push_back(const T& value) {
        if (currentSize < maxCapacity) {
            arr[currentSize++] = value;
        }
        else {
            cout << "�迭�� �� á���ϴ�" << endl;
        }
    }

    // pop_back: �迭�� ������ ���� ����
    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
        else {
            cout << "������ �迭�� �����ϴ�" << endl;
        }
    }

    // size: ���� ���� ���� ��ȯ
    int size() const {
        return currentSize;
    }

    // capacity: �迭�� �ִ� ũ�� ��ȯ
    int capacity() const {
        return maxCapacity;
    }
};

int main() {
    // �⺻ ������
    SimpleVector<int> vec;
    cout << "ó�� �뷮: " << vec.capacity() << endl;

    // push_back
    for (int i = 0; i < 12; i++) {
        vec.push_back(i);
        cout << "Size after push_back(" << i << "): " << vec.size() << endl;
    }

    // pop_back
    vec.pop_back();
    cout << "Size after pop_back: " << vec.size() << endl;

    // ũ�⸦ �����ϴ� ������
    SimpleVector<string> strVec(5);
    strVec.push_back("Hello");
    strVec.push_back("World");
    cout << "strVec size: " << strVec.size() << ", capacity: " << strVec.capacity() << endl;

    return 0;
}
