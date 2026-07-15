// function template(1)

#include <iostream>

using namespace std;

class ComplexNumber {
    int real_part;
    int imaginary_part;

public:
    ComplexNumber() {
        real_part = 0;
        imaginary_part = 0;
    }

    ComplexNumber(int real_part, int imaginary_part) {
        this->real_part = real_part;
        this->imaginary_part = imaginary_part;
    }

    void set(int real_part, int imaginary_part) {
        this->real_part = real_part;
        this->imaginary_part = imaginary_part;
    }

    bool operator>(ComplexNumber& other) {
        return real_part > other.real_part &&
               imaginary_part > other.imaginary_part;
    }

    bool operator<(ComplexNumber& other) {
        return real_part < other.real_part &&
               imaginary_part < other.imaginary_part;
    }

    bool operator==(ComplexNumber& other) {
        return real_part == other.real_part &&
               imaginary_part == other.imaginary_part;
    }

    bool operator==(int value) {
        return real_part == value && imaginary_part == value;
    }

    ComplexNumber operator=(ComplexNumber& other) {
        real_part = other.real_part;
        imaginary_part = other.imaginary_part;
        return *this;
    }

    friend ostream& operator<<(ostream& output, ComplexNumber value);
    friend istream& operator>>(istream& input, ComplexNumber& value);
};

ostream& operator<<(ostream& output, ComplexNumber value) {
    if (value.imaginary_part < 0) {
        output << value.real_part << " " << value.imaginary_part << "i";
    } else {
        output << value.real_part << " + " << value.imaginary_part << "i";
    }
    return output;
}

istream& operator>>(istream& input, ComplexNumber& value) {
    cout << "Enter the real part: ";
    input >> value.real_part;
    cout << "Enter the imaginary part: ";
    input >> value.imaginary_part;
    return input;
}

const int column_count = 4;
const int row_count = 2;

template<typename T>
void print_zero_columns(T matrix[row_count][column_count]) {
    bool found_zero_column = false;

    for (int column = 0; column < column_count; column++) {
        bool column_contains_zero = false;

        for (int row = 0; row < row_count; row++) {
            if (matrix[row][column] == 0) {
                column_contains_zero = true;
            }
        }

        if (column_contains_zero) {
            found_zero_column = true;
            cout << "column " << column + 1 << endl;
            for (int row = 0; row < row_count; row++) {
                cout << matrix[row][column] << "  ";
            }
            cout << endl;
        }
    }

    if (!found_zero_column) {
        cout << "no zero column\n";
    }
}

int main() {
    setlocale(LC_ALL, "Ru");

    int integer_matrix[row_count][column_count] = {
        {1, 2, 0, 0},
        {5, 6, 7, 8}
    };

    double double_matrix[row_count][column_count] = {
        {1.0, 0.0, 3.6, 7.4},
        {4.5, 6.6, 7.9, 8.9}
    };

    ComplexNumber complex_matrix[row_count][column_count] = {
        {{1, 0}, {2, 4}, {3, 6}, {0, 0}},
        {{4, 5}, {6, 6}, {7, 9}, {8, 9}}
    };

    cout << "Search in the int matrix:\n";
    print_zero_columns(integer_matrix);
    cout << "\nSearch in the double matrix:\n";
    print_zero_columns(double_matrix);
    cout << "\nSearch in the complex matrix:\n";
    print_zero_columns(complex_matrix);

    return 0;
}
