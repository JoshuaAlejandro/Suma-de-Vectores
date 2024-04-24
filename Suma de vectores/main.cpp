#include <iostream>

using namespace std;

class Vector {
private:
    int m_x;
    int m_y;

public:

    //constructor default
    explicit Vector();

    // Constructor paramétrico
    explicit Vector(int p_x, int p_y);


    //constructor copia
    Vector(Vector&o);

    // Destructor
    virtual ~Vector();

    //método para sumar dos vectores
    Vector sumar(Vector& A, Vector& B);


    //sobrecarga del operador suma
    Vector operator+(const Vector&);
    //sobrecarga del operador resta
    Vector operator-(const Vector&);
    //sobrecarga del operador de asignacion
    void operator=(const Vector&);

    //metodo para enviar y recivir informacion
    int getx();
    int gety();
    void setx(int v);
    void sety(int v);
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    friend std::istream& operator>>(std::istream& is, Vector& v);
};

//contructor defautl
Vector::Vector(){}
//contructor parametrico
Vector::Vector(int p_x, int p_y){

    m_x=p_x;
    m_y=p_y;
}
//contructor copia
Vector::Vector(Vector&o){}
Vector::~Vector(){}
//r       A                 B
Vector Vector::operator+(const Vector&o){
    Vector r;
    r.m_x=m_x+o.m_x;
    r.m_y=m_y+o.m_y;
    return r;
}

//Vector Vector::operator-(const Vector&o){
//    Vector r;
//    r.m_x=m_x-o.m_x;
//    r.m_y=m_y-o.m_y;
//    return r;
//}

//C                         r
void Vector::operator=(const Vector&o){
    m_x=o.m_x;
    m_y=o.m_y;
}

//Vector Vector::sumar(Vector& A, Vector& B){
//
//        Vector C;
//        C=A+B;
//
//        return C;
//
//}
int Vector::getx(){
    return m_x;
}
int Vector::gety(){
    return m_y;
}
void Vector::setx(int v){
    m_x=v;
}
void Vector::sety(int v){
    m_y=v;
}
class Programa{
private:
    Vector*m_vector1;
    Vector*m_vector2;
    Vector*m_vectorC;
public:
    //constructor default
    explicit Programa();
    //destructor
    virtual ~Programa();
    void PedirVectores();
    void MostrarResultado();
    void Run();

};
Programa::Programa(){
    m_vector1= new Vector;
    m_vector2= new Vector;
    m_vectorC= new Vector;
}
Programa::~Programa(){
    delete m_vector1;
    delete m_vector2;
    delete m_vectorC;
}
void Programa::PedirVectores(){
//    int val;
Vector a,b,c; //no se usarlo ptm
//    cout<<"Programa para sumar vectores"<<endl;
//    cout<<"siendo la suma de dos vectores que parten del origen (0,0)"<<endl;
//    cout<<"\n";
//    cout<<"dame de A la x"<<endl;
//    cin>>val;
//    m_vector1->setx(val);
//    cout<<"ahora dame y:";
//    cin>>val;
//    m_vector1->sety(val);
//    cout<<"Dame del vector b x"<<endl;
//    cin>>val;
//    m_vector2->setx(val);
//    cout<<"Dame del vectopr b y:";
//    cin>>val;
//    m_vector2->sety(val);
while(true){
        std::cout << "Ingrese las coordenadas del vector a (x, y): ";
        std::cin >> *m_vector1;

        if (!cin.fail()) {
             break;
        }else{
            cout << "Formato de vector invalido. Debe ser (x, y)." << endl<<endl;
        cin.clear();
        cin.ignore();
        }
        }

while(true){
    cout << "Ingrese las coordenadas del vector b (x, y): ";
    cin >> *m_vector2;

    if (!cin.fail()) {
             break;
        }else{
            cout << "Formato de vector invalido. Debe ser (x, y)." << endl<<endl;
        cin.clear();
        cin.ignore();
        }
        }
}
 ostream& operator<<(ostream& os, const Vector& v) {
        os << "(" << v.m_x << "," << v.m_y <<")";
        return os;
    }
istream& operator>>(istream& is, Vector& v) {
        char abrir_parentesis, coma, cerrar_parentesis;
        is >> abrir_parentesis >> v.m_x >> coma >> v.m_y >> cerrar_parentesis;

        if (abrir_parentesis == '(' && coma == ',' && cerrar_parentesis == ')')
            {
            return is;
      } else {
            is.setstate(ios::failbit);
            return is;
        }
        }
void Programa::MostrarResultado(){
//    cout<<endl<<"El resultado es: "<<endl;
//    cout<<"(";
//    cout<<m_vectorC->getx();
//    cout<<",";
//    cout<<m_vectorC->gety();
//    cout<<")";
    cout << "El vector c resultante es: " << *m_vectorC << endl;
}
void Programa::Run(){
    PedirVectores();
    *m_vectorC=*m_vector1 + *m_vector2;
    MostrarResultado();
}
int main()
{
    Programa(P);
    P.Run();
    return 0;
}
