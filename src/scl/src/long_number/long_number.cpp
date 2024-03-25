#include "long_number.hpp"
#include <iostream>

namespace SCL {
	LongNumber::LongNumber() {
		this->numbers = new int[0];
        this->length = 0;
        this->sign = POSITIVE;        
	}
	
	LongNumber::LongNumber(const char* const str) {
		if (str[0] == MINUS) this->sign=NEGATIVE;
		else this->sign=POSITIVE;

		int sign_indentation = 0;
		if (this->sign == NEGATIVE) sign_indentation++;

		this->length = get_length(str) - sign_indentation;
		this->numbers = new int[this->length];

		for (int i = 0; i < this->length; i++){
			char current_digit = str[i+sign_indentation];
			this->numbers[i] = current_digit - '0';
		}
	}

	LongNumber::LongNumber(const LongNumber& x) {
		this->sign = x.sign;
		this->length = x.length;
		this->numbers = new int[this->length];

		for (int i = 0; i < this->length; i++){
			this->numbers[i] = x.numbers[i];
		}
	}
	
	LongNumber::LongNumber(LongNumber&& x) {
		this->sign = x.sign;
		this->length = x.length;
		this->numbers = x.numbers;

		x.numbers = nullptr;
		x.length = 0;
		x.sign = POSITIVE;
	}
	
	LongNumber::~LongNumber() {
		delete [] this->numbers;
	}
	
	LongNumber& LongNumber::operator = (const char* const str) {
		delete [] this->numbers;

		if (str[0] == MINUS) this->sign=NEGATIVE;
		else this->sign=POSITIVE;

		int sign_indentation = 0;
		if (this->sign == NEGATIVE) sign_indentation++;

		this->length = get_length(str) - sign_indentation;
		this->numbers = new int[this->length];

		for (int i = 0; i < this->length; i++){
			char current_digit = str[i+sign_indentation];
			this->numbers[i] = current_digit - '0';
		}
		return *this;
	}
	
	LongNumber& LongNumber::operator = (const LongNumber& x) {
		if (this == &x) return *this;

		delete [] this->numbers;

		this->sign = x.sign;
		this->length = x.length;
		this->numbers = new int[this->length];

		for (int i = 0; i < this->length; i++){
			this->numbers[i] = x.numbers[i];
		}
		return *this;
	}
	
	LongNumber& LongNumber::operator = (LongNumber&& x) {
		delete [] this->numbers;

		this->sign = x.sign;
		this->length = x.length;
		this->numbers = x.numbers;
		x.numbers = nullptr;
		return *this;
	}
	
	bool LongNumber::operator == (const LongNumber& x) const {
		if (this->sign != x.sign || this->length != x.length) {
			return false;	
		}

		for (int i = 0; i < this->length; i++) {
			if (this->numbers[i] != x.numbers[i]) return false;
		}

		return true;
	}

	bool LongNumber::operator != (const LongNumber& x) const {
		return !(*this==x);
	}
	
	bool LongNumber::operator > (const LongNumber& x) const {
		if (this->sign == NEGATIVE && x.sign == POSITIVE) return false;
		if (this->sign == POSITIVE && x.sign == NEGATIVE) return true;

		if (this->sign == POSITIVE){
			if (this->length > x.length) return true;
			if (this->length < x.length) return false;
			for (int i = 0; i < this->length; i++) {
				if (this->numbers[i] > x.numbers[i]) return true;
				if (this->numbers[i] < x.numbers[i]) return false;
			}
		}

		if (this->sign == NEGATIVE){
			if (this->length > x.length) return false;
			if (this->length < x.length) return true;
			for (int i = 1; i < this->length; i++) {
				if (this->numbers[i] > x.numbers[i]) return false;
				if (this->numbers[i] < x.numbers[i]) return true;
			}
		}
		return false;
	}

	bool LongNumber::operator >= (const LongNumber& x) const {
		return !(*this<x);
	}
	
	bool LongNumber::operator < (const LongNumber& x) const {
		return (*this != x) && !(*this>x);
	}

	bool LongNumber::operator <= (const LongNumber& x) const {
		return !(*this>x);
	}
	
	LongNumber LongNumber::operator + (const LongNumber& x) const {
		LongNumber result;
		
		if (this->is_positive() && !x.is_positive()) {
			LongNumber result = x;
			result.sign = POSITIVE;
			result = *this - result;
			return result;
		}

		if (!this->is_positive() && x.is_positive()){
			LongNumber result = *this;
			result.sign = POSITIVE;
			result = x - result;
			return result;
		}

		if (!this->is_positive() && !x.is_positive()){
			result.sign = NEGATIVE;
		}

		if (this->is_positive() && x.is_positive()){
			result.sign = POSITIVE;
		}

		result.length = std::max(this->length, x.length);
		result.numbers = new int[result.length];

		int debt = 0;
		for (int i = 0; i < result.length; i++){
			int this_index = this->length-i-1;
			int x_index = x.length-i-1;
			int result_index = result.length-i-1;
			int current_digit = debt;
			if (this_index >= 0) current_digit+=this->numbers[this_index];
			if (x_index >= 0) current_digit+=x.numbers[x_index];
			debt = 0;
			if (current_digit >= 10) {
				current_digit -= 10;
				debt += 1;
			}
			result.numbers[result_index] = current_digit;
		}

		if (debt == 1) {
			result.length++;;
			int* old_numbers = result.numbers;
			result.numbers = new int[result.length];
			result.numbers[0] = 1;
			for (int i = 0; i < result.length-1; i++){
				result.numbers[i+1] = old_numbers[i];
			}
		}

		return result;
	}
	
	LongNumber& LongNumber::operator += (const LongNumber& x){
		*this = *this+x;
		return *this;
	}

	LongNumber& LongNumber::operator ++ (){
		*this = *this+"1";
		return *this;
	}

	LongNumber& LongNumber::operator ++ (int){
		*this = *this+"1";
		return *this;
	}

	LongNumber LongNumber::operator - (const LongNumber& x) const {
		LongNumber result;

		if (*this == x){
			result = "0";
			return result;
		}

		if (!x.is_positive()) {
			LongNumber abs_x = x;
			abs_x.sign = POSITIVE;
			result = *this + abs_x;
			return result;
		}

		if (!this->is_positive()){
			LongNumber abs_this = *this;
			abs_this.sign = POSITIVE;
			LongNumber abs_x = x;
			abs_x.sign = POSITIVE;
			result = abs_this + abs_x;
			result.sign = NEGATIVE;
			return result;
		}

		if (*this>x) {
			result.sign = POSITIVE; 

			result.length = std::max(this->length, x.length);
			result.numbers = new int[result.length];

			int debt = 0;
			for (int i = 0; i < result.length; i++){
				int this_index = this->length-i-1;
				int x_index = x.length-i-1;
				int result_index = result.length-i-1;
				int current_digit = debt;
				if (this_index >= 0) current_digit+=this->numbers[this_index];
				if (x_index >= 0) current_digit-=x.numbers[x_index];

				debt = 0;
				if (current_digit < 0) {
					current_digit += 10;
					debt -= 1;
				}
				result.numbers[result_index] = current_digit;
			}

			// Fixing leading zeroes
			for (int i = 0; i < result.length; i++){
				if (result.numbers[0] == 0){
					int *new_numbers = new int[result.length-1];

					for (int i = 0; i < result.length-1; i++){
						new_numbers[i] = result.numbers[i+1];
					}
					delete [] result.numbers;
					result.numbers = new_numbers;
					result.length--;
				}
			}

		}
		else {
			result = x-*this;
			result.sign = NEGATIVE;
		};

		return result;

	}
	
	LongNumber& LongNumber::operator -= (const LongNumber& x){
		*this = *this-x;
		return *this;
	}

	LongNumber& LongNumber::operator -- (){
		*this = *this-"1";
		return *this;
	}

	LongNumber& LongNumber::operator -- (int){
		*this = *this-"1";
		return *this;
	}

	LongNumber LongNumber::operator * (const LongNumber& x) const{
		//TODO
		LongNumber result;
		return result;
	} 
	
	LongNumber LongNumber::operator / (const LongNumber& x) const{
		//TODO
		LongNumber result;
		return result;
	} 
	
	LongNumber LongNumber::operator % (const LongNumber& x) const {
		// TODO
		LongNumber result;
		return result;
	}
	
	int LongNumber::get_digits_number() const {
		return length;
	}
	
	bool LongNumber::is_positive() const {
		return sign == POSITIVE;
	}
	
	// ----------------------------------------------------------
	// PRIVATE
	// ----------------------------------------------------------
	int LongNumber::get_length(const char* const str) const {
		int length = 0;
			while (str[length] != END) length++;
		return length;
	}

	const char* LongNumber::to_char() const {
		int sign_indentation = 0;
		if (this->sign == NEGATIVE) sign_indentation++;

		char* result = new char[this->length+sign_indentation+1];
		result[this->length+sign_indentation] = END;
		if (sign_indentation) result[0] = MINUS;

		for (int i = 0; i < this->length; i++){
			char current_digit = this->numbers[i] + '0';
			result[i+sign_indentation] = current_digit;
		}

		return result;
	}

	void LongNumber::toggle_sign(){
		this->sign*=-1;
	}

	// ----------------------------------------------------------
	// FRIENDLY
	// ----------------------------------------------------------
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		os << x.to_char();
		return os;
	}
}
