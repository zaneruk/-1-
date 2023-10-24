// рк1 Синюшин.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    char** prez = new char* [100];
    char** srok = new char* [100];
    int* prior = new int[100];
    char** mab = new char* [100];
    bool more = false;
    int count = 0;
    while (more == false) {
        cout << "Введите название задачи: ";
        char buffer1[100];
        cin.getline(buffer1, 100);
        prez[count] = new char[strlen(buffer1) + 1];
        strcpy(prez[count], buffer1);
        cout << "Введите срок выполнения задачи: ";
        char buffer2[100];
        cin.getline(buffer2, 100);
        srok[count] = new char[strlen(buffer2) + 1];
        strcpy(srok[count], buffer2);
        cout << "Введите приоритет задачи (от 1 до 10): ";
        cin >> prior[count];
        cin.ignore();
        cout << "Задача добавлена! \n";
        cout << "Хотите добавить ещё 1 задачу?(da/net): ";
        char buffer3[100];
        cin.getline(buffer3, 100);
        mab[count] = new char[strlen(buffer3) + 1];
        strcpy(mab[count], buffer3);
        if ((strcmp(mab[count], "net") == 0)) {
            more = true;
            count++;
            break;
        }
        count++;
    }
    //сортировка по приоритету
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (prior[j] < prior[j + 1]) {
                swap(prior[j], prior[j + 1]);
            }
        }
    }
    //вывод отсортированного списка дел
    cout << "\nОтсортированный по приоритету список задач: \n";
    for (int i = 0; i < count; ++i) {
        cout << i + 1 << " Задача: " << prez[i] << " Приоритет: " << prior[i] << " Срок выполонения: " << srok[i] << endl;
    }
    //освобождаем место
    for (int i = 0; i < count; i++) {
        delete[] prez[i];
        delete[] srok[i];
        delete[] mab[i];
    }
    delete[] prez;
    delete[] prior;
    delete[] srok;
    delete[] mab;
    return 0;
}