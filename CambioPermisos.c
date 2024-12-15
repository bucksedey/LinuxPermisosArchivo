/*
Grupo: 4CV1
Flores Anzurez Marco Antonio

Programa que utilizando sys/lib (sólo linux) que maneje y simule las matrices de acceso drwx | rwx | rwx
*/
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    // Verifica si se proporciona un argumento al programa.
    if (argc != 2) {
        printf("Uso: %s <\Users\52173\Documents\1.Tareas\Semestre4\SistemasOperativos\Programas\5Junio\Archivo.txt>\n", argv[0]);
        return 1;
    }

    // Define los permisos para el archivo.
    // S_IRWXU -> rwx para el propietario
    // S_IRWXG -> rwx para el grupo
    // S_IRWXO -> rwx para otros
    mode_t mode = S_IRWXU | S_IRWXG | S_IRWXO;

    // Cambia los permisos del archivo especificado por el argumento.
    // argv[1] es el nombre del archivo proporcionado como argumento.
    // La función chmod() devuelve 0 si tiene éxito, o -1 si ocurre un error.
    if (chmod(argv[1], mode) == -1) {
        perror("Error al cambiar los permisos del archivo");
        return 1;
    }

    printf("Los permisos del archivo han sido cambiados con éxito.\n");

    return 0;
}
