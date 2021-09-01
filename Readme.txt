1ª SECCION:
	en el siguiente trabajo se presenta el tda lista, cola y pila, todos en un mismo
	archivo, junto con un iterador interno y otro externo. Al haber solo un archivo, 
	pero bien separados por sus respectivas funciones, se pueden crear cualquiera de
	de los tres tda por separado. Tomando las funciones para crear "una lista", se 
	crea una lista en la cual se puede ir agregando elementos tanto al final de esta
	como en cualquier posicion, siendo lo mismo para borrar un elemento. tambien 
	cuenta con funciones que nos dicen si la lista esta vacia, otra que retorna la 
	cantidad de elementos en esta o el elemento que esta al final. Tomando las 
	funciones para crear una "pila", se crea una lista, y se van apilando los 
	elementos en el final de esta, con la particularidad que cuando se borra, 
	solo se puede borrar el elemento del final, existe una funcion de nos dice que
	elemento esta al final de la pila. Por ultimo, si tomamos las funciones para 
	crear una "cola", los  elementos se van encolando al final, pero cuando se tiene 
	que borrar, se iran borrando desde el primer elemento insertado, existiendo la
	funcion que nos dice cual es el primer elemento de la cola. cuando se termina de
	ultilizar la lista (en cualquier de sus variantes), se debe destruir la lista con
	la funcion destruir_lista.
	Utilizando las funciones de iterador externo, debemos pasarle por parametro la
	lista que queremos iterar, una vez hecho esto, se crea el iterador y nosotros
	vamos controlando cuando queremos movernos dentro de la lista con la funcion de
	avanzar, teniendo como ayuda una funcion que nos dice si existe una elemento
	siguiente y una funcion que nos retorna el elemento en donde se encuentra el
	iterador. cuando se termina la lista, se debe destruir el iterador con la
	funcion de destruir_iterador. Sin embargo cuando se quiere utilizar el iterador
	interno, se debe pasar por parametro tanto la lista como una funcion booleana
	que funciona como condicion para seguir iterando dentro de la lista, este 
	iterador retorna la cantidad de elementos que cumplen la condicion de la funcion
	booleana hasta que se encuentre uno que no cumpla o que se llegue al final 
	de la lista.

	LINEA DE COMPILACION:
	se compila con la siguiente linea:
		"gcc *.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic 
			-Werror -O0"
	en el cual: 
		gcc: es un compilador de programas en c.
		*.c: significa que se deberan compilar todos los archivos con extencion .c en 
			la carpeta donde nos encontremos.
		-g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0: flags
			 nesesarios para que el programa nos informe de cualquier error que 
			 tengamos.
		-o lista_se: como llamaremos al programa ya compilado y listo para 
			ejecutar 

	LINEA DE EJECUCION:
	se ejecuta de la siguiente manera:
	"./lista_se"
	./: lo que escribas despues de el sera un archivo dentro del directoria donde te
		encontras y no un comando.
		lista_se: nombre del archivo.

2ª SECCION:
	EXPLICACION DE CONCEPTOS:

	"¿Qué es lo que entendés por una lista? ¿Cuáles son las diferencias entre ser
		simple o doblemente enlazada?"

	Lo que entiendo por una lista es que es una formacion de nodos que estan unidos 
	de manera tal que no tienen que estar unos seguidos de otro para mantener dicha
	union, denro de estos nodos, se pueden guardar los elementos que queremos tener
	en la dicha y un puntero al nodo siguiente, la cual sirve para mantener la union.
	la diferencia entre una lsita enlazada y otra doblemente enlazada es que en la
	primera, los nodos esta unidos de manera tal que el anterior nodo conoce a su 
	siguiente, pero no al revez, esto repercuta en que a la lista solo se la puede
	recorrer de manera continua y no reversible, comenzando desde el principio.
	en cambio, una lista doblemente enlazada, un nodo conoce a su predecedor y a su
	antesesor, lo caul a pesar que hace mas grande al nodo, tenemos la capacidad de
	recorrer la lista de varias maneras, con la posibilidad de retroceder si queremos.

	"¿Cuáles son las características fundamentales de las Pilas? ¿Y de las Colas?"

	las pilas tambien son una formacion de nodos, pero tienen como caracteristica
	especial su eliminacion e insercion, para ser conciderado "pila", un elemento 
	debe ser inseretado al final de esta y cuando se elimina, se debe eliminar el
	elemento final de la lista. con cola pasa algo parecido, en cuando que su 
	caracteristica especial recide en su insercion y su eliminacion, para ser 
	conciderado "cola", se debe insertar el elemento en el final de todo, pero 
	cuando se elimina, se debe eliminar el primer elemento dentro de la lista.

	"¿Qué es un iterador? ¿Cuál es su función?"

	un iterador es un una estructura que permite al usuario el recorrer la lista que 
	tiene. tiene como funcion principal el recorrer la lista y retornar los 
	elementos donde se encuentra actualmente.

	"¿En qué se diferencia un iterador interno de uno externo?"

	la diferencia principal entre ambos es que con el iterador externo, los usuarios
	tiene la capacidad de contralor a voluntar el recorrido de la lista, en cambio,
	con el iterador interno, el usuario debe pasar una funcion que se utiliza como
	condicion de corte de la iteracion y no es posible controlarla, este iterador 
	retorna la cantidad de elementos que cumplen con las funcion antes dada.