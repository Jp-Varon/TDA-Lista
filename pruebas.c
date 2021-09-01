#include <stdio.h>
#include "lista.h"
#include "pa2mm.h"

bool mostrar_elementos(void* elemento, void* contador){
    if(elemento && contador)
        printf("Elemento %i: %c \n", (*(int*)contador)++, *(char*)elemento);
    return true;
}

void probar_creacion_lista(){
	pa2m_nuevo_grupo("PRUEBAS CREACION DE LISTA");
	lista_t* lista = NULL;
	pa2m_afirmar((lista = lista_crear()) != NULL, "pudo crear lista");
	pa2m_afirmar(lista->cantidad == 0, "crear lista con 0 nodos");
	pa2m_afirmar(lista->nodo_inicio == NULL, "crear lista con primer nodo a NULL");
	pa2m_afirmar(lista->nodo_fin == NULL, "crear lista con ultimo nodo a NULL");
	lista_destruir(lista);
}
void probar_insertar_elemento(){
	pa2m_nuevo_grupo("PRUEBAS INSERTAR ELEMENTOS");
	lista_t* lista = NULL;
	int resultado;
	int borrar;
	int elemento_1 = 1;
	int elemento_2 = 2;
	int elemento_3 = 3;
	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_1)) == -1, "no se pudo insertar, lista no valida");
	pa2m_afirmar((borrar = lista_borrar(lista)) == -1,"no se pudo borrar elemento, lista no valida");
	pa2m_afirmar(lista_vacia(lista) == true, "lista no valida, la lista esta vacia");
	lista = lista_crear();
	pa2m_afirmar((borrar = lista_borrar(lista)) == -1,"no se pudo borrar elemento, cantidad igual a 0");

	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_1)) == 0, "se pudo insertar, elemento_1");
	pa2m_afirmar(lista->cantidad == 1, "cantidad es igual a 1");
	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_2)) == 0, "se pudo insertar, elemento_2");
	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_3)) == 0, "se pudo insertar, elemento_3");
	pa2m_afirmar(lista->cantidad == 3, "cantidad es igual a 3");
	pa2m_afirmar(lista->nodo_inicio->elemento == &elemento_1, "elemento del inicio es igual al elemento_1");
	pa2m_afirmar(lista->nodo_fin->elemento == &elemento_3, "elemento del final es igual al elemento_3");
	pa2m_afirmar((borrar = lista_borrar(lista)) == 0, "se pudo borrar el elemento_3");
	pa2m_afirmar(lista->cantidad == 2, "cantidad es igual a 2");
	pa2m_afirmar(lista->nodo_fin->elemento == &elemento_2, "elemento del final es igual al elemento_2");
	pa2m_afirmar((borrar = lista_borrar(lista)) == 0, "se pudo borrar el elemento_2");
	pa2m_afirmar((borrar = lista_borrar(lista)) == 0, "se pudo borrar el elemento_1");
	pa2m_afirmar(lista->cantidad == 0, "cantidad es igual a 0");
	lista_destruir(lista);
}

void probar_insertar_elemento_posicion(){
	pa2m_nuevo_grupo("PRUEBAS INSERTAR ELEMENTO EN POSICION");
	lista_t* lista = NULL;
	lista = lista_crear();
	int elemento_1 = 1;
	int elemento_2 = 2;
	int elemento_3 = 3;
	int elemento_4 = 4;
	int resultado;
	int borrar;
	pa2m_afirmar((resultado = lista_insertar_en_posicion(lista, &elemento_1, 0)) == 0, "insertar elemento en posicion 0 en lista vacia");
	pa2m_afirmar((resultado = lista_insertar_en_posicion(lista, &elemento_4, 0)) == 0, "insertar elemento_4 en posicion 0 con lista llena");
	pa2m_afirmar((resultado = lista_insertar_en_posicion(lista, &elemento_2, 6)) == 0, "insertar elemento_2 en posicion inexistente");
	pa2m_afirmar((resultado = lista_insertar_en_posicion(lista, &elemento_3, 0)) == 0,"insertar elemento_3 en medio");
	pa2m_afirmar((borrar = lista_borrar(lista)) == 0, "se pudo borrar el elemento_2");
	pa2m_afirmar((borrar = lista_borrar(lista)) == 0, "se pudo borrar el elemento_3");
	pa2m_afirmar((borrar = lista_borrar(lista)) == 0, "se pudo borrar el elemento_1");
	pa2m_afirmar((borrar = lista_borrar(lista)) == 0, "se pudo borrar el elemento_4");
	lista_destruir(lista);


}

void probar_lista_destruir(){
	pa2m_nuevo_grupo("PRUEBAS LISTA_DESTRUIR");
	lista_t* lista = NULL;
	lista = lista_crear();
	int elemento_1 = 1;
	int elemento_2 = 2;
	int elemento_3 = 3;
	int resultado;
	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_1)) == 0, "se pudo insertar, elemento_1");
	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_2)) == 0, "se pudo insertar, elemento_2");
	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_3)) == 0, "se pudo insertar, elemento_3");
	lista_destruir(lista);
}

void probar_eliminar_posicion(){
	pa2m_nuevo_grupo("PRUEBAS ELIMINAR_EN_POSICION");
	lista_t* lista = NULL;
	lista = lista_crear();
	int elemento_1 = 1;
	int elemento_2 = 2;
	int elemento_3 = 3;
	int resultado;
	int borrar;
	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_1)) == 0, "se pudo insertar, elemento_1");
	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_2)) == 0, "se pudo insertar, elemento_2");
	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_3)) == 0, "se pudo insertar, elemento_3");
	pa2m_afirmar((borrar = lista_borrar_de_posicion(lista, 1)) == 0, "se pudo eliminar el elemento del medio");
	pa2m_afirmar(lista->cantidad == 2, "cantidad es igual a 2");
	pa2m_afirmar((borrar = lista_borrar_de_posicion(lista, 6)) == 0, "se pudo eliminar en posicion no valida");
	pa2m_afirmar((borrar = lista_borrar_de_posicion(lista, 0)) == 0, "se pudo eliminar en posicion 0 con un elemento");
	
	lista_destruir(lista);
}
void probar_lista_elementos(){
	pa2m_nuevo_grupo("PRUEBAS ELEMENTOS EN LISTA");
	lista_t* lista = NULL;
	void* elemento;
	pa2m_afirmar((elemento = lista_elemento_en_posicion(lista, 0)) == NULL, "lista no valida, elemento en primera posicion es NULL");
	lista = lista_crear();
	int elemento_1 = 1;
	int elemento_2 = 2;
	int elemento_3 = 3;
	int resultado;
	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_1)) == 0, "se pudo insertar, elemento_1");
	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_2)) == 0, "se pudo insertar, elemento_2");
	pa2m_afirmar((resultado = lista_insertar(lista, &elemento_3)) == 0, "se pudo insertar, elemento_3");
	pa2m_afirmar((elemento = lista_elemento_en_posicion(lista, 2)) == &elemento_3, "elemento en ultima posicion es el elemento_3");
	pa2m_afirmar((elemento = lista_elemento_en_posicion(lista, 1)) == &elemento_2, "elemento en segunda posicion es el elemento_2");
	pa2m_afirmar((elemento = lista_elemento_en_posicion(lista, 6)) == NULL, "no existe posicion");
	pa2m_afirmar((elemento = lista_ultimo(lista)) == &elemento_3, "el ultimo elemento es elemento_3");
	pa2m_afirmar((resultado = lista_insertar(lista, NULL)) == 0, "se pudo insertar, NULL");
	pa2m_afirmar((elemento = lista_ultimo(lista)) == NULL, "el ultimo elemento es NULL");
	lista_destruir(lista);

}

void probar_apilar_elementos(){
	pa2m_nuevo_grupo("PRUEBAS APILAR ELEMENTOS");
	lista_t* lista = NULL;
	int resultado;
	int borrar;
	int elemento_1 = 1;
	int elemento_2 = 2;
	int elemento_3 = 3;
	pa2m_afirmar((resultado = lista_apilar(lista, &elemento_1)) == -1, "no se pudo insertar, lista no valida");
	pa2m_afirmar((borrar = lista_desapilar(lista)) == -1,"no se pudo borrar elemento, lista no valida");
	lista = lista_crear();
	pa2m_afirmar((borrar = lista_desapilar(lista)) == -1,"no se pudo borrar elemento, cantidad igual a 0");

	pa2m_afirmar((resultado = lista_apilar(lista, &elemento_1)) == 0, "se pudo insertar, elemento_1");
	pa2m_afirmar(lista->cantidad == 1, "cantidad es igual a 1");
	pa2m_afirmar((resultado = lista_apilar(lista, &elemento_2)) == 0, "se pudo insertar, elemento_2");
	pa2m_afirmar((resultado = lista_apilar(lista, &elemento_3)) == 0, "se pudo insertar, elemento_3");
	pa2m_afirmar(lista->cantidad == 3, "cantidad es igual a 3");
	pa2m_afirmar(lista->nodo_inicio->elemento == &elemento_1, "elemento del inicio es igual al elemento_1");
	pa2m_afirmar(lista_tope(lista) == &elemento_3, "elemento del final es igual al elemento_3");
	pa2m_afirmar((borrar = lista_desapilar(lista)) == 0, "se pudo borrar el elemento_3");
	pa2m_afirmar(lista->cantidad == 2, "cantidad es igual a 2");
	pa2m_afirmar(lista_tope(lista) == &elemento_2, "elemento del final es igual al elemento_2");
	pa2m_afirmar((borrar = lista_desapilar(lista)) == 0, "se pudo borrar el elemento_2");
	pa2m_afirmar((borrar = lista_desapilar(lista)) == 0, "se pudo borrar el elemento_1");
	pa2m_afirmar(lista->cantidad == 0, "cantidad es igual a 0");
	pa2m_afirmar(lista_tope(lista) == NULL, "la lista esta vacia");
	lista_destruir(lista);

}

void probar_encolar_elementos(){
	pa2m_nuevo_grupo("PRUEBAS ENCOLAR ELEMENTOS");
	lista_t* lista = NULL;
	int resultado;
	int borrar;
	int elemento_1 = 1;
	int elemento_2 = 2;
	int elemento_3 = 3;
	pa2m_afirmar((resultado = lista_encolar(lista, &elemento_1)) == -1, "no se pudo insertar, lista no valida");
	pa2m_afirmar((borrar = lista_desencolar(lista)) == -1,"no se pudo borrar elemento, lista no valida");
	pa2m_afirmar(lista_primero(lista) == NULL, "lista no valida, elemento del inicio es igual a NULL");
	pa2m_afirmar(lista_tope(lista) == NULL, "lista no valida, elemento del final es igual a NULL");
	lista = lista_crear();
	pa2m_afirmar((borrar = lista_desencolar(lista)) == -1,"no se pudo borrar elemento, cantidad igual a 0");

	pa2m_afirmar((resultado = lista_encolar(lista, &elemento_1)) == 0, "se pudo insertar, elemento_1");
	pa2m_afirmar(lista->cantidad == 1, "cantidad es igual a 1");
	pa2m_afirmar((resultado = lista_encolar(lista, &elemento_2)) == 0, "se pudo insertar, elemento_2");
	pa2m_afirmar((resultado = lista_encolar(lista, &elemento_3)) == 0, "se pudo insertar, elemento_3");
	pa2m_afirmar(lista->cantidad == 3, "cantidad es igual a 3");
	pa2m_afirmar(lista_primero(lista) == &elemento_1, "elemento del inicio es igual al elemento_1");
	pa2m_afirmar(lista_tope(lista) == &elemento_3, "elemento del final es igual al elemento_3");
	pa2m_afirmar((borrar = lista_desencolar(lista)) == 0, "se pudo borrar el elemento_1");
	pa2m_afirmar(lista->cantidad == 2, "cantidad es igual a 2");
	pa2m_afirmar(lista_tope(lista) == &elemento_3, "elemento del final es igual al elemento_2");
	pa2m_afirmar((borrar = lista_desencolar(lista)) == 0, "se pudo borrar el elemento_2");
	pa2m_afirmar((borrar = lista_desencolar(lista)) == 0, "se pudo borrar el elemento_3");
	pa2m_afirmar(lista->cantidad == 0, "cantidad es igual a 0");
	pa2m_afirmar(lista_primero(lista) == NULL, "elemento del inicio es NULL");
	lista_destruir(lista);
}

void probar_iteradores(){
	pa2m_nuevo_grupo("PRUEBAS ITERADORES");
	lista_iterador_t * iterador = NULL;
	lista_t * lista = NULL;
	int resultado;
	lista_iterador_crear(lista);
	pa2m_afirmar((iterador = lista_iterador_crear(lista)) == NULL, "no se pudo crear iterador, lista no valida");
	lista = lista_crear();
	pa2m_afirmar((iterador = lista_iterador_crear(lista)) != NULL, "se pudo crear iterador con lista vacia");
	pa2m_afirmar((lista_iterador_tiene_siguiente(iterador)) == false, "no tiene siguiente, lista vacia");
	pa2m_afirmar((lista_iterador_avanzar(iterador)) == false, "no se puede avanzar, lista vacia");
	pa2m_afirmar((lista_iterador_elemento_actual(iterador)) == NULL, "no tiene elemento, lista vacia");
	pa2m_afirmar((lista_con_cada_elemento(lista, mostrar_elementos, NULL)) == 0, "elementos igual a 0 con iterador interno")
	int elemento_1 = 1;
	int elemento_2 = 2;
	int elemento_3 = 3;
	lista_iterador_destruir(iterador);
	pa2m_afirmar((resultado = lista_encolar(lista, &elemento_1)) == 0, "se pudo insertar, elemento_1");
	pa2m_afirmar((resultado = lista_encolar(lista, &elemento_2)) == 0, "se pudo insertar, elemento_2");
	pa2m_afirmar((resultado = lista_encolar(lista, &elemento_3)) == 0, "se pudo insertar, elemento_3");
	pa2m_afirmar((iterador = lista_iterador_crear(lista)) != NULL, "se pudo crear iterador con elementos");
	pa2m_afirmar((lista_iterador_tiene_siguiente(iterador)) == true, "tiene siguiente");
	pa2m_afirmar((lista_iterador_elemento_actual(iterador)) == &elemento_1, "elemento en posicion 0 es igual al elemento_1");
	pa2m_afirmar((lista_iterador_avanzar(iterador)) == true, "se puede avanzar, iterador en posicion 1");
	pa2m_afirmar((lista_iterador_tiene_siguiente(iterador)) == true, "tiene siguiente");
	pa2m_afirmar((lista_iterador_elemento_actual(iterador)) == &elemento_2, "elemento en posicion 1 es igual al elemento_2");
	pa2m_afirmar((lista_iterador_avanzar(iterador)) == true, "se puede avanzar, iterador en posicion 2");
	pa2m_afirmar((lista_iterador_tiene_siguiente(iterador)) == true, "tiene siguiente");
	pa2m_afirmar((lista_iterador_elemento_actual(iterador)) == &elemento_3, "elemento en posicion 1 es igual al elemento_3");
	pa2m_afirmar((lista_iterador_avanzar(iterador)) == false, "se puede avanzar, iterador en posicion 3");
	pa2m_afirmar((lista_iterador_tiene_siguiente(iterador)) == false, "no tiene siguiente, final de la lista");
	pa2m_afirmar((lista_iterador_elemento_actual(iterador)) == NULL, "no tiene elemento, final de la lista");
	pa2m_afirmar((lista_iterador_avanzar(iterador)) == false, "no se puede avanzar, final de la lista");
	pa2m_afirmar((lista_con_cada_elemento(lista, mostrar_elementos, NULL)) == 3, "elementos igual a 3 con iterador interno");
	pa2m_afirmar((lista_con_cada_elemento(lista, NULL, NULL)) == 0, "elementos igual a 0 con iterador interno Y no hay funcion");


	lista_iterador_destruir(iterador);
	lista_destruir(lista);
	pa2m_mostrar_reporte();

}

int main(){

	probar_creacion_lista();
	probar_insertar_elemento();
	probar_insertar_elemento_posicion();
	probar_lista_destruir();
	probar_eliminar_posicion();
	probar_lista_elementos();
	probar_apilar_elementos();
	probar_encolar_elementos();
	probar_iteradores();



	return 0;
}