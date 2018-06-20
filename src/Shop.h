#pragma once

#include <memory>
#include <vector>
#include "Device.h"

using namespace std;

class Shop
{
    vector<shared_ptr<Device> > devices;
public:
    void addDevice(shared_ptr<Device> device);
    void removeDevice(int position);
    void print() const;
    int getSize() const;
};