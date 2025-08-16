#include <stdio.h>
#include <string.h>

int main() {
    long file_size;
    FILE *f;
    if( (f = fopen("myfile", "rb")) == NULL ){
        fprintf(stderr, "Impossibile aprire il file\n");
        return 1;
    }
    if(fseek(f, 0, SEEK_END) == -1){
        fprintf(stderr, "Errore fseek su file\n");
        goto end;
    }
    if((file_size = ftell(f)) == -1){
	    fprintf(stderr, "Errore ftell su file\n");
        goto end;
    }
	printf("File size: %ld\n", file_size);
end:
    if(fclose(f) == EOF){
        fprintf(stderr, "Errore chiusura file\n");
        return 1;
    }
    return 0;
}
