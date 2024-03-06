# OOP-FACULTY PROJECT(IN ROMANIAN)
-Acest proiect simulează gestionarea unei pizzerii, folosind paradigma de programare orientata pe obiecte.

-Programul conține 11 clase, prima și a doua clasa(clasa Angajat și AngajatVector),respectiv a treia și a patra(Client și Clientlist)fiind corelate prin agregare

-In clasa angajat sunt reținute detaliile esențiale, precum nume, funcție, salariu, etc.Clasa conține mai multe tipuri de constructori, cu sau fără parametri, de copiere, destructor care va sterge memoria alocată dinamic pentru a evita leak-urile, precum și operatorii de stream, respectiv de asignare supraincarcati pentru tipul de date respectiv.

-Clasa AngajatVector permite creerea unui vector alocat dinamic, cu obiecte de tip Angajat.Funcționalitățile sunt asemănătoare clasei Angajat.

-Analog sunt corelate clasa Client de clasa Clientlist, obiectele de tip Clientlist fiind de fapt liste de clienți, menite sa simuleze structura de coada, de asemenea clasa Client fiind clasa de baza pentru clasa ClientFidel.

-Nu in cele din urma, clasa HR, deși are structura mult mai simpla, este menită sa țină evidenta elementelor de bussines și management, precum numărul de angajați sau media salariilor.

-De asemenea, o clasa remarcabila, este clasa Produs, care este de fapt o interfata, din care se mostenesc 3 clase diferite:Pizza, Paste si Desert, clase ce au rolul sa suprascrie metodele pur virtuale din interfata.

-Avem, de asemenea, situatii de polimorfism la executie, upcasting si downcasting, destructori virtuali in clasele de baza, precum si o clasa custom de exceptii, ce extinde clasa std::exception.

-Se folosesc si containere stl, precum std::queue si std::string

-In main veți gasi un meniu interactiv in care puteți testa funcționalitățile proiectului, având instrucțiuni explicite despre fiecare operație.
