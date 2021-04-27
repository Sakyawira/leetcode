#include <iostream>

namespace apple {
	void pie() {
		return;
	}
}

namespace orange {
	void juice() {
		return;
	}
}

int main() {

	using namespace apple;
	pie();
	using namespace orange;
	pie();


	std::cin.get();
}