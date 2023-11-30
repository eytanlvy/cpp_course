#ifndef MON_PTR_HPP
#define MON_PTR_HPP

#include <iostream>

template <typename T>
class Mon_ptr_u {
	private:
		static std::vector<T*> ptrs;
		T* ptr;
	public:
		Mon_ptr_u(T* p): ptr(p) {
			if (is_in_ptrs(p)) {
				throw std::runtime_error("Erreur : pointeur déjà présent dans le vecteur");
			}
			ptrs.push_back(p);
		};
		~Mon_ptr_u() { 
			erase(ptr);
			delete ptr;
		};

		Mon_ptr_u(const Mon_ptr_u& mp) = delete;
		//Mon_ptr_u& operator=(const Mon_ptr_u& mp) = delete;

		T* release() {
			T* tmp = ptr;
			ptr = nullptr;
			return tmp;
		};

		void echange(Mon_ptr_u& mp) {
			T* tmp = ptr;
			ptr = mp.ptr;
			mp.ptr = tmp;
		}

		operator bool() const { return ptr != nullptr; }
		T& operator*() const { return *ptr; };
		T* operator->() const { return ptr; }; 

		// ptrs methods
		std::vector <T*> const get_ptrs() const { return ptrs; };
		bool const is_in_ptrs(T* ptr) const {
			for (auto p : ptrs) {
				if (p == ptr) {
					return true;
				}
			}
			return false;
		};
		void erase(T* ptr) {
			for (auto it = ptrs.begin(); it != ptrs.end(); ++it) {
				if (*it == ptr) {
					ptrs.erase(it);
					return;
				}
			}
		};

};

#endif