#include "sequential.cpp"
#include "linkedlist.cpp"
#pragma once

int main() {
	// 1. �������� ������� ���������� ��� �������� �������� ���� int

	SequentialContainer<int> SeqContainer;
	std::cout << "Sequential Container was created" << std::endl;

	// 2. ���������� � ��������� ������ ��������� (0, 1 � 9)

	for (int value = 0; value < 10; value++)
	{
		SeqContainer.push_back(value);
	}

	// 3. ����� ����������� ���������� �� �����

	SeqContainer.printContainer();
	
	// 4. ����� ������� ���������� �� ����� (��������� ��������� : 10)

	std::cout << SeqContainer.size() << std::endl;

	// 5. �������� ��������(�� �����), ������ � �������� ���������

	SeqContainer.erase(2);
	SeqContainer.erase(3);
	SeqContainer.erase(4);


	// 6. ����� ����������� ���������� �� ����� (��������� ��������� : 0, 1, 3, 5, 7, 8, 9)

	SeqContainer.printContainer();

	// 7. ���������� �������� 10 � ������ ����������

	SeqContainer.insert(0, 10);

	// 8. ����� ����������� ���������� �� ����� (��������� ��������� : 10, 0, 1, 3, 5, 7, 8, 9)

	SeqContainer.printContainer();

	// 9. ���������� �������� 20 � �������� ����������

	int index = SeqContainer.size() / 2;
	SeqContainer.insert(index, 20);

	//	10. ����� ����������� ���������� �� ����� (��������� ��������� : 10, 0, 1, 3, 20, 5, 7, 8, 9)

	SeqContainer.printContainer();

	// 11. ���������� �������� 30 � ����� ����������

	SeqContainer.push_back(30);
		
	//12. ����� ����������� ���������� �� �����	(��������� ��������� : 10, 0, 1, 3, 20, 5, 7, 8, 9, 30)

	SeqContainer.printContainer();



	// 1. �������� ������� ���������� ���������� ���� ��� �������� �������� ���� int

	LinkedListContainer<int> LinkedListContainer;
	std::cout << "\nLinked List Container was created" << std::endl;

	// 2. ���������� � ��������� ������ ��������� (0, 1 � 9)

	for (int value = 0; value < 10; value++)
	{
		LinkedListContainer.push_back(value);
	}

	// 3. ����� ����������� ���������� �� �����

	LinkedListContainer.printContainer();

	// 4. ����� ������� ���������� �� ����� (��������� ��������� : 10)

	std::cout << LinkedListContainer.size() << std::endl;

	// 5. �������� ��������(�� �����), ������ � �������� ���������

	LinkedListContainer.erase(2);
	LinkedListContainer.erase(3);
	LinkedListContainer.erase(4);


	// 6. ����� ����������� ���������� �� ����� (��������� ��������� : 0, 1, 3, 5, 7, 8, 9)

	LinkedListContainer.printContainer();

	// 7. ���������� �������� 10 � ������ ����������

	LinkedListContainer.insert(0, 10);

	// 8. ����� ����������� ���������� �� ����� (��������� ��������� : 10, 0, 1, 3, 5, 7, 8, 9)

	LinkedListContainer.printContainer();

	// 9. ���������� �������� 20 � �������� ����������

	int _index = LinkedListContainer.size() / 2;
	LinkedListContainer.insert(_index, 20);

	//	10. ����� ����������� ���������� �� ����� (��������� ��������� : 10, 0, 1, 3, 20, 5, 7, 8, 9)

	LinkedListContainer.printContainer();

	// 11. ���������� �������� 30 � ����� ����������

	LinkedListContainer.push_back(30);

	//12. ����� ����������� ���������� �� �����	(��������� ��������� : 10, 0, 1, 3, 20, 5, 7, 8, 9, 30)

	LinkedListContainer.printContainer();

	return 0;
}