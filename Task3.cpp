#include <iostream>
#include <vector>

using namespace std;

// Функция для выполнения циклического сдвига строк
void shiftRows(vector<vector<int>>& matrix, int shifts) {
    int M = matrix.size();
    int N = matrix[0].size();
    shifts = shifts % M; // Убираем лишние полные обороты

    if (shifts < 0) shifts += M; // Для отрицательных сдвигов

    vector<vector<int>> temp(matrix);  // Создаем временную матрицу для перемещения

    for (int i = 0; i < M; ++i) {
        matrix[i] = temp[(i - shifts + M) % M]; // Циклический сдвиг
    }
}

// Функция для выполнения циклического сдвига столбцов
void shiftColumns(vector<vector<int>>& matrix, int shifts) {
    int M = matrix.size();
    int N = matrix[0].size();
    shifts = shifts % N; // Убираем лишние полные обороты

    if (shifts < 0) shifts += N; // Для отрицательных сдвигов

    vector<vector<int>> temp = matrix; // Создаем временную матрицу для перемещения

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < M; ++i) {
            matrix[i][j] = temp[(i - shifts + M) % M][j]; // Циклический сдвиг
        }
    }
}

// Функция для вывода матрицы
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
    int M, N;
    cout << "Введите количество строк (M): ";
    cin >> M;
    cout << "Введите количество столбцов (N): ";
    cin >> N;

    vector<vector<int>> matrix(M, vector<int>(N));

    // Заполнение матрицы значениями
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "Элемент [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    int shifts;
    char direction;
    cout << "Введите количество сдвигов: ";
    cin >> shifts;
    cout << "Для сдвига строк введите 'r' (вправо) или 'l' (влево): ";
    cin >> direction;

    if (direction == 'r') {
        shiftRows(matrix, shifts);
    }
    else if (direction == 'l') {
        shiftRows(matrix, -shifts); // Для сдвига влево
    }

    cout << "Введите количество сдвигов столбцов: ";
    cin >> shifts;
    cout << "Для сдвига столбцов введите 'd' (вниз) или 'u' (вверх): ";
    cin >> direction;

    if (direction == 'd') {
        shiftColumns(matrix, shifts);
    }
    else if (direction == 'u') {
        shiftColumns(matrix, -shifts); // Для сдвига вверх
    }

    cout << "Результирующая матрица:" << endl;
    printMatrix(matrix);

    return 0;
}