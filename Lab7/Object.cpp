#include "Object.h"

std::ostream& operator<<(std::ostream& s, const Object& o)
{
  o.print(s,0);
  return s;
}