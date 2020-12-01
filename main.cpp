#include <iostream>
#include "Sparse.h"

int main()
{
	Sparse<int> sparse;


	std::cout << "Add 5 elements" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		sparse.addElement(i,i*i);
	}
	sparse.print();

	std::cout << "---------" << std::endl;
	std::cout << "Remove second element" << std::endl;
	sparse.removeElementByIndex(2);
	sparse.print();

	std::cout << "---------" << std::endl;
	std::cout << "Return third element" << std::endl;
	std::cout << sparse[3] << std::endl;

	std::cout << "---------" << std::endl;
	std::cout << "Return deleted element" << std::endl;
	std::cout << sparse[2] << std::endl;

	return 0;
}