#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <random>
#include "stringuri.h"
using namespace std;
class Angajat{
private:
    int id;
    char*nume;
    char*pozitia;
    double salariu;
    int varsta;
public:
    Angajat():id(0),nume(nullptr),pozitia(nullptr),salariu(0),varsta(0){
        nume=new char[1];
        nume[0]='\0';
        pozitia=new char[1];
        pozitia[0]='\0';
    }
    Angajat(int id, const char* nume, const char* pozitia, double salariu, int varsta):id(id),salariu(salariu),varsta(varsta){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->pozitia = new char[strlen(pozitia)+1];
        strcpy(this->pozitia, pozitia);
    }
    Angajat(const Angajat& A):id(A.id),salariu(A.salariu),varsta(A.varsta){
        this->nume=new char[strlen(A.nume)+1];
        strcpy(this->nume, A.nume);
        this->pozitia=new char[strlen(A.pozitia)+1];
        strcpy(this->pozitia, A.pozitia);
    }
    Angajat&operator=(const Angajat& A){
        if (this != &A) {
            this->id = A.id;
            delete[] this->nume;
            this->nume = new char[strlen(A.nume) + 1];
            strcpy(this->nume, A.nume);
            delete[] this->pozitia;
            this->pozitia = new char[strlen(A.pozitia) + 1];
            strcpy(this->pozitia, A.pozitia);
            this->salariu = A.salariu;
            this->varsta = A.varsta;
        }
        return *this;
    }
    int get_id()const
    {
        return this->id;
    }
    char* get_nume()const
    {
        return this->nume;
    }
    void reset_pozitia(const char*pozitia)
    {
        delete[] this->pozitia;
        this->pozitia = new char[strlen(pozitia) + 1];
        strcpy(this->pozitia, pozitia);
    }
    char* get_pozitia()const
    {
        return this->pozitia;
    }
    void marire_salariu(double marire)
    {
        this->salariu+=marire;
    }
    double get_salariu()const
    {
        return this->salariu;
    }
    void marire_varsta()
    {
        this->varsta++;
    }
    double get_varsta()const
    {
        return this->varsta;
    }
    ~Angajat()
    {
        if(this->nume!=nullptr)
            delete[] this->nume;
        if(this->pozitia!=nullptr)
            delete[] this->pozitia;
    }
    friend istream& operator >> (istream&citire,Angajat&ob);
    friend ostream& operator << (ostream&afisare,Angajat&ob);
};
istream& operator >> (istream&citire,Angajat&ob)
{
    cout<<"Introduceti ID:";citire>>ob.id;citire.get();
    cout<<"Introduceti numele:";ob.nume=new char[30];citire.get(ob.nume,30,'\n');citire.get();
    cout<<"Introduceti pozitia:";ob.pozitia=new char[30];citire.get(ob.pozitia,30,'\n');citire.get();
    cout<<"Introduceti salariul:";citire>>ob.salariu;citire.get();
    cout<<"Introduceti varsta:";citire>>ob.varsta;citire.get();
    return citire;
}
ostream& operator << (ostream&afisare,Angajat&ob)
{
    cout<<"ID:";afisare<<ob.id<<endl;
    cout<<"Nume:";afisare<<ob.nume<<endl;
    cout<<"Pozitia:";afisare<<ob.pozitia<<endl;
    cout<<"Salariul:";afisare<<ob.salariu<<endl;
    cout<<"Varsta:";afisare<<ob.varsta<<endl;
    return afisare;
}
class AngajatVector{
private:
    int size;
    Angajat*data;
public:
    AngajatVector()
    {
        size=0;
        data=nullptr;
    }
    AngajatVector(int k,Angajat&x)
    {
        data=new Angajat[k];
        for(int i=0;i<=k-1;i++)
            data[i]=x;
        size=k;
    }
    AngajatVector(const AngajatVector&v)
    {
        this->data=new Angajat[v.size];
        for(int i=0;i<v.size;i++)
            this->data[i]=v.data[i];
        this->size=v.size;
    }
    Angajat*get_address()
    {
        return this->data;
    }
    Angajat&get_angajatul_k(int k)
    {
        if(k<size)
            return this->data[k];
        else cout<<"Angajatul nr "<<k<<" nu exista!";
    }
    int get_size()
    {
        return this->size;
    }
    void add(AngajatVector&v, Angajat&x)
    {
        Angajat* new_data = new Angajat[v.size + 1];
        for (int i = 0; i < v.size; i++)
        {
            new_data[i] = v.data[i];
        }
        new_data[v.size] = x;
        delete[] v.data;
        v.data = new_data;
        v.size++;
    }
    void test(const AngajatVector&v)
    {
        cout<<&v<<" "<<this;
    }
    ~AngajatVector()
    {
        if(data!=nullptr)
            delete[] data;
    }
    AngajatVector& operator = (const AngajatVector&v)
    {
        if(this!=&v) {
            delete[] this->data;
            this->data = new Angajat[v.size];
            for (int i = 0; i < v.size; i++)
                this->data[i] = v.data[i];
            this->size=v.size;
        }
        return *this;
    }
    friend ostream& operator << (ostream&afisare,AngajatVector&V);
    friend istream& operator >>(istream&afisare,AngajatVector&V);
};
ostream& operator << (ostream&afisare,AngajatVector&V) {
    int n = V.get_size();
    for (int i = 0; i <= n - 1; i++)
        afisare << V.data[i] << "\n\n";
    return afisare;
}
istream& operator >> (istream&citire,AngajatVector&V)
{
    int n,x;
    cout<<"Introduceti numarul de angajati:";citire>>n;
    V.size=n;
    if(V.data!=nullptr)
        delete[] V.data;
    V.data=new Angajat[V.size];
    for(int i=0;i<n;i++)
        citire>>V.data[i];
    return citire;
}
class Client{
protected:
    char*nume;
    char*comanda;
    char*tip_comanda;
    int nr_telefon;
public:
    Client():nume(nullptr),comanda(nullptr)
    {
        nume=new char[1];
        nume[0]='\0';
        comanda=new char[1];
        comanda[0]='\0';
        tip_comanda=new char[1];
        tip_comanda[0]='\0';
    }
    Client(char*nume,char*comanda,char*tip_comanda,int nr_telefon):nume(nullptr),comanda(nullptr),tip_comanda(nullptr),nr_telefon(nr_telefon)
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->comanda=new char[strlen(comanda)+1];
        strcpy(this->comanda,comanda);
        this->tip_comanda=new char[strlen(tip_comanda)+1];
        strcpy(this->tip_comanda,tip_comanda);
    }
    Client(const Client& A):nr_telefon(nr_telefon){
        this->nume=new char[strlen(A.nume)+1];
        strcpy(this->nume, A.nume);
        this->comanda=new char[strlen(A.comanda)+1];
        strcpy(this->comanda, A.comanda);
        this->tip_comanda=new char[strlen(A.tip_comanda)+1];
        strcpy(this->tip_comanda, A.tip_comanda);
    }
    Client&operator=(const Client& A){
        if (this != &A) {
            delete[] this->nume;
            this->nume = new char[strlen(A.nume) + 1];
            strcpy(this->nume, A.nume);
            delete[] this->comanda;
            this->comanda = new char[strlen(A.comanda) + 1];
            strcpy(this->comanda, A.comanda);
            delete[] this->tip_comanda;
            this->tip_comanda = new char[strlen(A.tip_comanda) + 1];
            strcpy(this->tip_comanda, A.tip_comanda);
            this->nr_telefon = A.nr_telefon;
        }
        return *this;
    }
    virtual ~Client()
    {
        if(this->nume!=nullptr)
            delete[] this->nume;
        if(this->comanda!=nullptr)
            delete[] this->comanda;
        if(this->tip_comanda!=nullptr)
            delete[] this->tip_comanda;
    }
    char*get_nume()
    {
        return this->nume;
    }
    char*get_comanda()
    {
        return this->comanda;
    }
    char*get_tip_comanda()
    {
        return this->tip_comanda;
    }
    int get_nrtelefon()
    {
        return this->nr_telefon;
    }
    friend istream& operator >> (istream&citire,Client&ob);
    friend ostream& operator << (ostream&afisare,Client&ob);

};
class ClientList{
private:
    class Nod{
    private:
        Client info;
        Nod*next;
    public:
        void set_data(Client&info,Nod*next)
        {
            this->info=info;
            this->next=next;
        }
        Client&get_data()
        {
            return this->info;
        }
        Nod*get_next()
        {
            return next;
        }
        ~Nod()
        {
            if(this->next!=nullptr)
                delete this->next;
        }
    };
    Nod*ROOT,*r,*END;
public:
    ClientList()
    {
        ROOT=nullptr;
    }
    ~ClientList()
    {
        if(this->ROOT!=nullptr)
            delete this->ROOT;
    }
    Client&get_root()
    {
        return this->ROOT->get_data();
    }
    Client&get_end()
    {
        return this->END->get_data();
    }
    void add_begin(Client&val)
    {
        if(ROOT==nullptr)
        {
            ROOT=new Nod;
            (*ROOT).set_data(val,nullptr);
            END=ROOT;
        }
        else{
            r=new Nod;
            (*r).set_data(val,ROOT);
            ROOT=r;
        }
    }
    void add_end(Client&val)
    {
        if(ROOT==nullptr)
        {
            ROOT=new Nod;
            (*ROOT).set_data(val,nullptr);
            END=ROOT;
        }
        else{
            r=new Nod;
            (*r).set_data(val,nullptr);
            (*END).set_data(END->get_data(),r);
            END=r;
        }
    }
    void pop()
    {
        if(ROOT!=nullptr)
        {
            if(ROOT->get_next()!=nullptr)
                ROOT=ROOT->get_next();
            else cout<<"Exista doar un singur client la coada!"<<endl;
        }
        else cout<<"Momentan nu exista clienti!"<<endl;
    }
    void interogare_coada()
    {
        Nod*aux;
        aux=ROOT;
        cout<<"Coada este formata din urmatorii clienti:";
        while(aux!=nullptr)
        {
            cout<<aux->get_data().get_nume()<<"\t";
            aux=aux->get_next();
        }
    }
};
class ClientFidel:public Client{
private:
    int procent_discount;
public:
    int get_procent_discount()const
    {
        return this->procent_discount;
    }
    ClientFidel():Client()
    {
        procent_discount=0;
    }
    ClientFidel(char*nume,char*comanda,char*tip_comanda,int nr_telefon,int procent_discount):Client(nume,comanda,tip_comanda,nr_telefon)
    {
        this->procent_discount=procent_discount;
    }
    ClientFidel(const ClientFidel&A):Client(A)
    {
        procent_discount=0;
    }
    ~ClientFidel() override
    {}
};
class HR{
private:
    int nr_angajati;
    int nr_clienti;
    double medie_varsta_angajati;
    double medie_salarii_angajati;
public:
    HR():nr_angajati(0),nr_clienti(0),medie_varsta_angajati(0),medie_salarii_angajati(0)
    {}
    int get_nr_angajati()
    {
        return this->nr_angajati;
    }
    void update_nr_angajati(int x)
    {
        nr_angajati+=x;
    }
    int get_nr_clienti()
    {
        return this->nr_clienti;
    }
    void update_nr_clienti(int x)
    {
        nr_angajati+=x;
    }
    void recalculare_medie_salarii_angajati(double x)
    {
        double aux=medie_salarii_angajati*nr_angajati;
        aux+=x;
        aux=aux/1.0/(nr_angajati+1);
        medie_salarii_angajati=aux;
    }
    void recalculare_medie_varsta_angajati(double x)
    {
        double aux=medie_varsta_angajati*nr_angajati;
        aux+=x;
        aux=aux/1.0/(nr_angajati+1);
        medie_varsta_angajati=aux;
    }
    double get_medie_salarii()
    {
        return this->medie_salarii_angajati;
    }
    double get_medie_varste()
    {
        return this->medie_varsta_angajati;
    }
};
class Produs{
public:
    virtual int get_pret()=0;
    virtual int get_gramaj()=0;
    virtual string get_denumire()=0;
    virtual ~Produs()
    {}
};
class Pizza:public Produs{
private:
    int pret;
    string denumire;
    static const int gramaj=350;
public:
    Pizza(int pret,string denumire):pret(pret),denumire(denumire)
    {}
    int get_pret() override
    {
        return this->pret;
    }
    int get_gramaj()override
    {
        return Pizza::gramaj;
    }
    string get_denumire() override
    {
        return this->denumire;
    }
    ~Pizza() override
    {}
};
class Paste:public Produs{
private:
    int pret;
    string denumire;
    static  const int gramaj=400;
public:
    Paste(int pret,string denumire):pret(pret),denumire(denumire)
    {}
    int get_pret() override
    {
        return this->pret;
    }
    int get_gramaj() override
    {
        return Paste::gramaj;
    }
    string get_denumire() override
    {
        return this->denumire;
    }
    ~Paste() override
    {}
};
class Desert:public Produs{
private:
    int pret;
    string denumire;
    static const int gramaj=200;
public:
    Desert(int pret,string denumire):pret(pret),denumire(denumire)
    {}
    int get_pret() override
    {
        return this->pret;
    }
    int get_gramaj() override
    {
        return Desert::gramaj;
    }
    string get_denumire() override
    {
        return this->denumire;
    }
    ~Desert() override
    {}
};
queue<Produs*> coada;
queue<ClientFidel*> coada_clienti_fideli;
istream& operator >> (istream&citire,Client&ob)///de la Client
{
    cout<<"Introduceti numele:";ob.nume=new char[30];citire.get(ob.nume,30,'\n');citire.get();
    cout<<"Introduceti tipul comenzii:";ob.tip_comanda=new char[30];citire.get(ob.tip_comanda,30,'\n');citire.get();
    if(stricmp(ob.tip_comanda,"pizza")==0)
    {
        cout<<"Introduceti comanda:";ob.comanda=new char[30];citire.get(ob.comanda,30,'\n');citire.get();
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(35, 50);
        int randomValue = dist(gen);
        Produs*p=new Pizza(randomValue,string(ob.comanda));
        coada.push(p);
    }
    else if(stricmp(ob.tip_comanda,"paste")==0)
    {
        cout<<"Introduceti comanda:";ob.comanda=new char[30];citire.get(ob.comanda,30,'\n');citire.get();
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(40, 60);
        int randomValue = dist(gen);
        Produs*p=new Paste(randomValue,string(ob.comanda));
        coada.push(p);
    }
    else if(stricmp(ob.tip_comanda,"desert")==0){
        cout<<"Introduceti comanda:";ob.comanda=new char[30];citire.get(ob.comanda,30,'\n');citire.get();
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(20, 35);
        int randomValue = dist(gen);
        Produs*p=new Desert(randomValue,string(ob.comanda));
        coada.push(p);
    }
    cout<<"Introduceti nr_telefon(fara prefixul +40):";citire>>ob.nr_telefon;citire.get();
    return citire;
}
ostream& operator << (ostream&afisare,Client&ob)
{
    cout<<"Nume:";afisare<<ob.nume<<endl;
    cout<<"Tipul comenzii:";afisare<<ob.tip_comanda<<endl;
    cout<<"Comanda:";afisare<<ob.comanda<<endl;
    cout<<"Nr_telefon:0";afisare<<ob.nr_telefon<<endl;
    return afisare;
}
class Exceptie : public std::exception {
public:
    const char* what() const noexcept {
        return "A aparut o exceptie!\n";
    }
};
int main()
{
    int cerinta;
    cout<<"Buoungiorno!\nBine ati venit la Tudi's Pizza,adevarata pizza napoletana din Bucuresti!";
    cout<<"Acesta este un meniu interactiv in care puteti gestiona atat clientii cat si angajatii din pizzerie!\nPentru a adauga un angajat,apasati tasta 1\n";
    cout<<"Pentru a adauga un client la coada,apasati tasta 2\nPentru a elimina un client de la coada,apasati tasta 3\nPentru a afisa coada de clienti,apsati tasta 4\n";
    cout<<"Pentru a afisa lista de angajati,apasati tasta 5\nPentru a afisa numarul de amgajati,apasati tasta 6\n";
    cout<<"Pentru a afisa numarul de clienti,apasati tasta 7\nPentru a afisa media salariilor angajatilor,apasati tasta 8\n";
    cout<<"Pentru a afisa media varstelor angajatilor,apasati tasta 9\nPentru a adauga un client fidel la o coada speciala,apsati tasta 10\n";
    cout<<"Pentru a scoate un client fidel din coada speciala,apasati tasta 11\nPentru a afisa coada primul client fidel de la coada speciala,apasati tasta 12\n";
    cout<<"Pentru a intrerupe meniul interactiv,apasati tasta 0\n";
    cout<<"Introduceti cerinta:";cin>>cerinta;cin.get();
    Angajat X;
    AngajatVector V;
    Client Y;
    ClientList L;
    HR H;
    while(cerinta)
    {
        switch(cerinta)
        {
            case 1:{
                cin>>X;
                V.add(V,X);
                H.update_nr_angajati(1);
                H.recalculare_medie_salarii_angajati(X.get_salariu());
                H.recalculare_medie_varsta_angajati(X.get_varsta());
            }break;
            case 2:{
                cin>>Y;
                L.add_end(Y);
                H.update_nr_clienti(1);
            }break;
            case 3:{
                L.pop();
                if(coada.size()) {
                    delete coada.front();
                    coada.pop();
                    H.update_nr_clienti(-1);
                }
            }break;
            case 4:{
                L.interogare_coada();
                cout<<endl;
                cout<<"In acest moment se prepara ";
                if(coada.size())
                   cout<<coada.front()->get_denumire()<<",de "<<coada.front()->get_gramaj()<<" grame si costa "<<coada.front()->get_pret()<<" lei"<<endl;
                else cout<<"nu se prepara niciun preparat momentan!"<<endl;
            }break;
            case 5:{
                cout<<"Lista de angajati este:"<<endl;
                cout<<V;
            }break;
            case 6:{
                cout<<"Numarul de angajati este:"<<H.get_nr_angajati()<<endl;
            }break;
            case 7:{
                cout<<"Numarul de clienti este:"<<H.get_nr_clienti()<<endl;
            }break;
            case 8:{
                cout<<"Media salariilor angajatilor este:"<<H.get_medie_salarii()<<endl;
            }break;
            case 9:{
                cout<<"Media varstelor angajatilor este:"<<H.get_medie_varste()<<endl;
            }break;
            case 10:{
                char nume[30],comanda[30],tip_comanda[30];
                int nr_telefon,procent_discount;
                cin.get();
                cout<<"Introduceti numele:";
                cin.get(nume,30,'\n');
                cin.get();
                cout<<"Introduceti tipul comenzii:";
                cin.get(tip_comanda,30,'\n');
                cin.get();
                cout<<"Introduceti comanda:";
                cin.get(comanda,30,'\n');
                cin.get();
                cout<<"Introduceti numarul de telefon:";cin>>nr_telefon;
                cout<<"Introduceti procentul de discount:";cin>>procent_discount;
                Client*p=new ClientFidel(nume,comanda,tip_comanda,nr_telefon,procent_discount);
                ClientFidel*p2=dynamic_cast<ClientFidel*>(p);
                if(p2)
                {
                    coada_clienti_fideli.push(p2);
                }
            }break;
            case 11:{
                if(coada_clienti_fideli.size()) {
                    delete coada_clienti_fideli.front();
                    coada_clienti_fideli.pop();
                }
            }break;
            case 12:{
                if(coada_clienti_fideli.size())
                    cout<<"Clientul fidel de la coada este "<<coada_clienti_fideli.front()->get_nume()<<" care a comandat "<<coada_clienti_fideli.front()->get_comanda()<<" la care are un discount de "<<coada_clienti_fideli.front()->get_procent_discount()<<"%"<<endl;
            }break;
            default:{
                try{
                    if(cerinta>12)
                    {
                        throw Exceptie();
                    }
                }catch(const Exceptie&e)
                {
                    cout<<"Nu aveti voie sa apasati o tasta mai mare ca 12!\n";
                    e.what();
                }
            }
        }
        cout<<"Introduceti cerinta:";cin>>cerinta;cin.get();
    }
    return 0;
}