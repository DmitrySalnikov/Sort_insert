#pragma once

template <typename T>
bool less(T const & a, T const & b) {
    return a < b;
}

template <typename T>
void sort(T * a, T * b, bool (*compare)(T const &, T const &) = less) {
	for (auto p = a + 1; p < b; ++p) {
		auto temp = *p;
		auto temp_p = p;
		while ((temp_p != a) && !compare(*(temp_p - 1), temp)) {
			*temp_p = *(temp_p - 1);
			--temp_p;
		}
		*temp_p = temp;
	}
}
