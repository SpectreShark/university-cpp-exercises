// exception(6)

#include <iostream>

using namespace std;

class IntVector {
protected:
    int* data;
    int size;

public:
    ~IntVector() {
        delete[] data;
    }

    IntVector(int size) {
        this->size = size;
        data = new int[size];
    }

    int& at(int index) {
        if ((index < 0) || (index >= size)) {
            throw string{"Bad index"};
        }
        return data[index];
    }

    int length() {
        return size;
    }

    IntVector operator+(IntVector& other) {
        for (int index = 0; index < size; index++) {
            if (at(index) == 0) {
                throw string{"right mass has null"};
            }
        }
        for (int index = 0; index < other.length(); index++) {
            if (other.at(index) == 0) {
                throw string{"left mass has null"};
            }
        }

        int result_size = min(size, other.length());
        IntVector result(result_size);
        for (int index = 0; index < result_size; index++) {
            result.at(index) = at(index) + other.at(index);
        }
        return result;
    }

    IntVector operator-(IntVector& other) {
        for (int index = 0; index < size; index++) {
            if (at(index) == 0) {
                throw string{"right mass has null"};
            }
        }
        for (int index = 0; index < other.length(); index++) {
            if (other.at(index) == 0) {
                throw string{"left mass has null"};
            }
        }

        int result_size = min(size, other.length());
        IntVector result(result_size);
        for (int index = 0; index < result_size; index++) {
            result.at(index) = at(index) - other.at(index);
        }
        return result;
    }

    void print() {
        cout << "{";
        for (int index = 0; index < size; index++) {
            cout << data[index];
            if (index != size - 1) {
                cout << ",";
            }
        }
        cout << "}\n";
    }

    void input() {
        for (int index = 0; index < size; index++) {
            cout << "data[" << index << "]= ";
            cin >> data[index];
        }
    }
};

void test_wrong_index() {
    IntVector vector(3);
    vector.at(0) = 2;
    vector.at(1) = 2;
    vector.at(2) = 2;

    cout << "element at 0: ";

    try {
        cout << vector.at(0) << endl;
    } catch (string error) {
        cout << "ERROR: " << error << endl;
    }

    cout << "element at 10: ";
    try {
        cout << vector.at(10) << endl;
    } catch (string error) {
        cout << "ERROR: " << error << endl;
    }
}

void test_addition() {
    IntVector left(3);
    IntVector right(5);

    left.at(0) = 2;
    left.at(1) = 5;
    left.at(2) = 6;

    right.at(0) = 2;
    right.at(1) = 5;
    right.at(2) = 6;
    right.at(3) = 2;
    right.at(4) = 5;

    cout << "result 1:\n";

    try {
        (left + right).print();
        cout << "\n";
    } catch (string error) {
        cout << "ERROR: " << error << endl;
    }

    left.at(1) = 0;

    cout << "result 2:\n";

    try {
        (left + right).print();
        cout << "\n";
    } catch (string error) {
        cout << "ERROR: " << error << endl;
    }

    left.at(1) = 1;
    right.at(0) = 0;

    cout << "result 3:\n";

    try {
        (left + right).print();
        cout << "\n";
    } catch (string error) {
        cout << "ERROR: " << error << endl;
    }
}

int main() {
    test_wrong_index();
    test_addition();

    return 0;
}
