#include "Shop.h"
#include <iostream>

using namespace std;

void Shop::addDevice(shared_ptr<Device> device) {
    devices.push_back(device);
}

void Shop::removeDevice(int position) {
	devices.erase(devices.begin() + position);
}

void Shop::print() const {
    for (int i = 0; i < getSize(); i++) {
        devices[i]->print();
        cout << endl;
    }
}

int Shop::getSize() const {
    return devices.size();
}