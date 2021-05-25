#include <iostream>
#include <cstring>
using namespace std;

struct str
{
  public:
    char* p;
    int len;
    str(char* ptr)
	  {
      for (len = 0; ptr[len] != '\0'; len++);
      p = new char[len + 1];
      for (int i = 0; ptr[i] != '\0'; i++)
      {
        p[i] = ptr[i];
      }
      p[len] = '\0';
    }
    ~str()
	  {
      if (p != NULL)
        delete[] p;
	  }
  
    bool operator== (str a)
    {
      if (len != a.len)
        return 0;
      for (int i = 0; i < len; i++){
        if (p[i] != a.p[i])
          return 0;
      }
      return 1;
    }

    str operator- (char a)
    {
      char r[len + 1];
      int k = 0;
      for(char* i = p; *i != '\0'; i++){
        if (*i != a){
          r[k] = *i;
          k++;
        }
      }
      r[k] = '\0';
      str res(r);
      return res;
    }

    str strset(str a, str b)
    {
      str res(a.p);
      for(char* i = b.p; *i != '\0'; i++)
        res = res - *i;
      return res;
    }
};
