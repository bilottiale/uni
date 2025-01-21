package controller;

import model.Aula;

public class GestoreAule {
    // check if Aula is AulaDidattica or Laboratorio
    public static boolean isAulaDidattica(Aula aula) {
        return "Aula Didattica".equals(aula.getTipo());
    }


    // da Aula a -> String
    // se Aula Didattica, controlla se ha lavagna(accessorio1) e/o proiettore(accessorio2), se Laboratorio, controlla se ha pc(accessorio1) e/o prese elettriche(accessorio2)
    public static String aulaToString(Aula aula) {
        if (isAulaDidattica(aula)) {
            return aula.getN_aula() + "," + aula.getCapienza() + "," + aula.getTipo() + "," + aula.getAccessori() + "\n";
        } else {
            return aula.getN_aula() + "," + aula.getCapienza() + "," + aula.getTipo() + "," + aula.getAccessori() + "\n";
        }
    }
}
