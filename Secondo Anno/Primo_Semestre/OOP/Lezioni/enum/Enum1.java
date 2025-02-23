import java.lang.reflect.Field;

public class Enum1 {
    public void fireEvent(EventType.Type event) {
        System.out.println("L'evento ricevuto è:");
        if (event == EventType.Type.OPEN) {
            System.out.println("OPEN");
        }
        else if (event == EventType.Type.CLOSE) {
            System.out.println("CLOSE");
        }
        else if (event == EventType.Type.EXIT) {
            System.out.println("EXIT");
        }

        // studiamo la classe dell'evento
        Class eventClass = event.getClass();
        System.out.println("Nome della classe di evento: " + eventClass.getName());
        for (Field f : eventClass.getFields()) {
            System.out.println("Campo: " + f.getName());
            System.out.println("\t visibilita': ");
            int modificatore = f.getModifiers();
            if(modificatore == 1)
                System.out.println("\t\t public");
            else if(modificatore == 2)
                System.out.println("\t\t private");
            else if(modificatore == 4)
                System.out.println("\t\t protected");
            else
                System.out.println("\t\t default");
        }
    }

    public static void main(String[] argv) {
        Enum1 m = new Enum1();
        m.fireEvent(EventType.Type.OPEN);
        m.fireEvent(EventType.Type.CLOSE);
        System.out.println("Come risulta stampato? --> " + EventType.Type.OPEN);
    }
}
