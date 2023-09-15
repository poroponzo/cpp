#ifndef NET_H
#define NET_H
#include "PC.h"
#include "NetworkItem.h"
#include "IP.h"
#include <list>
#include <iostream>
using namespace std;


class Net : public NetworkItem {
private:
    list<NetworkItem*> NetItemList;
    list<IP> IPList;

public:
    // Constructor
    Net(const string& itemName, const IP& ip) : NetworkItem(itemName, ip) {}

    // Copy constructor
    Net(const Net& other) : NetworkItem(other) {
        for (auto item : other.NetItemList) {
            NetItemList.push_back(item->clone());
        }
        IPList = other.IPList;
    }

    // Assignment operator
    Net& operator=(const Net& other) {
        if (this != &other) {
            NetworkItem::operator=(other);

            for (auto item : NetItemList) {
                delete item;
            }
            NetItemList.clear();

            for (auto item : other.NetItemList) {
                NetItemList.push_back(item->clone());
            }
            IPList = other.IPList;
        }

        return *this;
    }

    // Destructor
    virtual ~Net() {
        for (auto item : NetItemList) {
            delete item;
        }
    }

    // Clone method
    virtual NetworkItem* clone() const {
        return new Net(*this);
    }


    // AddCopy method
    bool AddCopy(const NetworkItem* item) {
        if (item == nullptr) {
            return false;
        }

        NetworkItem* cloneItem = item->clone();
        NetItemList.push_back(cloneItem);
        IPList.push_back(cloneItem->getIP());

        return true;
    }

    // Add method
    bool Add(NetworkItem* item) {
        if (item == nullptr) {
            return false;
        }

        NetItemList.push_back(item);
        IPList.push_back(item->getIP());

        return true;
    }

    // Remove method
    bool remove(const IP ipremove) {
        for (auto it = NetItemList.begin(); it != NetItemList.end(); ++it) {
            if ((*it)->getIP() == ipremove) {
                delete* it;
                NetItemList.erase(it);
                IPList.remove(ipremove);

                return true;
            }
        }

        return false;
    }

    // Print method
    virtual void Print() const {
        cout << "Network: " << ItemName << endl;
        m_ip.Print();

        cout << "Number of items in the network: " << NetItemList.size() << endl;
        for (auto item : NetItemList) {
            item->Print();
        }
    }
    virtual int Size() const {
        int size = 1; // the net itself

        for (auto item : NetItemList) {
            size += item->Size();
        }

        return size;
    }
};
#endif
