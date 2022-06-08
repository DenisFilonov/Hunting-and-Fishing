#include "Commodity.h"

void Commodity::fillComm()
{
    char tmp[100] = "";
    cout << "Модель товара: ";
    cin.ignore();
    cin.getline(tmp, 100);
    name.setMyString(tmp);

    cout << "Отдел товара в магазине:\n1. Охотничий\n2. Рыбацкий\n3. Экипировочный\n4. Технический\nНомер: ";
    cin >> departureOf;
    if (departureOf < 0 || departureOf > 4)
    {
        cout << "\nПроизошла ошибка введённых данных! Товару присваивается код отдела #5.\n\n";
        departureOf = 5;
    }

    cout << "Категория товара: ";
    cin.ignore();
    cin.getline(tmp, 100);
    category.setMyString(tmp);

    cout << "Тип товара: ";
    cin.getline(tmp, 100);
    type.setMyString(tmp);

    cout << "Описание товара: ";
    cin.getline(tmp, 100);
    description.setMyString(tmp);

    cout << "Характеристика товара: ";
    cin.getline(tmp, 100);
    characteristic.setMyString(tmp);

    cout << "Упаковка товара. Если это расходный материал - указываются граммы/литры: ";
    cin.getline(tmp, 100);
    package.setMyString(tmp);

    cout << "Дата поступления товара в магазин: ";
    arrived.fillDate();

    cout << "Количество товара в магазине: ";
    cin >> amount;

    cout << "Цена единицы товара: ";
    cin >> price;
}

void Commodity::showComm()
{
    cout << "\n=================================================================\n";
    cout << "Модель товара: " << name.str << endl;
    cout << "Отдел товара в магазине: " << departureOf << endl;
    cout << "Категория товара: " << category.str << endl;
    cout << "Тип товара: " << type.str << endl;
    cout << "Описание товара: " << description.str << endl;
    cout << "Характеристика товара: " << characteristic.str << endl;
    cout << "Упаковка товара: " << package.str << endl;
    cout << "Дата поступления товара в магазин: " << arrived.toString() << endl;
    cout << "Количество товара в магазине: " << amount << endl;
    cout << "Цена единицы товара: " << price << endl;
    cout << "=================================================================\n\n";

    if (departureOf < 0 || departureOf > 4)
    {
        do
        {
            cout << "\nТовар не может быть закреплён ни за каким отделом, введите отдел товара, к которому он принадлежит:";
            cin >> departureOf;
        } while (departureOf < 0 || departureOf > 4);
        cout << "\nДанные изменены!\n\n";
    }
}

void Commodity::delCommData()
{
    if (name.str != NULL)	delete[] name.str;
    if (category.str != NULL)	delete[] category.str;
    if (type.str != NULL)	delete[] type.str;
    if (description.str != NULL)	delete[] description.str;
    if (characteristic.str != NULL)	delete[] characteristic.str;
    if (package.str != NULL)	delete[] package.str;
}

void Commodity::saveComm(FILE* fp)
{
    fwrite(&name.length, sizeof(int), 1, fp);
    fwrite(name.str, sizeof(char), name.length, fp);

    fwrite(&departureOf, sizeof(int), 1, fp);

    fwrite(&category.length, sizeof(int), 1, fp);
    fwrite(category.str, sizeof(char), category.length, fp);

    fwrite(&type.length, sizeof(int), 1, fp);
    fwrite(type.str, sizeof(char), type.length, fp);

    fwrite(&description.length, sizeof(int), 1, fp);
    fwrite(description.str, sizeof(char), description.length, fp);

    fwrite(&characteristic.length, sizeof(int), 1, fp);
    fwrite(characteristic.str, sizeof(char), characteristic.length, fp);

    fwrite(&package.length, sizeof(int), 1, fp);
    fwrite(package.str, sizeof(char), package.length, fp);

    fwrite(&arrived.day, sizeof(int), 1, fp);
    fwrite(&arrived.month, sizeof(int), 1, fp);
    fwrite(&arrived.year, sizeof(int), 1, fp);

    fwrite(&amount, sizeof(int), 1, fp);

    fwrite(&price, sizeof(float), 1, fp);
}

void Commodity::loadComm(FILE* fp)
{
    char tmp[100] = "";
    int size = 0;

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    name.setMyString(tmp);

    fread(&departureOf, sizeof(int), 1, fp);

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    category.setMyString(tmp);

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    type.setMyString(tmp);

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    description.setMyString(tmp);

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    characteristic.setMyString(tmp);

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    package.setMyString(tmp);

    fread(&arrived.day, sizeof(int), 1, fp);
    fread(&arrived.month, sizeof(int), 1, fp);
    fread(&arrived.year, sizeof(int), 1, fp);

    fread(&amount, sizeof(int), 1, fp);

    fread(&price, sizeof(float), 1, fp);
}


void addCommodity(Commodity*& arr, int& size)
{
    cout << endl;
    Commodity* tmp = new Commodity[++size];
    for (int i = 0; i < size - 1; i++)
    {
        tmp[i] = arr[i];
    }
    if (arr != NULL) delete[] arr;
    cout << "Введите данные о новом товаре:\n";
    tmp[size - 1].fillComm();
    arr = tmp;
    cout << "\nТовар успешно добавлен!\n\n";
}

void delCommodity(Commodity*& arr, int& size)
{
    int id = 0;
    cout << "Номер удаляемого товара: ";
    cin >> id;
    id--;

    Commodity* tmp = new Commodity[--size];
    for (int i = 0; i < size; i++)
    {
        if (i < id) tmp[i] = arr[i];
        else if (i >= id) tmp[i] = arr[i + 1];
    }
    arr[id].delCommData();
    if (arr != NULL) delete[] arr;
    arr = tmp;

    cout << "Товар, находящийся в магазине в ассортименте под номером [" << id + 1 << "] удалён из базы данных.\n\n";
}

void showStore(Commodity* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\tТовар #" << i + 1 << endl;
        arr[i].showComm();
        cout << endl;
    }
}

void editDataOfCommodity(Commodity* arr, int size)
{
    int id = -1;
    cout << "\nВведите номер товара, для которого требуется изменить информацию: ";
    cin >> id;
    id--;

    int changeInfo;
    cout << "\nКакую информацию изменить:";
    cout << "\n1) Модель товара";
    cout << "\n2) Отдел товара";
    cout << "\n3) Категория товара";
    cout << "\n4) Тип товара";
    cout << "\n5) Описание товара";
    cout << "\n6) Характеристика товара";
    cout << "\n7) Упаковка товара";
    cout << "\n8) Количество товара в магазине";
    cout << "\n9) Цена единицы товара\nВыбор: ";
    cin >> changeInfo;

    char tmp[100] = "";
    switch (changeInfo)
    {
    case 1: 
        cout << "\nМодель товара: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].name.setMyString(tmp);
        cout << "\nМодель товара изменена успешно!\n\n";
        break;

    case 2: 
        cout << "\nОтдел товара в магазине: ";
        cin >> arr[id].departureOf;
        cout << "\nОтдел товара изменён успешно!\n\n";
        break;

    case 3: 
        cout << "\nКатегория товара: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].category.setMyString(tmp);
        cout << "\nКатегория товара изменена успешно!\n\n";
        break;

    case 4: 
        cout << "\nТип товара: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].type.setMyString(tmp);
        cout << "\nТип товара изменён успешно!\n\n";
        break;

    case 5: 
        cout << "\nОписание товара: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].description.setMyString(tmp);
        cout << "\nОписание товара изменено успешно!\n\n";
        break;

    case 6: 
        cout << "\nХарактеристика товара: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].characteristic.setMyString(tmp);
        cout << "\nХарактеристика товара изменена успешно!\n\n";
        break;

    case 7: 
        cout << "\nУпаковка товара. Если это расходный материал - указываются граммы/литры: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].package.setMyString(tmp);
        cout << "\nИнформация товара изменена успешно!\n\n";
        break;

    case 8: 
        cout << "\nКоличество товара в магазине: ";
        cin >> arr[id].amount;
        cout << "\nКоличество товара изменено успешно!\n\n";
        break;

    case 9: 
        cout << "\nЦена единицы товара: ";
        cin >> arr[id].price;
        cout << "\nЦена товара изменена успешно!\n\n";
        break;

    default: if (changeInfo > 9 && changeInfo != 0) cout << "Неверно выбран пункт меню.\n\n"; break;
    }
}

int getIDbyName(Commodity* arr, int size, const char* name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(name, arr[i].name.str) == 0)
        {
            return i;
        }
        else return -1;
    }
    return -1;
}

void showCommodity(Commodity* arr, int size, const char* name)
{
    int id = getIDbyName(arr,size, name);

    if (id == -1) cout << "Товар \"" << name << "\" не обнаружен, проверьте подлинность введённых данных.\n\n";
    else arr[id].showComm();
}

void printThisSection(Commodity* arr, int size, int departureOf)
{
    int check = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].departureOf == departureOf)
        {
            arr[i].showComm();
            cout << endl;
            check++;
        }
    }
    if (check == -1) "\nИскомый отдел не обнаружен. Проверьте правильность ввода или обратитесь к консультанту\n\n";
}

void printThisCategory(Commodity* arr, int size, const char* category)
{
    int check = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].category.str, category) == 0)
        {
            arr[i].showComm();
            check++;
        }
    }
    if (check == -1) "\nИскомая категория не обнаружена. Проверьте правильность ввода или обратитесь к консультанту\n\n";
}

float totalPriseInThisSection(Commodity* arr, int size, int departureOf)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].departureOf == departureOf)
        {
            sum += arr[i].amount * arr[i].price;
        }
    }
    return sum;
}


bool upPrice(Commodity a, Commodity b)
{
    return a.price > b.price;
}
bool downPrice(Commodity a, Commodity b)
{
    return a.price < b.price;
}
bool upDate(Commodity a, Commodity b)
{
    return strcmp(a.arrived.toString(), b.arrived.toString()) <= 0;
}
bool downDate(Commodity a, Commodity b)
{
    return strcmp(a.arrived.toString(), b.arrived.toString()) >= 0;
}
void sortCommodity(Commodity* arr, int size, bool(*cmp)(Commodity,Commodity))
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (cmp(arr[j + 1], arr[j])) //if (arr[j + 1].price > arr[j].price)
            {
                swap(arr[j + 1], arr[j]);
            }           
        }
    }
    cout << "\nАссортимент отсортирован по цене.\n\n";
}



void saveStore(Commodity* arr, int size)
{
    FILE* fp;
    fopen_s(&fp, "HuntingAndFishingStore.dat", "wb");

    if (fp == NULL)
    {
        cout << "\n======================================================\n";
        cout << "==  Ошибка сохранения базы данных товаров! Проверьте файлы  ==";
        cout << "\n======================================================\n\n";
    }
    else
    {
        fwrite(&size, sizeof(int), 1, fp);
        for (int i = 0; i < size; i++)
        {
            arr[i].saveComm(fp);
        }
        fclose(fp);
        cout << "\n==============================================\n";
        cout << "==  Данные успешно сохранены в базу данных  ==";
        cout << "\n==============================================\n\n";
    }
}

void loadStore(Commodity*& arr, int& size)
{
    FILE* fp;
    fopen_s(&fp, "HuntingAndFishingStore.dat", "rb");

    if (fp == NULL)
    {
        cout << "\n============================================================\n";
        cout << "==  Ошибка выгрузки базы данных товаров! Проверьте файлы  ==";
        cout << "\n============================================================\n\n";
        arr = nullptr;
        size = 0;
    }
    else
    {
        fread(&size, sizeof(int), 1, fp);
        arr = new Commodity[size];
        for (int i = 0; i < size; i++)
        {
            arr[i].loadComm(fp);
        }
        fclose(fp);
        cout << "\n======================================================\n";
        cout << "==  Данные товаров успешно выгружены в базу данных  ==";
        cout << "\n======================================================\n\n";
    }
}