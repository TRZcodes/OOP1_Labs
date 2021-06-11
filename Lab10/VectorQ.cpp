#include "VectorQ.h"

void VectorQ::add(std::unique_ptr<Person> prsn)
{
  _queue.push_back(std::move(prsn));
}

void VectorQ::print(std::string s) const
{
  std::cout<<s<<std::endl;
  for(auto const &elem: _queue)
    elem->print();
}

std::vector<Woman*> VectorQ::getWomen()
{
  std::vector<Woman*> women;
  for(auto const &elem: _queue)
  {
    auto wom_ptr=dynamic_cast<Woman*>(elem.get());
    if(wom_ptr)
    {
      women.push_back(wom_ptr);
    }
  }
  return women;
}

void VectorQ::countNames()
{
  std::map<std::string, int> temp_map;
  for(auto const &elem: _queue)
  {
    temp_map[elem->name()]++;
  }

  for (auto elem: temp_map)
  {
    std::cout<<elem.first<<": "<<elem.second<<std::endl;
  }
}

void VectorQ::haircut()
{
  _queue[0]->haircut();
  if(_queue[0]->done())
    _queue.erase(_queue.begin());
}

void VectorQ::haircut(std::string name)
{
  unsigned int i=0;
  for(auto const &elem: _queue)
  {
    if(!elem->name().compare(name))
    {
      elem->haircut();
      if(elem->done())
        _queue.erase(_queue.begin()+i);
      break;
    }
    i++;
  }
}

void VectorQ::shave()
{
  _queue[0]->shave();
  if(_queue[0]->done())
    _queue.erase(_queue.begin());
}

void VectorQ::shave(std::string name)
{
  unsigned int i=0;
  for(auto const &elem: _queue)
  {
    if(!elem->name().compare(name))
    {
      dynamic_cast<Man*>(elem.get())->shave();
      if(elem->done())
        _queue.erase(_queue.begin()+i);
      break;
    }
    i++;
  }
}