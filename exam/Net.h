class Net : public NetworkItem{
list<NetworkItem*> NetItemList;
list<IP> IPList;
public:
bool AddCopy(const NetworkItem* item);
bool Add(NetworkItem* item);
bool remove(const IP ipremove);
//..
};