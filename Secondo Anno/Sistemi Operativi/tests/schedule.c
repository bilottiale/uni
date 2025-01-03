#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/delay.h>

static struct task_struct *example_thread;

/* Funzione eseguita dal thread del kernel */
int example_function(void *data) {
    printk(KERN_INFO "Esempio: Thread iniziato.\n");

    /* Simulazione di lavoro con sospensioni */
    while (!kthread_should_stop()) {
        set_current_state(TASK_INTERRUPTIBLE);  // Imposta il processo come sospendibile
        schedule();  // Cede la CPU ad altri processi
        printk(KERN_INFO "Esempio: Ripreso dopo schedule().\n");
    }

    printk(KERN_INFO "Esempio: Thread terminato.\n");
    return 0;
}

/* Funzione di inizializzazione del modulo */
static int __init example_init(void) {
    printk(KERN_INFO "Esempio: Modulo caricato.\n");

    /* Creazione di un thread kernel */
    example_thread = kthread_run(example_function, NULL, "example_thread");
    if (IS_ERR(example_thread)) {
        printk(KERN_ERR "Esempio: Errore nella creazione del thread.\n");
        return PTR_ERR(example_thread);
    }

    return 0;
}

/* Funzione di uscita del modulo */
static void __exit example_exit(void) {
    if (example_thread) {
        kthread_stop(example_thread);  // Termina il thread
    }
    printk(KERN_INFO "Esempio: Modulo scaricato.\n");
}

module_init(example_init);
module_exit(example_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Esempio");
MODULE_DESCRIPTION("Esempio di utilizzo di schedule() nel kernel Linux.");