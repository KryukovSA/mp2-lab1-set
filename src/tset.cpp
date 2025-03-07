// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"
//using namespace std;
TSet::TSet(int mp) : MaxPower(mp), BitField(mp)
{
	
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField), MaxPower (s.MaxPower)
{
	
}
// конструктор преобразования типа
TSet::TSet(const TBitField &bf) :MaxPower(bf.GetLength()), BitField(bf)  
{

}

TSet::operator TBitField()
{
	return BitField; 
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	if (BitField.GetBit(Elem)) {
		return true;
	}
	return false;
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	
	BitField = s.BitField;
	MaxPower = s.MaxPower;
	return *this;

}

int TSet::operator==(const TSet &s) const // сравнение
{
	if (BitField == s.BitField)
		return 1;
	else
		return 0;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	if (BitField != s.BitField)
		return 1;
	else
		return 0;
}

TSet TSet::operator+(const TSet &s) // объединение
{
	TSet tmp(BitField | s.BitField);
	return tmp;
	
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	TSet tmp(*this);
	 tmp.InsElem(Elem);
	return tmp;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	TSet tmp(BitField & (~Elem));
	return tmp;
}

TSet TSet::operator*(const TSet &s) // пересечение метод
{
	TSet tmp(BitField & s.BitField);
	return tmp;
}

TSet TSet::operator~(void) // дополнение
{
	TSet tmp(~BitField);
	return tmp;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
	istr >> s.MaxPower;
	istr >> s.BitField;
	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
	ostr << s.MaxPower << s.BitField << " ";
	ostr << endl;
	return ostr;
}
