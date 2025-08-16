#include <Python.h>
#include <iostream>

int main() {
    // Inizializza Python
    Py_Initialize();
    
    // Verifica che Python sia stato inizializzato correttamente
    if (!Py_IsInitialized()) {
        std::cerr << "Errore: Python non inizializzato correttamente\n";
        return 1;
    }

    // Aggiungi la directory corrente al path Python
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('.')");

    // Importa il modulo script
    PyObject *pName = PyUnicode_DecodeFSDefault("script");
    if (!pName) {
        std::cerr << "Errore: impossibile creare il nome del modulo\n";
        Py_Finalize();
        return 1;
    }
    
    PyObject *pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (!pModule) {
        PyErr_Print();
        std::cerr << "Errore: modulo 'script' non trovato\n";
        Py_Finalize();
        return 1;
    }

    // Ottieni la funzione 'saluta'
    PyObject *pFunc = PyObject_GetAttrString(pModule, "saluta");

    if (!pFunc) {
        std::cerr << "Errore: funzione 'saluta' non trovata\n";
        Py_DECREF(pModule);
        Py_Finalize();
        return 1;
    }
    
    if (!PyCallable_Check(pFunc)) {
        std::cerr << "Errore: 'saluta' non è una funzione callable\n";
        Py_DECREF(pFunc);
        Py_DECREF(pModule);
        Py_Finalize();
        return 1;
    }

    // Crea gli argomenti per la funzione
    PyObject *pName_arg = PyUnicode_FromString("Alessandro");
    if (!pName_arg) {
        std::cerr << "Errore: impossibile creare l'argomento stringa\n";
        Py_DECREF(pFunc);
        Py_DECREF(pModule);
        Py_Finalize();
        return 1;
    }
    
    PyObject *pArgs = PyTuple_Pack(1, pName_arg);
    Py_DECREF(pName_arg);  // Non serve più dopo averlo aggiunto alla tupla
    
    if (!pArgs) {
        std::cerr << "Errore: impossibile creare la tupla degli argomenti\n";
        Py_DECREF(pFunc);
        Py_DECREF(pModule);
        Py_Finalize();
        return 1;
    }

    // Chiama la funzione Python
    PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
    Py_DECREF(pArgs);

    if (pValue) {
        // Converte il risultato in stringa C
        const char* result_str = PyUnicode_AsUTF8(pValue);
        if (result_str) {
            std::cout << result_str << std::endl;
        } else {
            std::cerr << "Errore: impossibile convertire il risultato in stringa\n";
        }
        Py_DECREF(pValue);
    } else {
        std::cerr << "Errore durante la chiamata alla funzione Python:\n";
        PyErr_Print();
    }

    // Cleanup
    Py_DECREF(pFunc);
    Py_DECREF(pModule);

    Py_Finalize();
    return 0;
}
