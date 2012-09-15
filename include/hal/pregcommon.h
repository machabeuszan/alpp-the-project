#ifndef PREGCOMMON_H
#define PREGCOMMON_H

#include "hal/onoff.h"


template <class T>
class PRegCommon
{
    public:
        PRegCommon(volatile T& reg);
        void set(const T& value, const T& mask);
        static void set(volatile T& reg, const T& value, const T& mask);
        T get(const T& mask);
        static T get(volatile T& reg, const T& mask);
    protected:
        volatile T& regHandle;
};


template <class T> PRegCommon<T>::PRegCommon(volatile T& reg): regHandle(reg)
{
  ;
}

/*template <class T> void PRegCommon<T>::valWithMask(volatile T &reg, T& val, T& mask)
{

}*/

template <class T> void PRegCommon<T>::set(const T& value, const T& mask)
{
  set(regHandle,value,mask);
}

template <class T> void PRegCommon<T>::set(volatile T& reg, const T& value, const T& mask)
{
  T a=value&mask;
  T b=value|(~mask);
  reg=(b&reg);
  reg=a|reg;
}

template <class T> T PRegCommon<T>::get(const T& mask)
{
  get(regHandle,mask);
}

template <class T> T PRegCommon<T>::get(volatile T& reg, const T& mask)
{
  T val=reg;
  T a=val&mask;
  T b=val|mask;
  val=a|(b&reg);
  return val;
}

#endif // PREGCOMMON_H
