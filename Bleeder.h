#include <cstdint>

#include "EdgeIterator.h"

#ifndef Bleeder_h
#define Bleeder_h

class Bleeder
{
  public:
    Bleeder(EdgeIteratorBase *start) 
    {
        _count = 0;
        EdgeIteratorBase** arr = new EdgeIteratorBase*[1 << ITERATIONS] { start };
        _iterators = arr;
    }
    Bleeder(const Bleeder& rhs)
    {
        _iterators = rhs._iterators;
        _count = rhs._count;
    }
    ~Bleeder()
    {
        for (int i = 0; i < _count; i++)
        {
            delete _iterators[i];
        }
        delete _iterators;
    }
    bool moveNext()
    {
        if (_count == 0)
        {
            _count++;
            return true;
        }
        if (_count == (1 << ITERATIONS))
            return false;

        uint8_t newCount = _count*2;
        uint8_t index = _count;

        for (int i = 0; i < _count; i++)
        {
            EdgeIteratorBase *previous = _iterators[i];
            _iterators[index] = previous->getNextA();
            index = (index+1) % newCount;
            _iterators[index] = previous->getNextB();
            index = (index+1) % newCount;
            delete previous;
        }
        _count = newCount;
        return true;
    }
    uint8_t count()
    {
        return _count;
    }
    EdgeIteratorBase** getIterators(){
        return _iterators;
    }
  private:
    static const uint8_t ITERATIONS = 5;
    uint8_t _count;
    EdgeIteratorBase** _iterators;
};

#endif