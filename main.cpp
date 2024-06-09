#include <iostream>

using namespace std;


//Задан массив из k чисел. Определить количество инверсий в массиве (т. е. таких
//пар элементов, в которых большее число находится слева от меньшего).

void task1(){
    int k,count = 0;
    cout << "Enter array length: ";
    cin >> k;
    int *array = new int[k];
    for(int i = 0; i < k; i++)
    {
        cout<<"Enter array["<<i<<"] ";
        cin>>array[i];
    }
    for(int i = 0; i < k; i++) {
            if (array[i] > array[i+1]) {
                count++;
            }
    }
    cout<<"Count of inversions = "<<count<<endl;
    delete []array;
}

//В матрице размером M x N переставить строки так, чтобы на главной диагонали
//матрицы были расположены элементы, наибольшие по абсолютной величине.

void swapRows(int** matrix, int row1, int row2, int N) {
    for (int i = 0; i < N; ++i) {
        int temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

void rearrangeMatrix(int** matrix, int M, int N) {
    for (int i = 0; i < min(M, N); ++i) {
        int maxRow = i;
        for (int j = i + 1; j < M; ++j) {
            if (abs(matrix[j][i]) > abs(matrix[maxRow][i])) {
                maxRow = j;
            }
        }
        if (maxRow != i) {
            swapRows(matrix, i, maxRow, N);
        }
    }
}

void printMatrix(int** matrix, int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void task2(){
    int m, n;
    cout << "Enter the number of rows (M): ";
    cin >> m;
    cout << "Enter the number of columns (N): ";
    cin >> n;

    int** matrix = new int*[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];
    }

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Matrix [" << i << "]["<<j<<"]"; cin >> matrix[i][j];
        }
    }

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, m, n);

    rearrangeMatrix(matrix, m, n);

    cout << "Rearranged Matrix:" << endl;
    printMatrix(matrix, m, n);

    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

//Дан массив A размера N. Сформировать новый массив B того же размера по
//следующему правилу: элемент BK равен сумме элементов массива A с номерами от
//1 до K.

void task3(){
    int n;
    cout << "Enter the size of the array (N): ";
    cin >> n;

    // Создаем массивы A и B
    int* A = new int[n];
    int* B = new int[n];

    // Считываем элементы массива A
    cout << "Enter the elements of the array A:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Формируем массив B
    for (int i = 0; i < n; ++i) {
        B[i] = 0;
        for (int j = 0; j <= i; ++j) {
            B[i] += A[j];
        }
    }

    // Выводим массив B
    cout << "Array B:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;

    // Освобождаем память
    delete[] A;
    delete[] B;

}


//Дан целочисленный массив размера N. Преобразовать массив, увеличив его первую
//серию наибольшей длины на один элемент.
void task4(){
    int n;
    cout << "Enter the size of the array (N): ";
    cin >> n;

    // Создаем массив A
    int* A = new int[n];

    // Считываем элементы массива A
    cout << "Enter the elements of the array A:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Находим первую серию наибольшей длины
    int maxSeriesLength = 1;
    int maxSeriesStart = 0;
    int currentSeriesLength = 1;
    int currentSeriesStart = 0;

    for (int i = 1; i < n; ++i) {
        if (A[i] == A[i - 1]) {
            currentSeriesLength++;
        } else {
            if (currentSeriesLength > maxSeriesLength) {
                maxSeriesLength = currentSeriesLength;
                maxSeriesStart = currentSeriesStart;
            }
            currentSeriesStart = i;
            currentSeriesLength = 1;
        }
    }

    // Проверяем последнюю серию
    if (currentSeriesLength > maxSeriesLength) {
        maxSeriesLength = currentSeriesLength;
        maxSeriesStart = currentSeriesStart;
    }

    // Создаем новый массив увеличенного размера
    int newN = n + 1;
    int* B = new int[newN];

    // Копируем элементы массива, увеличивая первую серию наибольшей длины на один элемент
    int j = 0;
    for (int i = 0; i < n; ++i) {
        B[j++] = A[i];
        if (i == maxSeriesStart + maxSeriesLength - 1) {
            B[j++] = A[i]; // Добавляем элемент, чтобы увеличить серию
        }
    }

    // Выводим новый массив B
    cout << "Array B:" << endl;
    for (int i = 0; i < newN; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;

    // Освобождаем память
    delete[] A;
    delete[] B;

}

//Дана квадратная матрица порядка M. Обнулить элементы матрицы, лежащие ниже
//главной диагонали. Условный оператор не использовать.
void task5(){
    int m;
    cout << "Enter the order of the matrix (M): ";
    cin >> m;

    // Создаем квадратную матрицу A
    int** matrix = new int*[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[m];
    }

    // Считываем элементы матрицы A
    cout << "Enter the elements of the matrix A:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "Matrix [" << i << "]["<<j<<"]"; cin >> matrix[i][j];
        }
    }

    // Обнуляем элементы ниже главной диагонали
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
            matrix[i][j] = 0;
        }
    }

    // Выводим измененную матрицу
    cout << "Modified Matrix:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Освобождаем память
    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    task1();
//    task2();
//    task3();
//    task4();
//    task5();
    return 0;
}
