#include <iostream>
#include "Money.h"
money::money(int hrn, short int kop) : hrn(hrn), kop(kop) {}
money money::add(money other) {
	int total_kop = kop + other.kop;
	int total_hrn = hrn + other.hrn + total_kop / 100;
	return money(total_hrn, total_kop % 100);
}
//додаються копійки двох різних цін і виходить взагальному ціна в копійках
//потім так же само з гривнями, але ще додаються копійки поділені на 100 і з тих переведених копійок ще додаються гривні

money money::multiply(int quantity) {
	int total_kop = (hrn * 100 + kop) * quantity;
	return money(total_kop / 100, total_kop % 100);
}
// / 100 це скільки повних гривень % 100 це залишок коп.
void money::round() {
	kop = (kop + 5) / 10 * 10;
	if (kop == 100) {
		hrn = hrn + 1;
		kop = 0;
	}
}              // після ділення копійок якщо = 100, то додажться одна гривня і копійки обнуляються
void money::print() const {
	std::cout << hrn << " grn " << kop << " kop." << std::endl;
}
//виводить грн та коп в термінал
