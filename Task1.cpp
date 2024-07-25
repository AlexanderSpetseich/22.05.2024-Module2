#include <iostream> 
#include <vector> 

using namespace std;

// Функция для добавления столбца в двумерный массив 
void addColumn(vector<vector<int>>& matrix, const vector<int>& newColumn, int position) {
    // Проверка корректности позиции 
    if (position < 0 || position > matrix[0].size()) {
        cout << "Ошибка: некорректная позиция." << endl;
        return;
    }

    // Добавляем новый столбец к каждому ряду массива 
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i].insert(matrix[i].begin() + position, newColumn[i]);
    }
}

// Функция для вывода двумерного массива 
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<vector<int>> matrix = { {5, 2, 9}, {7, 5, 2} };
    vector<int> newColumn;
    int position;

    cout << "Исходный массив:" << endl;
    printMatrix(matrix);

    // Ввод позиции для добавления нового столбца
    cout << "Введите позицию, куда добавляем новый столбец (0 - " << matrix[0].size() << "): ";
    cin >> position;

    // Ввод данных нового столбца
    cout << "Введите значения нового столбца (количество значений должно соответствовать количеству строк):" << endl;
    for (size_t i = 0; i < matrix.size(); ++i) {
        int value;
        cout << "Значение для строки " << i + 1 << ": ";
        cin >> value;
        newColumn.push_back(value);
    }

    addColumn(matrix, newColumn, position);

    cout << "Массив после добавления столбца:" << endl;
    printMatrix(matrix);

    return 0;
}