# Respuestas

#### 1. ¿Cuáles son los tipos de type descriptors que podemos encontrar en /proc//fd?
* Podemos encontrar los tipos provistos por la standard I/O las cuales son 0 para `stdin`, 1 para `stdout` y 2 para `stderr`. Es decir, dentro de `/proc/[pid]/fd/*` se obtiene un acceso al file descriptor del proceso de id 'pid'

> Referencia: M. Mitchell, J. Oldham y A. Samuel Cap. 2.1.4 Standard I/O, Cap. 7.2.5 Process File 
> Descriptors, Advanced Linux Programming

#### 2. Suponiendo que un usuario está ejecutando el proceso pid 1212, ¿Es válida la ejecución del siguiente comando desde una terminal nueva? % echo “Hello, world.” >> /proc/1212/fd/1
* Si, es completamente valido como podemos ver en la foto:

![alt text](https://github.com/ICOMP-UNC/soi---2021---laboratorio-3-Fran-cio/blob/main/pic.jpeg "Foto 1")

Salvo que en este caso en lugar de 1212 es el proceso numero 9704 como el indica el `top`.

#### 3. Qué diferencia hay entre hard y soft limits?
* Los `soft-limits` son los límites que se asignan para el procesamiento real de la aplicación o los usuarios, mientras que los `hard-limits`, no son más que un límite superior a los valores de los soft-limits. En otras palabras, los soft-limits son limitan lo que me permito hacer, y los hard-limits es lo que puedo, notese la analogia con las capacidades individuales.

> Referencia: [ulimit soft limits and hard limits in linux](https://www.geeksforgeeks.org/ulimit-soft- limits-and-hard-limits-in-linux/)


