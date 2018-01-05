#include <string>
#include <chrono>

using namespace std;

class ObjDataBlockNode {
public:
  ObjDataBlockNode(unsigned int index, string ledgerData, string prevNodeHash = "") 
            : m_createTime(chrono::system_clock::now()),
              m_chainIndex(index),
              m_ledgerData(ledgerData),
              m_PreviousNode(prevNodeHash) {  }
              
  string hashOut();
  
  bool isValidNode();
  
  bool initFirstNode();
  
  bool isItFirstNode();

private:
  unsigned int      m_createTime;
  unsigned int      m_chainIndex;
  string            m_ledgerData;
  string            m_PreviousNode;
};
