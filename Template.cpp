#include <iostream>
using namespace std;

template <typename T>
class SimpleVector {
private:
    T* arr;            // 동적 배열
    int currentSize;   // 현재 원소 개수
    int maxCapacity;   // 배열의 최대 크기

public:
    // 단일 생성자 (기본 인자 사용)
    SimpleVector(int capacity = 10) : currentSize(0), maxCapacity(capacity) {
        arr = new T[maxCapacity];
    }

    // 소멸자 (동적 메모리 해제)
    ~SimpleVector() {
        delete[] arr;
    }

    // push_back: 배열의 맨 뒤에 원소 추가
    void push_back(const T& value) {
        if (currentSize < maxCapacity) {
            arr[currentSize++] = value;
        }
        else {
            cout << "배열이 꽉 찼습니다" << endl;
        }
    }

    // pop_back: 배열의 마지막 원소 제거
    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
        else {
            cout << "제거할 배열이 없습니다" << endl;
        }
    }

    // size: 현재 원소 개수 반환
    int size() const {
        return currentSize;
    }

    // capacity: 배열의 최대 크기 반환
    int capacity() const {
        return maxCapacity;
    }
};

int main() {
    // 기본 생성자
    SimpleVector<int> vec;
    cout << "처음 용량: " << vec.capacity() << endl;

    // push_back
    for (int i = 0; i < 12; i++) {
        vec.push_back(i);
        cout << "Size after push_back(" << i << "): " << vec.size() << endl;
    }

    // pop_back
    vec.pop_back();
    cout << "Size after pop_back: " << vec.size() << endl;

    // 크기를 지정하는 생성자
    SimpleVector<string> strVec(5);
    strVec.push_back("Hello");
    strVec.push_back("World");
    cout << "strVec size: " << strVec.size() << ", capacity: " << strVec.capacity() << endl;

    return 0;
}
