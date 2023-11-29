
# Laboratorio di Programmazione - Progetto intermedio

Costruzione di una classe *BookShelf* (libreria) che gestisce istanze della classe *Book*  
*BookShelf* utilizza vettori dinamici similmente alla classe [*std::Vector*](https://cplusplus.com/reference/vector/vector/) simulando una libreria         
*Book* fa uso della classe *Date* che rappresenta istanze di tipo data (giorno,mese,anno) 


## Authors

- **Aghi Filippo** 
- **Marchetti Alessio**
- **Milan Matteo**


## Features
*All'interno delle classi sono state implementate le opportune funzionionalità e validazioni di input* 
___
- Date: controllo validità giorno, mese, anno
- Book: Controllo di validita data copyright
- Book: controllo validità ISBN (13 cifre numeriche con prefisso 978) 
> Ausilio di Regular Expression --> [Regex](https://en.cppreference.com/w/cpp/regex)



## Installation

La compilazione dei file sorgente è predisposta per l'utilizzo di *CMake* 

L'utilizzo è possibile mediante file _CMakeLists.txt_

    
