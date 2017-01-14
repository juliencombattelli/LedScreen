/*
 * Vector2D.h
 *
 *  Created on: 14 janv. 2017
 *      Author: JulienCombattelli
 */

#ifndef SRC_VECTOR2D_H_
#define SRC_VECTOR2D_H_

#include <memory>

template<typename T, class A = std::allocator<T>>
class Vector2D
{
public:

	using allocator_type = A;
	using value_type = typename allocator_type::value_type;
	using reference = typename allocator_type::reference;
	using const_reference = typename allocator_type::const_reference;
	using pointer = typename allocator_type::pointer;
	using const_pointer = typename allocator_type::const_pointer;
	using difference_type = typename allocator_type::difference_type;
	using size_type = typename allocator_type::size_type;

	using iterator = pointer;
	using const_iterator = const_pointer;

	Vector2D();
	Vector2D(int rowCount, int columnCount, const std::initializer_list<T>& list);
	Vector2D(const std::initializer_list<std::initializer_list<T>>& list);
	~Vector2D();

	iterator begin();
	iterator end();

	void setSize(int row, int column);
	int getRowCount() const;
	int getColumnCount() const;

	void clear();

	T& operator()(int row, int column);

	const T& operator()(int row, int column) const;

protected:

	int m_row;
	int m_column;
	T* m_data;
};

template<typename T, class A>
Vector2D<T,A>::Vector2D() :
	m_row(0), m_column(0), m_data(nullptr)
{

}

template<typename T, class A>
Vector2D<T,A>::Vector2D(int rowCount, int columnCount, const std::initializer_list<T>& list) :
	m_row(rowCount), m_column(columnCount), m_data(nullptr)
{
	m_data = new T[m_row*m_column];

	std::copy(list.begin(), list.end(), begin());
}

template<typename T, class A>
Vector2D<T,A>::Vector2D(const std::initializer_list<std::initializer_list<T>>& list) :
	m_row(list.size()), m_column(list.begin()->size()), m_data(nullptr)
{
	m_data = new T[m_row*m_column];

	iterator i = end() - m_column;
	for(auto& subList : list)
	{
		std::copy(subList.begin(), subList.end(), i);
		i -= m_column;
	}
}

template<typename T, class A>
Vector2D<T,A>::~Vector2D()
{
	delete[] m_data;
}

template<typename T, class A>
typename Vector2D<T,A>::iterator Vector2D<T,A>::begin()
{
	return &m_data[0];
}

template<typename T, class A>
typename Vector2D<T,A>::iterator Vector2D<T,A>::end()
{
	return &m_data[m_row*m_column];
}

template<typename T, class A>
void Vector2D<T,A>::setSize(int row, int column)
{
	m_row = row;
	m_column = column;
	m_data = new T[m_row*m_column];
}

template<typename T, class A>
int Vector2D<T,A>::getRowCount() const
{
	return m_row;
}

template<typename T, class A>
int Vector2D<T,A>::getColumnCount() const
{
	return m_column;
}

template<typename T, class A>
void Vector2D<T,A>::clear()
{
	delete[] m_data;
	m_data = nullptr;
	m_row = 0;
	m_column = 0;
}

template<typename T, class A>
T& Vector2D<T,A>::operator()(int row, int column)
{
	return m_data[row*m_column+column];
}

template<typename T, class A>
const T& Vector2D<T,A>::operator()(int row, int column) const
{
	return m_data[row*m_column+column];
}

#endif /* SRC_VECTOR2D_H_ */
