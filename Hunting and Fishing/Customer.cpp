#include "Customer.h"

void Client::fillCustomer()
{
    char tmp[100] = "";
    cout << "��� �������: ";
    cin.ignore();
    cin.getline(tmp, 100);
    nameOfClient.setMyString(tmp);

    cout << "��-��� �������: ";
    cin >> idNumber;

    cout << "���� �������� �������: ";
    dateOfBirth.fillDate();

    cout << "����� �������� �������: ";
    cin.ignore();
    cin.getline(tmp, 100);
    telNumber.setMyString(tmp);

    cout << "����������� ����� �������: ";
    cin.getline(tmp, 100);
    email.setMyString(tmp);

    cout << "����� ���������� �������: ";
    cin.getline(tmp, 100);
    addressOfClient.setMyString(tmp);
}

void Client::showCustomer()
{
    cout << "\n=================================================================\n";
    cout << "��� �������: " << nameOfClient.str << endl;
    cout << "��-��� �������: " << idNumber << endl;
    cout << "���� �������� �������: " << dateOfBirth.toString() << endl;
    cout << "����� �������� �������: " << telNumber.str << endl;;
    cout << "����������� ����� �������: " << email.str << endl;
    cout << "����� ���������� �������: " << addressOfClient.str << endl;
    cout << "���������� ������� �������: " << amountofbuying << endl;
    cout << "=================================================================\n\n";
}

void Client::delCustomerData()
{
    if (nameOfClient.str != NULL)	delete[] nameOfClient.str;
    if (telNumber.str != NULL)	delete[] telNumber.str;
    if (email.str != NULL)	delete[] email.str;
    if (addressOfClient.str != NULL)	delete[] addressOfClient.str;
}

void Client::addBuy(float sum)
{
    Sales* tmp = new Sales[++amountofbuying];
    for (int i = 0; i < amountofbuying - 1; i++)
    {
        tmp[i] = arrs[i];
    }
    tmp[amountofbuying - 1].dateofsale.getNowDate();
    tmp[amountofbuying - 1].timeofsale.getNowTime();
    tmp[amountofbuying - 1].sumOfSales = sum;
    if (arrs != NULL) delete[] arrs;
    arrs = tmp;
}

void Client::delBuy(int id)
{
    Sales* tmp = new Sales[--amountofbuying];
    for (int i = 0; i < amountofbuying; i++)
    {
        if (i < id) tmp[i] = arrs[i];
        else if (i >= id) tmp[i] = arrs[i + 1];
    }
    if (arrs != NULL) delete[] arrs;
    arrs = tmp;
}

float Client::calcTotalBuys()
{
    float s = 0;
    for (int i = 0; i < amountofbuying; i++)
    {
        s += arrs[i].sumOfSales;
    }
    return s;
}

void Client::saveCustomer(FILE* fp)
{
    fwrite(&nameOfClient.length, sizeof(int), 1, fp);
    fwrite(nameOfClient.str, sizeof(char), nameOfClient.length, fp);

    fwrite(&idNumber, sizeof(long long), 1, fp);

    fwrite(&dateOfBirth.day, sizeof(int), 1, fp);
    fwrite(&dateOfBirth.month, sizeof(int), 1, fp);
    fwrite(&dateOfBirth.year, sizeof(int), 1, fp);

    fwrite(&telNumber.length, sizeof(int), 1, fp);
    fwrite(telNumber.str, sizeof(char), telNumber.length, fp);

    fwrite(&email.length, sizeof(int), 1, fp);
    fwrite(email.str, sizeof(char), email.length, fp);

    fwrite(&addressOfClient.length, sizeof(int), 1, fp);
    fwrite(addressOfClient.str, sizeof(char), addressOfClient.length, fp);

    fwrite(&amountofbuying, sizeof(int), 1, fp);
    for (int i = 0; i < amountofbuying; i++)
    {
        arrs[i].saveSale(fp);
    }
}

void Client::loadCustomer(FILE* fp)
{
    char tmp[100] = "";
    int size = 0;

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    nameOfClient.setMyString(tmp);

    fread(&idNumber, sizeof(long long), 1, fp);

    fread(&dateOfBirth.day, sizeof(int), 1, fp);
    fread(&dateOfBirth.month, sizeof(int), 1, fp);
    fread(&dateOfBirth.year, sizeof(int), 1, fp);

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    telNumber.setMyString(tmp);

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    email.setMyString(tmp);

    fread(&size, sizeof(int), 1, fp);
    fread(tmp, sizeof(char), size, fp);
    addressOfClient.setMyString(tmp);


    fread(&amountofbuying, sizeof(int), 1, fp);
    arrs = new Sales [amountofbuying];
    for (int i = 0; i < amountofbuying; i++)
    {
        arrs[i].loadSale(fp);
    }
}

void addCustomer(Client*& arr, int& size)
{
    cout << endl;
    Client* tmp = new Client[++size];
    for (int i = 0; i < size - 1; i++)
    {
        tmp[i] = arr[i];
    }
    if (arr != NULL) delete[] arr;
    cout << "������� ������ � ����� ����������:\n";
    tmp[size - 1].fillCustomer();
    arr = tmp;
    cout << "\n������ ������� �������� � ���� ������!\n\n";
}

void delCustomerByID(Client*& arr, int& size, int id)
{
    Client* tmp = new Client[--size];
    for (int i = 0; i < size; i++)
    {
        if (i < id) tmp[i] = arr[i];
        else if (i >= id) tmp[i] = arr[i + 1];
    }
    arr[id].delCustomerData();
    if (arr != NULL) delete[] arr;
    arr = tmp;

    cout << "��������� \"" << arr[id].nameOfClient.str << "\" ����� �� ���� ������.\n\n";
}

void editCustomersData(Client* arr, int size, int id)
{
    char tmp[100] = "";

    int choise;
    cout << "\n\n1. ��� �������";
    cout << "\n2. ��-��� �������";
    cout << "\n3. ���� �������� �������";
    cout << "\n4. ����� �������� �������";
    cout << "\n5. ����������� ����� �������";
    cout << "\n6. ����� ���������� �������\n�����: ";
    cin >> choise;

    switch (choise)
    {
    case 1:
        cout << "\n��� �������: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].nameOfClient.setMyString(tmp);
        cout << "��� ������� ��������.\n\n";
        break;

    case 2:
        cout << "\n��-��� �������: ";
        cin >> arr[id].idNumber;
        cout << "��-��� ������� ������.\n\n";
        break;

    case 3:
        cout << "\n���� �������� �������: ";
        arr[id].dateOfBirth.fillDate();
        cout << "���� �������� ������� ��������.\n\n";
        break;

    case 4:
        cout << "\n����� �������� �������: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].telNumber.setMyString(tmp);
        cout << "����� �������� ������� ������.\n\n";
        break;

    case 5:
        cout << "\n����������� ����� �������: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].email.setMyString(tmp);
        cout << "����������� ����� ������� ��������.\n\n";
        break;

    case 6:
        cout << "\n����� ���������� �������: ";
        cin.ignore();
        cin.getline(tmp, 100);
        arr[id].addressOfClient.setMyString(tmp);
        cout << "����� ���������� ������� ������.\n\n";
        break;

    default: if (choise > 6 && choise != 0 || choise < 0) cout << "������� ������ ����� ����.\n\n"; break;
    }
}

void findCustomerByName(Client* arr, int size, const char* name)
{
    int id = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].nameOfClient.str, name) == 0)
        {
            id = i;
        }
    }

    if (id == -1) cout << "������ \"" << name << "\" �� ���������, ��������� ����������� �������� ������.\n\n";
    else
    {
        arr[id].showCustomer();
    }
}

int findCustomerByPhoneNumber(Client* arr, int size, const char* phone)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(phone, arr[i].telNumber.str) == 0)
        {
            return i;
        }
        else return -1;
    }
    return -1;
}

void showAllCustomers(Client* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\t������ #" << i + 1 << endl;
        arr[i].showCustomer();
        cout << endl;
    }
}

void sortCustomersByTotalBuying(Client* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j + 1].calcTotalBuys() > arr[j].calcTotalBuys())
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}

float calcCustomersPurchases(Client* arr, int size, const char* number)
{
    float sum = 0;
    int id = findCustomerByPhoneNumber(arr, size, number);

    if (id == -1) return 0;
    else
    {
        for (int i = 0; i < arr[id].amountofbuying; i++)
        {
            sum += arr[id].arrs[i].sumOfSales;
        }
        return sum;
    }
    return -1;
}

float calcAllCustomersPurchases(Client* arr, int size)
{
    long long sum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < arr[i].amountofbuying; j++)
        {
            sum += arr[i].arrs[j].sumOfSales;
        }
    }
    return sum;
}

void saveClients(Client* arr, int size)
{
    FILE* fp;
    fopen_s(&fp, "Client.dat", "wb");

    if (fp == NULL)
    {
        cout << "\n======================================================\n";
        cout << "==  ������ ���������� ���� ������ ��������! ��������� �����  ==";
        cout << "\n======================================================\n\n";
    }
    else
    {
        fwrite(&size, sizeof(int), 1, fp);
        for (int i = 0; i < size; i++)
        {
            arr[i].saveCustomer(fp);
        }
        fclose(fp);
        cout << "\n==============================================\n";
        cout << "==  ������ ������� ��������� � ���� ������  ==";
        cout << "\n==============================================\n\n";
    }
}

void loadClients(Client*& arr, int& size)
{
    FILE* fp;
    fopen_s(&fp, "Client.dat", "rb");

    if (fp == NULL)
    {
        cout << "\n=============================================================\n";
        cout << "==  ������ �������� ���� ������ ��������! ��������� �����  ==";
        cout << "\n=============================================================\n\n";
        arr = nullptr;
        size = 0;
    }
    else
    {
        fread(&size, sizeof(int), 1, fp);
        arr = new Client[size];
        for (int i = 0; i < size; i++)
        {
            arr[i].loadCustomer(fp);
        }
        fclose(fp);
        cout << "\n======================================================\n";
        cout << "==  ������ �������� ������� ��������� � ���� ������ ==";
        cout << "\n======================================================\n\n";
    }

}
