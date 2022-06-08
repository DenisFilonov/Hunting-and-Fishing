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
	cout << "==  ЗАПУСК РАБОТЫ ТЕРМИНАЛА МАГАЗИНА \"Hunting && Fishing\" ==";
	cout << "\n============================================================\n";
	//мы щас сидим за главным компьютером руководства, с которого можно что-то изменять или дополнять

	//addWorker(arrw, amountOfworkers); //запилить РАБотника
	//showAllWorkers(arrw, amountOfworkers); //проверка
	//showAllCustomers(arrcl, amountOfClients); //проверка
	//showStore(arrcom, amountOfCommodity); //проверка


	//Приколы: Клиенты-7

	do
	{//в каждом отделе по 3 пары терминалов: один для клиента, второй для сотрудника/руководителя
		cout << "\n1. Меню для покупателя.\n";//терминалы в магазине ссылаются на главный сервер
		cout << "2. Меню для персонала.\n";//терминалы находятся рядом с терминалами для покупателей и там есть выбор либо для сотрудника, либо для руководства
		cout << "3. Меню для управленца.\n";
		cout << "0. Завершить раборту с магазином.\nВыбор: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			cout << "\n\nДобро пожаловать в магазин Охота и Рыбалка!\n\nДля продолжения, выберите любой пункт меню.\nИли, ознакомьтесь с нашим магазином и его ассортиментом, нажав на раздел \"Информация\"\n\n";
			do
			{
				cout << "1. Информация по магазину.\n";
				cout << "2. Найти товар.\n";
				cout << "3. Просмотреть список товаров.\n";
				cout << "4. Сортировать товар.\n";
				cout << "5. Показать весь товар данной категории.\n";
				cout << "6. Показать весь товар данного отдела.\n";
				cout << "0. Вернуться в главное меню.\nВыбор: ";
				cin >> menu1;

				switch (menu1)
				{
				case 1:
					do
					{
						cout << "\nВ нашем магазине есть 4 отдела, которые Вы можете посетить:\n";
						cout << "1.Охотничий\n2.Рыбацкий\n3.Технический\n4.Экипировочный\n";
						cout << "\nВо всех отделах есть в наличии ряд категорий и типы товаров, входящих в данную категорию.\n";
						cout << "Чтобы вернуться, нажмите 0.\nПросмотреть информацию по конкретному отделу: "; cin >> id;

						switch (id)
						{
						case 1: cout << "\nВ охотничем отделе представлены ряды холодного и огнестрельного орудия разных производителей и брендов.\n"
							<< "Так же, всевозможные аксессуары и обвесы для оружия, например: лазерные целеуказатели, оптика и так далее.\n"
							<< "Помимо этого здесь можно найти наборы для тех.обслуживания для оружия, разные сувениры и сейфы для удобного хранения всего Вашего инвентаря.\n";
							break;

						case 2: cout << "\nВ рыбацком отделе представлены ряды разного рода удочек и спиннингов любых производителей и брендов.\n"
							<< "Так же, всевозможные аксессуары для продолжительной ловли рыбы, например: поплавки, сачки, сетки, прикормки, и так далее.\n"
							<< "Помимо этого здесь можно найти наборы для небольшого кемпинга: брезентовые палатки, складные стулья, мангалы, зонты/тенты.\n";
							break;

						case 3: cout << "\nВ техническом отделе представлены зал и площадка с лодками, катерами, ещё с автомобилями-внедорожниками, прицепами разных марок и производителей.\n"
							<< "Так же, всевозможные ремонтные наборы и расходные материалы для Вашей техники, как комплекты ключей, запасные покрышки, горюще-смазывательные вещества и так далее.\n";
							break;

						case 4: cout << "\nВ экипировочном отделе представлены полки и витрины с различными костюмами для различных ситуаций, с которыми Вы можете столкнуться на охоте, рыбалке, или попросту дома, ремонтируя свою технику.\n"
							<< "В этом отделе мы Вам предлагаем на любой вкус и цвет, для рыбалки и охоты:"
							<< "\n\n> Водонепроницаемые костюмы с брезентовым материалом и с внутренним толстым или тонким пошивом для дождливой или пасмурной погоды.\n"
							<< "\n> Лёгкие костюмы, имеющие застёжки на рукавах и ногах для тёплой солнечной или знойной погоды.\n"
							<< "\n> Так же, предлагаем собрать себе костюм самому, как только душа пожелает, приобретая отдельные элементы одежды.\n"
							<< "\nУ нас есть широкий выбор: головных уборов, обычных и тактических жилетов, перчаток, штанов, носков и ботинок. И всё это под любые условия, какие только Вы можете себе представить!\n";
							break;

						default: if (menu1 > 4 && menu1 != 0 || menu1 < 0) cout << "Неверно выбран пункт меню.\n\n"; break;
						}
					} while (id != 0);

					cout << "\n\nВпечатлены? Дайте нам знать!\nВы всегда можете обратиться к нам в приёмную за дополнительной информацией, или попросить наших консультантов устроить Вам мини-экскурсию."
						<< "\nНаш коллектив является профессионалом своего дела, мы с радостью покажем и расскажем Вам о любом товаре нашего магазина, который Вы пожелаете приобрести!\n"
						<< "Желаем Вам хороших покупок!\n\n";

					break;

				case 2:
					cout << "\nВведите название товара: ";
					cin.ignore();
					cin.getline(name, 100);
					showCommodity(arrcom, amountOfCommodity, name);
					break;

				case 3:
					showStore(arrcom, amountOfCommodity);
					break;

				case 4:
				{
					cout << "1. По цене - по возрастанию.\n";
					cout << "2. По цене - по убыванию.\n";
					cout << "3. По дате поступления - по возрастанию.\n";
					cout << "4. По дате поступления - по убыванию.\n";
					cout << "0. Вернуться в предыдущее меню.\nВыбор: ";
					cin >> menu3;

					bool (*Functions[])(Commodity, Commodity) = { upPrice, downPrice, upDate, downDate };
					if (menu3 >= 1 && menu3 <= 4)
					{
						sortCommodity(arrcom, amountOfCommodity, Functions[menu3 - 1]);
						cout << "\nТовар отсортирован.\nВыберите в меню пункт #3 для дальнейшего просмотра\n\n";
					}
					else if (menu3 < 0 && menu3 > 4) cout << "\nНеверно выбран пункт меню, выберите с 1 по 4!\n\n";
				}
					break;

				case 5:
					cout << "\nВведите категорию товара: ";
					cin.ignore();
					cin.getline(name, 100);
					printThisCategory(arrcom, amountOfCommodity, s);
					break;

				case 6:
					cout << "\nВведите номер отдела товара: ";
					cin >> id;
					printThisSection(arrcom, amountOfCommodity, id);
					break;

				default: if (menu1 > 11 && menu1 != 0 || menu1 < 0) cout << "Неверно выбран пункт меню.\n\n"; break;
				}
			} while (menu1 != 0);

			break;

		case 2: //Меню для персонала
			do
			{
				cout << "\n1. Добавить клиента в базу данных.\n";
				cout << "2. Найти клиента по его информации.\n";
				cout << "3. Просмотреть список всех клиентов.\n";
				cout << "4. Просмотреть список товаров.\n";
				cout << "5. Оформить продажу.\n";
				cout << "0. Вернуться в главное меню.\nВыбор: ";
				cin >> menu1;

				switch (menu1)
				{
				case 1:
					addCustomer(arrcl, amountOfClients);
					break;

				case 2:
					cout << "\n\n1. Ввести ФИО";
					cout << "\n2. Ввести номер телефона\nВыбор: ";
					cin >> menu2;
					switch (menu2)
					{
					case 1:
						cout << "\nФИО клиента: ";
						cin.ignore();
						cin.getline(name, 100);
						findCustomerByName(arrcl, amountOfClients, name);
						break;
					case 2:
						cout << "\nМобильный клиента: ";
						cin.ignore();
						cin.getline(s, 100);
						iCostumer = findCustomerByPhoneNumber(arrcl, amountOfClients, s);

						if (iCostumer == -1) cout << "\nКлиент не найден, проверьте вводимые данные.\n\n";
						else arrcl[iCostumer].showCustomer();
						break;

					default: if (menu2 > 2 && menu2 != 0 || menu2 < 0) cout << "\nНеверно выбран пункт меню.\n\n"; break;
					}
					break;

				case 3:
					cout << "\nНеобходимо подтвердить право доступа!\nВведите свои инициалы: ";
					cin.ignore();
					cin.getline(name, 100);
					cout << "Введите свой ранг: ";
					cin >> authoris;

					iWorker = findIDByInitials(arrw, amountOfworkers, name);
					if (iWorker == -1) cout << "\nОшибка введённых данных, проверьте корректность!\n\n";
					else
					{
						if (authoris == arrw[iWorker].rank && authoris == 4)
						{
							cout << "Введите пароль: ";
							cin.ignore();
							cin.getline(s, 100);

							if (strcmp(s, "Mojsklep2022") == 0) showAllCustomers(arrcl, amountOfClients);
							else cout << "\nНеверный пароль, в доступе отказано!\n\n";
						}
						else cout << "\nНедостаточно полномочий, в доступе отказано!\n\n";
					}
					break;

				case 4:
					showStore(arrcom, amountOfCommodity);
					break;

				case 5:
					cout << "\nВведите номер товара на витрине: ";
					cin >> id;
					id--;
					cout << "Введите количество товара: ";
					cin >> amount;
					cout << "Введите ФИО консультанта: ";//Волков Константин Евгеньевич //+38 050 618 94 68
					cin.ignore();
					cin.getline(name, 100);
					cout << "Введите номер телефона клиента: ";
					cin.getline(s, 100);

					iCostumer = findCustomerByPhoneNumber(arrcl, amountOfClients, s);
					iWorker = findIDByInitials(arrw, amountOfworkers, name);
					if (iCostumer == -1)
					{
						cout << "\nКлиент не найден, проверьте вводимые данные.\n\n";
					}
					else if (iWorker == -1)
					{
						cout << "\nКонсультант не найден, проверьте вводимые данные.\n\n";
					}
					else if (id < 0 || id >= amountOfCommodity)
					{
						cout << "\nТовар не найден, проверьте вводимые данные.\n\n";
					}
					else if (amount < 1 || amount > arrcom[id].amount)
					{
						cout << "\nНедопустимое количество товара.\n\n";
					}
					else
					{
						cout << "\nК оплате: " << arrcom[id].price * amount << " гривен.\n";
						cout << "Ожидание оплаты. Выберите тип оплаты: Наличные/Карта\n";
						arrw[iWorker].addSale(arrcom[id].price);
						arrcom[id].amount -= amount;
						arrcl[iCostumer].addBuy(arrcom[id].price);

						system("pause");
						cout << "\nТовар приобретён успешно!\n\n";
					}
					break;

				default: if (menu1 > 6 && menu1 != 0 || menu1 < 0) cout << "Неверно выбран пункт меню.\n\n"; break;
				}
			} while (menu1 != 0);

			break;

		case 3: //Меню для руководства

			cout << "\nНеобходимо подтвердить право доступа!\nВведите свои инициалы: ";
			cin.ignore();
			cin.getline(name, 100);
			cout << "Введите свой ранг: ";
			cin >> authoris;

			iWorker = findIDByInitials(arrw, amountOfworkers, name);
			if (iWorker == -1) cout << "\nОшибка введённых данных, проверьте корректность!\n\n";
			else
			{
				if (authoris == arrw[iWorker].rank && authoris == 4)
				{
					cout << "Введите пароль: ";
					cin.ignore();
					cin.getline(s, 100);

					if (strcmp(s, "Mojsklep2022") != 0) cout << "\nНеверный пароль, в доступе отказано!\n\n";
					else
					{
						cout << "\nЗапрос подтверждён. Приветствую Вас, " << name << "!\n";
						do
						{
							cout << "\n1. Сотрудники.\n";//+
							cout << "2. Клиенты.\n";//+
							cout << "3. Товар.\n";
							cout << "0. Вернуться в главное меню.\nВыбор: ";
							cin >> menu1;

							switch (menu1)
							{
							case 1:
								do
								{
									cout << "\n1. Добавить сотрудника.\n";//+
									cout << "2. Удалить сотрудника.\n";//+
									cout << "3. Просмотреть информацию о сотруднике.\n";//+ arrw
									cout << "4. Просмотреть информацию о всех сотрудниках.\n"; //+ arrw
									cout << "5. Изменить информацию о сотруднике.\n";//+
									cout << "6. Просмотреть состав департамента.\n";//+
									cout << "7. Сортировка сотрудников.\n";//свич/бул
									cout << "0. Вернуться в предыдущее меню.\nВыбор: ";
									cin >> menu2;

									switch (menu2)
									{
									case 1:
										addWorker(arrw, amountOfworkers);
										break;

									case 2:
										cout << "\nФИО сотрудника: ";
										cin.ignore();
										cin.getline(name, 100);

										iWorker = findIDByInitials(arrw, amountOfworkers, name);

										if (iWorker == -1) cout << "\nРаботник не найден, проверьте вводимые данные.\n\n";
										else delWorkerByID(arrw, amountOfworkers, iWorker);
										break;

									case 3:
										cout << "\nФИО сотрудника: ";
										cin.ignore();
										cin.getline(name, 100);

										iWorker = findIDByInitials(arrw, amountOfworkers, name);

										if (iWorker == -1) cout << "\nРаботник не найден, проверьте вводимые данные.\n\n";
										else arrw[iWorker].showWorker();
										break;

									case 4:
										showAllWorkers(arrw, amountOfworkers);
										break;

									case 5:
										cout << "\nФИО сотрудника: ";
										cin.ignore();
										cin.getline(name, 100);

										iWorker = findIDByInitials(arrw, amountOfworkers, name);

										if (iWorker == -1) cout << "\nРаботник не найден, проверьте вводимые данные.\n\n";
										else editWorkersData(arrw, amountOfworkers, iWorker);
										break;

									case 6:
										cout << "\nДепартамент: ";
										cin.ignore();
										cin.getline(s, 100);
										showDepartment(arrw, amountOfworkers, s);
										break;

									case 7:
										do
										{
											cout << "\n1. По рангу - по возрастанию.\n";
											cout << "2. По рангу - по убыванию.\n";
											cout << "3. По департаменту - по возрастанию.\n";
											cout << "4. По департаменту - по убыванию.\n";
											cout << "5. По дате трудоустройства - по возрастанию.\n";
											cout << "6. По дате трудоустройства - по убыванию.\n";
											cout << "7. По дате рождения - по возрастанию.\n";
											cout << "8. По дате рождения - по убыванию.\n";
											cout << "0. Вернуться в предыдущее меню.\nВыбор: ";
											cin >> menu3;

											bool (*Functions[])(Worker, Worker) = { upRank, downRank, upDepartment, downDepartment, upStartWork, downStartWork, upAge, downRank };
											if (menu3 >= 1 && menu3 <= 8)
											{
												sortWorkers(arrw, amountOfworkers, Functions[menu3 - 1]);
												cout << "\nСотрудники отсортированы.\n\n";
											}
											else if (menu3 < 0 && menu3 > 8) cout << "\nНеверно выбран пункт меню!\n\n";
											/*switch (menu3)
											{
											case 1:
												sortWorkers(arrw, amountOfworkers, upRank);
												cout << "\nСотрудники отсортированы.\n\n";
												break;

											case 2:
												sortWorkers(arrw, amountOfworkers, downRank);
												cout << "\nСотрудники отсортированы.\n\n";
												break;

											case 3:
												sortWorkers(arrw, amountOfworkers, upDepartment);
												cout << "\nСотрудники отсортированы.\n\n";
												break;

											case 4:
												sortWorkers(arrw, amountOfworkers, downDepartment);
												cout << "\nСотрудники отсортированы.\n\n";
												break;

											case 5:
												sortWorkers(arrw, amountOfworkers, upStartWork);
												cout << "\nСотрудники отсортированы.\n\n";
												break;

											case 6:
												sortWorkers(arrw, amountOfworkers, downStartWork);
												cout << "\nСотрудники отсортированы.\n\n";
												break;

											case 7:
												sortWorkers(arrw, amountOfworkers, upAge);
												cout << "\nСотрудники отсортированы.\n\n";
												break;

											case 8:
												sortWorkers(arrw, amountOfworkers, downAge);
												cout << "\nСотрудники отсортированы.\n\n";
												break;

											default: if (menu3 > 8 && menu3 != 0 || menu3 < 0) cout << "Неверно выбран пункт меню.\n\n"; break;
											}*/
										} while (menu3 != 0);
										break;

									default: if (menu2 > 7 && menu2 != 0 || menu2 < 0) cout << "Неверно выбран пункт меню.\n\n"; break;
									}
								} while (menu2 != 0);

								break;

							case 2:
								do
								{
									cout << "\n1. Удалить клиента.\n";
									cout << "2. Изменить информацию о клиенте.\n";
									cout << "3. Просмотреть информацию о клиенте.\n";
									cout << "4. Просмотреть информацию о всех клиентах.\n";
									cout << "5. Сортировать покупки конкретного клиента.\n";
									cout << "6. Просмотреть сумму приобретения у конкретного клиента.\n";
									cout << "7. Просмотреть сумму приобретения у всех клиентов.\n";
									cout << "0. Вернуться в главное меню.\nВыбор: ";
									cin >> menu1;

									switch (menu1)
									{
									case 1:
										cout << "\nМобильный клиента: ";
										cin.ignore();
										cin.getline(s, 100);
										iCostumer = findCustomerByPhoneNumber(arrcl, amountOfClients, s);

										if (iCostumer == -1) cout << "\nКлиент не найден, проверьте вводимые данные.\n\n";
										else delCustomerByID(arrcl, amountOfClients, iCostumer);
										break;

									case 2:
										cout << "\nМобильный клиента: ";
										cin.ignore();
										cin.getline(s, 100);
										iCostumer = findCustomerByPhoneNumber(arrcl, amountOfClients, s);

										if (iCostumer == -1) cout << "\nКлиент не найден, проверьте вводимые данные.\n\n";
										else editCustomersData(arrcl, amountOfClients, iCostumer);
										break;

									case 3:
										cout << "\nМобильный клиента: ";
										cin.ignore();
										cin.getline(s, 100);
										iCostumer = findCustomerByPhoneNumber(arrcl, amountOfClients, s);

										if (iCostumer == -1) cout << "\nКлиент не найден, проверьте вводимые данные.\n\n";
										else arrcl[iCostumer].showCustomer();
										break;

									case 4:
										showAllCustomers(arrcl, amountOfClients);
										break;

									case 5:
										sortCustomersByTotalBuying(arrcl, amountOfClients);
										break;

									case 6:
										cout << "\nМобильный клиента: ";
										cin.ignore();
										cin.getline(s, 100);
										lsum = calcCustomersPurchases(arrcl, amountOfClients, s);
										cout << "\nИтого приобретено на " << lsum << " грн.\n\n";
										break;

									case 7:
										lsum = calcAllCustomersPurchases(arrcl, amountOfClients);//приколы
										cout << "\nИтого реализовано на " << lsum << " грн.\n\n";
										break;

									default: if (menu1 > 7 && menu1 != 0 || menu1 < 0) cout << "Неверно выбран пункт меню.\n\n"; break;
									}
								} while (menu1 != 0);

								break;

							case 3:
								do
								{
									cout << "\n1. Добавить товар в магазин.\n";
									cout << "2. Удалить товар с магазина.\n";
									cout << "3. Найти номер товара на витрине магазина.\n";
									cout << "4. Показать весь товар в наличии.\n";
									cout << "5. Изменить информацию о товаре.\n";
									cout << "6. Просмотреть товар.\n";
									cout << "7. Просмотреть отдел товара.\n";
									cout << "8. Просмотреть категорию товара.\n";
									cout << "9. Просмотреть суммарную стоимость товара в отделе.\n";
									cout << "10. Сортировать товар.\n"; //свич меню 3/бул
									cout << "0. Вернуться в предыдущее меню.\nВыбор: ";
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
										cout << "\nНазвание товара: ";
										cin.ignore();
										cin.getline(s, 100);
										id = getIDbyName(arrcom, amountOfCommodity, s);
										cout << "\nТовар [" << s << "] расположен на витрине номер " << id << endl << endl;
										break;

									case 4:
										showStore(arrcom, amountOfCommodity);
										break;

									case 5:
										editDataOfCommodity(arrcom, amountOfCommodity);
										break;

									case 6:
										cout << "\nНазвание товара: ";
										cin.ignore();
										cin.getline(s, 100);
										showCommodity(arrcom, amountOfCommodity, s);
										break;

									case 7:
										cout << "\nДепартамент: ";
										cin >> id;
										if (id >= 1 && id <= 4)
										{
											printThisSection(arrcom, amountOfCommodity, id);
										}
										else cout << "\nПроизошла ошибка, попробуйте снова.\n\n";

										break;

									case 8:
										cout << "\nКатегория товара: ";
										cin.ignore();
										cin.getline(s, 100);
										printThisCategory(arrcom, amountOfCommodity, s);
										break;

									case 9:
										cout << "\nОтдел: ";
										cin >> id;
										lsum = totalPriseInThisSection(arrcom, amountOfCommodity, id);
										if (id >= 1 && id <= 4)
										{
											if (id == 1) cout << "\nИтого в охотничьем отделе - " << lsum << " грн.\n\n";
											else if (id == 2) cout << "\nИтого в рыбацком отделе - " << lsum << " грн.\n\n";
											else if (id == 3) cout << "\nИтого в экипировочном отделе - " << lsum << " грн.\n\n";
											else 
											{
												cout << "\nКурс доллара на сегодняшний день: ";
												cin >> sum;
												cout << "\nИтого в техническом отделе - " << lsum * sum << " долларов.\n\n";
											}
										}
										else cout << "\nПроизошла ошибка, попробуйте снова.\n\n";
										break;

									case 10:
										do
										{
											cout << "\n1. По цене - по возрастанию.\n";
											cout << "2. По цене - по убыванию.\n";
											cout << "3. По дате поступления - по возрастанию.\n";
											cout << "4. По дате поступления - по убыванию.\n";
											cout << "0. Вернуться в предыдущее меню.\nВыбор: ";
											cin >> menu3;

											bool (*Functions[])(Commodity, Commodity) = { upPrice, downPrice, upDate, downDate };
											if (menu3 >= 1 && menu3 <= 4)
											{
												sortCommodity(arrcom, amountOfCommodity, Functions[menu3 - 1]);
												cout << "\nТовар отсортирован.\n\n";
											}
											else if (menu3 < 0 && menu3 > 4) cout << "\nНеверно выбран пункт меню!\n\n";
										} while (menu3 != 0);
										break;


									default: if (menu1 > 10 && menu1 != 0 || menu1 < 0) cout << "Неверно выбран пункт меню.\n\n"; break;
									}
								} while (menu2 != 0);

								break;


							default: if (menu1 > 2 && menu1 != 0 || menu1 < 0) cout << "Неверно выбран пункт меню.\n\n"; break;
							}
						} while (menu1 != 0);
					}
				}
				else cout << "\nНедостаточно полномочий, в доступе отказано!\n\n";
			}

			break;

		default: if (menu > 3 && menu != 0 || menu < 0) cout << "Неверно выбран пункт меню.\n\n"; break;
		}
	} while (menu != 0);

	saveStore(arrcom, amountOfCommodity);
	saveClients(arrcl, amountOfClients);
	saveWorkers(arrw, amountOfworkers);
	cout << "\n==================================================================\n";
	cout << "==  ЗАВЕРШЕНИЕ РАБОТЫ ТЕРМИНАЛА МАГАЗИНА \"Hunting && Fishing\" ==";
	cout << "\n==================================================================\n\n";

	cout << endl;
	system("pause");
	return 0;
}