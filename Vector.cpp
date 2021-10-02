#include <iostream>
#include <ctime>

using namespace std;
class Vector;

int Vector_value()
{
    int value = rand() % 20;
    return value;
}

class Vector
{
private:
    int *number;
    int size;

public:
    Vector()
    {
        number = new int[1];
        number[0] = NULL;
        size = 1;
    }
    Vector(int size)
    {
        this->size = size;
        number = new int[size];
        for (int i = 0; i < size; i++)
        {
            number[i] = Vector_value();
        }
    }
    void get()
    {
        for (int i = 0; i < size; i++)
        {
            cout << number[i] << "\t";
        }
        cout << endl;
    }
    void set(int val, int pos)
    {
        if (pos >= size || pos < 0)
            cout << "Неправильная позиция" << endl;
        else
            number[pos] = val;
    }
    void add(int value)
    {
        int *num = new int[size + 1];
        for (int i = 0; i < size; i++)
        {
            num[i] = number[i];
        }
        delete[] number;
        number = &*num;
        number[size++] = value;
    }
    void push_back(int value)
    {
        int *num = new int[size + 1];
        num[0] = value;
        for (int i = 0; i < size; i++)
        {
            num[i + 1] = number[i];
        }
        delete[] number;
        number = &*num;
        size++;
    }
    int return_value(int pos)
    {
        return number[pos];
    }
    void show_size()
    {
        cout << "Размер вектора: " << size << endl;
    }
    ~Vector()
    {
        delete[] number;
    }
};

void main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int size;
    cout << "Введите размер вектора:"
         << "\t";
    cin >> size;
    Vector vector(size);
    //Проверка
    vector.get();
    vector.add(5);
    vector.push_back(5);
    vector.get();
    vector.show_size();
}