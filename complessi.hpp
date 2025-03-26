template<typename T> requires std::floating_point<T>

class complex
{
    T Re, Im;
	
	
public:

    complex()
        : Re(0), Im(0)
    {}
    
    explicit complex(T n)
        : Re(n), Im(0)
    {}
    
    complex(T n, T d)
        : Re(n), Im(d)
    {}
    
    T realpart(void) const {
        return Re;
    }
    
    T impart(void) const {
        return Im;
    }
	
	complex<T> conjugate(void) {
		return complex<T>(Re, -Im);
	}
    
	
    complex& operator+=(const complex& other) {
        T a = Re;
        T b = Im;
        T c = other.Re;
        T d = other.Im;
        Re = a+c;
        Im = b+d;
        return *this;
	}

	complex operator+(const complex& other) const {
        complex ret = *this;
        ret += other;
        return ret;
    }

	complex operator*=(const complex& other){
		T a = Re;
        T b = Im;
        T c = other.Re;
        T d = other.Im;
		Re = a*c - b*d;
		Im = a*d + b*c;	
	}
	
	complex operator*(const complex& other) const {
		complex ret = *this;
        ret *= other;
        return ret;
	}
	
	complex& operator+=(const T& other) {
		Re += other;
		return *this;
		
	}
	
	complex operator+(const T& other) const {
	complex ret = *this;
	ret += other;
	return ret;
	}
	
	complex operator*=(const T& other){
		Re *= other;
		return *this;
	}
	
	complex operator*(const T& other) const {
		complex ret = *this;
		ret *= other;
		return ret;
	}
};

/* This operator is defined outside the complex class and is needed
 * to compute the sum of an I on the left and a complex<I> on the
 * right. */
template<typename T>	requires std::floating_point<T>
complex<T>
operator+(const T& i, const complex<T>& c)
{
    return c + i;
}

template<typename T>	requires std::floating_point<T>
complex<T>
operator*(const T& i, const complex<T>& c)
{
    return c * i;
}


template<typename T>
std::ostream&
operator<<(std::ostream& os, const complex<T>& c) {
		if (c.impart() == 0)
			os << c.realpart();
		else if (c.impart() > 0)
			os << c.realpart() << "+" << c.impart()<<"i";
		else
			os << c.realpart() << "" << c.impart()<<"i";
    return os;
}




