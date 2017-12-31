#include <string>
#include <memory>

using namespace std;

class StateObj {
  public:
    virtual setState(...) = 0;
  private:
};


template<typename T> class StateAdapter {
  public: 
    static StateAdapter* createAdapter(...);
  private:
    StateObj* m_state;
    T*        m_obj;
};
