template<typename T> requires std::floating_point<T>

class complex
{
    T Re, Im;
	
	
public:
	/* costruttore di default */

    complex()
        : Re(0), Im(0)
    {}
    
    explicit complex(T n)
        : Re(n), Im(0)
    {}
    
    complex(T n, T d)
        : Re(n), Im(d)
    {}
    
	/* Definizione del metodo realpart che restituisce la parte reale di un numero complesso
		segue la definizione di impart, analogo per la parte immaginaria del numero*/
	
    T realpart(void) const {
        return Re;
    }
    
    T impart(void) const {
        return Im;
    }
	
	/* Definizione del metodo conjugate , che resituisce il coniugato di un numero complesso */
	complex<T> conjugate(void) {
		return complex<T>(Re, -Im);
	}
    
	/* Definizione dell'operatore += per i numeri complessi; questo operatore prende 
		una sola istanza e la aggiunge all'istanza su cui viene viene chiamato*/
    complex& operator+=(const complex& other) {
        T a = Re;
        T b = Im;
        T c = other.Re;
        T d = other.Im;
        Re = a+c;
        Im = b+d;
        return *this;
	}
	
	/* Definizione dell'operatore +, sfruttando l'operatore += definito in precedenza*/
	complex operator+(const complex& other) const {
        complex ret = *this;
        ret += other;
        return ret;
    }

	/* Definizione degli operatori *= e * tra complessi*/
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
	
	/* Definisco gli operatori +=, +, *= e * per le operazioni tra un complesso a sinistra
		e un type T a destra*/
	complex& operator+=(const T& other) {
		Re += other;
		return *this;
		
	}
	
	complex operator+(const T& other) const {
	complex ret = *this;
	ret += other;
	return ret;
	}
	
	complex& operator*=(const T& other){
		Re *= other;
		Im *= other;
		return *this;
	}
	
	complex operator*(const T& other) const {
		complex ret = *this;
		ret *= other;
		return ret;
	}
};

/* I seguenti operatori sono definiti fuori dalla classe 'complex' e servono per calcolare
	la somma e il prodotto tra un type T a sinistra e un complesso a destra */
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

/* overload dell'operatore << per stampare numeri complessi*/
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
