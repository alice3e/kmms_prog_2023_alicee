#pragma once
#include <iostream>
namespace IBusko {
	template <typename T> 
	class Vector {
		private:
			T* arr;
			std::size_t capacity = 10;
			std::size_t size = 0;
		public:
			Vector() noexcept = default;
			Vector(const Vector&) = delete;
			Vector& operator = (const Vector&) = delete;
			~Vector() noexcept;
			
			void push_back(const T& value) noexcept;
			bool has_item(const T& value) const noexcept;
			bool insert(const int position, const T& value);
			void print() const noexcept;
			bool remove_first(const T& value) noexcept;
			std::size_t get_size() const noexcept;
	};
}
