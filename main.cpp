#include "sequential.cpp"
#pragma once

int main() {
	// 1. создание объекта контейнера дл€ хранени€ объектов типа int

	SequentialContainer<int> SeqContainer;

	// 2. добавление в контейнер дес€ти элементов (0, 1 Е 9)

	for (int value = 0; value < 10; value++)
	{
		SeqContainer.push_back(value);
	}

	// 3. вывод содержимого контейнера на экран

	SeqContainer.printContainer();
	
	// 4. вывод размера контейнера на экран (ожидаемый результат : 10)

	std::cout << SeqContainer.size() << std::endl;

	// 5. удаление третьего(по счЄту), п€того и седьмого элементов

	SeqContainer.erase(2);
	SeqContainer.erase(3);
	SeqContainer.erase(4);


	// 6. вывод содержимого контейнера на экран (ожидаемый результат : 0, 1, 3, 5, 7, 8, 9)

	SeqContainer.printContainer();

	// 7. добавление элемента 10 в начало контейнера

	SeqContainer.insert(0, 10);

	// 8. вывод содержимого контейнера на экран (ожидаемый результат : 10, 0, 1, 3, 5, 7, 8, 9)

	SeqContainer.printContainer();

	// 9. добавление элемента 20 в середину контейнера

	int index = SeqContainer.size() / 2;
	SeqContainer.insert(index, 20);

	//	10. вывод содержимого контейнера на экран (ожидаемый результат : 10, 0, 1, 3, 20, 5, 7, 8, 9)

	SeqContainer.printContainer();

	// 11. добавление элемента 30 в конец контейнера

	SeqContainer.push_back(30);
		
	//12. вывод содержимого контейнера на экран	(ожидаемый результат : 10, 0, 1, 3, 20, 5, 7, 8, 9, 30)

	SeqContainer.printContainer();


	return 0;
}