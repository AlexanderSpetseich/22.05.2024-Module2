#include <iostream>
#include <vector>

using namespace std;

// Функция для удаления столбца из двумерного массива
void removeColumn(vector<vector<int>>& matrix, int position) {
    // Проверка корректности позиции
    if (position < 0 || position > matrix[0].size()) {
        cout << "Ошибка: некорректная позиция." << endl;
        return;
    }

    // Удаляем указанный столбец из каждого ряда массива
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i].erase(matrix[i].begin() + position);
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
    int position;

    cout << "Исходный массив:" << endl;
    printMatrix(matrix);

    // Ввод позиции для удаления столбца
    cout << "Введите позицию столбца для удаления (0 - " << matrix[0].size() - 1 << "): ";
    cin >> position;

    removeColumn(matrix, position);

    cout << "Массив после удаления столбца:" << endl;
    printMatrix(matrix);

    return 0;
}