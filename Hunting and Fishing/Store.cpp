#include"Customer.h"
#include<Windows.h>


int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int amountOfCommodity = 0;
	Commodity* arrcom = nullptr;
	loadStore(arrcom, amountOfCommodity);

	int amountOfworkers = 0;
	Worker* arrw = nullptr;
	loadWorkers(arrw, amountOfworkers);

	int amountOfClients = 0;
	Client* arrcl = nullptr;
	loadClients(arrcl, amountOfClients);

	int menu, menu1, menu2, menu3;

	char password[20] = "";
	int authoris;

	char name[100] = "";
	char s[100] = "";
	int id = -1;
	int iWorker = 0, iCostumer = 0;
	int amount = 0;
	float sum = 0;
	long long lsum = 0;

	cout << "\n============================================================\n";
	cout << "==  ������ ������ ��������� �������� \"Hunting && Fishing\" ==";
	cout << "\n============================================================\n";
	//�� ��� ����� �� ������� ����������� �����������, � �������� ����� ���-�� �������� ��� ���������

	//addWorker(arrw, amountOfworkers); //�������� ���������
	//showAllWorkers(arrw, amountOfworkers); //��������
	//showAllCustomers(arrcl, amountOfClients); //��������
	//showStore(arrcom, amountOfCommodity); //��������


	//�������: �������-7

	do
	{//� ������ ������ �� 3 ���� ����������: ���� ��� �������, ������ ��� ����������/������������
		cout << "\n1. ���� ��� ����������.\n";//��������� � �������� ��������� �� ������� ������
		cout << "2. ���� ��� ���������.\n";//��������� ��������� ����� � ����������� ��� ����������� � ��� ���� ����� ���� ��� ����������, ���� ��� �����������
		cout << "3. ���� ��� ����������.\n";
		cout << "0. ��������� ������� � ���������.\n�����: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			cout << "\n\n����� ���������� � ������� ����� � �������!\n\n��� �����������, �������� ����� ����� ����.\n���, ������������ � ����� ��������� � ��� �������������, ����� �� ������ \"����������\"\n\n";
			do
			{
				cout << "1. ���������� �� ��������.\n";
				cout << "2. ����� �����.\n";
				cout << "3. ����������� ������ �������.\n";
				cout << "4. ����������� �����.\n";
				cout << "5. �������� ���� ����� ������ ���������.\n";
				cout << "6. �������� ���� ����� ������� ������.\n";
				cout << "0. ��������� � ������� ����.\n�����: ";
				cin >> menu1;

				switch (menu1)
				{
				case 1:
					do
					{
						cout << "\n� ����� �������� ���� 4 ������, ������� �� ������ ��������:\n";
						cout << "1.���������\n2.��������\n3.�����������\n4.�������������\n";
						cout << "\n�� ���� ������� ���� � ������� ��� ��������� � ���� �������, �������� � ������ ���������.\n";
						cout << "����� ���������, ������� 0.\n����������� ���������� �� ����������� ������: "; cin >> id;

						switch (id)
						{
						case 1: cout << "\n� ��������� ������ ������������ ���� ��������� � �������������� ������ ������ �������������� � �������.\n"
							<< "��� ��, ������������ ���������� � ������ ��� ������, ��������: �������� �������������, ������ � ��� �����.\n"
							<< "������ ����� ����� ����� ����� ������ ��� ���.������������ ��� ������, ������ �������� � ����� ��� �������� �������� ����� ������ ���������.\n";
							break;

						case 2: cout << "\n� �������� ������ ������������ ���� ������� ���� ������ � ���������� ����� �������������� � �������.\n"
							<< "��� ��, ������������ ���������� ��� ��������������� ����� ����, ��������: ��������, �����, �����, ���������, � ��� �����.\n"
							<< "������ ����� ����� ����� ����� ������ ��� ���������� ��������: ����������� �������, �������� ������, �������, �����/�����.\n";
							break;

						case 3: cout << "\n� ����������� ������ ������������ ��� � �������� � �������, ��������, ��� � ������������-��������������, ��������� ������ ����� � ��������������.\n"
							<< "��� ��, ������������ ��������� ������ � ��������� ��������� ��� ����� �������, ��� ��������� ������, �������� ��������, ������-�������������� �������� � ��� �����.\n";
							break;

						case 4: cout << "\n� ������������� ������ ������������ ����� � ������� � ���������� ��������� ��� ��������� ��������, � �������� �� ������ ����������� �� �����, �������, ��� �������� ����, ���������� ���� �������.\n"
							<< "� ���� ������ �� ��� ���������� �� ����� ���� � ����, ��� ������� � �����:"
							<< "\n\n> ����������������� ������� � ����������� ���������� � � ���������� ������� ��� ������ ������� ��� ��������� ��� ��������� ������.\n"
							<< "\n> ˸���� �������, ������� ������� �� ������� � ����� ��� ����� ��������� ��� ������� ������.\n"
							<< "\n> ��� ��, ���������� ������� ���� ������ ������, ��� ������ ���� ��������, ���������� ��������� �������� ������.\n"
							<< "\n� ��� ���� ������� �����: �������� ������, ������� � ����������� �������, ��������, ������, ������ � �������. � �� ��� ��� ����� �������, ����� ������ �� ������ ���� �����������!\n";
							break;

						default: if (menu1 > 4 && menu1 != 0 || menu1 < 0) cout << "������� ������ ����� ����.\n\n"; break;
						}
					} while (id != 0);

					cout << "\n\n����������? ����� ��� �����!\n�� ������ ������ ���������� � ��� � ������� �� �������������� �����������, ��� ��������� ����� ������������� �������� ��� ����-���������."
						<< "\n��� ��������� �������� �������������� ������ ����, �� � �������� ������� � ��������� ��� � ����� ������ ������ ��������, ������� �� ��������� ����������!\n"
						<< "������ ��� ������� �������!\n\n";

					break;

				case 2:
					cout << "\n������� �������� ������: ";
					cin.ignore();
					cin.getline(name, 100);
					showCommodity(arrcom, amountOfCommodity, name);
					break;

				case 3:
					showStore(arrcom, amountOfCommodity);
					break;

				case 4:
				{
					cout << "1. �� ���� - �� �����������.\n";
					cout << "2. �� ���� - �� ��������.\n";
					cout << "3. �� ���� ����������� - �� �����������.\n";
					cout << "4. �� ���� ����������� - �� ��������.\n";
					cout << "0. ��������� � ���������� ����.\n�����: ";
					cin >> menu3;

					bool (*Functions[])(Commodity, Commodity) = { upPrice, downPrice, upDate, downDate };
					if (menu3 >= 1 && menu3 <= 4)
					{
						sortCommodity(arrcom, amountOfCommodity, Functions[menu3 - 1]);
						cout << "\n����� ������������.\n�������� � ���� ����� #3 ��� ����������� ���������\n\n";
					}
					else if (menu3 < 0 && menu3 > 4) cout << "\n������� ������ ����� ����, �������� � 1 �� 4!\n\n";
				}
					break;

				case 5:
					cout << "\n������� ��������� ������: ";
					cin.ignore();
					cin.getline(name, 100);
					printThisCategory(arrcom, amountOfCommodity, s);
					break;

				case 6:
					cout << "\n������� ����� ������ ������: ";
					cin >> id;
					printThisSection(arrcom, amountOfCommodity, id);
					break;

				default: if (menu1 > 11 && menu1 != 0 || menu1 < 0) cout << "������� ������ ����� ����.\n\n"; break;
				}
			} while (menu1 != 0);

			break;

		case 2: //���� ��� ���������
			do
			{
				cout << "\n1. �������� ������� � ���� ������.\n";
				cout << "2. ����� ������� �� ��� ����������.\n";
				cout << "3. ����������� ������ ���� ��������.\n";
				cout << "4. ����������� ������ �������.\n";
				cout << "5. �������� �������.\n";
				cout << "0. ��������� � ������� ����.\n�����: ";
				cin >> menu1;

				switch (menu1)
				{
				case 1:
					addCustomer(arrcl, amountOfClients);
					break;

				case 2:
					cout << "\n\n1. ������ ���";
					cout << "\n2. ������ ����� ��������\n�����: ";
					cin >> menu2;
					switch (menu2)
					{
					case 1:
						cout << "\n��� �������: ";
						cin.ignore();
						cin.getline(name, 100);
						findCustomerByName(arrcl, amountOfClients, name);
						break;
					case 2:
						cout << "\n��������� �������: ";
						cin.ignore();
						cin.getline(s, 100);
						iCostumer = findCustomerByPhoneNumber(arrcl, amountOfClients, s);

						if (iCostumer == -1) cout << "\n������ �� ������, ��������� �������� ������.\n\n";
						else arrcl[iCostumer].showCustomer();
						break;

					default: if (menu2 > 2 && menu2 != 0 || menu2 < 0) cout << "\n������� ������ ����� ����.\n\n"; break;
					}
					break;

				case 3:
					cout << "\n���������� ����������� ����� �������!\n������� ���� ��������: ";
					cin.ignore();
					cin.getline(name, 100);
					cout << "������� ���� ����: ";
					cin >> authoris;

					iWorker = findIDByInitials(arrw, amountOfworkers, name);
					if (iWorker == -1) cout << "\n������ �������� ������, ��������� ������������!\n\n";
					else
					{
						if (authoris == arrw[iWorker].rank && authoris == 4)
						{
							cout << "������� ������: ";
							cin.ignore();
							cin.getline(s, 100);

							if (strcmp(s, "Mojsklep2022") == 0) showAllCustomers(arrcl, amountOfClients);
							else cout << "\n�������� ������, � ������� ��������!\n\n";
						}
						else cout << "\n������������ ����������, � ������� ��������!\n\n";
					}
					break;

				case 4:
					showStore(arrcom, amountOfCommodity);
					break;

				case 5:
					cout << "\n������� ����� ������ �� �������: ";
					cin >> id;
					id--;
					cout << "������� ���������� ������: ";
					cin >> amount;
					cout << "������� ��� ������������: ";//������ ���������� ���������� //+38 050 618 94 68
					cin.ignore();
					cin.getline(name, 100);
					cout << "������� ����� �������� �������: ";
					cin.getline(s, 100);

					iCostumer = findCustomerByPhoneNumber(arrcl, amountOfClients, s);
					iWorker = findIDByInitials(arrw, amountOfworkers, name);
					if (iCostumer == -1)
					{
						cout << "\n������ �� ������, ��������� �������� ������.\n\n";
					}
					else if (iWorker == -1)
					{
						cout << "\n����������� �� ������, ��������� �������� ������.\n\n";
					}
					else if (id < 0 || id >= amountOfCommodity)
					{
						cout << "\n����� �� ������, ��������� �������� ������.\n\n";
					}
					else if (amount < 1 || amount > arrcom[id].amount)
					{
						cout << "\n������������ ���������� ������.\n\n";
					}
					else
					{
						cout << "\n� ������: " << arrcom[id].price * amount << " ������.\n";
						cout << "�������� ������. �������� ��� ������: ��������/�����\n";
						arrw[iWorker].addSale(arrcom[id].price);
						arrcom[id].amount -= amount;
						arrcl[iCostumer].addBuy(arrcom[id].price);

						system("pause");
						cout << "\n����� ��������� �������!\n\n";
					}
					break;

				default: if (menu1 > 6 && menu1 != 0 || menu1 < 0) cout << "������� ������ ����� ����.\n\n"; break;
				}
			} while (menu1 != 0);

			break;

		case 3: //���� ��� �����������

			cout << "\n���������� ����������� ����� �������!\n������� ���� ��������: ";
			cin.ignore();
			cin.getline(name, 100);
			cout << "������� ���� ����: ";
			cin >> authoris;

			iWorker = findIDByInitials(arrw, amountOfworkers, name);
			if (iWorker == -1) cout << "\n������ �������� ������, ��������� ������������!\n\n";
			else
			{
				if (authoris == arrw[iWorker].rank && authoris == 4)
				{
					cout << "������� ������: ";
					cin.ignore();
					cin.getline(s, 100);

					if (strcmp(s, "Mojsklep2022") != 0) cout << "\n�������� ������, � ������� ��������!\n\n";
					else
					{
						cout << "\n������ ����������. ����������� ���, " << name << "!\n";
						do
						{
							cout << "\n1. ����������.\n";//+
							cout << "2. �������.\n";//+
							cout << "3. �����.\n";
							cout << "0. ��������� � ������� ����.\n�����: ";
							cin >> menu1;

							switch (menu1)
							{
							case 1:
								do
								{
									cout << "\n1. �������� ����������.\n";//+
									cout << "2. ������� ����������.\n";//+
									cout << "3. ����������� ���������� � ����������.\n";//+ arrw
									cout << "4. ����������� ���������� � ���� �����������.\n"; //+ arrw
									cout << "5. �������� ���������� � ����������.\n";//+
									cout << "6. ����������� ������ ������������.\n";//+
									cout << "7. ���������� �����������.\n";//����/���
									cout << "0. ��������� � ���������� ����.\n�����: ";
									cin >> menu2;

									switch (menu2)
									{
									case 1:
										addWorker(arrw, amountOfworkers);
										break;

									case 2:
										cout << "\n��� ����������: ";
										cin.ignore();
										cin.getline(name, 100);

										iWorker = findIDByInitials(arrw, amountOfworkers, name);

										if (iWorker == -1) cout << "\n�������� �� ������, ��������� �������� ������.\n\n";
										else delWorkerByID(arrw, amountOfworkers, iWorker);
										break;

									case 3:
										cout << "\n��� ����������: ";
										cin.ignore();
										cin.getline(name, 100);

										iWorker = findIDByInitials(arrw, amountOfworkers, name);

										if (iWorker == -1) cout << "\n�������� �� ������, ��������� �������� ������.\n\n";
										else arrw[iWorker].showWorker();
										break;

									case 4:
										showAllWorkers(arrw, amountOfworkers);
										break;

									case 5:
										cout << "\n��� ����������: ";
										cin.ignore();
										cin.getline(name, 100);

										iWorker = findIDByInitials(arrw, amountOfworkers, name);

										if (iWorker == -1) cout << "\n�������� �� ������, ��������� �������� ������.\n\n";
										else editWorkersData(arrw, amountOfworkers, iWorker);
										break;

									case 6:
										cout << "\n�����������: ";
										cin.ignore();
										cin.getline(s, 100);
										showDepartment(arrw, amountOfworkers, s);
										break;

									case 7:
										do
										{
											cout << "\n1. �� ����� - �� �����������.\n";
											cout << "2. �� ����� - �� ��������.\n";
											cout << "3. �� ������������ - �� �����������.\n";
											cout << "4. �� ������������ - �� ��������.\n";
											cout << "5. �� ���� ��������������� - �� �����������.\n";
											cout << "6. �� ���� ��������������� - �� ��������.\n";
											cout << "7. �� ���� �������� - �� �����������.\n";
											cout << "8. �� ���� �������� - �� ��������.\n";
											cout << "0. ��������� � ���������� ����.\n�����: ";
											cin >> menu3;

											bool (*Functions[])(Worker, Worker) = { upRank, downRank, upDepartment, downDepartment, upStartWork, downStartWork, upAge, downRank };
											if (menu3 >= 1 && menu3 <= 8)
											{
												sortWorkers(arrw, amountOfworkers, Functions[menu3 - 1]);
												cout << "\n���������� �������������.\n\n";
											}
											else if (menu3 < 0 && menu3 > 8) cout << "\n������� ������ ����� ����!\n\n";
											/*switch (menu3)
											{
											case 1:
												sortWorkers(arrw, amountOfworkers, upRank);
												cout << "\n���������� �������������.\n\n";
												break;

											case 2:
												sortWorkers(arrw, amountOfworkers, downRank);
												cout << "\n���������� �������������.\n\n";
												break;

											case 3:
												sortWorkers(arrw, amountOfworkers, upDepartment);
												cout << "\n���������� �������������.\n\n";
												break;

											case 4:
												sortWorkers(arrw, amountOfworkers, downDepartment);
												cout << "\n���������� �������������.\n\n";
												break;

											case 5:
												sortWorkers(arrw, amountOfworkers, upStartWork);
												cout << "\n���������� �������������.\n\n";
												break;

											case 6:
												sortWorkers(arrw, amountOfworkers, downStartWork);
												cout << "\n���������� �������������.\n\n";
												break;

											case 7:
												sortWorkers(arrw, amountOfworkers, upAge);
												cout << "\n���������� �������������.\n\n";
												break;

											case 8:
												sortWorkers(arrw, amountOfworkers, downAge);
												cout << "\n���������� �������������.\n\n";
												break;

											default: if (menu3 > 8 && menu3 != 0 || menu3 < 0) cout << "������� ������ ����� ����.\n\n"; break;
											}*/
										} while (menu3 != 0);
										break;

									default: if (menu2 > 7 && menu2 != 0 || menu2 < 0) cout << "������� ������ ����� ����.\n\n"; break;
									}
								} while (menu2 != 0);

								break;

							case 2:
								do
								{
									cout << "\n1. ������� �������.\n";
									cout << "2. �������� ���������� � �������.\n";
									cout << "3. ����������� ���������� � �������.\n";
									cout << "4. ����������� ���������� � ���� ��������.\n";
									cout << "5. ����������� ������� ����������� �������.\n";
									cout << "6. ����������� ����� ������������ � ����������� �������.\n";
									cout << "7. ����������� ����� ������������ � ���� ��������.\n";
									cout << "0. ��������� � ������� ����.\n�����: ";
									cin >> menu1;

									switch (menu1)
									{
									case 1:
										cout << "\n��������� �������: ";
										cin.ignore();
										cin.getline(s, 100);
										iCostumer = findCustomerByPhoneNumber(arrcl, amountOfClients, s);

										if (iCostumer == -1) cout << "\n������ �� ������, ��������� �������� ������.\n\n";
										else delCustomerByID(arrcl, amountOfClients, iCostumer);
										break;

									case 2:
										cout << "\n��������� �������: ";
										cin.ignore();
										cin.getline(s, 100);
										iCostumer = findCustomerByPhoneNumber(arrcl, amountOfClients, s);

										if (iCostumer == -1) cout << "\n������ �� ������, ��������� �������� ������.\n\n";
										else editCustomersData(arrcl, amountOfClients, iCostumer);
										break;

									case 3:
										cout << "\n��������� �������: ";
										cin.ignore();
										cin.getline(s, 100);
										iCostumer = findCustomerByPhoneNumber(arrcl, amountOfClients, s);

										if (iCostumer == -1) cout << "\n������ �� ������, ��������� �������� ������.\n\n";
										else arrcl[iCostumer].showCustomer();
										break;

									case 4:
										showAllCustomers(arrcl, amountOfClients);
										break;

									case 5:
										sortCustomersByTotalBuying(arrcl, amountOfClients);
										break;

									case 6:
										cout << "\n��������� �������: ";
										cin.ignore();
										cin.getline(s, 100);
										lsum = calcCustomersPurchases(arrcl, amountOfClients, s);
										cout << "\n����� ����������� �� " << lsum << " ���.\n\n";
										break;

									case 7:
										lsum = calcAllCustomersPurchases(arrcl, amountOfClients);//�������
										cout << "\n����� ����������� �� " << lsum << " ���.\n\n";
										break;

									default: if (menu1 > 7 && menu1 != 0 || menu1 < 0) cout << "������� ������ ����� ����.\n\n"; break;
									}
								} while (menu1 != 0);

								break;

							case 3:
								do
								{
									cout << "\n1. �������� ����� � �������.\n";
									cout << "2. ������� ����� � ��������.\n";
									cout << "3. ����� ����� ������ �� ������� ��������.\n";
									cout << "4. �������� ���� ����� � �������.\n";
									cout << "5. �������� ���������� � ������.\n";
									cout << "6. ����������� �����.\n";
									cout << "7. ����������� ����� ������.\n";
									cout << "8. ����������� ��������� ������.\n";
									cout << "9. ����������� ��������� ��������� ������ � ������.\n";
									cout << "10. ����������� �����.\n"; //���� ���� 3/���
									cout << "0. ��������� � ���������� ����.\n�����: ";
									cin >> menu2;

									switch (menu2)
									{
									case 1:
										addCommodity(arrcom, amountOfCommodity);
										break;

									case 2:
										delCommodity(arrcom, amountOfCommodity);
										break;

									case 3:
										cout << "\n�������� ������: ";
										cin.ignore();
										cin.getline(s, 100);
										id = getIDbyName(arrcom, amountOfCommodity, s);
										cout << "\n����� [" << s << "] ���������� �� ������� ����� " << id << endl << endl;
										break;

									case 4:
										showStore(arrcom, amountOfCommodity);
										break;

									case 5:
										editDataOfCommodity(arrcom, amountOfCommodity);
										break;

									case 6:
										cout << "\n�������� ������: ";
										cin.ignore();
										cin.getline(s, 100);
										showCommodity(arrcom, amountOfCommodity, s);
										break;

									case 7:
										cout << "\n�����������: ";
										cin >> id;
										if (id >= 1 && id <= 4)
										{
											printThisSection(arrcom, amountOfCommodity, id);
										}
										else cout << "\n��������� ������, ���������� �����.\n\n";

										break;

									case 8:
										cout << "\n��������� ������: ";
										cin.ignore();
										cin.getline(s, 100);
										printThisCategory(arrcom, amountOfCommodity, s);
										break;

									case 9:
										cout << "\n�����: ";
										cin >> id;
										lsum = totalPriseInThisSection(arrcom, amountOfCommodity, id);
										if (id >= 1 && id <= 4)
										{
											if (id == 1) cout << "\n����� � ���������� ������ - " << lsum << " ���.\n\n";
											else if (id == 2) cout << "\n����� � �������� ������ - " << lsum << " ���.\n\n";
											else if (id == 3) cout << "\n����� � ������������� ������ - " << lsum << " ���.\n\n";
											else 
											{
												cout << "\n���� ������� �� ����������� ����: ";
												cin >> sum;
												cout << "\n����� � ����������� ������ - " << lsum * sum << " ��������.\n\n";
											}
										}
										else cout << "\n��������� ������, ���������� �����.\n\n";
										break;

									case 10:
										do
										{
											cout << "\n1. �� ���� - �� �����������.\n";
											cout << "2. �� ���� - �� ��������.\n";
											cout << "3. �� ���� ����������� - �� �����������.\n";
											cout << "4. �� ���� ����������� - �� ��������.\n";
											cout << "0. ��������� � ���������� ����.\n�����: ";
											cin >> menu3;

											bool (*Functions[])(Commodity, Commodity) = { upPrice, downPrice, upDate, downDate };
											if (menu3 >= 1 && menu3 <= 4)
											{
												sortCommodity(arrcom, amountOfCommodity, Functions[menu3 - 1]);
												cout << "\n����� ������������.\n\n";
											}
											else if (menu3 < 0 && menu3 > 4) cout << "\n������� ������ ����� ����!\n\n";
										} while (menu3 != 0);
										break;


									default: if (menu1 > 10 && menu1 != 0 || menu1 < 0) cout << "������� ������ ����� ����.\n\n"; break;
									}
								} while (menu2 != 0);

								break;


							default: if (menu1 > 2 && menu1 != 0 || menu1 < 0) cout << "������� ������ ����� ����.\n\n"; break;
							}
						} while (menu1 != 0);
					}
				}
				else cout << "\n������������ ����������, � ������� ��������!\n\n";
			}

			break;

		default: if (menu > 3 && menu != 0 || menu < 0) cout << "������� ������ ����� ����.\n\n"; break;
		}
	} while (menu != 0);

	saveStore(arrcom, amountOfCommodity);
	saveClients(arrcl, amountOfClients);
	saveWorkers(arrw, amountOfworkers);
	cout << "\n==================================================================\n";
	cout << "==  ���������� ������ ��������� �������� \"Hunting && Fishing\" ==";
	cout << "\n==================================================================\n\n";

	cout << endl;
	system("pause");
	return 0;
}