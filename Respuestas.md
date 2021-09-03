#Respuestas
###1. ¿Cuáles son los tipos de type descriptors que podemos encontrar en /proc//fd?
* Podemos encontrar los tipos provistos por la standard I/O las cuales son 0 para `stdin`, 1 para `stdout` y 2 para `stderr`. Es decir, dentro de `/proc/[pid]/fd/*` se obtiene un acceso al file descriptor del proceso de id 'pid'

###2. Suponiendo que un usuario está ejecutando el proceso pid 1212, ¿Es válida la ejecución del siguiente comando desde una terminal nueva? % echo “Hello, world.” >> /proc/1212/fd/1
*Si, es completamente valido como podemos ver en la foto:

![alt text](https://github.com/ICOMP-UNC/soi---2021---laboratorio-3-Fran-cio/pic.png "Foto 1")

Salvo que en este caso en lugar de 1212 es el proceso numero 9704 como el indica el `top`.
