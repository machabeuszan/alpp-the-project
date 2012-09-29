/*---------------------------------------------+
|                                              |
| Name: include/hal/pregcommon.h               |
|  Project: alpp                               |
|  Author: Adrian Ciesielski                   |
|  Creation Date: 2012-08-31                   |
|  Copyright: (c) 2012 by Adrian Ciesielski    |
|  License: See top of Makefile                |
|  Version: See top of Makefile                |
|                                              |
+---------------------------------------------*/

#ifndef PREGCOMMON_H
#define PREGCOMMON_H

#include "hal/onoff.h"

/**
 * Szablon klasy która służy do manipulowania rejestrami.
 */
template <class T>
class PRegCommon
{
    public:
	/**
	 * Konstruktor.
	 * @param reg to rejestr typu T. Pobierany jest jako referencja.
	 */
        PRegCommon(volatile T& reg);
	/**
	 * Setter.
	 * Jego zadaniem jest ustawienie wartości rejestru na wartość tylko na tych bitach na których zezwala na to maska.
	 * @param value to wartość która ma zostać ustawina w rejestrze.
	 *  @param mask to maska bitowa. Jeżeli na danym bicie jest jedynka to do rejestru zostanie skopiowana wartość bitu na tej samej pozycji z argumentu value. Jeśli na danej pozycji jest zero wartość odpowiadającego bitu w rejestrze pozostanie bez zmian.
	 */
        void set(const T& value, const T& mask);
	/** Static setter.
	 * Ta metoda robi dokładnie to samo co powyższa, z tym że nie trzeba tworzyć egzemplarza obiektu tej klasy. To oznacza że można wywołać tą metodę tak jakby była luźną funkcją (czyli nie będącą metodą żadnej klasy).
	 * @param reg jest rejestrem na którym będziemy dokonywać operacji zamaskowanego ustawiania.
	 * @param value jak w odpowiedającej metodzie niestatycznej.
	 * @param mask jak w odpowiadającej metodzie niestatycznej.
	 * @see PRegCommon argument reg
	 */
        static void set(volatile T& reg, const T& value, const T& mask);
	/**
	 * Getter.
	 * Pobiera zamaskowaną wartość z rejestru.
	 * @param value to zmienna do której zostanie wpisany wynik operacji odczytu z maską. Zostanie on także zwrócony przez funkcję.
	 * @param mask to maska bitowa. Jeżeli na danym bicie maski jest jedynka to bit znajdujący się na tej samej pozycji w wartości zwracanej przez funkcję będzie miał wartość opowiedniego bitu z rejestru. Jeśli na danym bicie maski jest zero to odpowiadający bit zwracany będzie miał wartość zero.
	 */
        T get(T& value, const T& mask);
	/**
	 * Static getter.
	 * Działa tak samo jak powyższy getter z tą jednak różnicą, że działamy na rejestrze podanum jako argument. Tak jak w przypadku statycznej metody set nie potrzeba tworzyć egzemplarza tej klasy. Metodę można wywoływać tak jak luźną funckcję.
	 * @param reg jest rejestrem na którym będziemy dokonywać operacji zamaskowanego odczytu.
	 * @param value jak w odpowiedającej metodzie niestatycznej.
	 * @param mask jak w odpowiadającej metodzie niestatycznej.
	 * @see PRegCommon argument reg
 	 */
        static T get(volatile T& reg, T& value, const T& mask);
    protected:
        volatile T& regHandle;
        //T& valWM(T &setted, T &val, T &mask);
};


template <class T> PRegCommon<T>::PRegCommon(volatile T& reg): regHandle(reg)
{
  ;
}

/*template <class T> void PRegCommon<T>::valWM(T &setted, T &val, T &mask))
{
    T a=val&mask;
    T b=val|(~mask);
    setted=(b&setted);
    setted=a|setted;
}*/

template <class T> void PRegCommon<T>::set(const T& value, const T& mask)
{
  set(regHandle,value,mask);
}

template <class T> void PRegCommon<T>::set(volatile T& reg, const T& value, const T& mask)
{
    //valWM(reg,value,mask);
  T a=value&mask;
  T b=value|(~mask);
  reg=(b&reg);
  reg=a|reg;
}

template <class T> T PRegCommon<T>::get(T& value, const T& mask)
{
  return get(regHandle,value,mask);
}

template <class T> T PRegCommon<T>::get(volatile T& reg, T& val, const T& mask)
{
    //return valWM(val,reg,mask);
  T a=reg&mask;
  T b=reg|(~mask);
  val=b&val;
  val=a|val;
  return val;
}

#endif // PREGCOMMON_H
