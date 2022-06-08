#include "Staff.h"

void Worker::fillWorker()
{
	char tmp[100] = "";
    cout << "ФИО сотрудника: ";
    cin.ignore();
    cin.getline(tmp, 100);
    nameOfWorker.setMyString(tmp);

    cout << "Отдел работы сотрудника: ";
    cin.getline(tmp, 100);
    department.setMyString(tmp);

    cout << "Должность сотрудника: ";
    cin.getline(tmp, 100);
    position.setMyString(tmp);

    cout << "Ранг сотрудника: ";
    cin >> rank;
    if (rank > 4)
    {
        cout << "\nПроизошла опечатка, ранг присваевается первый автоматически.\n\n";
        rank = 1; 
    }
    else if (rank == 4)
    {
        cout << "\nДля подтверждения необходим пароль: ";
        cin >> tmp;
        if (strcmp(tmp, "Mojsklep2022") == 0)
        {
            cout << "\nЗапрос подтверждён.\n\n";
            rank = 4;
        }
    }
    cout << "Дата рождения сотрудника: ";
    dateofbirth.fillDate();

    cout << "Номер телефона сотрудника: ";
    cin.ignore();
    cin.getline(tmp, 100);
    contact.setMyString(tmp);

    cout << "Адрес проживания сотрудника: ";
    cin.getline(tmp, 100);
    addressOfWorker.setMyString(tmp);

    cout << "Дата начала трудового стажа сотрудника: ";
    startwork.fillDate();

    cout << "Назначенный оклад сотрудника: ";
    cin >> salary;
}

void Worker::showWorker()
{
    cout << "\n=================================================================\n";
    cout << "ФИО сотрудника: " << nameOfWorker.str << endl;
    cout << "Отдел работы сотрудника: " << department.str << endl;
    cout << "Должность сотрудника: " << position.str << endl;
    cout << "Количество продаж сотрудника: " << amountOfSales << endl;
    cout << "Ранг сотрудника: " << rank << endl;
    cout << "Дата рождения сотрудника: " << dateofbirth.toString() << endl;
    cout << "Номер телефона сотрудника: " << contact.str << endl;
    cout << "Адрес проживания сотрудника: " << addressOfWorker.str << endl;
    cout << "Дата начала трудового стажа сотрудника: " << startwork.toString() << endl;
    cout << "Назначенный оклад сотрудника: " << salary << " грн/мес.\n";
    cout << "=================================================================\n\n";
}

void Worker::delWorkerData()
{
    if (nameOfWorker.str != NULL)	delete[] nameOfWorker.str;
    if (department.str != NULL)	delete[] department.str;
    if (contact.str != NULL)	delete[] contact.str;
    if (addressOfWorker.str != NULL)	delete[] addressOfWorker.str;
    if (position.str != NULL)	delete[] position.str;
}

void Worker::addSale(float sum)
{
    Sales* tmp = new Sales[++amountOfSales];
    for (int i = 0; i < amountOfSales - 1; i++)
    {
        tmp[i] = arr[i];
    }
    tmp[amountOfSales - 1].dateofsale.getNowDate();
    tmp[amountOfSales - 1].timeofsale.getNowTime();
    tmp[amountOfSales - 1].sumOfSales = sum;
    if (arr != NULL) delete[] arr;
    arr = tmp;
}

void Worker::delSale(int id)
{
    Sales* tmp = new Sales[--amountOfSales];
    for (int i = 0; i < amountOfSales; i++)
    {
        if (i < id) tmp[i] = arr[i];
        else if (i >= id) tmp[i] = arr[i + 1];
    }
    if (arr != NULL) delete[] arr;
    arr = tmp;
}

void Worker::saveWorker(FILE* fp)
{
    fwrite(&nameOfWorker.length, sizeof(int), 1, fp);
    fwrite(nameOfWorker.str, sizeof(char), nameOfWorker.length, fp);

    fwrite(&department.length, sizeof(int), 1, fp);
    fwrite(department.str, sizeof(char), department.length, fp);

    fwrite(&position.length, sizeof(int), 1, fp);
    fwrite(position.str, sizeof(char), position.length, fp);

    fwrite(&amountOfSales, sizeof(int), 1, fp);

    fwrite(&rank, sizeof(int), 1, fp);

    fwrite(&dateofbirth.day, sizeof(int), 1, fp);
    fwrite(&dateofbirth.month, sizeof(int), 1, fp);
    fwrite(&dateofbirth.year, sizeof(int), 1, fp);

    fwrite(&contact.length, sizeof(int), 1, fp);
    fwrite(contact.str, sizeof(char), contact.length, fp);

    fwrite(&addressOfWorker.length, sizeof(int), 1, fp);
    fwrite(addressOfWorker.str, sizeof(char), addressOfWorker.length, fp);

    fwrite(&startwork.day, sizeof(int), 1, fp);
    fwrite(&startwork.month, sizeof(int), 1, fp);
    fwrite(&startwork.year, sizeof(int), 1, fp);

    fwrite(&salary, sizeof(int), 1, fp);

    fwrite(&amountOfSales, sizeof(int), 1, fp);
    for (int i = 0; i < amountOfSales; i++)
    {
        arr[i].saveSale(fp);
    }
}

void Worker::loadWorker(FILE* fp)
{
    char tmp[100] = "";
    int size = 0;

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    nameOfWorker.setMyString(tmp);


    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    department.setMyString(tmp);

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    position.setMyString(tmp);

    fread(&amountOfSales, sizeof(int), 1, fp);

    fread(&rank, sizeof(int), 1, fp);

    fread(&dateofbirth.day, sizeof(int), 1, fp);
    fread(&dateofbirth.month, sizeof(int), 1, fp);
    fread(&dateofbirth.year, sizeof(int), 1, fp);

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    contact.setMyString(tmp);

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    addressOfWorker.setMyString(tmp);

    fread(&startwork.day, sizeof(int), 1, fp);
    fread(&startwork.month, sizeof(int), 1, fp);
    fread(&startwork.year, sizeof(int), 1, fp);

    fread(&salary, sizeof(int), 1, fp);

    fread(&amountOfSales, sizeof(int), 1, fp);
    arr = new Sales[amountOfSales];
    for (int i = 0; i < amountOfSales; i++)
    {
        arr[i].loadSale(fp);
    }
}

void addWorker(Worker*& arr, int& size)
{
    cout << endl;
    Worker* tmp = new Worker[++size];
    for (int i = 0; i < size - 1; i++)
    {
        tmp[i] = arr[i];
    }
    if (arr != NULL) delete[] arr;
    cout << "Введите данные о новом сотруднике:\n";
    tmp[size - 1].fillWorker();
    arr = tmp;
    cout << "\nСотрудник добавлен в базу данных!\n\n";
}

void delWorkerByID(Worker*& arr, int& size, int id)
{
    Worker* tmp = new Worker[--size];
    for (int i = 0; i < size; i++)
    {
        if (i < id) tmp[i] = arr[i];
        else if (i >= id) tmp[i] = arr[i + 1];
    }
    arr[id].delWorkerData();
    if (arr != NULL) delete[] arr;
    arr = tmp;

    cout << "Сотрудник успешно удалён из базы данных.\n\n";
}

void editWorkersData(Worker* arr, int size, int id)
{
    char tmp[100] = "";

    int choise;
    cout << "Изменить:\n1. ФИО сотрудника";
    cout << "\n2. Отдел работы сотрудника";
    cout << "\n3. Должность сотрудника";
    cout << "\n4. Ранг сотрудника";
    cout << "\n5. Дата рождения сотрудника";
    cout << "\n6. Номер телефона сотрудника";
    cout << "\n7. Адрес проживания сотрудника";
    cout << "\n8. Дата начала трудового стажа сотрудника";
    cout << "\n9. Назначенный оклад сотрудника\nВыбор: ";
    cin >> choise;

    switch (choise)
    {
    case 1:
        cout << "\nФИО сотрудника: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].nameOfWorker.setMyString(tmp);
        cout << "\nФИО сотрудника изменено.\n\n";
        break;

    case 2:
        cout << "\nОтдел работы сотрудника: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].department.setMyString(tmp);
        cout << "\nОтдел работы сотрудника изменён.\n\n";
        break;

    case 3:
        cout << "\nДолжность сотрудника: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].position.setMyString(tmp);
        cout << "\nДолжность сотрудника изменена.\n\n";
        break;

    case 4:
        cout << "\nРанг сотрудника: ";
        cin >> arr[id].rank;
        cout << "\nРанг сотрудника изменён.\n\n";
        break;

    case 5:
        cout << "\nДата рождения сотрудника: ";
        arr[id].dateofbirth.fillDate();
        cout << "\nДата рождения сотрудника изменена.\n\n";
        break;

    case 6:
        cout << "\nНомер телефона сотрудника: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].contact.setMyString(tmp);
        cout << "\nНомер телефона сотрудника изменён.\n\n";
        break;

    case 7:
        cout << "\nАдрес проживания сотрудника: ";
        cin.getline(tmp, 100);
        arr[id].addressOfWorker.setMyString(tmp);
        cout << "\nАдрес проживания сотрудника изменён.\n\n";
        break;

    case 8:
        cout << "\nДата начала трудового стажа сотрудника: ";
        arr[id].startwork.fillDate();
        cout << "\nДата начала трудового стажа сотрудника изменена.\n\n";
        break;

    case 9:
        cout << "\nНазначенный оклад сотрудника: ";
        cin >> arr[id].salary;
        cout << "\nНазначенный оклад сотрудника изменён.\n\n";
        break;

    default: if (choise > 9 && choise != 0 || choise < 0) cout << "Неверно выбран пункт меню.\n\n"; break;
    }
}

void showDepartment(Worker* arr, int size, const char* dep)
{
    int no = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].department.str, dep) == 0)
        {
            arr[i].showWorker();
            cout << endl;
            no++;
        }
    }
    if (no == -1) cout << "\nТакой отдел не существует, ошибка ввода!\n\n";
}

int findIDByInitials(Worker* arr, int size, const char* name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(name, arr[i].nameOfWorker.str) == 0)
        {
            return i;
        }
    }
    return -1;
}

void showAllWorkers(Worker* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\tСотрудник #" << i + 1 << endl;
        arr[i].showWorker();
    }
}

void sortWorkers(Worker* arr, int size, bool(*cmp)(Worker, Worker))
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (cmp(arr[j + 1], arr[j]))
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
    cout << "\nПерсонал отсортирован по отделам.\n\n";
}

bool upAge(Worker a, Worker b)
{
    return strcmp(a.dateofbirth.toString(),b.dateofbirth.toString()) < 0;
}

bool downAge(Worker a, Worker b)
{
    return strcmp(a.dateofbirth.toString(), b.dateofbirth.toString()) > 0;
}

bool upRank(Worker a, Worker b)
{
    return a.rank < b.rank;
}

bool downRank(Worker a, Worker b)
{
    return a.rank > b.rank;
}

bool upStartWork(Worker a, Worker b)
{
    return strcmp(a.startwork.toString(), b.startwork.toString()) > 0;
}

bool downStartWork(Worker a, Worker b)
{
    return strcmp(a.startwork.toString(), b.startwork.toString()) < 0;
}

bool upDepartment(Worker a, Worker b)
{
    return strcmp(a.department.str, b.department.str) < 0;
}

bool downDepartment(Worker a, Worker b)
{
    return strcmp(a.department.str, b.department.str) > 0;
}



void saveWorkers(Worker* arr, int size)
{
    FILE* fp;
    fopen_s(&fp, "Staff.dat", "wb");

    if (fp == NULL)
    {
        cout << "\n==================================================================\n";
        cout << "==  Ошибка сохранения базы данных сотрудников! Проверьте файлы  ==";
        cout << "\n==================================================================\n\n";
    }
    else
    {
        fwrite(&size, sizeof(int), 1, fp);
        for (int i = 0; i < size; i++)
        {
            arr[i].saveWorker(fp);
        }
        fclose(fp);
        cout << "\n==============================================\n";
        cout << "==  Данные успешно сохранены в базу данных  ==";
        cout << "\n==============================================\n\n";
    }
}

void loadWorkers(Worker*& arr, int& size)
{
    FILE* fp;
    fopen_s(&fp, "Staff.dat", "rb");

    if (fp == NULL)
    {
        cout << "\n================================================================\n";
        cout << "==  Ошибка выгрузки базы данных сотрудников! Проверьте файлы  ==";
        cout << "\n================================================================\n\n";
        arr = nullptr;
        size = 0;
    }
    else
    {
        fread(&size, sizeof(int), 1, fp);
        arr = new Worker[size];
        for (int i = 0; i < size; i++)
        {
            arr[i].loadWorker(fp);
        }
        fclose(fp);
        cout << "\n==========================================================\n";
        cout << "==  Данные сотрудников успешно выгружены в базу данных  ==";
        cout << "\n==========================================================\n\n";
    }
}
