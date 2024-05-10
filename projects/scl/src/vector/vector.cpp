//
// Created by Andrei Sulimov on 10.05.2024.
//
#include "vector.hpp"
#include <cstddef>
#include <stdexcept>
#include <iostream>


template <typename T>
IBusko::Vector<T>::~Vector() noexcept{
	delete[] arr;
	capacity = 0;
	size = 0;
	arr = nullptr;
}


template <typename T>
void IBusko::Vector<T>::push_back(const T& value) noexcept{
	if (capacity == size){
		T* new_arr = new T[capacity * 2];
		for (std::size_t i = 0; i < capacity; i++)
        {
			new_arr[i] = arr[i];
		}
		capacity *= 2;
        delete[] arr;
		arr = new_arr;
	}
	arr[size] = value;
	size++;
}

template <typename T>
bool IBusko::Vector<T>::has_item(const T& value) const noexcept {
    for (std::size_t i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool IBusko::Vector<T>::insert(const int position, const T& value){
	if (position > size) throw std::out_of_range("position out");

	if (capacity == size){
		T* new_arr = new T[2 * capacity];
		for (std::size_t i = 0; i < capacity; i++){
			new_arr[i] = arr[i];
		}
		arr = new_arr;
        delete[] arr;
		capacity = 2 * capacity;
	}
	for (std::size_t i = size; i > position; i--){
		arr[i] = arr[i-1];
	}
	size += 1;
	arr[position] = value;
	return 1;
}

template <typename T>
void IBusko::Vector<T>::print() const noexcept {
    for (std::size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

template <typename T>
bool IBusko::Vector<T>::remove_first(const T& value) noexcept{
	T* new_arr = new T[capacity - 1];

	for (std::size_t i = 0; i < size; i++){
		if (arr[i] == value){
			for (std::size_t j = i; j < size-1; j++){
				new_arr[j] = arr[j+1];
			}
			delete[] arr;
			arr = new_arr;
			capacity -= 1;
			size -= 1;
			return true;
		}
		new_arr[i] = arr[i];
	}

	return false;
}

template <typename T>
std::size_t IBusko::Vector<T>::get_size() const noexcept{
	return size;
}