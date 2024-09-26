#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000;

struct Person
{ // 用户结构体
	string name;
	string sex;
	int age;
	string phone; // 电话
	string addre; // 地址
};

struct AddressBooks
{ // 通讯录结构体
	Person personArray[MAX];
	int Size;
};

// 打印菜单
void ShowMenu()
{
	cout << "**********************" << '\n';
	cout << "*****1.添加联系人*****" << '\n';
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "**********************" << endl;
	return;
}

void addPerson(AddressBooks *abs)
{
	if (abs->Size == MAX)
	{
		cout << "杂鱼杂鱼~?，人满了下次啊再来哦~" << '\n';
		return;
	}
	else
	{
		string name;
		cout << "输入姓名：\n";
		cin >> name;
		abs->personArray[abs->Size].name = name;

		string sex;
		cout << "输入性别：\n";
		cin >> sex;
		abs->personArray[abs->Size].sex = sex;

		int age;
		cout << "输入年龄：\n";
		cin >> age;
		abs->personArray[abs->Size].age = age;

		string phone;
		cout << "输入电话：\n";
		cin >> phone;
		abs->personArray[abs->Size].phone = phone;

		string add;
		cout << "输入地址：\n";
		cin >> add;
		abs->personArray[abs->Size].addre = add;

		abs->Size++;
		cout << "添加成功！" << endl;
		system("pause"); // 请按任意键继续
		system("cls");	 // 全部清屏
		return;
	}
}

// 显示联系人
void ShowPerson(AddressBooks *abs)
{
	if (abs->Size == 0)
	{
		cout << "当前通讯录为空\n"
			 << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->Size; i++)
		{
			cout << "姓名为：" << abs->personArray[i].name << endl;
			cout << "性别为：" << abs->personArray[i].sex << endl;
			cout << "年龄为：" << abs->personArray[i].age << endl;
			cout << "电话为：" << abs->personArray[i].phone << endl;
			cout << "地址为：" << abs->personArray[i].addre << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}

// 检测联系人是否存在
int isExit(AddressBooks *abs, string name)
{
	if (abs->Size == 0)
	{
		cout << "通讯录为空" << endl;
		return -1;
	}
	else
	{
		for (int i = 0; i < abs->Size; i++)
		{
			if (abs->personArray[i].name == name)
			{
				return i;
			}
		}
		return -1;
	}
}

// 删除联系人
void deletePerson(AddressBooks *abs, string name)
{
	int pos = isExit(abs, name);
	for (int i = pos; i < abs->Size; i++)
	{
		abs->personArray[i] = abs->personArray[i + 1];
	}
	abs->Size--;
	cout << "删除成功\n";
}

// 查找联系人
void findPerson(AddressBooks *abs)
{
	string name;
	cout << "请输入姓名\n";
	cin >> name;
	if (isExit(abs, name) == -1)
	{
		cout << "该杂鱼不存在哦~?\n";
	}
	else
	{
		int i = isExit(abs, name);
		cout << "姓名为：" << abs->personArray[i].name << endl;
		cout << "性别为：" << abs->personArray[i].sex << endl;
		cout << "年龄为：" << abs->personArray[i].age << endl;
		cout << "电话为：" << abs->personArray[i].phone << endl;
		cout << "地址为：" << abs->personArray[i].addre << endl;
	}
	system("pause");
	system("cls");
	return;
}

// 修改联系人
void changePerson(AddressBooks *abs)
{
	cout << "请输入您要修改的联系人，杂鱼~\n";
	string name;
	cin >> name;
	int pos = isExit(abs, name);
	if (pos == -1)
	{
		cout << "联系人不存在\n";
	}
	else
	{
		cout << "开始修改联系人\n";
		cout << "修改姓名为：\n";
		cin >> abs->personArray[pos].name;
		cout << "修改性别为：\n";
		cin >> abs->personArray[pos].sex;
		cout << "修改年龄为：\n";
		cin >> abs->personArray[pos].age;
		cout << "修改电话为：\n";
		cin >> abs->personArray[pos].phone;
		cout << "修改地址为：\n";
		cin >> abs->personArray[pos].addre;
		cout << "修改完毕!" << '\n';
	}
	system("pause");
	system("cls");
	return;
}

void clearPerson(AddressBooks *abs)
{
	abs->Size = 0;
	cout << "清空成功，杂鱼~\n";
	system("pause");
	system("cls");
	return;
}

int main()
{

	AddressBooks abs;
	abs.Size = 0;

	int select = 0; // 用户输入
	while (true)
	{
		ShowMenu();
		cin >> select;
		switch (select)
		{
		case 1: // 1添加联系人
			addPerson(&abs);
			break;

		case 2: // 2.显示联系人
			ShowPerson(&abs);
			break;

		case 3:
		{ // 3.删除联系人
			cout << "请输入名字：\n";
			string name;
			cin >> name;
			if (isExit(&abs, name) == -1)
			{
				cout << "联系人不存在\n";
			}
			else
			{
				cout << "找到此人，现在进行删除\n";
				deletePerson(&abs, name);
			}
			system("pause");
			system("cls");
		}
		break;

		case 4: // 4.查找联系人
			findPerson(&abs);
			break;

		case 5: // 5.修改联系人
			changePerson(&abs);
			break;

		case 6: // 6.清空联系人
			clearPerson(&abs);
			break;
		case 0: // 0.退出通讯录
			cout << "欢迎杂鱼下次再使用该通讯录~?" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "杂鱼杂鱼~怎么连数字都输不对~需不需要鸽鸽等你放学教育教育你~?\n";
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}